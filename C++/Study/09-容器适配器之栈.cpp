#include <iostream>
#include <stack>
#include <cassert>

/*
	容器适配器之栈
		1."stack"类模板的介绍
		2."stack"类模板的使用
		3."stack"类模板的元素访问
		4."stack"类模板中与容量相关的成员函数
		5."stack"类模板中与修改器相关的成员函数
		6."stack"类模板相关的非成员函数
*/

/**
	"stack"类模板的介绍："std::stack"类是容器适配器，具有栈的功能("LIFO"(后进先出)数据结构)，定义于头文件"stack"中，简称为"stack"。
		1."stack"的定义与特性
			a."stack"是一个类模板，它的定义为：template< class T, class Container = std::deque<T> > class stack;。
				a'."T"是存储的元素类型。
				b'."Container"是用于存储元素的底层容器类型，它需满足序列容器(线性排列中存储相同类型对象的容器)的要求。
					a''.C++具名要求中序列容器的相关文档：https://zh.cppreference.com/w/cpp/named_req/SequenceContainer。
					b''."Container"必须提供拥有通常语义的"push_back"、"pop_back"、"back"成员函数，标准容器"vector"、"deque"和"list"满足这些要求。
					c''.若不为特定的"stack"类特化指定容器类，则使用标准容器"deque"类。
			b."stack"类模板表现为底层容器的包装器(即充当底层容器的包装器)，只提供特定函数集合，即仅提供一组特定的函数。
			c.栈从被称作栈顶的容器尾部推弹元素，即栈从底层容器的背面(称为栈顶)压入和弹出元素。
		2."stack"的成员类型
			a."container_type"成员类型：定义为"Container"，即底层容器类型。
			b."value_type"成员类型：定义为"Container::value_type"，即底层容器的元素类型。
			c."size_type"成员类型：定义为"Container::size_type"，即底层容器的大小类型。
			d."reference"成员类型：定义为"Container::reference"，即底层容器的引用类型。
			e."const_reference"成员类型：定义为"Container::const_reference"，即底层容器的常引用类型。
		3."stack"的成员对象：唯一的"Container c"成员对象，代表底层容器，是受保护的成员对象。
*/

/**
	"stack"类模板的使用
		1."stack"的常见构造函数的函数原型(以下部分函数原型忽略分号)
			a."explicit stack( const Container& cont = Container() )"：C++11前的默认构造函数，以"cont"的内容复制构造底层容器"c"。
				a'."cont"参数：用作源初始化底层容器的容器。
				b'.在C++11起，此函数的原型为：explicit stack( const Container& cont );。
				c'.复杂度：同被包装容器上的对应操作。
			b."stack() : stack(Container()) { }"：C++11起的默认构造函数，容器将进行值初始化，同时它也是一个委托构造函数(视实现而定)。
				a'."stack(Container())"：以默认构造的底层容器作为参数，调用对应构造函数。
				b'.复杂度：同被包装容器上的对应操作。
		2."stack"的析构函数的函数原型：~stack();。
			a.销毁"stack"，调用元素的析构函数，然后解分配所用的存储(若元素是指针，则不销毁所指向的对象)。
			b.复杂度与"stack"的大小成线性级别。
		3."stack"中的"operator="成员函数：赋值给容器适配器，即替换容器适配器内容。
			a.常见函数原型：stack& operator=( const stack& other );。
				a'.拷贝赋值运算符，以"other"的内容替换容器适配器的内容，即以"other"的内容副本替换内容，其中"other"是用作源的另一容器适配器。
				b'.等效地调用"c = other.c"，并且实际上此函数是隐式声明的。
			b.复杂度：等价于底层容器"operator="的复杂度。
*/

////"stack"类模板的使用示例
//int main()
//{
//	std::stack<int> c1;
//
//	for (int i = 1; i <= 3; ++i)
//		c1.push(i);
//
//	std::stack<int> c2(c1);
//
//	for (int i = 0; i < 3; ++i)
//	{
//		std::cout << "c1.top() = " << c1.top() << std::endl;
//		std::cout << "c1.pop()" << std::endl;
//		c1.pop();
//	}
//	std::cout << std::endl;
//
//	for (int i = 0; i < 3; ++i)
//	{
//		std::cout << "c2.top() = " << c2.top() << std::endl;
//		std::cout << "c2.pop()" << std::endl;
//		c2.pop();
//	}
//	std::cout << std::endl;
//
//	c2 = c1;
//
//	assert(c2.empty());//断言为真，代表"c2"为空。
//
//	for (int i = 0; i < 3; ++i)
//		c1.push(i);
//
//	c2 = c1;
//
//	for (int i = 0; i < 3; ++i)
//	{
//		std::cout << "c2.top() = " << c2.top() << std::endl;
//		std::cout << "c2.pop()" << std::endl;
//		c2.pop();
//	}
//	std::cout << std::endl;
//
//	return 0;
//}

/**
	"stack"类模板的元素访问
		1."top"成员函数：访问栈顶元素。
			a.函数原型
				a'.reference top();。
				b'.const_reference top() const;。
			b.返回"stack"中顶元素的引用，它是最近推入的元素，此元素将在调用"pop"成员函数时被移除，等效于调用"c.back()"。
			c.复杂度为常数级别。
*/

////"stack"类模板的元素访问示例
//int main()
//{
//	std::stack<int> s;
//
//	s.push(2);
//	s.push(6);
//	s.push(51);
//
//	std::cout << s.size() << " elements on stack\n";
//	std::cout << "Top element: " << s.top() << "\n";//"top"成员函数不会移除栈顶元素。
//	std::cout << s.size() << " elements on stack\n";
//
//	s.pop();
//	std::cout << "s.pop()" << '\n';
//
//	std::cout << s.size() << " elements on stack\n";
//	std::cout << "Top element: " << s.top() << "\n";
//
//	return 0;
//}

/**
	"stack"类模板中与容量相关的成员函数
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

////"stack"类模板中与容量相关的成员函数示例
//int main()
//{
//	std::stack<int> s;
//
//	std::cout << "Initially, s.empty(): " << s.empty() << '\n';
//
//	s.push(1);
//	s.push(2);
//	s.push(3);
//
//	std::cout << "After pushing, s.empty(): " << s.empty() << '\n';
//	std::cout << "s.size(): " << s.size() << '\n';
//
//	s.pop();
//	s.pop();
//	s.pop();
//
//	std::cout << "After popping, s.empty(): " << s.empty() << '\n';
//
//	return 0;
//}

/**
	"stack"类模板中与修改器相关的成员函数(暂不介绍C++11起支持的"emplace"成员函数)
		1."push"成员函数：向栈顶插入元素，即推给定的元素到栈顶。
			a.常见函数原型：void push( const value_type& value );。
				a'."value"参数：要推入的元素值。
			b.等效地调用"c.push_back(value)"。
			c.复杂度：等于"Container::push_back"的复杂度。
		2."pop"成员函数：删除栈顶元素，即从栈顶移除顶元素。
			a.函数原型：void pop();。
			b.等效地调用"c.pop_back()"。
			c.复杂度：等于"Container::pop_back"的复杂度。
		3."swap"成员函数：交换内容。(C++11起)
			a.函数原型：void swap( stack& other );。(忽略"noexcept"说明符细节)
				a'."other"参数：要交换内容的容器适配器。
			b.交换容器适配器与"other"的内容，等效于调用"using std::swap"及"swap(c, other.c)"。
			c.复杂度：与底层容器相同，通常为常数级别。
*/

////"stack"类模板中与修改器相关的成员函数示例一：使用"push"成员函数和"pop"成员函数。
//int main()
//{
//	std::stack<int> s;
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

////"stack"类模板中与修改器相关的成员函数示例二：使用"swap"成员函数。
//void printStack(std::stack<int> s)
//{
//	while (!s.empty())
//	{
//		std::cout << s.top() << ' ';
//		s.pop();
//	}
//	std::cout << '\n';
//}
//
//int main()
//{
//	std::stack<int> s1, s2;
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
//	printStack(s1);
//	std::cout << "Before swapping, s2: ";
//	printStack(s2);
//
//	s1.swap(s2);
//
//	std::cout << "After swapping, s1: ";
//	printStack(s1);
//	std::cout << "After swapping, s2: ";
//	printStack(s2);
//
//	return 0;
//}

/**
	"stack"类模板相关的非成员函数
		1.按照字典顺序比较"stack"中的值(函数模板)。
			a.比较二个容器适配器的底层容器，通过应用对应的运算符到底层容器进行比较。
			b.常见函数原型(省略了模板声明、模板参数、分配器和命名空间等细节)
				a'.bool operator==( const stack& lhs, const stack& rhs );。
				b'.bool operator!=( const stack& lhs, const stack& rhs );。
				c'.bool operator<( const stack& lhs, const stack& rhs );。
				d'.bool operator<=( const stack& lhs, const stack& rhs );。
				e'.bool operator>( const stack& lhs, const stack& rhs );。
				f'.bool operator>=( const stack& lhs, const stack& rhs );。
			c.返回值：若对应比较产出"true"，则为"true"，否则为"false"。
			d.复杂度与容器大小成线性级别。
		2."swap"函数：标准算法库中的"swap"函数模板对"stack"类模板的特化，用于交换两个"stack"的内容。(函数模板)(C++11起)
			a.常见函数原型：void swap( stack& lhs, stack& rhs );。(C++17前)(省略了模板声明、模板参数、分配器和命名空间等细节)
			b.调用"lhs.swap(rhs)"。
			c.复杂度：与交换底层容器相同。
*/

////"stack"类模板相关的非成员函数示例一：使用比较运算符比较"stack"中的值。(于C++20前的标准下编译此代码)
//int main()
//{
//	std::stack<int> s1, s2;
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

////"stack"类模板中与修改器相关的成员函数示例二：使用"swap"非成员函数。
//void printStack(std::stack<int> s)
//{
//	while (!s.empty())
//	{
//		std::cout << s.top() << ' ';
//		s.pop();
//	}
//	std::cout << '\n';
//}
//
//int main()
//{
//	std::stack<int> s1, s2;
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
//	printStack(s1);
//	std::cout << "Before swapping, s2: ";
//	printStack(s2);
//
//	std::swap(s1, s2);
//
//	std::cout << "After swapping, s1: ";
//	printStack(s1);
//	std::cout << "After swapping, s2: ";
//	printStack(s2);
//
//	return 0;
//}