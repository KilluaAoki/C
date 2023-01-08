#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

/*
	容器适配器之优先级队列
		1."priority_queue"类模板的介绍
		2."priority_queue"类模板的使用
		3."priority_queue"类模板的元素访问
		4."priority_queue"类模板中与容量相关的成员函数
		5."priority_queue"类模板中与修改器相关的成员函数
		6."priority_queue"类模板相关的非成员函数
*/

/**
	"priority_queue"类模板的介绍："std::priority_queue"类是容器适配器，它提供常数时间的(默认)最大元素查找，对数代价的插入与释出，定义于头文件"queue"中，简称为"priority_queue"。
		1."priority_queue"的定义与特性
			a."priority_queue"是一个类模板，它的定义为：template< class T, class Container = std::vector<T>, class Compare = std::less<typename Container::value_type> > class priority_queue;。
				a'."T"是存储的元素类型。
				b'."Container"是用于存储元素的底层容器类型，它需满足序列容器(线性排列中存储相同类型对象的容器)的要求。
					a''.C++具名要求中序列容器的相关文档：https://zh.cppreference.com/w/cpp/named_req/SequenceContainer。
					b''."Container"必须提供带通常语义的"push_back"、"pop_back"、"front"成员函数，标准容器"vector"和"deque"满足这些要求。
					c''.若不为特定的"priority_queue"类特化指定容器类，则使用标准容器"vector"类。
				c'."Compare"是提供严格弱序的比较(Compare)类型，即比较器，是将两个元素("T"类型)作为参数并返回布尔值的二元谓词。
					a''.C++具名要求中比较的相关文档：https://zh.cppreference.com/w/cpp/named_req/Compare。
					b''.对于严格弱排序的相关文档：https://en.wikipedia.org/wiki/Strict_weak_ordering。
					c''.根据C++具名要求中的比较定义，使得若其第一参数在弱序中先于其第二参数，则返回"true"，否则返回"false"，但因为优先级队列首先输出最大元素，故"先来"的元素实际上最后输出，即队列头含有按照比较所施加弱序的"最后"元素。
					d''."Compare"可以是函数指针或函数对象，默认为"std::less<T>"，它将返回"true"当且仅当第一参数小于第二参数，另一种常用的比较器是"std::greater<T>"，它将返回"true"当且仅当第一参数大于第二参数。
			b.可用用户提供的"Compare"更改顺序，例如：用"std::greater<T>"将导致最小元素作为"top()"出现。
			c.使用"priority_queue"工作，类似于管理某些随机访问容器中的堆，其优势是不可能突然把堆非法化。
		2."priority_queue"的成员类型
			a."container_type"成员类型：定义为"Container"，即底层容器类型。
			b."value_compare"成员类型：定义为"Compare"，即比较器类型。
			c."value_type"成员类型：定义为"Container::value_type"，即底层容器的元素类型。
			d."reference"成员类型：定义为"Container::reference"，即底层容器的引用类型。
			e."const_reference"成员类型：定义为"Container::const_reference"，即底层容器的常引用类型。
			f."size_type"成员类型：定义为"Container::size_type"，即底层容器的大小类型。
		3."priority_queue"的成员对象
			a."c"成员对象：类型为"Container"，即底层容器，是受保护的成员对象。
			b."comp"成员对象：类型为"Compare"，即比较函数对象，是受保护的成员对象。
		4.关于标准算法库中的堆操作相关算法：定义于头文件"algorithm"中。(仅介绍"make_heap"、"push_heap"和"pop_heap"函数模板，以更好的理解"priority_queue"类的工作原理)
			a."make_heap"：从一个元素范围创建出一个最大堆。(函数模板)
				a'.常见函数原型
					a''.template< class RandomIt > void make_heap( RandomIt first, RandomIt last );。(C++20前)
						a'''.参数"first"和"last"是制作堆来源的元素范围，其分别指代元素范围的起始和终止位置。
						b'''.此版本使用"operator<"比较元素。
					b''.template< class RandomIt, class Compare > void make_heap( RandomIt first, RandomIt last, Compare comp );。(C++20前)
						a'''.参数"comp"是比较函数对象，是满足具名要求(比较)的对象。
						b'''.此版本使用给定的比较函数"comp"比较元素。
				b'.在范围"[first, last)"中构造最大堆(大根堆)。
				c'.复杂度：至多"3 * std::distance(first, last)"次比较。
			b."push_heap"：将一个元素加入到一个最大堆。(函数模板)
				a'.常见函数原型
					a''.template< class RandomIt > void push_heap( RandomIt first, RandomIt last );。(C++20前)
						a'''.参数"first"和"last"是定义要修改的堆的元素范围，其分别指代元素范围的起始和终止位置。
						b'''.此版本使用"operator<"比较元素。
					b''.template< class RandomIt, class Compare > void push_heap( RandomIt first, RandomIt last, Compare comp );。(C++20前)
						a'''.参数"comp"是比较函数对象，是满足具名要求(比较)的对象。
						b'''.此版本使用给定的比较函数"comp"比较元素。
				b'.插入位于位置"last - 1"的元素到范围"[first, last - 1)"所定义的最大堆中。
				c'.复杂度：至多"logN"次比较，其中"N"是"std::distance(first, last)"。
			c."pop_heap"：从最大堆中移除最大元素。(函数模板)
				a'.常见函数原型
					a''.template< class RandomIt > void pop_heap( RandomIt first, RandomIt last );。(C++20前)
						a'''.参数"first"和"last"是定义要修改的合法非空堆的元素范围，其分别指代元素范围的起始和终止位置。
						b'''.此版本使用"operator<"比较元素，这使堆成为最大堆。
					b''.template< class RandomIt, class Compare > void pop_heap( RandomIt first, RandomIt last, Compare comp );。(C++20前)
						a'''.参数"comp"是比较函数对象，是满足具名要求(比较)的对象。
						b'''.此版本使用给定的比较函数"comp"比较元素。
				b'.交换在位置"first"的值和在位置"last - 1"的值，并令子范围"[first, last-1)"变为堆，这拥有从范围"[first, last)"所定义的堆移除首个元素的效果。
				c'.复杂度：至多"2 * logN"次比较，其中"N"是"std::distance(first, last)"。
*/

////"priority_queue"类模板的介绍示例：标准算法库中的堆操作相关算法。
//int main()
//{
//	std::vector<int> v{ 3, 1, 4, 1, 5, 9 };//此处的初始化语法暂不需要理解。
//
//	//从一个元素范围创建出一个最大堆，即使用"std::make_heap"函数。
//	std::make_heap(v.begin(), v.end());
//
//	//输出最大堆的内容
//	std::cout << "v: ";
//	for (auto i: v) std::cout << i << ' ';
//	std::cout << '\n';
//
//	v.push_back(6);//将元素添加到容器末尾。
//
//	std::cout << "before push_heap: ";
//	for (auto i: v) std::cout << i << ' ';
//	std::cout << '\n';
//
//	//将一个元素加入到一个最大堆，即使用"std::push_heap"函数。
//	std::push_heap(v.begin(), v.end());//使此范围指代的元素构成一个最大堆。
//
//	std::cout << "after push_heap: ";
//	for (auto i: v) std::cout << i << ' ';
//	std::cout << '\n';
//
//	//将一个元素从一个最大堆中移除，即使用"std::pop_heap"函数。
//	std::pop_heap(v.begin(), v.end());//实际上是移动最大元素到结尾。
//
//	std::cout << "after pop_heap: ";
//	for (auto i: v) std::cout << i << ' ';
//	std::cout << '\n';
//
//	int largest = v.back();//取出最大元素的值。
//	v.pop_back();//实际上此处才是真正意义上的移除元素，并且是移出最大元素。
//	std::cout << "largest element: " << largest << '\n';
//
//	std::cout << "heap without largest: ";
//	for (auto i: v) std::cout << i << ' ';
//	std::cout << '\n';
//
//	return 0;
//}

/**
	"priority_queue"类模板的使用
		1."priority_queue"的常见构造函数的函数原型
			a."explicit priority_queue( const Compare& compare = Compare(), const Container& cont = Container() )"：C++11前的默认构造函数，用"cont"的内容复制构造底层容器"c"，并用"compare"的内容复制构造比较函数对象"comp"。
				a'."compare"参数：用于初始化底层比较函数对象的比较函数对象。
				b'."cont"参数：用作源初始化底层容器的容器。
				c'.在C++11起，此函数的原型为：priority_queue( const Compare& compare, const Container& cont );。
				d'.复杂度为线性级别，其中包括"O(N)"次比较和"O(N)"次"value_type"构造函数的调用，其中"N"是"cont"的大小。
			b."priority_queue() : priority_queue(Compare(), Container()) { }"：C++11起的默认构造函数，容器将进行值初始化，同时它也是一个委托构造函数(视实现而定)。
				a'."priority_queue(Compare(), Container())"：以默认构造的比较函数对象和默认构造的底层容器作为参数，调用对应的构造函数。
				b'.复杂度为常数级别。
			c."template< class InputIt > priority_queue( InputIt first, InputIt last, const Compare& compare = Compare(), const Container& cont = Container() )"：C++11前的范围构造函数，从"cont"复制构造"c"并从"compare"复制构造"comp"，然后将"[first, last)"范围内的元素插入到底层容器"c"中。
				a'.在C++11起，此函数的原型为：template< class InputIt > priority_queue( InputIt first, InputIt last, const Compare& compare, const Container& cont );。
				b'.复杂度："O(N + M)"次比较和"O(N)"次"value_type"构造函数的调用，其中"N"是"cont"的大小，"M"是"[first, last)"范围内的元素个数。
		2."priority_queue"的析构函数的函数原型：~priority_queue();。
			a.销毁"priority_queue"，调用元素的析构函数，然后解分配所用的存储(若元素是指针，则不销毁所指向的对象)。
			b.复杂度与"priority_queue"的大小成线性级别。
		3."priority_queue"中的"operator="成员函数：赋值给容器适配器，即替换容器适配器内容。
			a.常见函数原型：priority_queue& operator=( const priority_queue& other );。
				a'.拷贝赋值运算符，以"other"的内容替换容器适配器的内容，即以"other"的内容副本替换内容，其中"other"是用作源的另一容器适配器。
				b'.等效地调用"c = other.c"与"comp = other.comp"，并且实际上此函数是隐式声明的。
			b.复杂度：等价于底层容器"operator="的复杂度。
*/

////"priority_queue"类模板的使用示例
//int main()
//{
//	std::vector<int> v{ 3, 2, 7, 6, 0, 4, 1, 9, 8, 5 };
//
//	std::priority_queue<int> q1;
//
//	for (auto& e: v)
//	{
//		q1.push(e);
//	}
//
//	std::cout << "q1: ";
//	while (!q1.empty())
//	{
//		std::cout << q1.top() << " ";
//		q1.pop();
//	}
//	std::cout << std::endl;
//
//	std::priority_queue<int, std::vector<int>, std::greater<>> q2(v.begin(), v.end());
//
//	std::cout << "q2: ";
//	while (!q2.empty())
//	{
//		std::cout << q2.top() << " ";
//		q2.pop();
//	}
//	std::cout << std::endl;
//
//	return 0;
//}

/**
	"priority_queue"类模板的元素访问
		1."top"成员函数：访问顶部元素。
			a.函数原型：const_reference top() const;。
			b.返回"priority_queue"中顶元素的引用，此元素将在调用"pop"成员函数时被移除，如同以调用"c.front()"获得。
			c.若使用默认比较函数，则返回的元素亦为优先队列中最大的元素。
			d.复杂度为常数级别。
*/

////"priority_queue"类模板的元素访问示例
//int main()
//{
//	std::vector<int> v{ 3, 2, 7, 6, 0, 4, 1, 9, 8, 5 };
//
//	std::priority_queue<int> q(v.begin(), v.end());
//
//	std::cout << "q: ";
//	while (!q.empty())
//	{
//		std::cout << q.top() << " ";
//		q.pop();
//	}
//	std::cout << std::endl;
//
//	return 0;
//}

/**
	"priority_queue"类模板中与容量相关的成员函数
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

////"priority_queue"类模板中与容量相关的成员函数示例
//int main()
//{
//	std::vector<int> v{ 3, 2, 7, 6, 0, 4, 1, 9, 8, 5 };
//
//	std::priority_queue<int> q(v.begin(), v.end());
//
//	while (!q.empty())
//	{
//		std::cout << q.top() << std::endl;
//		std::cout << "Before pop, size: " << q.size() << std::endl;
//		q.pop();
//		std::cout << "After pop, size: " << q.size() << std::endl << std::endl;
//	}
//	std::cout << std::endl;
//
//	return 0;
//}

/**
	"priority_queue"类模板中与修改器相关的成员函数(暂不介绍C++11起支持的"emplace"成员函数)
		1."push"成员函数：插入元素，并对底层容器排序。
			a.常见函数原型：void push( const value_type& value );。
				a'."value"参数：要推入的元素值。
			b.等效地调用"c.push_back(value)"与"std::push_heap(c.begin(), c.end(), comp)"。
			c.复杂度：对数次比较，并且加上"Container::push_back"的复杂度。
		2."pop"成员函数：删除队首元素，即从"priority_queue"移除顶元素。
			a.函数原型：void pop();。
			b.等效地调用"std::pop_heap(c.begin(), c.end(), comp)"与"c.pop_back()"。
			c.复杂度：对数次比较，并且加上"Container::pop_back"的复杂度。
		3."swap"成员函数：交换内容。(C++11起)
			a.函数原型：void swap( priority_queue& other );。(忽略"noexcept"说明符细节)
			b.交换容器适配器与"other"的内容，等效于调用"using std::swap; swap(c, other.c)"及"swap(comp, other.comp)"。
			c.复杂度：与底层容器相同，通常为常数级别。
*/

////"priority_queue"类模板中与修改器相关的成员函数示例一：使用"push"成员函数和"pop"成员函数。
//int main()
//{
//	std::vector<int> v{ 3, 2, 7, 6, 0, 4, 1, 9, 8, 5 };
//
//	std::priority_queue<int> q1(v.begin(), v.end());
//	std::priority_queue<int> q2(v.begin(), v.end());
//
//	q1.push(10);
//	q2.push(11);
//
//	std::cout << "q1: ";
//	while (!q1.empty())
//	{
//		std::cout << q1.top() << " ";
//		q1.pop();
//	}
//	std::cout << std::endl;
//
//	std::cout << "q2: ";
//	while (!q2.empty())
//	{
//		std::cout << q2.top() << " ";
//		q2.pop();
//	}
//	std::cout << std::endl;
//
//	return 0;
//}

////"priority_queue"类模板中与修改器相关的成员函数示例二：使用"swap"成员函数。
//int main()
//{
//	std::vector<int> v{ 3, 2, 7, 6, 0, 4, 1, 9, 8, 5 };
//
//	std::priority_queue<int> q1(v.begin(), v.begin() + 5);
//	std::priority_queue<int> q2(v.begin() + 5, v.end());
//
//	q1.swap(q2);
//
//	std::cout << "q1: ";
//	while (!q1.empty())
//	{
//		std::cout << q1.top() << " ";
//		q1.pop();
//	}
//	std::cout << std::endl;
//
//	std::cout << "q2: ";
//	while (!q2.empty())
//	{
//		std::cout << q2.top() << " ";
//		q2.pop();
//	}
//	std::cout << std::endl;
//
//	return 0;
//}

/**
	"priority_queue"类模板中的非成员函数
		1."swap"函数：标准算法库中的"swap"函数模板对"priority_queue"类模板的特化，用于交换两个"priority_queue"的内容。(函数模板)(C++11起)
			a.函数原型：常见函数原型：void swap( priority_queue& lhs, priority_queue& rhs );。(C++17前)(省略了模板声明、模板参数、分配器和命名空间等细节)
			b.调用"lhs.swap(rhs)"。
			c.复杂度：与交换底层容器相同。
*/

////"priority_queue"类模板中的非成员函数示例：使用"swap"非成员函数。
//int main()
//{
//	std::vector<int> v{ 3, 2, 7, 6, 0, 4, 1, 9, 8, 5 };
//
//	std::priority_queue<int> q1(v.begin(), v.begin() + 5);
//	std::priority_queue<int> q2(v.begin() + 5, v.end());
//
//	std::swap(q1, q2);
//
//	std::cout << "q1: ";
//	while (!q1.empty())
//	{
//		std::cout << q1.top() << " ";
//		q1.pop();
//	}
//	std::cout << std::endl;
//
//	std::cout << "q2: ";
//	while (!q2.empty())
//	{
//		std::cout << q2.top() << " ";
//		q2.pop();
//	}
//	std::cout << std::endl;
//
//	return 0;
//}