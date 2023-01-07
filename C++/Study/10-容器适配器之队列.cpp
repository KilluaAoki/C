#include <iostream>
#include <queue>
#include <cassert>

/*
	容器适配器之队列
		1."queue"类模板的介绍
		2."queue"类模板的使用
		3."queue"类模板的元素访问
		4."queue"类模板中与容量相关的成员函数
		5."queue"类模板中与修改器相关的成员函数
		6."queue"类模板相关的非成员函数
*/

/**
	"queue"类模板的介绍："std::queue"类是容器适配器，具有队列的功能("FIFO"(先进先出)数据结构)，定义于头文件"queue"中，简称为"queue"。
		1."queue"的定义与特性
			a."queue"是一个类模板，它的定义为：template< class T, class Container = std::deque<T> > class queue;。
				a'."T"是存储的元素类型。
				b'."Container"是用于存储元素的底层容器类型，它需满足序列容器(线性排列中存储相同类型对象的容器)的要求。
					a''.C++具名要求中序列容器的相关文档：https://zh.cppreference.com/w/cpp/named_req/SequenceContainer。
					b''."Container"必须提供带通常语义的"push_back"、"pop_back"、"back"、"front"成员函数，标准容器"deque"和"list"满足这些要求。
					c''.若不为特定的"queue"类特化指定容器类，则使用标准容器"deque"类。
			b."queue"类模板表现为底层容器的包装器(即充当底层容器的包装器)，只提供特定函数集合，即仅提供一组特定的函数。
			c.队列在底层容器尾端推入元素，从首端弹出元素。
		2."queue"的成员类型
			a."container_type"成员类型：定义为"Container"，即底层容器类型。
			b."value_type"成员类型：定义为"Container::value_type"，即底层容器的元素类型。
			c."size_type"成员类型：定义为"Container::size_type"，即底层容器的大小类型。
			d."reference"成员类型：定义为"Container::reference"，即底层容器的引用类型。
			e."const_reference"成员类型：定义为"Container::const_reference"，即底层容器的常引用类型。
		3."queue"的成员对象：唯一的"Container c"成员对象，代表底层容器，是受保护的成员对象。
*/

/**
	"queue"类模板的使用
		1."queue"的常见构造函数的函数原型(以下部分函数原型忽略分号)
			a."explicit queue( const Container& cont = Container() )"：C++11前的默认构造函数，以"cont"的内容复制构造底层容器"c"。
				a'."cont"参数：用作源初始化底层容器的容器。
				b'.在C++11起，此函数的原型为：explicit queue( const Container& cont );。
				c'.复杂度：同被包装容器上的对应操作。
			b."queue() : queue(Container()) { }"：C++11起的默认构造函数，容器将进行值初始化，同时它也是一个委托构造函数(视实现而定)。
				a'."queue(Container())"：以默认构造的底层容器作为参数，调用对应构造函数。
				b'.复杂度：同被包装容器上的对应操作。
		2."queue"的析构函数的函数原型：~queue();。
			a.销毁"queue"，调用元素的析构函数，然后解分配所用的存储(若元素是指针，则不销毁所指向的对象)。
			b.复杂度与"queue"的大小成线性级别。
		3."queue"中的"operator="成员函数：赋值给容器适配器，即替换容器适配器内容。
			a.常见函数原型：queue& operator=( const queue& other );。
				a'.拷贝赋值运算符，以"other"的内容替换容器适配器的内容，即以"other"的内容副本替换内容，其中"other"是用作源的另一容器适配器。
				b'.等效地调用"c = other.c"，并且实际上此函数是隐式声明的。
			b.复杂度：等价于底层容器"operator="的复杂度。
*/

////"queue"类模板的使用示例
//int main()
//{
//	std::queue<int> q1;
//
//	for (int i = 1; i <= 3; ++i)
//		q1.push(i);
//
//	std::queue<int> q2(q1);
//
//	for (int i = 0; i < 3; ++i)
//	{
//		std::cout << "q1.front() = " << q1.front() << std::endl;
//		std::cout << "q1.back() = " << q1.back() << std::endl;
//		std::cout << "q1.pop()" << std::endl;
//		q1.pop();
//	}
//	std::cout << std::endl;
//
//	for (int i = 0; i < 3; ++i)
//	{
//		std::cout << "q2.front() = " << q2.front() << std::endl;
//		std::cout << "q2.back() = " << q2.back() << std::endl;
//		std::cout << "q2.pop()" << std::endl;
//		q2.pop();
//	}
//	std::cout << std::endl;
//
//	q2 = q1;
//
//	assert(q2.empty());//断言为真，代表"q2"为空。
//
//	for (int i = 0; i < 3; ++i)
//		q1.push(i);
//
//	q2 = q1;
//
//	for (int i = 0; i < 3; ++i)
//	{
//		std::cout << "q2.front() = " << q2.front() << std::endl;
//		std::cout << "q2.back() = " << q2.back() << std::endl;
//		std::cout << "q2.pop()" << std::endl;
//		q2.pop();
//	}
//	std::cout << std::endl;
//
//	return 0;
//}

/**
	"queue"类模板的元素访问
		1."front"成员函数：访问第一个元素。
			a.函数原型
				a'.reference front();。
				b'.const_reference front() const;。
			b.返回"queue"中首元素的引用，此元素将是调用"pop"成员函数时第一个被移除的元素，等效于调用"c.front()"。
			c.复杂度为常数级别。
		2."back"成员函数：访问最后一个元素。
			a.函数原型
				a'.reference back();。
				b'.const_reference back() const;。
			b.返回"queue"中末元素的引用，它是最近推入的元素，等效于调用"c.back()"。
			c.复杂度为常数级别。
*/

////"queue"类模板的元素访问示例
//int main()
//{
//	std::queue<int> q;
//
//	for (int i = 1; i <= 3; ++i)
//		q.push(i);
//
//	std::cout << "q.front() = " << q.front() << std::endl;
//	std::cout << "q.back() = " << q.back() << std::endl;
//	std::cout << std::endl;
//
//	q.pop();
//
//	std::cout << "q.front() = " << q.front() << std::endl;
//	std::cout << "q.back() = " << q.back() << std::endl;
//	std::cout << std::endl;
//
//	q.pop();
//
//	std::cout << "q.front() = " << q.front() << std::endl;
//	std::cout << "q.back() = " << q.back() << std::endl;
//	std::cout << std::endl;
//
//	return 0;
//}

/**
	"queue"类模板中与容量相关的成员函数
		1."empty"成员函数：检查底层容器是否为空。
			a.函数原型(C++20前)：bool empty() const;。
			b.用于检查底层容器是否为空，即是否"c.empty()"。
			c.返回值为布尔类型，若底层容器为空时返回"true"，否则返回"false"。
			d.复杂度为常数级别。
		2."size"成员函数：返回容纳的元素数。
			a.函数原型(C++20前)：size_type size() const;。
			b.返回底层容器中的元素数，即返回容器中的元素数，即"c.size()"。
			c.复杂度为常数级别。
*/

////"queue"类模板中与容量相关的成员函数示例
//int main()
//{
//	std::queue<int> q;
//
//	for (int i = 1; i <= 3; ++i)
//		q.push(i);
//
//	std::cout << "q.empty() = " << q.empty() << std::endl;
//	std::cout << "q.size() = " << q.size() << std::endl;
//	std::cout << std::endl;
//
//	q.pop();
//
//	std::cout << "q.empty() = " << q.empty() << std::endl;
//	std::cout << "q.size() = " << q.size() << std::endl;
//	std::cout << std::endl;
//
//	q.pop();
//
//	std::cout << "q.empty() = " << q.empty() << std::endl;
//	std::cout << "q.size() = " << q.size() << std::endl;
//	std::cout << std::endl;
//	
//	q.pop();
//	
//	std::cout << "q.empty() = " << q.empty() << std::endl;
//	std::cout << "q.size() = " << q.size() << std::endl;
//	std::cout << std::endl;
//
//	return 0;
//}

/**
	"queue"类模板中与修改器相关的成员函数(暂不介绍C++11起支持的"emplace"成员函数)
		1."push"成员函数：向队列尾部插入元素，即推给定的元素到队列尾。
			a.常见函数原型：void push( const value_type& value );。
				a'."value"参数：要推入的元素值。
			b.等效地调用"c.push_back(value)"。
			c.复杂度：等于"Container::push_back"的复杂度。
		2."pop"成员函数：删除首个元素，即从队列移除前端元素。
			a.函数原型：void pop();。
			b.等效地调用"c.pop_front()"。
			c.复杂度：等于"Container::pop_front"的复杂度。
		3."swap"成员函数：交换内容。(C++11起)
			a.函数原型：void swap( queue& other );。(忽略"noexcept"说明符细节)
				a'."other"参数：要交换内容的容器适配器。
			b.交换容器适配器与"other"的内容，等效于调用"using std::swap"及"swap(c, other.c)"。
			c.复杂度：与底层容器相同，通常为常数级别。
*/

////"queue"类模板中与修改器相关的成员函数示例一：使用"push"成员函数和"pop"成员函数。
//int main()
//{
//	std::queue<int> s;
//
//	s.push(1);
//	s.push(2);
//	s.push(3);
//
//	std::cout << "s.size(): " << s.size() << '\n';
//
//	s.pop();
//	s.pop();
//	s.pop();
//
//	std::cout << "After popping, s.size(): " << s.size() << '\n';
//
//	return 0;
//}

////"queue"类模板中与修改器相关的成员函数示例二：使用"swap"成员函数。
//void printQueue(std::queue<int> s)
//{
//	while (!s.empty())
//	{
//		std::cout << "front() = " << s.front() << ' ';
//		s.pop();
//	}
//	std::cout << '\n';
//}
//
//int main()
//{
//	std::queue<int> s1, s2;
//
//	s1.push(1);
//	s1.push(2);
//	s1.push(3);
//
//	s2.push(4);
//	s2.push(5);
//	s2.push(6);
//
//	std::cout << "Before swapping, s1: ";
//	printQueue(s1);
//	std::cout << "Before swapping, s2: ";
//	printQueue(s2);
//
//	s1.swap(s2);
//
//	std::cout << "After swapping, s1: ";
//	printQueue(s1);
//	std::cout << "After swapping, s2: ";
//	printQueue(s2);
//
//	return 0;
//}

/**
	"queue"类模板相关的非成员函数
		1.按照字典顺序比较"queue"中的值(函数模板)。
			a.比较二个容器适配器的底层容器，通过应用对应的运算符到底层容器进行比较。
			b.常见函数原型(省略了模板声明、模板参数、分配器和命名空间等细节)
				a'.bool operator==( const queue& lhs, const queue& rhs );。
				b'.bool operator!=( const queue& lhs, const queue& rhs );。
				c'.bool operator<( const queue& lhs, const queue& rhs );。
				d'.bool operator<=( const queue& lhs, const queue& rhs );。
				e'.bool operator>( const queue& lhs, const queue& rhs );。
				f'.bool operator>=( const queue& lhs, const queue& rhs );。
			c.返回值：若对应比较产出"true"，则为"true"，否则为"false"。
			d.复杂度与容器大小成线性级别。
		2."swap"函数：标准算法库中的"swap"函数模板对"queue"类模板的特化，用于交换两个"queue"的内容。(函数模板)(C++11起)
			a.常见函数原型：void swap( queue& lhs, queue& rhs );。(C++17前)(省略了模板声明、模板参数、分配器和命名空间等细节)
			b.调用"lhs.swap(rhs)"。
			c.复杂度：与交换底层容器相同。
*/

////"queue"类模板相关的非成员函数示例一：使用比较运算符比较"queue"中的值。(于C++20前的标准下编译此代码)
//int main()
//{
//	std::queue<int> s1, s2;
//
//	s1.push(1);
//	s1.push(2);
//	s1.push(3);
//
//	s2.push(4);
//	s2.push(5);
//	s2.push(6);
//
//	std::cout << "s1 == s2: " << (s1 == s2) << '\n';
//	std::cout << "s1 != s2: " << (s1 != s2) << '\n';
//	std::cout << "s1 < s2: " << (s1 < s2) << '\n';
//	std::cout << "s1 <= s2: " << (s1 <= s2) << '\n';
//	std::cout << "s1 > s2: " << (s1 > s2) << '\n';
//	std::cout << "s1 >= s2: " << (s1 >= s2) << '\n';
//
//	return 0;
//}

////"queue"类模板中与修改器相关的成员函数示例二：使用"swap"非成员函数。
//void printQueue(std::queue<int> s)
//{
//	while (!s.empty())
//	{
//		std::cout << "front() = " << s.front() << ' ';
//		s.pop();
//	}
//	std::cout << '\n';
//}
//
//int main()
//{
//	std::queue<int> s1, s2;
//
//	s1.push(1);
//	s1.push(2);
//	s1.push(3);
//
//	s2.push(4);
//	s2.push(5);
//	s2.push(6);
//
//	std::cout << "Before swapping, s1: ";
//	printQueue(s1);
//	std::cout << "Before swapping, s2: ";
//	printQueue(s2);
//
//	std::swap(s1, s2);
//
//	std::cout << "After swapping, s1: ";
//	printQueue(s1);
//	std::cout << "After swapping, s2: ";
//	printQueue(s2);
//
//	return 0;
//}