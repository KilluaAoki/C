#include <iostream>
#include <list>
#include <cassert>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>

/*
	顺序容器之双链表
		1."list"类模板的介绍
		2."list"类模板的使用
		3."list"类模板的元素访问
		4."list"类模板中与容量相关的成员函数
		5."list"类模板中与修改器相关的成员函数
		6."list"类模板中与操作相关的成员函数
		7."list"类模板相关的非成员函数
*/

/**
	"list"类模板的介绍："std::list"是支持常数时间从容器任何位置插入和移除元素的容器，定义于头文件"list"中，简称为"list"。
		1."list"的定义与特性
			a."list"是一个类模板，它的定义为：template< class T, class Allocator = std::allocator<T> > class list;。
				a'."T"是元素的类型。
				b'."Allocator"用于获取或释放内存及构造或析构内存中元素的分配器，此阶段暂不考虑此模板形参。
			b."list"是一个顺序容器，不支持快速随机访问，它通常实现为双向链表。
			c.在"list"内或在数个"list"间添加、移除和移动元素不会使迭代器或引用失效，迭代器只有在对应元素被删除时才会失效。
			d."list"是支持常数时间从容器任何位置插入和移除元素的容器。
		2."list"的常见成员类型(省略分配器相关的类型和逆向迭代器相关的类型)
			a."value_type"成员类型：定义为"list"的模板形参"T"。
			b."size_type"成员类型：无符号整数类型，通常定义为"std::size_t"。
			c."difference_type"成员类型：有符号整数类型，通常定义为"std::ptrdiff_t"。
			d."reference"成员类型：定义为"list"的模板形参"T"的左值引用类型，即"value_type&"。
			e."const_reference"成员类型：定义为"list"的模板形参"T"的常量左值引用类型，即"const value_type&"。
			f."iterator"成员类型：定义为指向"value_type"的迭代器类型。
			g."const_iterator"成员类型：定义为指向"const value_type"的迭代器类型。
*/

/**
	"list"类模板的使用
		1."list"的常见构造函数的函数原型(以下部分函数原型忽略命名空间、分号以及分配器等)
			a."explicit list()：默认构造函数，构造拥有默认构造的分配器的空容器，即空的"list"。
				a'.在C++14起，此构造函数被分为两个构造函数：默认构造函数和拥有给定分配器的空容器的构造函数。
					a''.默认构造函数：list()。
					b''.构造拥有给定分配器"alloc"的空容器：explicit list(const Allocator& alloc)。
				b'.复杂度为常数级别。
			b."explicit list( size_type count, const T& value = T())"：构造拥有"count"个有值"value"的元素的容器。(C++11前)
				a'.在C++11起，此函数的原型为：list( size_type count, const T& value)。
				b'.复杂度与"count"成线性级别。
			c."template< class InputIt > list( InputIt first, InputIt last)"：构造拥有范围"[first, last)"内容的容器。
				a'.复杂度与"first"和"last"的距离成线性级别。
			d."list( const list& other )"：复制构造函数，构造拥有"other"内容的容器。
				a'.复杂度与"other"的大小成线性级别。
		2."list"的析构函数的函数原型：~list();。
			a.销毁"list"，调用元素的析构函数，然后解分配所用的存储(若元素是指针，则不销毁所指向的对象)。
			b.复杂度与"list"的大小成线性级别。
		3."list"赋值相关成员函数
			a."operator="成员函数：赋值给容器，即替换容器内容。
				a'.常见函数原型：list& operator=( const list& other )。
					a''.拷贝赋值运算符，以"other"的副本替换内容。
					b''.返回值：*this。
					c''.复杂度与"*this"和"other"的大小成线性级别。
					d''.可能抛出实现定义的异常。
			b."assign"成员函数：将值赋给容器，即替换容器的内容。
				a'.常见函数原型
					a''.void assign( size_type count, const T& value )。
						a'''.以"count"份"value"的副本替换内容。
						b'''.复杂度与"count"成线性级别。
					b''.template< class InputIt > void assign( InputIt first, InputIt last )。
						a'''.以范围"[first, last)"中元素的副本替换内容，若任一参数是指向"*this"中的迭代器则行为未定义。
						b'''.复杂度与"first"和"last"间的距离成线性级别。
				b'.所有指向容器元素的迭代器、指针及引用均被非法化。
*/

////"list"类模板的使用示例一：使用"list"的常见构造函数。
//int main()
//{
//	//默认构造函数，调用函数原型为：list();。(C++14起)
//	std::list<int> v1;//创建一个空的"list"，其元素类型为"int"。
//	assert(v1.empty() && (v1.size() == 0));//断言结果均为真。
//
//	//构造拥有"count"个有值"value"的元素的容器，调用函数原型为：list( size_type count, const T& value);。(C++11起)
//	std::list<int> v2(5, 1);//创建一个拥有"5"个元素的"list"，其元素类型为"int"，且每个元素的值均为"1"。
//	for (auto i: v2)
//	{
//		std::cout << i << " ";
//	}
//	std::cout << std::endl;
//
//	//构造拥有范围"[first, last)"内容的容器，调用函数原型为：template< class InputIt > list( InputIt first, InputIt last);。
//	std::list<int> v3(v2.begin(), v2.end());//创建一个拥有"v2"内容的"list"，其元素类型为"int"。
//	for (auto i: v3)
//	{
//		std::cout << i << " ";
//	}
//	std::cout << std::endl;
//
//	//复制构造函数，调用函数原型为：list( const list& other );。
//	std::list<int> v4(v3);//创建一个拥有"v3"内容的"list"，其元素类型为"int"。
//	for (auto i: v4)
//	{
//		std::cout << i << " ";
//	}
//	std::cout << std::endl;
//
//	return 0;
//}

////"list"类模板的使用示例二：使用"operator="成员函数。
//int main()
//{
//	std::list<int> v1(5, 1);
//	std::list<int> v2(3, 2);
//	std::list<int> v3(2, 3);
//
//	v1 = v2 = v3;//将"v2"的内容赋给"v1"，即替换"v1"的内容。
//	std::cout << v1.size() << std::endl;
//	for (auto i: v1)
//	{
//		std::cout << i << " ";
//	}
//	std::cout << std::endl;
//
//	std::cout << v2.size() << std::endl;
//	for (auto i: v2)
//	{
//		std::cout << i << " ";
//	}
//	std::cout << std::endl;
//
//	std::cout << v3.size() << std::endl;
//	for (auto i: v3)
//	{
//		std::cout << i << " ";
//	}
//	std::cout << std::endl;
//
//	return 0;
//}

////"list"类模板的使用示例三：使用"assign"成员函数。
//int main()
//{
//	std::list<int> v1(5, 1);
//	std::list<int> v2(3, 2);
//
//	v1.assign(3, 4);//将"v1"的内容替换为"3"个元素，且每个元素的值均为"4"，调用函数原型为：void assign( size_type count, const T& value );。
//	std::cout << v1.size() << std::endl;
//	for (auto i: v1)
//	{
//		std::cout << i << " ";
//	}
//	std::cout << std::endl;
//
//	v2.assign(v1.begin(), v1.end());//将"v2"的内容替换为"v1"的内容，调用函数原型为：void assign( InputIt first, InputIt last );。
//	std::cout << v2.size() << std::endl;
//	for (auto i: v2)
//	{
//		std::cout << i << " ";
//	}
//	std::cout << std::endl;
//
//	return 0;
//}

/**
	"list"类模板的元素访问
		1."front"成员函数：访问第一个元素。
			a.函数原型
				a'.reference front();。
				b'.const_reference front() const;。
			b.返回到容器首元素的引用，在空容器上调用此函数是未定义的。
			c.复杂度为常数级别。
			d.对于一个容器"c"，表达式"c.front()"等价于表达式"*c.begin()"。
		2."back"成员函数：访问最后一个元素。
			a.函数原型
				a'.reference back();。
				b'.const_reference back() const;。
			b.返回到容器中最后一个元素的引用，在空容器上调用此函数将导致未定义行为。
			c.复杂度为常数级别。
		3.使用"list"中的迭代器
			a."begin"成员函数：返回指向起始的迭代器。
				a'.函数原型(C++11前)
					a''.iterator begin();。
					b''.const_iterator begin() const;。
				b'.返回指向"list"首元素的迭代器，若"list"为空，则返回的迭代器将等于"end"成员函数的返回值。
				c'.复杂度为常数级别。
			b."end"成员函数：返回指向末尾的迭代器。
				a'.函数原型(C++11前)
					a''.iterator end();。
					b''.const_iterator end() const;。
				b'.返回指向"list"末元素后一元素的迭代器，此元素表现为占位符，试图访问它导致未定义行为。
				c'.复杂度为常数级别。
			c."rbegin"成员函数：返回指向起始的逆向迭代器。
				a'.函数原型(C++11前)
					a''.reverse_iterator rbegin();。
					b''.const_reverse_iterator rbegin() const;。
				c'.返回指向逆向"list"首元素的逆向迭代器，它对应非逆向"list"的末元素，若"list"为空，则返回的迭代器等于"rend"成员函数的返回值。
				d'.复杂度为常数级别。
			d."rend"成员函数：返回指向末尾的逆向迭代器。
				a'.函数原型(C++11前)
					a''.reverse_iterator rend();。
					b''.const_reverse_iterator rend() const;。
				b'.返回指向逆向"list"末元素后一元素的逆向迭代器，它对应非逆向"list"首元素的前一元素，此元素表现为占位符，试图访问它会导致未定义行为。
				c'.复杂度为常数级别。
			e.C++11起支持的"cbegin"成员函数和"cend"成员函数以及"crbegin"成员函数和"crend"成员函数：除成员函数名不相同外，等价分别对应于没有"c"前缀的返回不可变的迭代器的成员函数(如："cbegin"成员函数等价于返回不可变的迭代器的"begin"成员函数)。
*/

////"list"类模板的元素访问示例一：使用"front"成员函数、"back"成员函数。
//int main()
//{
//	std::list<int> v(10, 1);
//	std::cout << "v.front() = " << v.front() << std::endl;
//	std::cout << "v.back() = " << v.back() << std::endl;
//	return 0;
//}

////"list"类模板的元素访问示例二：使用迭代器遍历"list"容器中的元素(正向与逆向)。
//int main()
//{
//	std::list<int> v(10, 1);
//
//	int i = 0;
//	for (auto& e: v)
//	{
//		e = i * 2;
//		++i;
//	}
//
//	//正向遍历
//	for (auto it = v.begin(); it != v.end(); it++)
//	{
//		std::cout << *it << " ";
//	}
//	std::cout << std::endl;
//
//	//逆向遍历
//	for (auto it = v.rbegin(); it != v.rend(); it++)
//	{
//		std::cout << *it << " ";
//	}
//	std::cout << std::endl;
//
//	return 0;
//}

/**
	"list"类模板中与容量相关的成员函数
		1."empty"成员函数：检查容器是否为空。
			a.函数原型(C++11前)：bool empty() const;。
			b.用于检查容器是否无元素，即"begin() == end()"。
			c.返回值为布尔类型，若容器为空时返回"true"，否则返回"false"。
			d.复杂度为常数级别。
		2."size"成员函数：返回容器中容纳的元素的数量。
			a.函数原型(C++11前)：size_type size() const;。
			b.复杂度为常数级别。
		3."max_size"成员函数：返回容器中可容纳的最大元素数。
			a.函数原型(C++11前)：size_type max_size() const;。
			b.返回根据系统或库实现限制的容器可保有的元素最大数量，即返回元素数量的最大值(反映容器大小上的理论极限)。
			c.复杂度为常数级别。
*/

////"list"类模板的容量相关成员函数示例一：使用"empty"成员函数。
//int main()
//{
//	std::list<int> numbers;
//	std::cout << "Initially, numbers.empty(): " << numbers.empty() << '\n';
//
//	numbers.push_back(42);
//	numbers.push_back(13317);
//	std::cout << "After adding elements, numbers.empty(): " << numbers.empty() << '\n';
//
//	return 0;
//}

////"list"类模板的容量相关成员函数示例二：使用"size"成员函数和"max_size"成员函数。
//int main()
//{
//	std::list<int> nums;
//
//	std::cout << "Maximum size of a \"list\" is " << nums.max_size() << "\n";
//
//	for (int i = 0; i < 10; i++)
//	{
//		nums.push_back(i);
//	}
//
//	std::cout << "nums contains " << nums.size() << " elements.\n";
//
//	return 0;
//}

/**
	"list"类模板中与修改器相关的成员函数(暂不介绍C++11起支持的"emplace"、"emplace_back"和"emplace_front"成员函数)
		1."clear"成员函数：清除内容。
			a.函数原型(C++11前)：void clear();。
			b.从容器擦除所有元素，调用此函数后"size"成员函数返回零。
			c.非法化任何指代所含元素的引用、指针或迭代器，包括任何尾后迭代器也都会失效。
			d.复杂度与当前容器的大小，即元素数成线性级别。
		2."insert"成员函数：插入元素，即插入元素到容器中的指定位置
			a.常见函数原型
				a'.iterator insert( const_iterator pos, const T& value );。
					a''.在"pos"前插入一个值为"value"的元素。
					b''.返回指向被插入"value"的迭代器。
					c''.复杂度为常数级别。
				b'.iterator insert( const_iterator pos, size_type count, const T& value );。
					a''.在"pos"前插入"count"个值为"value"的副本。
					b''.返回指向首个被插入元素的迭代器，或者在"count == 0"时返回"pos"。
					c''.复杂度与"count"成线性级别。
				c'.template< class InputIt > iterator insert( const_iterator pos, InputIt first, InputIt last );。
					a''."pos"前插入来自范围"[first, last)"中的元素。
					b''.返回指向首个被插入元素的迭代器，或者在"first == last"时返回"pos"。
					c''.复杂度与"std::distance(first, last)"(从"first"走到"last"所需的自增数)成线性级别。
			b.若此函数抛出异常，则此函数无效果(强异常保证)。
		3."erase"成员函数：擦除元素，即从容器擦除指定的元素。
			a.函数原型(C++11前)
				a'.iterator erase( iterator pos );。
					a''.移除位于"pos"的元素。
					b''.在C++11起，此函数的原型为：iterator erase( const_iterator pos );。
					c''.迭代器"pos"必须合法且可解引用，因此不能以"end"成员函数返回的迭代器(即使合法，但其依旧不可解引用)作为"pos"的值。
					d''.返回值为最后移除元素之后的迭代器，如果"pos"指代末元素，那么返回"end()"迭代器。
					e''.复杂度为常数级别。
				b'.iterator erase( iterator first, iterator last );。
					a''.移除范围"[first, last)"中的元素。
					b''.在C++11起，此函数的原型为：iterator erase( const_iterator first, const_iterator last );。
					c''.如果"first == last"，那么迭代器"first"不需要可解引用：擦除空范围是无操作。
					d''.返回值为最后移除元素之后的迭代器。
						a'''.如果在移除前"last == end()"，那么返回更新的"end"成员函数返回的迭代器。
						b'''.如果范围"[first, last)"为空，那么返回"last"。
					e''.复杂度与"first"和"last"之间的距离成线性级别。
			b.此函数将使指向被擦除元素的迭代器和引用会失效，其他引用和迭代器不受影响。
		4."push_back"成员函数：将元素添加到容器末尾，即后附给定元素到容器尾。
			a.常见函数原型：void push_back( const T& value );。
				a'.初始化新元素为"value"的副本。
			b.没有引用和迭代器会失效。
			c.复杂度为常数级别。
			d.若此函数抛出异常，则此函数无效果(强异常保证)。
		5."pop_back"成员函数：移除末元素，即移除容器的末元素。
			a.函数原型：void pop_back();。(C++20前)
			b.在空容器上调用"pop_back"导致未定义行为。
			c.使指向被擦除元素的迭代器和引用失效。
			d.复杂度为常数级别。
			e.不抛出异常。
		6."push_front"成员函数：插入元素到容器起始，即前附给定元素到容器起始。
			a.函数原型：void push_front( const T& value );。
			b.没有引用和迭代器会失效。
			c.复杂度为常数级别。
			d.若此函数抛出异常，则此函数无效果(强异常保证)。
		7."pop_front"成员函数：移除首元素，即移除容器的首元素。
			a.函数原型：void pop_front();。
			b.若容器中无元素，则行为未定义。
			c.指向被擦除元素的迭代器和引用会失效。
			d.复杂度为常数级别。
			e.不抛出异常。
		8."resize"成员函数：改变容器中可存储元素的个数。
			a.常见函数原型：void resize( size_type count, T value = T() );。(C++11前)
				a'.在C++11起，此函数的原型为：void resize( size_type count, const value_type& value );。
				b'.其中"value"是用以初始化新元素的值，而"count"是容器的大小。
				c'.如果当前大小大于"count"，那么减小容器到它的开头"count"个元素。
				d'.如果当前大小小于"count"，那么后附额外的"value"的副本。
			b.重设容器大小以容纳"count"个元素。
			c.复杂度与当前大小和"count"间的差成线性级别。
 		9."swap"成员函数：交换内容。
			a.函数原型(C++17前)：void swap( list& other );。
			b.将内容与"other"的交换，不在单独的元素上调用任何移动、复制或交换操作。
			c.所有迭代器和引用保持有效，但在操作后，未指明保有此容器中尾后值的迭代器指代此容器还是另一容器。
			d.复杂度为常数级别。
*/

////"list"类模板中与修改器相关的成员函数示例一：使用"clear"成员函数。
//int main()
//{
//	std::list<int> v(10, 100);
//	std::cout << "size of v: " << v.size() << std::endl;
//	v.clear();
//	std::cout << "size of v: " << v.size() << std::endl;
//	return 0;
//}

////"list"类模板中与修改器相关的成员函数示例二：使用"insert"成员函数。
//void print(int id, const std::list<int>& container)
//{
//	std::cout << id << ". ";
//	for (const int x: container)
//	{
//		std::cout << x << ' ';
//
//	}
//	std::cout << '\n';
//}
//
//int main()
//{
//	std::list<int> v1(5, 100);
//	std::list<int> v2(5, 200);
//	std::list<int> v3(5, 300);
//
//	print(1, v1);
//	print(2, v2);
//	print(3, v3);
//
//	//调用函数原型：iterator insert( const_iterator pos, const T& value );。
//	v1.insert(v1.begin(), 50);
//	print(4, v1);
//
//	//调用函数原型：iterator insert( const_iterator pos, size_type count, const T& value );。
//	v2.insert(v2.begin(), 5, 50);
//	print(5, v2);
//
//	//调用函数原型：template< class InputIt > iterator insert( const_iterator pos, InputIt first, InputIt last );。
//	v3.insert(v3.begin(), v2.begin(), v2.end());
//	print(6, v3);
//
//	return 0;
//}

////"list"类模板中与修改器相关的成员函数示例三：使用"erase"成员函数。
//void print_container(const std::list<int>& c)
//{
//	for (int i: c)
//	{
//		std::cout << i << " ";
//	}
//	std::cout << "\n";
//}
//
//int main()
//{
//	std::list<int> c;
//
//	for (int i = 0; i < 10; ++i)
//	{
//		c.push_back(i);
//	}
//	print_container(c);
//
//	//调用函数原型：iterator erase( iterator pos );。
//	c.erase(c.begin());
//	print_container(c);
//
//	//调用函数原型：iterator erase( iterator first, iterator last );。
//	c.erase(c.begin(), c.end());
//	print_container(c);
//
//	return 0;
//}

////"list"类模板中与修改器相关的成员函数示例四：使用"push_back"成员函数、"pop_back"成员函数、"push_front"成员函数、"pop_front"成员函数。
//int main()
//{
//	std::list<std::string> lc;
//
//	lc.push_back("Hello");
//	lc.push_back(" World!");
//	lc.push_front("C++ ");
//	lc.push_front("Programming ");
//
//	for (auto& s: lc)
//	{
//		std::cout << s;
//	}
//	std::cout << '\n';
//
//	lc.pop_back();
//	lc.pop_front();
//
//	for (auto& s: lc)
//	{
//		std::cout << s;
//	}
//
//	return 0;
//}

////"list"类模板中与修改器相关的成员函数示例五：使用"resize"成员函数。
//int main()
//{
//	std::list<int> v(10, 100);
//
//	std::cout << "size of v: " << v.size() << std::endl;
//	for (auto& s: v)
//	{
//		std::cout << s << ' ';
//	}
//	std::cout << '\n';
//
//	v.resize(8, 50);
//	std::cout << "size of v: " << v.size() << std::endl;
//	for (auto& s: v)
//	{
//		std::cout << s << ' ';
//	}
//	std::cout << '\n';
//
//	v.resize(12, 50);
//	std::cout << "size of v: " << v.size() << std::endl;
//	for (auto& s: v)
//	{
//		std::cout << s << ' ';
//	}
//	std::cout << '\n';
//
//	return 0;
//}

////"list"类模板中与修改器相关的成员函数示例六：使用"swap"成员函数。
//int main()
//{
//	std::list<int> v1(5, 0);
//	std::list<int> v2(5, 100);
//
//	for (auto& s: v1)
//	{
//		std::cout << s << ' ';
//	}
//	std::cout << '\n';
//
//	v1.swap(v2);
//
//	for (auto& s: v1)
//	{
//		std::cout << s << ' ';
//	}
//	std::cout << '\n';
//
//	return 0;
//}

/**
	"list"类模板中与操作相关的成员函数
		1."merge"成员函数：合并二个已排序列表(链表)(应以升序排序)，即归并二个已排序链表为一个。
			a.常见函数原型(C++11前)
				a'.void merge( list& other );。
				b'.template <class Compare> void merge( list& other, Compare comp );。
					a''.参数"comp"是比较函数对象(即满足比较(Compare)概念的对象)，即比较器，若第一参数小于(即先序于)第二参数则返回"true"。
					b''.比较函数的签名应等价于：bool cmp(const Type1 &a, const Type2 &b);。
			b.不复制元素，操作后容器"other"变为空。
			c.若"other"与"*this"指代同一对象则函数不做任何事。
			d.没有引用和迭代器变得非法，除了被移动元素的迭代器现在指代到"*this"中，而非到"other"中，当前所列出的函数原型使用"operator<"比较元素。
			e.复杂度：至多为"std::distance(begin(), end()) + std::distance(other.begin(), other.end()) - 1"次比较。
		2."splice"成员函数：从另一个"list"中移动元素，即将元素从一个"list"移动到另一个"list"。
			a.函数原型(C++11前)
				a'.void splice( const_iterator pos, list& other );。
					a''.从"other"转移所有元素到"*this"中。
					b''.元素被插入到"pos"指向的元素之前。
					c''.操作后容器"other"变为空。
					d''."other"与"*this"指代同一对象时行为未定义。
				b'.void splice( const_iterator pos, list& other, const_iterator it );。
					a''.从"other"转移"it"指向的元素到"*this"。
					b''.元素被插入到"pos"指向的元素之前。
				c'.void splice( const_iterator pos, list& other, const_iterator first, const_iterator last);。
					a''.从"other"转移范围"[first, last)"中的元素到"*this"。
					b''.元素被插入到"pos"指向的元素之前。
					c''."pos"是范围"[first, last)"中的迭代器时行为未定义。
			b.不复制或移动元素，仅重指向链表结点的内部指针。
			c.没有迭代器或引用会失效，指向被移动元素的迭代器保持有效，但现在指代到"*this"中，而非到"other"中。
			d.复杂度为常数级别。
		3."remove"成员函数和"remove_if"成员函数：移除所有满足特定标准的元素。
			a.函数原型(C++20前)
				a''.void remove( const T& value );。
					a'''.移除所有等于"value"的元素。
				b''.template <class UnaryPredicate> void remove_if( UnaryPredicate p );。
					a'''.移除所有谓词"p"对它返回"true"的元素，其中"p"是一元谓词(代表应该移除该元素则返回"true"的一元谓词)。
			b.没有迭代器或引用会失效。
			c.复杂度与容器的大小成线性级别。
		4."reverse"成员函数：将该链表的所有元素的顺序反转，即逆转容器中的元素顺序。
			a.函数原型(C++11前)：void reverse();。
			b.不非法化任何引用或迭代器。
			c.复杂度与容器的大小为线性级别。
		5."unique"成员函数：删除连续的重复元素，即从容器移除所有相继的重复元素(去重)。
			a.函数原型(C++20前)
				a''.void unique();。
					a'''.用"operator=="比较元素。
				b''.template <class BinaryPredicate> void unique( BinaryPredicate p );。
					a'''.用二元谓词"p"比较元素，其中"p"是二元谓词(代表两个元素相等则返回"true"的二元谓词)。
					b'''.谓词函数的签名应等价于：bool pred(const Type1 &a, const Type2 &b);。
			b.只留下相等元素组中的第一个元素，若选择的比较器不建立等价关系则行为未定义。
			c.复杂度：若容器非空则准确比较元素"size() - 1"次，否则不进行比较。
		6."sort"成员函数：对元素进行排序，即以升序排序元素，并保持相等元素的顺序。第二版本 。
			a.函数原型
				a''.void sort();。
					a'''.用"operator<"比较元素。
				b''.template <class Compare> void sort( Compare comp );。
					a'''.用给定的比较函数"comp"比较元素，其中"comp"类似于"list"容器中的"merge"成员函数原型其一的"comp"参数。
			b.不非法化任何引用或迭代器。
			c.复杂度：大约"N * logN"次比较，其中"N"是表中的元素数。
			d.若抛出异常，则"*this"中元素顺序未指定。
			e."std::sort"(标准算法库)要求随机访问迭代器且不能用于"list"，此函数它的区别：它不要求"list"的元素类型可交换，保留所有迭代器的值，并进行稳定排序。
*/

////"list"类模板中与操作相关的成员函数示例一：使用"list"类模板中的"merge"成员函数将两个有序链表合并为一个有序链表。
//int main()
//{
//	std::list<int> list1 = { 1, 3, 5, 7, 9 };//此处的初始化语法暂不需要理解。
//	std::list<int> list2 = { 2, 4, 6, 8, 10 };
//
//	list1.merge(list2);
//
//	for (auto i: list1)
//	{
//		std::cout << i << " ";
//	}
//	std::cout << std::endl;
//
//	return 0;
//}

////"list"类模板中与操作相关的成员函数示例二：使用"list"类模板中的"splice"成员函数将一个链表的元素移动到另一个链表中。
//int main()
//{
//	std::list<int> list1 = { 1, 3, 5, 7, 9 };//此处的初始化语法暂不需要理解。
//	std::list<int> list2 = { 2, 4, 6, 8, 10 };
//
//	list1.splice(list1.begin(), list2);
//
//	for (auto i: list1)
//	{
//		std::cout << i << " ";
//	}
//	std::cout << std::endl;
//
//	return 0;
//}

////"list"类模板中与操作相关的成员函数示例三：使用"list"类模板中的"remove"成员函数删除链表中的元素。
//int main()
//{
//	std::list<int> list1 = { 1, 3, 5, 7, 9 };//此处的初始化语法暂不需要理解。
//
//	list1.remove(3);
//
//	for (auto i: list1)
//	{
//		std::cout << i << " ";
//	}
//	std::cout << std::endl;
//
//	return 0;
//}

////"list"类模板中与操作相关的成员函数示例四：使用"list"类模板中的"reverse"成员函数将链表中的元素逆序。
//int main()
//{
//	std::list<int> list1 = { 1, 3, 5, 7, 9 };//此处的初始化语法暂不需要理解。
//
//	list1.reverse();
//
//	for (auto i: list1)
//	{
//		std::cout << i << " ";
//	}
//	std::cout << std::endl;
//
//	return 0;
//}

////"list"类模板中与操作相关的成员函数示例五：使用"list"类模板中的"unique"成员函数删除链表中的重复元素。
//int main()
//{
//	std::list<int> list1 = { 0, 1, 1, 2, 2, 3, 4, 5, 6, 7, 8, 9, 9 };//此处的初始化语法暂不需要理解。
//
//	list1.unique();
//
//	for (auto i: list1)
//	{
//		std::cout << i << " ";
//	}
//	std::cout << std::endl;
//
//	return 0;
//}

////"list"类模板中与操作相关的成员函数示例六：使用"list"类模板中的"sort"成员函数将链表中的元素排序。
//int main()
//{
//	std::list<int> list1 = { 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 };//此处的初始化语法暂不需要理解。
//
//	list1.sort();
//
//	for (auto i: list1)
//	{
//		std::cout << i << " ";
//	}
//	std::cout << std::endl;
//
//	return 0;
//}

////"list"类模板中与操作相关的成员函数示例七：测试"list"类模板中的"sort"成员函数的效率。
//int main()
//{
//	const int N = 10000000;
//	std::srand((unsigned)std::time(nullptr));
//
//	std::list<int> list;
//	for (int i = 0; i < N; i++)
//	{
//		list.push_back(std::rand());
//	}
//
//	std::vector<int> vector;
//	vector.reserve(N);
//	for (int i = 0; i < N; i++)
//	{
//		vector.push_back(std::rand());
//	}
//
//	//测试"list"类模板使用"sort"成员函数排序的效率
//	clock_t start = clock();
//	list.sort();
//	clock_t end = clock();
//	std::cout << "The list sort time is: " << (double)(end - start) / CLOCKS_PER_SEC << "s" << std::endl;
//
//	//测试"vector"类模板使用标准算法库中的"sort"算法排序的效率
//	start = clock();
//	std::sort(vector.begin(), vector.end());//标准算法库中的"sort"排序算法，使用需引用头文件"algorithm"。
//	end = clock();
//	std::cout << "The vector sort time is: " << (double)(end - start) / CLOCKS_PER_SEC << "s" << std::endl;
//
//	//将"list"类模板中的元素复制到"vector"类模板中
//	vector.clear();
//	vector.reserve(N);
//	for (auto i: list)
//	{
//		vector.push_back(i);
//	}
//
//	//测试对"vector"类模板使用标准算法库中的"sort"算法排序效率
//	start = clock();
//	std::sort(vector.begin(), vector.end());
//	end = clock();
//	std::cout << "The vector sort time is: " << (double)(end - start) / CLOCKS_PER_SEC << "s" << std::endl;
//
//	return 0;
//}

/**
	"list"类模板相关的非成员函数
		1.按照字典顺序比较"list"中的值(函数模板)。
			a.将各个用于比较的运算符进行重载，以便于比较二个"list"的内容。
			b.常见函数原型(省略了模板声明、模板参数、分配器和命名空间等细节)
				a''.bool operator==( const list &lhs, const list &rhs );。
					a'''.若"list"内容相等则为"true"，否则为"false"。
				b''.bool operator!=( const list &lhs, const list &rhs );。(C++20前)
					a'''.若"list"内容不相等则为"true"，否则为"false"。
				c''.bool operator<( const list &lhs, const list &rhs );。(C++20前)
					a'''.若"lhs"的内容按字典序小于"rhs"的内容则为"true"，否则为"false"。
				d''.bool operator>( const list &lhs, const list &rhs );。(C++20前)
					a'''.若"lhs"的内容按字典序大于"rhs"的内容则为"true"，否则为"false"。
				e''.bool operator<=( const list &lhs, const list &rhs );。(C++20前)
					a'''.若"lhs"的内容按字典序小于或等于"rhs"的内容则为"true"，否则为"false"。
				f''.bool operator>=( const list &lhs, const list &rhs );。(C++20前)
					a'''.若"lhs"的内容按字典序大于或等于"rhs"的内容则为"true"，否则为"false"。
			c.运算符"=="以及"!="意为检查"lhs"与"rhs"的内容是否相等，即它们是否拥有相同数量的元素且"lhs"中每个元素与"rhs"的同位置元素比较相等。
				a'.这些运算符的复杂度为：若"lhs"与"rhs"的大小不同则为常数，否则与"list"大小成线性级别。
			d.运算符"<"、"<="、">"以及">="意为按字典序比较"lhs"与"rhs"的内容。
				a'.这些运算符的复杂度与"list"的大小成线性级别。
		2."swap"函数：标准算法库中的"swap"函数模板对"list"类模板的特化，用于交换两个"list"的内容。(函数模板)
			a.常见函数原型：void swap( list& lhs, list& rhs );。(C++17前)(省略了模板声明、模板参数、分配器和命名空间等细节)
			b.等价于调用"lhs.swap(rhs)"。
			c.复杂度为常数级别。
*/

////"list"类模板相关的非成员函数示例一：使用比较运算符比较"list"中的值。
//int main()
//{
//	std::list<int> alice(3, 1);
//	std::list<int> bob(4, 2);
//	std::list<int> eve(3, 1);
//
//	//比较不相等的容器
//	std::cout << "alice == bob returns " << (alice == bob) << '\n';
//	std::cout << "alice != bob returns " << (alice != bob) << '\n';
//	std::cout << "alice <  bob returns " << (alice < bob) << '\n';
//	std::cout << "alice <= bob returns " << (alice <= bob) << '\n';
//	std::cout << "alice >  bob returns " << (alice > bob) << '\n';
//	std::cout << "alice >= bob returns " << (alice >= bob) << '\n';
//	std::cout << '\n';
//
//	//比较相等的容器
//	std::cout << "alice == eve returns " << (alice == eve) << '\n';
//	std::cout << "alice != eve returns " << (alice != eve) << '\n';
//	std::cout << "alice <  eve returns " << (alice < eve) << '\n';
//	std::cout << "alice <= eve returns " << (alice <= eve) << '\n';
//	std::cout << "alice >  eve returns " << (alice > eve) << '\n';
//	std::cout << "alice >= eve returns " << (alice >= eve) << '\n';
//	std::cout << '\n';
//
//	return 0;
//}

////"list"类模板相关的非成员函数示例二：使用"swap"非成员函数。
//int main()
//{
//	std::list<int> v1(5, 0);
//	std::list<int> v2(5, 100);
//
//	for (auto& s: v1)
//	{
//		std::cout << s << ' ';
//	}
//	std::cout << '\n';
//
//	std::swap(v1, v2);
//
//	for (auto& s: v1)
//	{
//		std::cout << s << ' ';
//	}
//	std::cout << '\n';
//
//	return 0;
//}