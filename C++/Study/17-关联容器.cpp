#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <string>

/*
	关联容器
		1.关联容器的介绍
		2.关联容器的使用
		3.关联容器的元素访问
		4.关联容器与容量和修改器相关的成员函数
		5.关联容器与查找相关的成员函数
		6.关联容器与观察器相关的成员函数
		7.关联容器相关的非成员函数
*/

/**
	关联容器的介绍：实现能快速查找("O(logN)"复杂度)的数据结构。
		1.四种关联容器
			a."set"类模板：键的集合，按照键排序，键是唯一的。
				a'.定义：template< class Key, class Compare = std::less<Key>, class Allocator = std::allocator<Key> > class set;。
					a''."Key"：键类型对象。
					b''."Compare"：比较器，是用于比较键的函数对象。
					c''."Allocator"：分配器对象。
				b'."set"是一个关联容器，其搜索、移除和插入拥有对数级别复杂度，通常以红黑树实现，是含有键类型对象的已排序集。
				c'.标准库使用比较器的等价关系确定唯一性，即两个对象相互比较不小于对方时等价。
				d'.其包含于头文件"set"中。
				e'.文档：https://zh.cppreference.com/w/cpp/container/set。
			b."map"类模板：键值对的集合，按照键排序，键是唯一的。
				a'.定义：template< class Key, class T, class Compare = std::less<Key>, class Allocator = std::allocator<std::pair<const Key, T>> > class map;。
					a''."T"：值类型对象。
				b'."map"是有序的键值对容器，其搜索、移除和插入操作拥有对数复杂度，通常以红黑树实现。
				c'.标准库使用比较器的等价关系确定唯一性，即两个对象相互比较不小于对方时等价。
				d'.其包含于头文件"map"中。
				e'.具有"value_compare"成员类：用于比较类型为"value_type"的对象。
				f'.文档：https://zh.cppreference.com/w/cpp/container/map。
			c."multiset"类模板：键的集合，按照键排序，键不是唯一的。
				a'.定义：template< class Key, class Compare = std::less<Key>, class Allocator = std::allocator<Key> > class multiset;。
				b'."multiset"类似于"set"，其是含有键类型对象有序集的容器，它允许多个键拥有等价的值。
				c'.比较等价的元素顺序是插入顺序，而且不会更改。(C++11起)
				d'.其包含于头文件"set"中。
				e'.文档：https://zh.cppreference.com/w/cpp/container/multiset。
			d."multimap"类模板：键值对的集合，按照键排序，键不是唯一的。
				a'.定义：template< class Key, class T, class Compare = std::less<Key>, class Allocator = std::allocator<std::pair<const Key, T>> > class multimap;。
				b'."multimap"类似于"map"，其是含有键值对的已排序列表，同时容许多个元素拥有同一键。
				c'.拥有等价键的键值对的顺序就是插入顺序，且不会更改。(C++11起)
				d'.其包含于头文件"map"中。
				e'.具有"value_compare"成员类：用于比较类型为"value_type"的对象。
				f'.文档：https://zh.cppreference.com/w/cpp/container/multimap。
		2."set"的常见成员类型(省略分配器相关的类型和C++17新增的相关类型)
			a."key_type"成员类型：定义为"set"的模板形参"Key"。
			b."value_type"成员类型：定义为"set"的模板形参"Key"。
			c."size_type"成员类型：无符号整数类型，通常定义为"std::size_t"。
			d."difference_type"成员类型：带符号整数类型，通常定义为"std::ptrdiff_t"。
			e."key_compare"成员类型：定义为"set"的模板形参"Compare"。
			f."value_compare"成员类型：定义为"set"的模板形参"Compare"。
			g."reference"成员类型：定义为"value_type&"。
			h."const_reference"成员类型：定义为"const value_type&"。
			i."iterator"成员类型：定义为指向"value_type"的迭代器类型。
			j."const_iterator"成员类型：定义为指向"const value_type"的迭代器类型。
			k."reverse_iterator"成员类型：定义为"std::reverse_iterator<iterator>"。
			l."const_reverse_iterator"成员类型：定义为"std::reverse_iterator<const_iterator>"。
		3."map"的常见成员类型(省略分配器相关的类型和C++17新增的相关类型)
			a."key_type"成员类型：定义为"map"的模板形参"Key"。
			b."mapped_type"成员类型：定义为"map"的模板形参"T"。
			c."value_type"成员类型：定义为"std::pair<const Key, T>"。
			d."size_type"成员类型：无符号整数类型，通常定义为"std::size_t"。
			e."difference_type"成员类型：带符号整数类型，通常定义为"std::ptrdiff_t"。
			f."key_compare"成员类型：定义为"map"的模板形参"Compare"。
			g."value_compare"成员类型：定义为"map"的模板形参"Compare"。
			i."reference"成员类型：定义为"value_type&"。
			j."const_reference"成员类型：定义为"const value_type&"。
			k."iterator"成员类型：定义为指向"value_type"的迭代器类型。
			l."const_iterator"成员类型：定义为指向"const value_type"的迭代器类型。
			m."reverse_iterator"成员类型：定义为"std::reverse_iterator<iterator>"。
			n."const_reverse_iterator"成员类型：定义为"std::reverse_iterator<const_iterator>"。
		4.键和键值对：计算机系统和应用程序中的一种数据表示形式。
			a.键：即"Key"，可理解为元素的索引。
				a'.在"set"和"map"中，键是唯一的，而"multiset"和"multimap"中，键不是唯一的。
				b'.在"set"和"multiset"中每个元素都是键，没有映射值(通常在底层上实际是存储为"Key-Key"形式，即键直接映射值(反之同理))。
			b.键值对：即"Key-Value"，可理解为元素的索引和索引对应的数据。
				a'.键值对是一种用来表示具有一一对应关系的的结构，一般只包含两个数据项，即键和映射值，映射值表示与键对应的信息。
				b'.在"map"和"multimap"中，每个元素都由一个键和一个映射值组成。
			c."pair"类模板：实现二元组，即一对值，在头文件"utility"中定义。
				a'.定义：template <class T1, class T2> struct pair;。
				b'."pair"提供在一个单元存储两个相异类型对象的途径。
				c'."pair"有两个成员类型"first_type"和"second_type"，分别表示"T1"和"T2"。
				d'."pair"有两个成员对象"first"和"second"，分别表示"T1"和"T2"。
				e'."pair"的常见成员函数
					a''.默认构造函数：pair();。(C++11前)
						a'''.值初始化"pair"的两个元素"first"和"second"。
					b''.构造函数：pair( const T1& x, const T2& y );。(C++11前)
						a'''.以"x"初始化"first"，并以"y"初始化"second"。
					c''.复制构造函数：pair( const pair& p ) = default;。
						a'''.默认隐式声明的复制构造函数。(C++11前)
					d''.复制构造函数：template< class U1, class U2 > pair( const pair<U1, U2>& p );。(C++11前)
						a'''.以"p.first"初始化"first"，并以"p.second"初始化"second"。
					e''."operator="成员函数
						a'''."pair& operator=( const pair& other )"：复制赋值运算符，以"other"内容的副本替换内容。(C++20前)
						b'''."template< class U1, class U2 > pair& operator=( const pair<U1, U2>& other )"：将"other.first"赋给"first"，将"other.second"赋给"second"。(C++20前)
					f''.用于交换内容的函数：void swap( pair& other );。(C++11起，C++20前)(省略"noexcept"关键词)
						a'''.交换"first"与"other.first"，以及交换"second"与"other.second"。
						b'''.如同使用标准库"swap"函数，先交换"first"与"other.first"，再交换"second"与"other.second"。
				f'."pair"的常见非成员函数
					a''."make_pair"函数：函数模板，用于创建一个"pair"对象，其类型根据各实参类型定义。
						a'''.常见函数原型：template <class T1, class T2> pair<T1,T2> make_pair( T1 t, T2 u );。(C++11前)
						b'''.返回值：构造一个"pair"对象，从参数类型推导目标类型，并返回含有指定值的"pair"对象。
					b''.用于重载比较运算符的众多"operator"函数：其按字典序比较"pair"中的值。
						a'''.测试"lhs"和"rhs"的两个元素是否都各自相等时，会分别比较"lhs.first"和"rhs.first"，以及"lhs.second"和"rhs.second"。("lhs"和"rhs"为要比较的两个"pair"对象)
						b'''.当使用"<、<=、>、>="运算符比较两"pair"对象时，会先比较首元素，如果首元素相等，再比较第二元素。
						c'''.存储"pair"的容器可以使用标准库算法"sort"对其进行排序。
					c''.特化标准库算法"swap"，使其支持"pair"的交换。
*/

////"pair"类模板的使用示例
//int main()
//{
//	std::pair<int, double> p1(1, 2.5);
//	std::pair<int, double> p2 = std::make_pair(1, 2.5);
//	std::pair<int, double> p3 = p1;
//	std::pair<int, double> p4(p1);
//	std::pair<int, double> p5;
//	p5 = p1;
//	std::pair<int, double> p6;
//	p6.swap(p1);
//	swap(p1, p2);
//	std::cout << p1.first << " " << p1.second << std::endl;
//	std::cout << p2.first << " " << p2.second << std::endl;
//	std::cout << p3.first << " " << p3.second << std::endl;
//	std::cout << p4.first << " " << p4.second << std::endl;
//	std::cout << p5.first << " " << p5.second << std::endl;
//	std::cout << p6.first << " " << p6.second << std::endl;
//
//	int n = 1;
//	int a[5] = { 1, 2, 3, 4, 5 };
//	p1 = std::make_pair(n, a[1]);
//	std::cout << "p1 的值是 " << "(" << p1.first << ", " << p1.second << ")\n";
//}

/**
	关联容器的使用
		1."set"类模板的使用
		2."map"类模板的使用
*/

/***
	"set"类模板的使用
		1."set"的常见构造函数的函数原型(以下部分函数原型忽略分号以及分配器等细节)
			a."set()"：默认构造函数，构造空容器。
				a'.另一默认构造函数形式：explicit set( const Compare& comp, const Allocator& alloc = Allocator() )。
				b'.C++11起支持构造拥有给定分配器"alloc"的空容器：explicit set( const Allocator& alloc )。
				c'.复杂度为常数级别。
			b."template< class InputIt > set( InputIt first, InputIt last )"：构造拥有范围"[first, last)"内容的容器。
				a'.如果范围中的多个元素的键比较相等，那么未指定插入哪个元素。
				b'.复杂度通常为"O(N * logN)"，若范围已按照"set"的成员函数"value_comp"排序则与"N"成线性级别，其中"N"为"first"到"last"的距离。
			c."set( const set& other )"：复制构造函数，以"other"内容的副本构造容器。
				a'.C++11起支持构造拥有给定分配器"alloc"的容器：set( const set& other, const Allocator& alloc )。
				b'.复杂度与"other"的大小成线性级别。
		2."set"的析构函数的函数原型：~set();。
			a.销毁"set"，调用元素的析构函数，然后解分配所用的存储(若元素是指针，则不销毁所指向的对象)。
			b.复杂度与"set"的大小成线性级别。
		3."set"的常见"operator="成员函数：set& operator=( const set& other );。
			a.复制赋值运算符，赋值给容器，即以"other"内容的副本替换容器内容。
			b.复杂度与"*this"和"other"的大小成线性级别。
*/

////"set"类模板的使用示例
//int main()
//{
//	std::vector<int> v{ 3, 1, 4, 6, 5, 9 };
//
//	//"set"的默认构造函数
//	std::set<int> s1;
//
//	//"set"的范围构造函数
//	std::set<int> s2(v.begin(), v.end());
//
//	//"set"的复制构造函数
//	std::set<int> s3(s2);
//
//	//"set"的赋值运算符
//	std::set<int> s4;
//	s4 = s3;
//
//	//输出"set"的元素
//	for (auto& e: { s1, s2, s3, s4 })
//	{
//		for (auto& ee: e)
//		{
//			std::cout << ee << " ";
//		}
//		std::cout << std::endl;
//	}
//}

/***
	"map"类模板的使用
		1."map"的常见构造函数的函数原型(以下部分函数原型忽略分号以及分配器等细节)
			a."map()"：默认构造函数，构造空容器。
				a'.另一默认构造函数形式：explicit map( const Compare& comp, const Allocator& alloc = Allocator() )。
				b'.C++11起支持构造拥有给定分配器"alloc"的空容器：explicit map( const Allocator& alloc )。
				c'.复杂度为常数级别。
			b."template< class InputIt > map( InputIt first, InputIt last )"：构造拥有范围"[first, last)"内容的容器。
				a'.如果范围中的多个元素的键比较相等，那么未指定插入哪个元素。
				b'.复杂度通常为"O(N * logN)"，若范围已按照"map"的成员函数"value_comp"排序则与"N"成线性级别，其中"N"为"first"到"last"的距离。
			c."map( const map& other )"：复制构造函数，以"other"内容的副本构造容器。
				a'.C++11起支持构造拥有给定分配器"alloc"的容器：map( const map& other, const Allocator& alloc )。
				b'.复杂度与"other"的大小成线性级别。
		2."map"的析构函数的函数原型：~map();。
			a.销毁"map"，调用元素的析构函数，然后解分配所用的存储(若元素是指针，则不销毁所指向的对象)。
			b.复杂度与"map"的大小成线性级别。
		3."map"的常见"operator="成员函数：map& operator=( const map& other );。
			a.复制赋值运算符，赋值给容器，即以"other"内容的副本替换容器内容。
			b.复杂度与"*this"和"other"的大小成线性级别。
*/

////"map"类模板的使用示例
//int main()
//{
//	std::vector<std::pair<int, std::string>> v{{ 3, "3" },
//											   { 1, "1" },
//											   { 4, "4" },
//											   { 6, "6" },
//											   { 5, "5" },
//											   { 9, "9" }};
//
//	//"map"的默认构造函数
//	std::map<int, std::string> m1;
//
//	//"map"的范围构造函数
//	std::map<int, std::string> m2{ v.begin(), v.end() };
//
//	//"map"的复制构造函数
//	std::map<int, std::string> m3(m2);
//
//	//"map"的赋值运算符
//	std::map<int, std::string> m4;
//	m4 = m3;
//
//	//输出"map"的元素
//	for (auto& e: { m1, m2, m3, m4 })
//	{
//		for (auto& ee: e)
//		{
//			std::cout << ee.first << " " << ee.second << std::endl;
//		}
//		std::cout << std::endl;
//	}
//}

/**
	关联容器的元素访问
		1."set"类模板的元素访问：仅支持迭代器访问，即"begin"、"end"、"rbegin"、"rend"。(包含C++11起支持的"cbegin"、"cend"、"crbegin"、"crend")
			a.因为"iterator"和"const_iterator"都是常迭代器(而且实际上可以是同一类型)，故不可能通过任何这些成员函数返回的迭代器修改容器元素。
		2."map"类模板的元素访问：同样支持迭代器访问，并且另外支持"at"和"operator[]"两种访问方式。
			a."at"成员函数：访问指定的元素，同时进行越界检查。
				a''.函数原型
					a'''.T& at( const Key& key );。
					b'''.const T& at( const Key& key ) const;。
				b''.返回键与"key"相同的元素所映射的映射值的引用，如果没有这种元素，那么抛出异常。
				c''.复杂度与容器大小成对数级别。
			b."operator[]"成员函数：访问或插入指定的元素。
				a''.常见函数原型：T& operator[]( const Key& key );。
					a'''.在键不存在的情况下插入"value_type(key, T())"。(C++11前)
				b''.返回键与"key"相同的元素所映射的映射值的引用，如果没用这种元素，即这种键不存在的情况下，则进行插入。
				c''.当没有这种元素时，返回新插入的元素的映射值的引用，否则返回已存在的元素的映射值的引用。
				d''.如果任何操作抛出异常，那么插入无效果。
				e''.复杂度与容器大小成对数级别。
*/

////关联容器的元素访问示例一："set"类模板的元素访问。
//int main()
//{
//	std::set<int> s{ 3, 1, 4, 6, 5, 9 };
//
//	//迭代器访问
//	for (auto it = s.begin(); it != s.end(); ++it)
//	{
//		std::cout << *it << " ";
//	}
//	std::cout << std::endl;
//
//	//反向迭代器访问
//	for (auto it = s.rbegin(); it != s.rend(); ++it)
//	{
//		std::cout << *it << " ";
//	}
//	std::cout << std::endl;
//}

////关联容器的元素访问示例二："map"类模板的元素访问。
//int main()
//{
//	std::map<int, char> m{{ 65, 'A' },
//						  { 66, 'B' },
//						  { 67, 'C' },
//						  { 68, 'D' },
//						  { 69, 'E' },
//						  { 70, 'F' }};
//
//	//迭代器访问
//	for (auto& it: m)
//	{
//		std::cout << it.first << "-" << it.second << " ";
//	}
//	std::cout << std::endl;
//
//	//插入新元素
//	m[71] = 'g';
//
//	//修改已有元素
//	m[71] = 'G';
//
//	//"at"成员函数访问
//	std::cout << m.at(71) << std::endl;
//}

/**
	关联容器与容量和修改器相关的成员函数
		1."set"类模板和"map"类模板与容量相关的成员函数，其均支持以下成员函数，且用法相同：
			a."empty"成员函数：检查容器是否为空。
			b."size"成员函数：返回容纳的元素数。
			c."max_size"成员函数：返回可容纳的最大元素数。
		2."set"类模板和"map"类模板与修改器相关的成员函数，其均支持以下成员函数(只介绍C++11前的成员函数)：
			a."clear"成员函数：清除内容，两容器用法相同。
			b."swap"成员函数：交换内容，两容器用法相同。
			c."set"类模板和"map"类模板的"insert"成员函数：用于插入元素，在C++17起支持插入节点(暂不介绍)。
				a'.常见函数原型
					a''.std::pair<iterator, bool> insert( const value_type& value );。
						a'''.插入"value"，即要插入的元素值。
						b'''.返回由指向被插入元素(或阻止插入的元素)的迭代器和只会在插入发生时是"true"的"bool"值组成的"pair"。
						c'''.复杂度与容器大小成对数级别。
					b''.iterator insert( iterator pos, const value_type& value );。
						a'''.插入"value"到尽可能接近正好在"pos"之前的位置。
						b'''.返回指向被插入元素，或阻止插入的元素的迭代器。
						c'''.复杂度：如果插入恰好发生在正好在"pos"之前的位置，那么是均摊常数级别，否则与容器大小成对数级别。
					c''.template< class InputIt > void insert( InputIt first, InputIt last );。
						a'''.插入来自范围"[first, last)"的元素，如果范围中的多个元素的键比较相等，那么未指定插入哪个元素。
						b'''.复杂度：O(N * log(size * N))，其中"size"是容器大小、"N"为"first"到"last"的距离。
				b'.如果容器未含拥有等价关键的元素，则插入元素到容器。
				c'."set"类模板和"map"类模板的"insert"成员函数在上述所列的常见成员函数是类似的，但"map"类模板其实具有更多的函数原型。
				d'.没有迭代器或引用会失效。
			d."set"类模板和"map"类模板的"erase"成员函数：擦除元素。
				a'.常见函数原型
					a''.iterator erase( iterator pos );。
						a'''.移除位于"pos"的元素。
						b'''.返回后随最后被移除的元素的迭代器。
						c'''.复杂度：均摊常数级别。
					b''.iterator erase( iterator first, iterator last );。
						a'''.移除范围"[first, last)"的元素，它必须是"*this"的合法范围。
						b'''.返回后随最后被移除的元素的迭代器。
						c'''.复杂度(给定实例"c")：log(c.size()) + std::distance(first, last)。
					c''.size_type erase( const Key& key );。
						a'''.移除键等价于"key"的元素(如果存在一个)。
						b'''.返回被移除的元素个数。
						c'''.复杂度(给定实例"c")：log(c.size()) + c.count(key)。
				b'.指向被擦除元素的引用和迭代器会失效，其他引用和迭代器不受影响。
				c'.迭代器"pos"必须合法且可解引用，从而"end"成员函数返回的迭代器即使合法，但其不可解引用，故不能用作"pos"所用的值。
*/

////关联容器与容量和修改器相关的成员函数示例："insert"成员函数和"erase"成员函数的使用。
//int main()
//{
//	std::map<std::string, double> heights1;
//	std::map<std::string, double> heights2;
//
//	std::cout << heights1.insert({ "X", 5.83 }).second << std::endl;
//	std::cout << heights1.insert({ "Y", 6.25 }).second << std::endl;
//	std::cout << heights1.insert({ "Z", 6.50 }).second << std::endl;
//
//	heights2.insert(heights2.begin(), { "A", 5.83 });
//	heights2.insert(heights1.begin(), heights1.end());
//
//	for (auto& it: heights2)
//	{
//		std::cout << it.first << "-" << it.second << " ";
//	}
//	std::cout << std::endl;
//
//	std::cout << heights2.erase(heights2.begin())->first << std::endl;
//	std::cout << heights2.erase(++heights2.begin(), --heights2.end())->first << std::endl;
//	std::cout << heights2.erase("?") << std::endl;
//}

/**
	关联容器与查找相关的成员函数("set"类模板和"map"类模板类似)
		1."count"成员函数：返回匹配特定键的元素数量。
			a.常见函数原型：size_type count( const Key& key ) const;。
			a.在"set"类模板和"map"类模板中，不允许重复的键，故返回值只能是"0"或"1"(仅对于常见函数原型)。
			b.在"multiset"类模板和"multimap"类模板中，允许重复的键，故返回值可以是"0"或大于等于"1"(仅对于常见函数原型)。
			c.复杂度：与容器大小成对数级别。
		2."find"成员函数：寻找带有特定键的元素。
			a.常见函数原型
				a'.iterator find( const Key& key );。
				b'.const_iterator find( const Key& key ) const;。
			b.寻找键等于"key"的元素(仅对于常见函数原型)。
			c.返回指向键等于"key"的元素的迭代器，若找不到这种元素，则返回"end"成员函数返回的迭代器。
			d.复杂度：与容器大小成对数级别。
		3."lower_bound"成员函数：返回指向首个不小于给定键的元素的迭代器。
			a.常见函数原型
				a'.iterator lower_bound( const Key& key );。
				b'.const_iterator lower_bound( const Key& key ) const;。
			b.返回指向首个不小于"key"的元素的迭代器，若找不到这种元素，则返回"end"成员函数返回的迭代器。
			d.复杂度：与容器大小成对数级别。
		4."upper_bound"成员函数：返回指向首个大于给定键的元素的迭代器。
			a.常见函数原型
				a'.iterator upper_bound( const Key& key );。
				b'.const_iterator upper_bound( const Key& key ) const;。
			b.返回指向首个大于"key"的元素的迭代器，若找不到这种元素，则返回"end"成员函数返回的迭代器。
			d.复杂度：与容器大小成对数级别。
		5."equal_range"成员函数：返回匹配特定键的元素范围。
			a.常见函数原型
				a'.std::pair<iterator, iterator> equal_range( const Key& key );。
				b'.std::pair<const_iterator, const_iterator> equal_range( const Key& key ) const;。
			b.返回容器中所有拥有给定关键的元素范围，范围以二个迭代器定义，一个指向首个不小于"key"的元素，而另一个指向首个大于"key"的元素。
			c.返回一个"std::pair"对象，其"first"成员是指向指向首个不小于"key"的元素，"second"成员是指向首个大于"key"的元素。
			d.若无元素不小于"key"，则将"end"成员函数返回的迭代器作为"first"返回，类似地，若无元素大于"key"，则将"end"成员函数返回的迭代器作为"second"返回。
			e.复杂度：与容器大小成对数级别。
*/

////关联容器与查找相关的成员函数示例一："count"成员函数和"find"成员函数的使用。
//int main()
//{
//	std::map<std::string, double> heights1;
//	std::map<std::string, double> heights2;
//
//	heights1.insert({ "X", 5.83 });
//	heights1.insert({ "Y", 6.25 });
//	heights1.insert({ "Z", 6.50 });
//
//	std::cout << heights1.count("X") << std::endl;
//	std::cout << heights1.count("A") << std::endl;
//
//	auto it = heights1.find("X");
//	if (it != heights1.end())
//	{
//		std::cout << it->first << "-" << it->second << std::endl;
//	}
//
//	it = heights1.find("A");
//	if (it != heights1.end())
//	{
//		std::cout << it->first << "-" << it->second << std::endl;
//	}
//	else
//	{
//		std::cout << "Not found!" << std::endl;
//	}
//}

////关联容器与查找相关的成员函数示例二："lower_bound"成员函数、"upper_bound"成员函数和"equal_range"成员函数的使用。
//int main()
//{
//	std::map<int, std::string> m{{ 0, "zero" },
//								 { 1, "one" },
//								 { 2, "two" }};
//
//	auto it = m.lower_bound(1);
//	if (it != m.end())
//	{
//		std::cout << it->first << "-" << it->second << std::endl;
//	}
//
//	it = m.upper_bound(1);
//	if (it != m.end())
//	{
//		std::cout << it->first << "-" << it->second << std::endl;
//	}
//
//	auto p = m.equal_range(1);
//	if (p.first != m.end())
//	{
//		std::cout << p.first->first << "-" << p.first->second << std::endl;
//	}
//	if (p.second != m.end())
//	{
//		std::cout << p.second->first << "-" << p.second->second << std::endl;
//	}
//}

/**
	关联容器与观察器相关的成员函数
 		1."key_comp"成员函数：返回用于比较键的函数对象。
			a.常见函数原型：key_compare key_comp() const;。
			b.对于"set"类模板而言，其返回用于比较键的函数对象，它是此容器构造函数参数"comp"的副本，它与"value_comp"成员函数的返回值相同。
			c.对于"map"类模板而言，其返回用于比较键的函数对象，它是此容器构造函数参数"comp"的副本。
			d.复杂度：常数级别。
		2."value_comp"成员函数：返回用于比较值的函数对象。
			a.常见函数原型
				a'."set"类模板为：std::set::value_compare value_comp() const;。
				b'."map"类模板为：std::map::value_compare value_comp() const;。
			b.对于"set"类模板而言，其返回比较值的函数对象，它与"key_comp"成员函数的返回值相同。
			c.对于"map"类模板而言，其返回用于比较"value_type"对象("pair")的函数对象，它将用"key_comp"成员函数比较"pair"的"first"成员。
			c.复杂度：常数级别。
*/

/**
	关联容器相关的非成员函数
		1.用于重载比较运算符的众多"operator"函数：按字典顺序比较容器中的值。
		2.特化标准库算法"swap"，使其支持容器的交换。
*/