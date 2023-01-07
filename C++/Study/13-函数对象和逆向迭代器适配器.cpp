#include <iostream>
#include <cstdlib>
#include <functional>
#include <algorithm>

/*
	函数对象和逆向迭代器
		1.函数对象
		2.逆向迭代器适配器
*/

/**
	函数对象：又被称为仿函数，是实现"operator()"的任何类型(重载调用运算符)，允许对象被当作普通函数一样调用。
		1.函数对象介绍
			a.任何定义了函数调用操作符的对象都是函数对象，C++支持创建、操作新的函数对象，同时也提供了许多内置的函数对象。
			b.函数对象的典型用途：编写回调函数。
				a'.在C语言中的回调可以通过使用函数指针来执行(泛指其他过程语言)，然而，将状态传入或传出回调函数可能很困难或很尴尬，此限制还抑制了函数的更多动态行为。
				b'.函数对象解决了C语言的这些问题(泛指其他过程语言)，因为函数实际上是完整对象的外观，带有自己的状态。
			c.C++中的谓词：谓词是一种函数对象，是一个可调用的表达式，它返回一个布尔值。
				a'.如果"operator()"接受一个参数，那么叫做一元谓词。
				b'.如果"operator()"接受两个参数，那么叫做二元谓词。
		2.函数对象的用途：C++标准库"functional"头文件中，包含多个函数对象，这些函数对象的其中一个用途是用作容器的排序条件，比如曾经提到过的"less"函数对象和"greater"函数对象。
			a."less"函数对象：运算符函数对象，用于比较，是实现"x < y"的函数对象。(类模板)(简要介绍)
				a'."less"类模板的定义：template< class T > struct less;。(C++14前)
				b'.实现比较的函数对象，调用类型"T"上的"operator<"，除非特化。
				c'."operator()"成员函数：用于检查第一参数是否小于第二个。
					a''.函数原型(C++14前)：bool operator()( const T& lhs, const T& rhs ) const;。
					b''.检查"lhs"是否小于"rhs"。
					c''.返回值：如果"lhs"小于"rhs"，则返回"true"，否则返回"false"。
			b."greater"函数对象：运算符函数对象，用于比较，是实现"x > y"的函数对象。(类模板)(简要介绍)
				a'."greater"类模板的定义：template< class T > struct greater;。(C++14前)
				b'.实现比较的函数对象，调用类型"T"上的"operator>"，除非特化。
				c'."operator()"成员函数：用于检查第一参数是否大于第二个。
					a''.函数原型(C++14前)：bool operator()( const T& lhs, const T& rhs ) const;。
					b''.检查"lhs"是否大于"rhs"。
					c''.返回值：如果"lhs"大于"rhs"，则返回"true"，否则返回"false"。
		3.函数对象的优点(相对于函数指针)
			a.编译器可以内联执行函数对象的调用。
			b.函数对象内部可以保持状态。
*/

////函数对象示例一：创建简单的函数对象(创建一个类型并实现"operator()")。
//class Functor
//{
//public:
//	int operator()(int a, int b)
//	{
//		return a < b;
//	}
//};
//
//int main()
//{
//	int a = 5;
//	int b = 7;
//
//	int ans1 = Functor()(a, b);
//	std::cout << ans1 << std::endl;
//
//	Functor functor;
//	int ans2 = functor(a, b);
//	std::cout << ans2 << std::endl;
//
//	return 0;
//}

////函数对象示例二：C语言的函数指针和C++的函数对象。
//int compareInts(const void* a, const void* b)
//{
//	return (*(int*)a - *(int*)b);
//}
//
//struct IntComparator
//{
//	bool operator()(const int& a, const int& b) const
//	{
//		return a < b;
//	}
//};
//
//int main()
//{
//	//C语言的函数指针示例
//	int itemsC[] = { 4, 3, 1, 2 };
//	qsort(itemsC, sizeof(itemsC) / sizeof(itemsC[0]), sizeof(itemsC[0]), compareInts);
//
//	//C++的函数对象示例
//	std::vector<int> itemsCpp{ 4, 3, 1, 2 };
//	std::sort(itemsCpp.begin(), itemsCpp.end(), IntComparator());//此处将一个函数对象"IntComparator()"(匿名)作为参数传递给"sort"函数。
//
//	return 0;
//}

////函数对象示例三：使用"less"函数对象。
//template<typename A, typename B, typename C = std::less<>>
//bool fun(A a, B b, C cmp = C())
//{
//	return cmp(a, b);
//}
//
//int main()
//{
//	std::cout << std::boolalpha
//			  << fun(1, 2) << ' '
//			  << fun(1.0, 1) << ' '
//			  << fun(1, 2.0) << ' '
//			  << std::less<int>{}(5, 5.6) << ' '//警告：隐式转换。
//			  << std::less<double>{}(5, 5.6) << ' '
//			  << std::less<int>{}(5.6, 5.7) << ' '//警告：隐式转换。
//			  << std::less{}(5, 5.6) << ' '
//			  << '\n';
//
//	return 0;
//}

////函数对象示例四：可维持状态的函数对象。
//class CountFrom
//{
//public:
//	CountFrom(int count) : count_(count)
//	{
//	}
//
//	int operator()()
//	{
//		return count_++;
//	}
//
//private:
//	int count_;
//};
//
//int main()
//{
//	CountFrom countFrom(10);
//
//	std::cout << countFrom() << std::endl;
//	std::cout << countFrom() << std::endl;
//	std::cout << countFrom() << std::endl;
//
//	return 0;
//}

/**
	逆向迭代器适配器：即"std::reverse_iterator"，逆序遍历的迭代器适配器，是一个类模板，定义于头文件"iterator"中，简称为反向迭代器或逆向迭代器。
		1.简要介绍
			a.逆向迭代器是一个反转给定必须至少是老式双向迭代器或实现"bidirectional_iterator"(C++20起)的迭代器方向的适配器。(当前阶段了解即可)
			b.当提供双向迭代器时，"std::reverse_iterator"产生一个新的迭代器，它从底层的双向迭代器所定义的序列的末尾移动到开端。
			c.标准库容器的"rbegin"及"rend"成员函数所返回的迭代器图片示例：https://upload.cppreference.com/mwiki/images/3/39/range-rbegin-rend.svg。
		2.可复用的逆向迭代器适配器：在标准实现中，"std::reverse_iterator"是一个可复用的适配器，其内部实现大多都是对于运算符重载的成员函数。
		3.逆向迭代器适配器相关文档：https://zh.cppreference.com/w/cpp/iterator/reverse_iterator。
*/

////逆向迭代器适配器示例一：使用"std::reverse_iterator"。
//int main()
//{
//	std::string s = "Hello, world";
//
//	std::reverse_iterator<std::string::iterator> r = s.rbegin();
//
//	r[7] = 'O';
//	r += 7;
//
//	std::string rev(r, s.rend());
//
//	std::cout << rev << '\n';
//
//	return 0;
//}

////逆向迭代器适配器示例二：实现简单的逆向迭代器适配器。
//namespace Aoki
//{
//	template<class Iterator, class pointer, class reference>
//	class reverse_iterator
//	{
//	public:
//		typedef Iterator iterator_type;
//		typedef reverse_iterator<Iterator, pointer, reference> this_type;
//
//		reverse_iterator() : mIterator()
//		{
//		}
//
//		explicit reverse_iterator(Iterator it) : mIterator(it)
//		{
//		}
//
//		reverse_iterator(const reverse_iterator& ri) : mIterator(ri.mIterator)
//		{
//		}
//
//		iterator_type base() const
//		{
//			return mIterator;
//		}
//
//		reference operator*()
//		{
//			iterator_type i(mIterator);
//			return *--i;
//		}
//
//		pointer operator->()
//		{
//			return &(operator*());
//		}
//
//		this_type& operator++()
//		{
//			--mIterator;
//			return *this;
//		}
//
//		this_type operator++(int)
//		{
//			reverse_iterator ri(*this);
//			--mIterator;
//			return ri;
//		}
//
//		this_type& operator--()
//		{
//			++mIterator;
//			return *this;
//		}
//
//		this_type operator--(int)
//		{
//			reverse_iterator ri(*this);
//			++mIterator;
//			return ri;
//		}
//
//	protected:
//		Iterator mIterator;
//	};
//
//	template<class Iterator, class reference, class pointer>
//	inline bool operator==(const reverse_iterator<Iterator, pointer, reference>& lhs,
//			const reverse_iterator<Iterator, pointer, reference>& rhs)
//	{
//		return lhs.base() == rhs.base();
//	}
//
//	template<class Iterator, class reference, class pointer>
//	inline bool operator!=(const reverse_iterator<Iterator, pointer, reference>& lhs,
//			const reverse_iterator<Iterator, pointer, reference>& rhs)
//	{
//		return lhs.base() != rhs.base();
//	}
//}