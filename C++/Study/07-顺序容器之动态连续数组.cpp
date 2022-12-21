#include <iostream>
#include <vector>
#include <cassert>

/*
	顺序容器之动态连续数组
		1.容器库介绍
		2.迭代器失效
		3."vector"类模板的介绍
		4."vector"类模板的使用
		5."vector"类模板的元素访问
		6."vector"类模板中与容量相关的成员函数
		7."vector"类模板中与修改器相关的成员函数
		8."vector"类模板相关的非成员函数
*/

/**
	容器库介绍
		1.容器库是类模板与算法的汇集，允许程序员简单地访问常见数据结构，例如队列、链表和栈等。
			a.容器管理为其元素分配的存储空间，并提供成员函数来直接或通过迭代器(具有类似于指针的属性的对象)访问它们。
			b.许多容器有几个共同的成员函数，并且共享功能。
			c.决定使用哪种类型的容器来满足特定需求通常不仅仅取决于容器提供的功能，还取决于其某些成员的效率(复杂性)。
		2.不同标准下的容器类别
			a.C++11前，仅有两类容器，即顺序容器和关联容器。
				a'.顺序容器：实现能按顺序访问的数据结构。
					a''."array"类模板：静态的连续数组。(C++11)
					b''."vector"类模板：动态的连续数组。
					c''."deque"类模板：双端队列。
					d''."forward_list"类模板：单链表。(C++11)
					e''."list"类模板：双链表。
				b'.关联容器：实现能快速查找("O(logN)"复杂度)的数据结构。
					a''."set"类模板：唯一键的集合，按照键排序。
					b''."multiset"类模板：键值对的集合，按照键排序，键是唯一的。
					c''."map"类模板：键的集合，按照键排序。
					d''."multimap"类模板：键值对的集合，按照键排序。
			b.C++11起，新增了无序关联容器，它提供能快速查找(均摊复杂度为常数级别，最坏复杂度为线性级别)的无序(哈希)数据结构。
				a'."unordered_set"类模板：唯一键的集合，按照键生成散列。(C++11)
				b'."unordered_map"类模板：键值对的集合，按照键生成散列，键是唯一的。(C++11)
				c'."unordered_multiset"类模板：键的集合，按照键生成散列。(C++11)
				d'."unordered_multimap"类模板：键值对的集合，按照键生成散列。(C++11)
		3.容器适配器
			a.容器适配器不是完整的容器，是提供特定接口的类，并依赖于其中一个容器类(如双端队列或列表)的对象来处理元素。
			b.底层容器以这样一种方式封装，即容器适配器的成员独立于所使用的底层容器类来访问其元素。
			c.容器适配器中的三大类模板
				a'."stack"类模板：适配一个容器以提供栈，栈是一种后进先出的数据结构("LIFO")。
				b'."queue"类模板：适配一个容器以提供队列，队列是一种先进先出的数据结构("FIFO")。
				c'."priority_queue"类模板：适配一个容器以提供优先级队列。
*/

/**
	迭代器失效：当迭代器指向的容器在内部执行某些操作时，导致迭代器没有正确表示它正在迭代的对象的状态，这就被称为迭代器失效。
		1.迭代器是一种广义化的指针，它使得C++程序可以通过统一的方式处理不同的数据结构。
		2.迭代器失效类似于指针失效，意味着迭代器指向旧的无效位置。
		3.不同容器的迭代器失效的情况与规则不同，需要根据具体的容器来分析。
		4.容器中的只读方法决不会使迭代器或引用失效。
*/

/**
	"vector"类模板的介绍："std::vector"是封装动态数组的顺序容器，定义于头文件"vector"中，简称为"vector"。
		1."vector"的定义与特性
			a."vector"是一个类模板，它的定义为：template <class T, class Allocator = std::allocator<T> > class vector;。
				a'."T"是元素的类型。
				b'."Allocator"用于获取或释放内存及构造或析构内存中元素的分配器，此阶段暂不考虑此模板形参。
			b."vector"是一个顺序容器，其连续存储元素，这意味着不仅可通过迭代器，还能用指向元素的常规指针访问元素。
			c.指向"vector"元素的指针能传递给任何期待指向数组元素的指针的函数。
			d."vector"的存储是自动管理的，按需扩张收缩，并且"vector"通常占用多于静态数组(静态数组对应的是动态数组)的空间，因为要分配更多内存以管理将来的增长。
				a'."vector"可不需要在每次插入元素时重新分配空间，而只在额外内存耗尽时重分配，而分配的内存总量可用对应的成员函数查询("capacity"成员函数)。
				b'.在C++11起，还可以通过调用对应的成员函数将多出的内存返回给系统("shrink_to_fit"成员函数)。
				c'.重分配内存通常上是对于性能上有开销的操作，与"string"类类似，"vector"也提供了对应的成员函数("reserve"成员函数)用于预先分配内存，以避免重分配。
			e."vector"常见操作的时间复杂度(效率)
				a'.随机访问：常数级别时间复杂度，即"O(1)"。
				b'.在末尾插入或移除元素：均摊常数级别时间复杂度，即"O(1)"。
				c'.插入或移除元素：与到"vector"结尾的距离成线性级别复杂度，即"O(n)"。
			f.标准库提供"std::vector"对类型"bool"为空间提效(可能)的特化，即"std::vector<bool>"，此阶段暂不考虑。
			g.对于"vector"容器的迭代器失效问题(不讨论引用)
				a'.所有的只读操作都决不会使迭代器失效。
				b'.使用标准算法库中的"swap"函数模板对"vector"类模板的特化以及"vector"中的"swap"成员函数，将使"end"成员函数返回的迭代器失效。
				c'.使用"clear"成员函数、"operator="成员函数、"assign"成员函数，将始终使所有迭代器失效。
				d'.使用"reserve"成员函数、"shrink_to_fit"成员函数(C++11)，导致"vector"更改容量时，将使所有迭代器失效，否则不失效。
				e'.使用"erase"成员函数，将使指向被擦除元素及之后的所有元素的迭代器失效(包括"end"成员函数返回的迭代器)。
				f'.使用"push_back"成员函数、"emplace_back"成员函数(C++11)，导致"vector"更改容量时，将使所有迭代器失效，否则只有"end"成员函数返回的迭代器失效。
				g'.使用"insert"成员函数、"emplace"成员函数(C++11)，导致"vector"更改容量时，将使所有迭代器失效，否则只有指向插入位置或插入位置之后的所有元素的迭代器失效(包括"end"成员函数返回的迭代器)。
				h'.使用"resize"成员函数，导致"vector"更改容量时，将使所有迭代器失效，否则只有"end"成员函数返回的迭代器以及指向被擦除的所有元素的迭代器失效。
				i'.使用"pop_back"成员函数，将使"end"成员函数返回的迭代器以及指向被擦除的所有元素的迭代器失效。
		2."vector"的常见成员类型(省略分配器相关的类型和逆向迭代器相关的类型)
			a."value_type"成员类型：定义为"vector"的模板形参"T"，表示"vector"中元素的类型。
			b."size_type"成员类型：无符号整数类型，通常定义为"std::size_t"，意义类似于"string"类模板中的"size_type"成员类型。
			c."difference_type"成员类型：有符号整数类型，通常定义为"std::ptrdiff_t"(表示二个指针相减结果的有符号整数类型)，表示两个迭代器之间的距离。
			d."reference"成员类型：定义为"vector"的模板形参"T"的左值引用类型，即"value_type&"，表示"vector"中元素的左值引用类型。
			e."const_reference"成员类型：定义为"vector"的模板形参"T"的左值常引用类型，即"const value_type&"，表示"vector"中元素的左值常引用类型。
			f."iterator"成员类型：根据实现定义，表示"vector"中元素的可变的迭代器类型。
			g."const_iterator"成员类型：根据实现定义，表示"vector"中元素的不可变的迭代器类型。
*/

/**
	"vector"类模板的使用
		1."vector"的常见构造函数的函数原型(以下函数原型忽略命名空间、分号以及分配器等)
			a."vector()"：默认构造函数，构造拥有默认构造的分配器的空容器，即空的"vector"。(C++17前)
				a'.复杂度为常数级别。
			b."explicit vector( size_type count, const T& value = T())"：构造拥有"count"个有值"value"的元素的容器。(C++11前)
				a'."count"参数表示容器的大小，而"value"参数表示以之初始化容器元素的值。
				b'.在C++11起直至C++20前，此函数的原型为：vector( size_type count, const T& value)。
				c'.在C++11前，"value"的默认值是通过调用"T"指代的类型的默认构造函数得到的，但是在C++11起，"value"无默认缺省值。
				d'.复杂度与"count"成线性级别。
			c."template< class InputIt > vector( InputIt first, InputIt last)"：构造拥有范围"[first, last)"内容的容器。(C++20前)
				a'.模板形参"InputIt"表示输入的迭代器类型，即表示范围"[first, last)"的迭代器类型，故"first"和"last"表示复制元素的来源范围。
				b'.复杂度：以给定"first"和"last"的距离为"N"，而后根据不同的情况而定。(了解)
					a''.如果"first"和"last"都是前向、双向或随机访问迭代器，那么只会调用"N"次"T"的复制构造函数，并且不会进行重分配。
					b''.否则，如果"first"和"last"都只是输入迭代器，那么会调用"O(N)"次"T"的复制构造函数，并且会进行"O(logN)"次重分配。
			d."vector( const vector& other )"：复制构造函数，构造拥有"other"内容的容器。(C++20前)
				a'."other"参数表示用作初始化容器元素来源的另一容器。
				b'.复杂度与"other"的大小成线性级别。
		2."vector"的析构函数的函数原型：~vector();。(C++20前)
			a.销毁"vector"，调用元素的析构函数，然后解分配所用的存储(若元素是指针，则不销毁所指向的对象)。
			b.复杂度与"vector"的大小成线性级别。
		3."vector"赋值相关成员函数
			a."operator="成员函数：赋值给容器，即替换容器内容。
				a'.常见函数原型：vector& operator=( const vector& other );。(C++20前)
					a''.拷贝赋值运算符，以"other"的副本替换内容。
					b''.返回值：*this。
					c''.复杂度与"*this"和"other"的大小成线性级别。
					d''.可能抛出实现定义的异常。
			b."assign"成员函数：将值赋给容器，即替换容器的内容。
				a'.常见函数原型
					a''.void assign( size_type count, const T& value );。(C++20前)
						a'''.以"count"份"value"的副本替换内容。
						b'''.复杂度与"count"成线性级别。
					b''.template< class InputIt > void assign( InputIt first, InputIt last );。(C++20前)
						a'''.以范围"[first, last)"中元素的副本替换内容，若任一参数是指向"*this"中的迭代器则行为未定义。
						b'''.复杂度：与"first"和"last"间的距离成线性级别。
				b'.所有指向容器元素的迭代器、指针及引用均被非法化，尾后迭代器亦被非法化。
*/

////"vector"类模板的使用示例一：使用"vector"的常见构造函数。
//int main()
//{
//	//默认构造函数，调用函数原型为：vector();。(C++17前)
//	std::vector<int> v1;//创建一个空的"vector"，其元素类型为"int"。
//	assert(v1.empty() && (v1.size() == 0));//断言结果均为真。
//	std::cout << std::endl;
//
//	//构造拥有"count"个有值"value"的元素的容器，调用函数原型为：vector( size_type count, const T& value );。(C++11前)
//	std::vector<int> v2(5, 1);//创建一个"vector"，其元素类型为"int"，且拥有"5"个元素，每个元素的值都为"1"。
//	std::cout << v2.size() << std::endl;
//	for (auto i: v2)
//	{
//		std::cout << i << " ";
//	}
//	std::cout << std::endl;
//
//	//构造拥有范围"[first, last)"内容的容器，调用函数原型为：vector( InputIt first, InputIt last );。(C++20前)
//	std::vector<int> v3(v2.begin(), v2.end());//创建一个"vector"，其元素类型为"int"，且拥有"v2"的内容。
//	std::cout << v3.size() << std::endl;
//	for (auto i: v3)
//	{
//		std::cout << i << " ";
//	}
//	std::cout << std::endl;
//
//	//复制构造函数，调用函数原型为：vector( const vector& other );。(C++20前)
//	std::vector<int> v4(v3);//创建一个"vector"，其元素类型为"int"，且拥有"v3"的内容。
//	std::cout << v4.size() << std::endl;
//	for (auto i: v4)
//	{
//		std::cout << i << " ";
//	}
//	std::cout << std::endl;
//
//	return 0;
//}

////"vector"类模板的使用示例二：使用"operator="成员函数。
//int main()
//{
//	std::vector<int> v1(5, 1);
//	std::vector<int> v2(10, 2);
//	std::vector<int> v3(15, 3);
//
//	//使用"operator="成员函数，调用函数原型为：vector& operator=( const vector& other );。(C++20前)
//	v1 = v2 = v3;//将"v3"的内容赋给"v2"，再将"v2"的内容赋给"v1"。
//
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
//	//迭代器失效示例
//	std::vector<int> v4(10, 6);
//	std::vector<int>::iterator it = v4.begin();
//	v4 = v4;//将"v4"的内容赋给"v4"，迭代器"it"失效。
//	//std::cout << *it << std::endl;//此时的迭代器"it"失效，其可能指向无效内存，此处为未定义行为。
//	it = v4.begin();//使"it"重新指向"v4"的首元素。
//	std::cout << *it << std::endl;
//
//	return 0;
//}

////"vector"类模板的使用示例三：使用"assign"成员函数。
//int main()
//{
//	std::vector<char> characters;
//	for (auto i: characters)
//	{
//		std::cout << i << " ";
//	}
//	std::cout << std::endl;
//
//	//以"count"份"value"的副本替换内容，调用函数原型为：void assign( size_type count, const T& value );。(C++20前)
//	characters.assign(5, 'a');//将"characters"的内容替换为"5"个元素，每个元素的值都为"'a'"。
//	for (auto i: characters)
//	{
//		std::cout << i << " ";
//	}
//	std::cout << std::endl;
//
//	//以范围"[first, last)"中元素的副本替换内容，调用函数原型为：template< class InputIt > void assign( InputIt first, InputIt last );。(C++20前)
//	std::vector<char> tmp(5, 'b');
//	characters.assign(tmp.begin(), tmp.end());//将"characters"的内容替换为"tmp"的内容。
//	for (auto i: characters)
//	{
//		std::cout << i << " ";
//	}
//	std::cout << std::endl;
//
//	//迭代器失效示例
//	std::vector<char> characters2(5, 'c');
//	std::vector<char>::iterator it = characters2.begin();
//	characters2.assign(tmp.begin(), tmp.end());//将"characters2"的内容替换为对应范围的"tmp"的内容，迭代器"it"失效。
//	//std::cout << *it << std::endl;//此时的迭代器"it"失效，其可能指向无效内存，此处为未定义行为。
//	it = characters2.begin();//使"it"重新指向"characters2"的首元素。
//	std::cout << *it << std::endl;
//
//	return 0;
//}

/**
	"vector"类模板的元素访问
		1."[]"下标成员访问运算符：访问指定的元素。
			a.函数原型(C++20前)
				a'.reference operator[]( size_type pos );。
				b'.const_reference operator[]( size_type pos ) const;。
			b.参数"pos"表示要返回的元素的位置。
			c.返回值为到所需元素的引用，即返回位于指定位置"pos"的元素的引用，不进行边界检查。
			d.此运算符决不插入新元素到容器，并且通过此运算符访问不存在的元素是未定义行为。
			e.复杂度为常数级别。
		2."at"成员函数：访问指定的元素，同时进行越界检查。
			a.函数原型(C++20前)
				a'.reference at( size_type pos );。
				b'.const_reference at( size_type pos ) const;。
			b.返回位于指定位置"pos"的元素的引用，有边界检查。
			c.复杂度为常数级别。
			d.若"pos"不在容器范围内，即若"!(pos < size())"为真，则抛出异常。
		3."front"成员函数：访问第一个元素。
			a.函数原型(C++20前)
				a'.reference front();。
				b'.const_reference front() const;。
			b.返回到容器首元素的引用，在空容器上调用此函数是未定义的。
			c.复杂度为常数级别。
			d.对于一个容器"c"，表达式"c.front()"等价于表达式"*c.begin()"。
		4."back"成员函数：访问最后一个元素。
			a.函数原型(C++20前)
				a'.reference back();。
				b'.const_reference back() const;。
			b.返回到容器中最后一个元素的引用，在空容器上调用此函数将导致未定义行为。
			c.复杂度为常数级别。
		5."data"成员函数：返回指向容器中第一个元素的指针。
			a.函数原型(C++11前)
				a'.T* data();。
				b'.const T* data() const;。
			b.返回指向作为元素存储工作的底层数组的指针，指针满足范围"[data(), data() + size())"，其始终是合法范围，即使容器为空(该情况下此函数的返回值不可解引用)。
			c.返回值为指向底层元素存储的指针，对于非空容器，返回的指针与首元素地址比较相等。
			c.复杂度为常数级别。
			d.若"size()为"0"，则此函数可能或可能不返回空指针。
		6.使用"vector"中的迭代器
			a."begin"成员函数：返回指向起始的迭代器。
				a'.函数原型(C++11前)
					a''.iterator begin();。
					b''.const_iterator begin() const;。
				b'.返回指向"vector"首元素的迭代器，若"vector"为空，则返回的迭代器将等于"end"成员函数的返回值。
				c'.复杂度为常数级别。
			b."end"成员函数：返回指向末尾的迭代器。
				a'.函数原型(C++11前)
					a''.iterator end();。
					b''.const_iterator end() const;。
				b'.返回指向"vector"末元素后一元素的迭代器，此元素表现为占位符，试图访问它导致未定义行为。
				c'.复杂度为常数级别。
			c."rbegin"成员函数：返回指向起始的逆向迭代器。
				a'.函数原型(C++11前)
					a''.reverse_iterator rbegin();。
					b''.const_reverse_iterator rbegin() const;。
				c'.返回指向逆向"vector"首元素的逆向迭代器，它对应非逆向"vector"的末元素，若"vector"为空，则返回的迭代器等于"rend"成员函数的返回值。
				d'.复杂度为常数级别。
			d."rend"成员函数：返回指向末尾的逆向迭代器。
				a'.函数原型(C++11前)
					a''.reverse_iterator rend();。
					b''.const_reverse_iterator rend() const;。
				b'.返回指向逆向"vector"末元素后一元素的逆向迭代器，它对应非逆向"vector"首元素的前一元素，此元素表现为占位符，试图访问它会导致未定义行为。
				c'.复杂度为常数级别。
			e.C++11起支持的"cbegin"成员函数和"cend"成员函数以及"crbegin"成员函数和"crend"成员函数：除成员函数名不相同外，等价分别对应于没有"c"前缀的返回不可变的迭代器的成员函数(如："cbegin"成员函数等价于返回不可变的迭代器的"begin"成员函数)。
*/

////"vector"类模板的元素访问示例一：使用"[]"下标成员访问运算符。
//int main()
//{
//	std::vector<int> v1(10, 1);
//
//	for (auto i = 0; i < v1.size(); ++i)
//	{
//		v1[i] = i * 2;
//	}
//
//	for (auto i: v1)
//	{
//		std::cout << i << " ";
//	}
//	std::cout << std::endl;
//
//	return 0;
//}

////"vector"类模板的元素访问示例二：使用"at"成员函数。
//int main()
//{
//	std::vector<int> data(6, 0);
//
//	data.at(1) = 88;
//
//	std::cout << "Element at index 2 has value " << data.at(2) << '\n';
//
//	std::cout << "data size = " << data.size() << '\n';
//
//	//抛出异常示例
//	try
//	{
//		std::cout << "!(6 < data.size()) == " << (!(6 < data.size())) << std::endl;//"!(6 < data.size())"为真，即"6"不在容器范围内。
//		data.at(6) = 666;//"!(pos < size())"为真，抛出异常。
//	}
//	catch (std::out_of_range const& exc)
//	{
//		std::cout << exc.what() << '\n';//输出异常信息。
//	}
//
//	std::cout << "data:";
//	for (auto elem: data)
//	{
//		std::cout << " " << elem;
//	}
//	std::cout << std::endl;
//
//	return 0;
//}

////"vector"类模板的元素访问示例三：使用"front"成员函数、"back"成员函数和"data"成员函数。
//int main()
//{
//	std::vector<int> v1(10, 1);
//
//	for (auto i = 0; i < v1.size(); ++i)
//	{
//		v1[i] = i * 2;
//	}
//
//	for (auto i: v1)
//	{
//		std::cout << i << " ";
//	}
//	std::cout << std::endl;
//
//	std::cout << "v1.front() = " << v1.front() << std::endl;
//	std::cout << "v1.back() = " << v1.back() << std::endl;
//	std::cout << "v1.data() = " << v1.data() << std::endl;
//	std::cout << "*(v1.data()) = " << *(v1.data()) << std::endl;
//
//	return 0;
//}

////"vector"类模板的元素访问示例四：使用迭代器遍历"vector"容器中的元素(正向与逆向)。
//int main()
//{
//	std::vector<int> v(10, 1);
//
//	for (auto i = 0; i < v.size(); ++i)
//	{
//		v[i] = i * 2;
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
	"vector"类模板中与容量相关的成员函数
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
		4."reserve"成员函数：预留存储空间(请求更改容量)。
			a.函数原型(C++20前)：void reserve( size_type new_cap );。
			b.增加"vector"的容量到大于或等于"new_cap"的值，其中"new_cap"是"vector"的新容量。
				a'.若"new_cap"大于当前"capacity"成员函数的返回值，则分配新存储，否则该方法不做任何事。
				b'.此函数不会改变"vector"的大小，即"size"成员函数的返回值不会改变。
				c'.如果"new_cap"大于当前"capacity"成员函数的返回值，那么所有迭代器，包含尾后迭代器和所有到元素的引用都会失效，否则，没有迭代器或引用会失效。
			c.若"new_cap"大于当前"max_size"成员函数的返回值，则抛出异常。
			d.若抛出异常，那么此函数无效果(强异常保证)。
			e.复杂度至多与当前容器的元素数量("size"函数返回值)成线性级别。
			f.不能用此函数减少容器容量，为该目的提供的对应成员函数是"shrink_to_fit"。
		5."capacity"成员函数：返回当前存储空间能够容纳的元素数。
			a.函数原型(C++11前)：size_type capacity() const;。
			b.返回容器当前已为之分配空间的元素数，即返回当前分配存储的容量。
			c.复杂度为常数级别。
		6."shrink_to_fit"成员函数：通过释放未使用的内存减少内存的使用，即请求移除未使用的容量。(C++11)
			a.函数原型(C++20前)：void shrink_to_fit();。
			b.这是减少容量("capacity")到大小("size")的非强制请求，是否满足请求取决并依赖于实现。
			c.如果发生重分配，那么所有迭代器，包含尾后迭代器，和所有到元素的引用都会失效，如果没有发生重分配，那么没有迭代器或引用会失效。
			d.复杂度至多与容器大小成线性级别。
*/

////"vector"类模板中与容量相关的成员函数示例一：使用"empty"成员函数。
//int main()
//{
//	std::vector<int> numbers;
//	std::cout << "Initially, numbers.empty(): " << numbers.empty() << '\n';
//
//	numbers.push_back(6);
//	std::cout << "After adding elements, numbers.empty(): " << numbers.empty() << '\n';
//
//	return 0;
//}

////"vector"类模板中与容量相关的成员函数示例二：使用"size"成员函数和"max_size"成员函数。
//int main()
//{
//	std::vector<int> nums;
//
//	std::cout << "nums.max_size(): " << nums.max_size() << '\n';
//
//	std::cout << "Initially, nums.size(): " << nums.size() << '\n';
//
//	nums.push_back(6);
//
//	std::cout << "After adding elements, nums.size(): " << nums.size() << '\n';
//
//	return 0;
//}

////"vector"类模板中与容量相关的成员函数示例三：使用"reserve"成员函数和"capacity"成员函数。
//int main()
//{
//	std::vector<int> nums;
//
//	std::cout << "nums.size() = " << nums.size() << "\n";
//	std::cout << "nums.capacity() = " << nums.capacity() << "\n\n";
//
//	nums.reserve(100);
//	std::cout << "s.reserve(100)" << "\n";
//	std::cout << "s.size() = " << nums.size() << "\n";
//	std::cout << "s.capacity() = " << nums.capacity() << "\n\n";
//
//	nums.reserve(10);
//	std::cout << "s.reserve(10)" << "\n";
//	std::cout << "s.size() = " << nums.size() << "\n";
//	std::cout << "s.capacity() = " << nums.capacity() << "\n\n";
//
//	nums.reserve(1000);
//	std::cout << "s.reserve(1000)" << "\n";
//	std::cout << "s.size() = " << nums.size() << "\n";
//	std::cout << "s.capacity() = " << nums.capacity() << "\n\n";
//
//	return 0;
//}

////"vector"类模板中与容量相关的成员函数示例四：测试容量的增长策略。
//int main()
//{
//	std::vector<int> nums;
//	size_t capacity = nums.capacity();
//	std::cout << "making nums grow:\n";
//	for (int i = 0; i < 2000; ++i)
//	{
//		nums.push_back(i);
//		if (capacity != nums.capacity())
//		{
//			capacity = nums.capacity();
//			std::cout << "\tcapacity changed: " << capacity << '\n';
//		}
//	}
//	return 0;
//}

////"vector"类模板中与容量相关的成员函数示例五：利用"reserve"成员函数提高插入数据的效率，避免增容带来的开销。
//int main()
//{
//	std::vector<int> nums;
//	nums.reserve(1000);
//	size_t capacity = nums.capacity();
//	std::cout << "making nums grow:\n";
//	for (int i = 0; i < 2000; ++i)
//	{
//		nums.push_back(i);
//		if (capacity != nums.capacity())
//		{
//			capacity = nums.capacity();
//			std::cout << "\tcapacity changed: " << capacity << '\n';
//		}
//	}
//	return 0;
//}

////"vector"类模板中与容量相关的成员函数示例六：使用"shrink_to_fit"成员函数。
//int main()
//{
//	std::vector<int> nums;
//	nums.reserve(1000);
//	std::cout << "s.capacity() = " << nums.capacity() << "\n";
//	nums.shrink_to_fit();
//	std::cout << "s.shrink_to_fit()\n";
//	std::cout << "s.capacity() = " << nums.capacity() << "\n";
//	return 0;
//}

////"vector"类模板中与容量相关的成员函数示例七："reserve"成员函数和"shrink_to_fit"成员函数相关的迭代器失效。
//int main()
//{
//	std::vector<int> nums(1000, 1);
//	auto it = nums.begin();
//	std::cout << "s.capacity() = " << nums.capacity() << "\n";
//
//	nums.shrink_to_fit();
//	std::cout << "s.shrink_to_fit()\n";
//	std::cout << "s.capacity() = " << nums.capacity() << "\n";
//	//std::cout << "it = " << *it << "\n";//迭代器失效。
//	it = nums.begin();
//	std::cout << "it = " << *it << "\n";
//
//	nums.reserve(10000);
//	std::cout << "s.capacity() = " << nums.capacity() << "\n";
//	//std::cout << "it = " << *it << "\n";//迭代器失效。
//	it = nums.begin();
//	std::cout << "it = " << *it << "\n";
//
//	return 0;
//}

/**
	"vector"类模板中与修改器相关的成员函数(暂不介绍C++11起支持的"emplace"、"emplace_back"和"emplace_front"成员函数)
		1."clear"成员函数：清除内容。
			a.函数原型：void clear();。(C++11前)
			b.从容器擦除所有元素，调用此函数后"size"成员函数返回零，并保持"vector"的容量不变。
			c.非法化任何指代所含元素的引用、指针或迭代器，包括任何尾后迭代器也都会失效。
			d.复杂度与当前容器的大小，即元素数成线性级别。
		2."insert"成员函数：插入元素，即插入元素到容器中的指定位置，常见函数原型如下：
			a.iterator insert( const_iterator pos, const T& value );。(C++20前)
				a'.在"pos"前插入一个值为"value"的元素，其中"pos"指代将内容插入到它前面的迭代器("pos"可以是"end"成员函数返回的迭代器)(此函数其他函数原型中的"pos"参数含义相同)。
				b'.返回指向被插入"value"的迭代器。
				c'.复杂度为常数级别，加上"pos"与容器结尾的距离成线性级别。
			b.iterator insert( const_iterator pos, size_type count, const T& value );。(C++20前)
				a'.在"pos"前插入"count"个值为"value"的副本。
				b'.返回指向首个被插入元素的迭代器，或者在"count == 0"时返回"pos"。
				c'.复杂度与"count"成线性级别，加上"pos"与容器结尾的距离成线性级别。
			c.template< class InputIt > iterator insert( const_iterator pos, InputIt first, InputIt last );。(C++20前)
				a'.在"pos"前插入来自范围"[first, last)"中的元素，其中"first"和"last"指代要插入的元素范围，但不能是指向调用"insert"所用的容器中的迭代器。
				b'.返回指向首个被插入元素的迭代器，或者在"first == last"时返回 pos。
				c'.复杂度与"std::distance(first, last)"(从"first"走到"last"所需的自增数)成线性级别，加上"pos"与容器结尾的距离成线性级别。
		3."erase"成员函数：擦除元素，即从容器擦除指定的元素。
			a.函数原型(C++11前)
				a'.iterator erase( iterator pos );。
					a''.移除位于"pos"的元素，其中"pos"指向要移除的元素的迭代器。
					b''.在C++11起直至C++20前，此函数的原型为：iterator erase( const_iterator pos );。
					c''.迭代器"pos"必须合法且可解引用，因此不能以"end"成员函数返回的迭代器(即使合法，但其依旧不可解引用)作为"pos"的值。
					d''.返回值为最后移除元素之后的迭代器，如果"pos"指代末元素，那么返回"end()"迭代器。
				b'.iterator erase( iterator first, iterator last );。
					a''.移除范围"[first, last)"中的元素，其中"first"和"last"指代要移除的元素范围。
					b''.在C++11起直至C++20前，此函数的原型为：iterator erase( const_iterator first, const_iterator last );。
					c''.如果"first == last"，那么迭代器"first"不需要可解引用：擦除空范围是无操作。
					d''.返回值为最后移除元素之后的迭代器。
						a'''.如果在移除前"last == end()"，那么返回更新的"end"成员函数返回的迭代器。
						b'''.如果范围"[first, last)"为空，那么返回"last"。
			b.此函数将使位于擦除点或之后的迭代器失效，包含"end"成员函数返回的迭代器。
			c.复杂度为线性级别：调用"T"析构函数的次数与被擦除的元素数相同，调用"T"赋值运算符的次数与"vector"中被擦除元素后的元素数相等。
		4."push_back"成员函数：将元素添加到容器末尾，即后附给定元素到容器尾。
			a.常见函数原型：void push_back( const T& value );。(C++20前)
				a'.初始化新元素为"value"的副本，其中"value"是要后附的元素值。
			b.如果新的"size()"大于"capacity()"，那么所有迭代器和引用(包含尾后迭代器)都会失效，否则只有尾后迭代器会失效。
			c.均摊复杂度为常数级别。
			d.若此函数抛出异常，则此函数无效果(强异常保证)。
			e.一些实现在"push_back"导致会超出"max_size"的重分配时亦抛出异常，由于这会隐式调用"reserve(size() + 1)"的等价者。
		5."pop_back"成员函数：移除末元素，即移除容器的末元素。
			a.函数原型：void pop_back();。(C++20前)
			b.在空容器上调用"pop_back"导致未定义行为。
			c.使指向末元素的迭代器和引用，以及"end()"迭代器失效。
			d.复杂度为常数级别。
			e.不抛出异常。
		6."resize"成员函数：改变容器中可存储元素的个数。
			a.常见函数原型：void resize( size_type count, T value = T() );(C++11前)
				a'.在C++11起直至C++20前，此函数的原型为：void resize( size_type count, const value_type& value );。
				b'.其中"value"是用以初始化新元素的值，而"count"是容器的大小。
				c'.如果当前大小大于"count"，那么减小容器到它的开头"count"个元素。
				d'.如果当前大小小于"count"，那么后附额外的"value"的副本。
			b.重设容器大小以容纳"count"个元素。
			c.复杂度与当前大小和"count"间的差成线性级别，如果容量小于"count"那么就可能有重分配所致的额外复杂度。
			d.若此函数抛出异常，则此函数无效果(强异常保证)。
		7."swap"成员函数：交换内容。
			a.函数原型(C++17前)：void swap( vector& other );。
			b.将内容与"other"的交换，不在单独的元素上调用任何移动、复制或交换操作，其中"other"是要与之交换内容的容器。
			c.所有迭代器和引用保持有效，而尾后迭代器会失效。
			d.复杂度为常数级别。
*/

////"vector"类模板中与修改器相关的成员函数示例一：使用"clear"成员函数。
//int main()
//{
//	std::vector<int> v(10, 100);
//
//	std::cout << "size of v: " << v.size() << std::endl;
//	std::cout << "capacity of v: " << v.capacity() << std::endl;
//
//	v.clear();
//
//	std::cout << "size of v: " << v.size() << std::endl;
//	std::cout << "capacity of v: " << v.capacity() << std::endl;
//
//	//迭代器失效示例
//	std::vector<int>::iterator it = v.begin();
//	v.clear();
//	v.push_back(100);
//	//std::cout << *it << std::endl;//迭代器失效。
//	it = v.begin();
//	std::cout << *it << std::endl;
//
//	return 0;
//}

////"vector"类模板中与修改器相关的成员函数示例二：使用"insert"成员函数。
//void print(int id, const std::vector<int>& container)
//{
//	std::cout << id << ". ";
//	for (const int x: container)
//	{
//		std::cout << x << ' ';
//	}
//	std::cout << '\n';
//}
//
//int main()
//{
//	std::vector<int> v1(5, 100);
//	std::vector<int> v2(5, 200);
//	std::vector<int> v3(5, 300);
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
//	//迭代器失效示例
//	std::vector<int> v4(5, 0);
//	print(7, v4);
//	std::vector<int>::iterator it = v4.end();
//	v4.insert(v4.begin(), 50);
//	print(7, v4);
//	//std::cout << *it << std::endl;//迭代器失效。
//	it = v4.begin();
//	std::cout << *it << std::endl;
//
//	return 0;
//}

////"vector"类模板中与修改器相关的成员函数示例三：使用"erase"成员函数。
//void print_container(const std::vector<int>& c)
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
//	std::vector<int> c;
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
//	c.erase(c.begin() + 2, c.begin() + 5);
//	print_container(c);
//
//	//移除所有偶数
//	for (auto it = c.begin(); it != c.end();)
//	{
//		if (*it % 2 == 0)
//		{
//			it = c.erase(it);
//		}
//		else
//		{
//			++it;
//		}
//	}
//	print_container(c);
//
//	//迭代器失效示例
//	std::vector<int> v(5, 0);
//	print_container(v);
//	std::vector<int>::iterator it = v.begin();
//	v.erase(it);
//	print_container(v);
//	//std::cout << *it << std::endl;//迭代器失效。
//	it = v.begin();
//	std::cout << *it << std::endl;
//
//	return 0;
//}

////"vector"类模板中与修改器相关的成员函数示例四：使用"push_back"成员函数和"pop_back"成员函数。
//template<class T>
//void print(T const& xs)
//{
//	std::cout << "[ ";
//	for (auto&& x: xs)
//	{
//		std::cout << x << ' ';
//	}
//	std::cout << "]\n";
//}
//
//int main()
//{
//	std::vector<int> numbers;
//	print(numbers);
//
//	numbers.push_back(5);
//	numbers.push_back(3);
//	numbers.push_back(4);
//	print(numbers);
//
//	numbers.pop_back();
//	print(numbers);
//
//	//迭代器失效示例("push_back")
//	std::vector<int> v1(5, 0);
//	print(v1);
//	std::vector<int>::iterator it = v1.end();
//	v1.push_back(50);
//	print(v1);
//	//std::cout << *it << std::endl;//迭代器失效。
//	it = v1.begin();
//	std::cout << *it << std::endl;
//
//	//迭代器失效示例("pop_back")
//	std::vector<int> v2(5, 0);
//	print(v2);
//	it = v2.end();
//	v2.pop_back();
//	print(v2);
//	//std::cout << *it << std::endl;//迭代器失效。
//	it = v2.begin();
//	std::cout << *it << std::endl;
//
//	return 0;
//}

////"vector"类模板中与修改器相关的成员函数示例五：使用"resize"成员函数。
//int main()
//{
//	std::vector<int> c(3, 0);
//	std::cout << "vector 持有：";
//	for (const auto& el: c) std::cout << el << ' ';
//	std::cout << '\n';
//
//	c.resize(5, 0);
//	std::cout << "在增加大小到 5 之后（初始化器 = 0）：";
//	for (const auto& el: c) std::cout << el << ' ';
//	std::cout << '\n';
//
//	c.resize(2, 0);
//	std::cout << "在减少大小到 2 之后（初始化器 = 0）：";
//	for (const auto& el: c) std::cout << el << ' ';
//	std::cout << '\n';
//
//	c.resize(6, 4);
//	std::cout << "在增加大小到 6 之后（初始化器 = 4）：";
//	for (const auto& el: c) std::cout << el << ' ';
//	std::cout << '\n';
//
//	//迭代器失效示例
//	std::vector<int> v(5, 0);
//	std::cout << "vector 持有：";
//	for (const auto& el: v) std::cout << el << ' ';
//	std::cout << '\n';
//	std::vector<int>::iterator it = v.end();
//	v.resize(10, 0);
//	std::cout << "在增加大小到 10 之后（初始化器 = 0）：";
//	for (const auto& el: v) std::cout << el << ' ';
//	std::cout << '\n';
//	//std::cout << *it << std::endl;//迭代器失效。
//	it = v.begin();
//	std::cout << *it << std::endl;
//
//	return 0;
//}

////"vector"类模板中与修改器相关的成员函数示例六：使用"swap"成员函数。
//int main()
//{
//	std::vector<int> v1(5, 10);
//	std::vector<int> v2(10, 5);
//
//	std::cout << "v1: ";
//	for (const auto& el: v1) std::cout << el << ' ';
//
//	std::cout << "\nv2: ";
//	for (const auto& el: v2) std::cout << el << ' ';
//
//	std::cout << '\n';
//
//	v1.swap(v2);
//
//	std::cout << "v1: ";
//	for (const auto& el: v1) std::cout << el << ' ';
//
//	std::cout << "\nv2: ";
//	for (const auto& el: v2) std::cout << el << ' ';
//
//	std::cout << '\n';
//
//	//迭代器失效示例
//	std::vector<int> v3(5, 10);
//	std::vector<int> v4(10, 5);
//	std::vector<int>::iterator it = v3.end();
//	v3.swap(v4);
//	//std::cout << *it << std::endl;//迭代器失效。
//	it = v3.begin();
//	std::cout << *it << std::endl;
//
//	return 0;
//}

/**
	"vector"类模板相关的非成员函数(常见)
		1.按照字典顺序比较"vector"中的值(函数模板)。
			a.将各个用于比较的运算符进行重载，以便于比较二个"vector"的内容。
			b.常见函数原型(省略了模板声明、模板参数、分配器和命名空间等细节)
				a'.bool operator==( const vector& lhs, const vector& rhs );。(C++20前)
					a''.若"vector"内容相等则为"true"，否则为"false"。
				b'.bool operator!=( const vector& lhs, const vector& rhs );。(C++20前)
					a''.若"vector"内容不相等则为"true"，否则为"false"。
				c'.bool operator<( const vector& lhs, const vector& rhs );。(C++20前)
					a''.若"lhs"的内容按字典序小于"rhs"的内容则为"true"，否则为"false"。
				d'.bool operator<=( const vector& lhs, const vector& rhs );。(C++20前)
					a''.若"lhs"的内容按字典序小于或等于"rhs"的内容则为"true"，否则为"false"。
				e'.bool operator>( const vector& lhs, const vector& rhs );。(C++20前)
					a''.若"lhs"的内容按字典序大于"rhs"的内容则为"true"，否则为"false"。
				f'.bool operator>=( const vector& lhs, const vector& rhs );。(C++20前)
					a''.若"lhs"的内容按字典序大于或等于"rhs"的内容则为"true"，否则为"false"。
			c.运算符"=="以及"!="意为检查"lhs"与"rhs"的内容是否相等，即它们是否拥有相同数量的元素且"lhs"中每个元素与"rhs"的同位置元素比较相等。
				a'.这些运算符的复杂度若"lhs"与"rhs"的大小不同则为常数级别，否则与"vector"的大小成线性级别。
			d.运算符"<"、"<="、">"以及">="意为按字典序比较"lhs"与"rhs"的内容。
				a'.这些运算符的复杂度与"vector"的大小成线性级别。
		2."swap"非成员函数：标准算法库中的"swap"函数模板对"vector"类模板的特化，用于交换两个"vector"的内容。(函数模板)
			a.常见函数原型：void swap( vector& lhs, vector& rhs );。(C++17前)(省略了模板声明、模板参数、分配器和命名空间等细节)
			b."lhs"、"rhs"参数：要交换内容的容器。
			c.等价于"lhs.swap(rhs)"。
			d.复杂度为常数级别。
*/

////"vector"类模板相关的非成员函数示例一：使用比较运算符比较"vector"中的值。
//int main()
//{
//	std::vector<int> alice(3, 1);
//	std::vector<int> bob(4, 2);
//	std::vector<int> eve(3, 1);
//
//	// 比较不相等的容器
//	std::cout << "alice == bob returns " << (alice == bob) << '\n';
//	std::cout << "alice != bob returns " << (alice != bob) << '\n';
//	std::cout << "alice <  bob returns " << (alice < bob) << '\n';
//	std::cout << "alice <= bob returns " << (alice <= bob) << '\n';
//	std::cout << "alice >  bob returns " << (alice > bob) << '\n';
//	std::cout << "alice >= bob returns " << (alice >= bob) << '\n';
//	std::cout << '\n';
//
//	// 比较相等的容器
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

////"vector"类模板相关的非成员函数示例二：使用"swap"非成员函数。
//int main()
//{
//	std::vector<int> v1(5, 10);
//	std::vector<int> v2(10, 5);
//
//	std::cout << "v1: ";
//	for (const auto& el: v1) std::cout << el << ' ';
//
//	std::cout << "\nv2: ";
//	for (const auto& el: v2) std::cout << el << ' ';
//
//	std::cout << '\n';
//
//	swap(v1, v2);
//
//	std::cout << "v1: ";
//	for (const auto& el: v1) std::cout << el << ' ';
//
//	std::cout << "\nv2: ";
//	for (const auto& el: v2) std::cout << el << ' ';
//
//	std::cout << '\n';
//
//	//迭代器失效示例
//	std::vector<int> v3(5, 10);
//	std::vector<int> v4(10, 5);
//	std::vector<int>::iterator it = v3.end();
//	swap(v3, v4);
//	//std::cout << *it << std::endl;//迭代器失效。
//	it = v3.begin();
//	std::cout << *it << std::endl;
//
//	return 0;
//}