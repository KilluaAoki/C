#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>

/*
	无序关联容器
		1.无序关联容器的介绍
		2.无序关联容器的使用
		3.无序关联容器的元素访问
		4.无序关联容器与容量和修改器相关的成员函数
		5.无序关联容器与查找相关的成员函数
		6.无序关联容器与桶接口相关的成员函数
		7.无序关联容器与哈希策略相关的成员函数
		8.无序关联容器与观察器相关的成员函数
		9.无序关联容器相关的非成员函数
*/

/**
	无序关联容器的介绍：C++11起，提供能快速查找(均摊"O(1)"复杂度 ，最坏情况"O(n)"复杂度)的无序(哈希)数据结构。
		1.四种无序关联容器
			a."unordered_set"类模板：唯一键的集合，按照键生成散列。
				a'.定义：template< class Key, class Hash = std::hash<Key>, class KeyEqual = std::equal_to<Key>, class Allocator = std::allocator<Key> > class unordered_set;。
				b'."unordered_set"是含有"Key"类型唯一对象集合的关联容器，其搜索、插入和移除拥有平均常数时间复杂度。
				c'.在内部，元素并不以任何特别顺序排序，而是组织进桶中。
					a''.元素被放进哪个桶完全依赖其值的哈希。
					b''.允许对单独元素的快速访问，因为哈希一旦确定，就准确指代元素被放入的桶。
				d'.不可修改容器元素(即使通过非"const"迭代器)，因为修改可能更改元素的哈希，并破坏容器。
				e'.其包含于头文件"unordered_set"中。
				f'.文档：https://zh.cppreference.com/w/cpp/container/unordered_set。
			b."unordered_map"类模板：键值对的集合，按照键生成散列，键是唯一的。
				a'.定义：template< class Key, class T, class Hash = std::hash<Key>, class KeyEqual = std::equal_to<Key>, class Allocator = std::allocator<Key> > class unordered_map;。
				b'."unordered_map"是无序关联容器，其含有带唯一键的键值对，其搜索、插入和元素移除拥有平均常数时间复杂度。
				c'.在内部，元素并不以任何特别顺序排序，而是组织进桶中。
					a''.元素被放进哪个桶完全依赖其值的哈希。
					b''.允许对单独元素的快速访问，因为哈希一旦确定，就准确指代元素被放入的桶。
				d'.其包含于头文件"unordered_map"中。
				f'.文档：https://zh.cppreference.com/w/cpp/container/unordered_map。
			c."unordered_multiset"类模板：键的集合，按照键生成散列。(类似于"unordered_set"，其含有可能非唯一"Key"类型对象的集合)
				a'.不要求此容器的遍历顺序稳定。
				b'.文档：https://zh.cppreference.com/w/cpp/container/unordered_multiset。
			d."unordered_multimap"类模板：键值对的集合，按照键生成散列。(类似于"unordered_map"，其支持等价的键(一个"unordered_multimap"可含有每个键值的多个副本)和将键与另一类型的值关联。
				a'.不要求此容器的遍历顺序稳定。
				b'.文档：https://zh.cppreference.com/w/cpp/container/unordered_multimap。
		2.无序关联容器的迭代器失效
			a."unordered_set"和"unordered_map"的所有只读操作以及"swap"和"std::swap"操作决不会使迭代器失效。
				a'."swap"函数不会使容器内的任何迭代器失效，但它们会使标记交换区域结尾的迭代器失效。
				b'.指向在容器中存储的键或元素的引用和指针只会因为擦除该元素而失效，即使对应迭代器失效。
			b."unordered_set"和"unordered_map"的"clear"、"rehash"、"reserve"以及"operator="操作将始终使迭代器失效。
			c."unordered_set"和"unordered_map"的"insert"以及"emplace"和"emplace_hint"操作只会在重哈希的情况下使迭代器失效。("unordered_map"的"operator[]"操作也包含在内)
			d."unordered_set"和"unordered_map"的"erase"操作只会使指向被擦除元素的迭代器失效。
*/

/**
	关联容器的使用
		1."unordered_set"类模板的使用
		2."unordered_map"类模板的使用
*/

/***
	"unordered_set"类模板的使用
		1."unordered_set"的常见构造函数的函数原型(以下部分函数原型忽略分号以及分配器等细节)
			a."unordered_set()"：默认构造函数，构造空容器，
				a'.另一默认构造函数形式：explicit unordered_set( size_type bucket_count, const Hash& hash = Hash(), const key_equal& equal = key_equal(), const Allocator& alloc = Allocator() )。
				b'.同时支持构造拥有给定分配器"alloc"的空容器：explicit unordered_set( const Allocator& alloc )。
				c'.设置"max_load_factor()"为"1.0"，而桶数是实现定义的。
				d'.复杂度为常数级别。
			b."template< class InputIt > unordered_set( InputIt first, InputIt last, size_type bucket_count = //根据定义实现, const Hash& hash = Hash(), const key_equal& equal = key_equal() )"：构造拥有范围"[first, last)"内容的容器。
				a'.如果范围中的多个元素的键比较相等，那么未指定哪个元素会被插入。
				b'.设置"max_load_factor()"为"1.0"。
				c'.复杂度：平均情况与"first"和"last"间的距离成线性，最坏情况成平方。
			c."unordered_set( const unordered_set& other )"：复制构造函数，构造拥"other"内容副本的容器，一同复制加载因子、谓词和哈希函数。
				a'.同时支持复制构造拥有给定分配器"alloc"的容器：unordered_set( const unordered_set& other, const Allocator& alloc )。
				b'.复杂度与"other"的大小成线性级别。
		2."unordered_set"的析构函数的函数原型：~unordered_set();。
			a.销毁"unordered_set"，调用元素的析构函数，然后解分配所用的存储(若元素是指针，则不销毁所指向的对象)。
			b.复杂度与"unordered_set"的大小成线性级别。
		3."unordered_set"的常见"operator="成员函数：unordered_set& operator=( const unordered_set& other );。
			a.复制赋值运算符，赋值给容器，即以"other"的副本替换内容。
			b.复杂度与"*this"和"other"的大小成线性级别。
*/

////"unordered_set"类模板的使用示例
//int main()
//{
//	std::vector<int> v{ 3, 1, 4, 6, 5, 9 };
//
//	//"unordered_set"的默认构造函数
//	std::unordered_set<int> hashSet1;
//
//	//"unordered_set"的范围构造函数
//	std::unordered_set<int> hashSet2(v.begin(), v.end());
//
//	//"unordered_set"的复制构造函数
//	std::unordered_set<int> hashSet3(hashSet2);
//
//	//"unordered_set"的赋值运算符
//	std::unordered_set<int> hashSet4;
//	hashSet4 = hashSet3;
//
//	//输出"unordered_set"的元素
//	for (auto& e: { hashSet1, hashSet2, hashSet3, hashSet4 })
//	{
//		for (auto& ee: e)
//		{
//			std::cout << ee << " ";
//		}
//		std::cout << std::endl;
//	}
//}

/***
	"unordered_map"类模板的使用
		1."unordered_map"的常见构造函数的函数原型(以下部分函数原型忽略分号以及分配器等细节)
			a."unordered_map()"：默认构造函数，构造空容器，
				a'.另一默认构造函数形式：explicit unordered_map( size_type bucket_count, const Hash& hash = Hash(), const key_equal& equal = key_equal(), const Allocator& alloc = Allocator() )。
				b'.同时支持构造拥有给定分配器"alloc"的空容器：explicit unordered_map( const Allocator& alloc )。
				c'.设置"max_load_factor()"为"1.0"，而桶数是实现定义的。
				d'.复杂度为常数级别。
			b."template< class InputIt > unordered_map( InputIt first, InputIt last, size_type bucket_count = //根据定义实现, const Hash& hash = Hash(), const key_equal& equal = key_equal() )"：构造拥有范围"[first, last)"内容的容器。
				a'.如果范围中的多个元素的键比较相等，那么未指定哪个元素会被插入。
				b'.设置"max_load_factor()"为"1.0"。
				c'.复杂度：平均情况与"first"和"last"间的距离成线性，最坏情况成平方。
			c."unordered_map( const unordered_map& other )"：复制构造函数，构造拥"other"内容副本的容器，一同复制加载因子、谓词和哈希函数。
				a'.同时支持复制构造拥有给定分配器"alloc"的容器：unordered_map( const unordered_map& other, const Allocator& alloc )。
				b'.复杂度与"other"的大小成线性级别。
		2."unordered_map"的析构函数的函数原型：~unordered_map();。
			a.销毁"unordered_map"，调用元素的析构函数，然后解分配所用的存储(若元素是指针，则不销毁所指向的对象)。
			b.复杂度与"unordered_map"的大小成线性级别。
		3."unordered_map"的常见"operator="成员函数：unordered_map& operator=( const unordered_map& other );。
			a.复制赋值运算符，赋值给容器，即以"other"的副本替换内容。
			b.复杂度与"*this"和"other"的大小成线性级别。
*/

////"unordered_map"类模板的使用示例
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
//	std::unordered_map<int, std::string> hashMap1;
//
//	//"map"的范围构造函数
//	std::unordered_map<int, std::string> hashMap2{ v.begin(), v.end() };
//
//	//"map"的复制构造函数
//	std::unordered_map<int, std::string> hashMap3(hashMap2);
//
//	//"map"的赋值运算符
//	std::unordered_map<int, std::string> hashMap4;
//	hashMap4 = hashMap3;
//
//	//输出"map"的元素
//	for (auto& e: { hashMap1, hashMap2, hashMap3, hashMap4 })
//	{
//		for (auto& ee: e)
//		{
//			std::cout << ee.first << " " << ee.second << std::endl;
//		}
//		std::cout << std::endl;
//	}
//}

/**
	无序关联容器的元素访问
		1."unordered_set"类模板的元素访问：支持正向迭代器访问，即"begin"、"end"、"cbegin"以及"cend"。
			a.因为"iterator"和"const_iterator"都是常迭代器(而且实际上可以是同一类型)，故不可能通过任何这些成员函数返回的迭代器修改容器元素。
		2."unordered_map"类模板的元素访问：同样支持正向迭代器访问，并且另外支持"at"和"operator[]"两种访问方式。
				a."at"成员函数：访问指定的元素，同时进行越界检查。
					a'.函数原型
						a''.T& at( const Key& key );。
						b''.const T& at( const Key& key ) const;。
					b'.返回到拥有等于"key"的关键的元素被映射值的引用，如果没有这种元素，那么抛出异常。
					c'.复杂度：平均为常数级别，最坏情况与容器大小成线性级别。
				b."operator[]"成员函数：访问或插入指定的元素。
					a'.常见函数原型：T& operator[]( const Key& key );。
						a''.在键不存在的情况下插入从"std::piecewise_construct, std::forward_as_tuple(key), std::tuple<>()"原位构造的"value_type"对象。
						b''.使用默认分配器时，这导致从"key"复制构造键，并值初始化被映射值。
					b'.返回到映射到等于"key"的键的值的引用，这种键不存在的情况下就会进行插入。
					c'.不存在拥有键"key"的元素时返回到新元素被映射值的引用，否则返回到既存的关键等价于"key"的元素的被映射值的引用。
					d'.如果任何操作抛出异常，那么插入无效果。
					e'."operator[]"非"const"，因为它会在键不存在时插入键，如果此行为非所需或容器为"const"，那么可以使用"at()"。
					f'.复杂度：平均为常数级别，最坏情况与容器大小成线性级别。
*/

////无序关联容器的元素访问示例一："unordered_set"类模板的元素访问。
//int main()
//{
//	std::unordered_set<int> unorderedSet{ 3, 1, 4, 6, 5, 9 };
//
//	for (auto it = unorderedSet.begin(); it != unorderedSet.end(); ++it)
//	{
//		std::cout << *it << " ";
//	}
//	std::cout << std::endl;
//}

////无序关联容器的元素访问示例二："unordered_map"类模板的元素访问。
//int main()
//{
//	std::unordered_map<int, char> unordered_map{{ 65, 'A' },
//												{ 66, 'B' },
//												{ 67, 'C' },
//												{ 68, 'D' },
//												{ 69, 'E' },
//												{ 70, 'F' }};
//
//	for (auto& it: unordered_map)
//	{
//		std::cout << it.first << "-" << it.second << " ";
//	}
//	std::cout << std::endl;
//
//	unordered_map[71] = 'G';
//
//	for (auto& it: unordered_map)
//	{
//		std::cout << it.first << "-" << it.second << " ";
//	}
//	std::cout << std::endl;
//}

/**
	无序关联容器与容量和修改器相关的成员函数
		1."unordered_set"类模板和"unordered_map"类模板与容量相关的成员函数，其均支持以下成员函数，且用法相同：
			a."empty"成员函数：检查容器是否为空。
			b."size"成员函数：返回容纳的元素数。
			c."max_size"成员函数：返回可容纳的最大元素数。
		2."unordered_set"类模板和"unordered_map"类模板与修改器相关的成员函数，其均支持以下成员函数(不包含C++17起、C++23起以及原位构造相关函数)：
			a."clear"成员函数：清除内容，两容器用法相同。
			b."swap"成员函数：交换内容，两容器用法相同。
			c."unordered_set"类模板和"unordered_map"类模板的"insert"成员函数：用于插入元素，在C++17起支持插入节点(暂不介绍)。
				a'.常见函数原型
					a''.std::pair<iterator,bool> insert( const value_type& value );。
						a'''.插入"value"，即要插入的元素值。
						b'''.返回由指向被插入元素(或阻止插入的元素)的迭代器和只会在插入发生时是"true"的"bool"值组成的"pair"。
						c'''.复杂度：平均情况"O(1)"，最坏情况"O(size())"。
					b''.iterator insert( const_iterator hint, const value_type& value );。
						a'''.插入"value"，以"hint"作为应当开始搜索的位置的非强制建议。
						b'''.返回指向被插入元素，或阻止插入的元素的迭代器。
						c'''.复杂度：平均情况"O(1)"，最坏情况"O(size())"。
					c''.template< class InputIt > void insert( InputIt first, InputIt last );。
						a'''.插入来自范围"[first, last)"的元素，如果范围中的多个元素的键比较相等，那么未指定插入哪个元素。
						b'''.如果"[first, last)"不是有效范围，或者"first"或"last"是指向"*this"中的迭代器，那么行为未定义。
						c'''.复杂度：平均情况"O(N)"，其中"N"是要插入的元素数，最坏情况"O(N * size() + N)"。
				b'.如果容器尚未含有带等价键的元素，那么就会将元素插入到容器中。
				c'."unordered_set"类模板和"unordered_map"类模板的"insert"成员函数在上述所列的常见成员函数是类似的，但"unordered_map"类模板其实具有更多的函数原型。
			d."unordered_set"类模板和"unordered_map"类模板的"erase"成员函数：擦除元素。
				a'.常见函数原型
					a''.iterator erase( iterator pos );。
						a'''.移除位于"pos"的元素。
						b'''.返回后随最后被移除的元素的迭代器。
						c'''.复杂度(给定实例"c")：平均情况下为常数级别，最坏情况下为"c.size()"。
					b''.iterator erase( const_iterator first, const_iterator last );。
						a'''.移除范围"[first, last)"的元素，它必须是"*this"的合法范围。
						b'''.返回后随最后被移除的元素的迭代器。
						c'''.复杂度(给定实例"c")：平均情况下为"std::distance(first, last)"，最坏情况下为"c.size()"。
					c''.size_type erase( const Key& key );。
						a'''.移除键等价于"key"的元素(如果存在一个)。
						b'''.返回被移除的元素个数。
						c'''.复杂度(给定实例"c")：平均情况下为"c.count(key)"，最坏情况下为"c.size()"。
				b'.从容器移除指定的元素，保留未被移除的元素的顺序(这使得可能在迭代通过容器时移除单独的元素)。
				c'.指向被擦除元素的引用和迭代器会失效，其他引用和迭代器不受影响。
				d'.迭代器"pos"必须合法且可解引用，从而"end"成员函数返回的迭代器即使合法，但其不可解引用，故不能用作"pos"所用的值。
*/

////无序关联容器与容量和修改器相关的成员函数示例："insert"成员函数和"erase"成员函数的使用。
//int main()
//{
//	std::unordered_map<int, std::string> c{{ 1, "one" },
//										   { 2, "two" },
//										   { 3, "three" },
//										   { 4, "four" },
//										   { 5, "five" },
//										   { 6, "six" }};
//
//	//删除对象中的所有奇数
//	for (auto it = c.begin(); it != c.end();)
//	{
//		if (it->first % 2 != 0)
//			it = c.erase(it);
//		else
//			++it;
//	}
//
//	for (auto& p: c)
//		std::cout << p.first << "-" << p.second << ' ';
//	std::cout << "\n";
//
//	c.insert(std::make_pair(10, "ten"));
//
//	for (auto& p: c)
//		std::cout << p.first << "-" << p.second << ' ';
//	std::cout << "\n";
//}

/**
	无序关联容器与查找相关的成员函数(不包括C++20起支持的成员函数)
		1."count"成员函数：返回匹配特定键的元素数量。("unordered_set"类模板和"unordered_map"类模板类似)
			a.常见函数原型：size_type count( const Key& key ) const;。
			a.在"unordered_set"类模板和"unordered_map"类模板中，不允许重复的键，故返回值只能是"0"或"1"(仅对于常见函数原型)。
			b.在"unordered_multiset"类模板和"unordered_multimap"类模板中，允许重复的键，故返回值可以是"0"或大于等于"1"(仅对于常见函数原型)。
			c.复杂度：平均为常数级别，最坏情况与容器大小成线性级别。
		2."find"成员函数：寻找带有特定键的元素。("unordered_set"类模板和"unordered_map"类模板类似)
			a.常见函数原型
				a'.iterator find( const Key& key );。
				b'.const_iterator find( const Key& key ) const;。
			b.寻找键等于"key"的元素(仅对于常见函数原型)。
			c.返回指向键等于"key"的元素的迭代器，若找不到这种元素，则返回"end"成员函数返回的迭代器。
			d.复杂度：平均为常数级别，最坏情况与容器大小成线性级别。
		3."equal_range"成员函数：返回匹配特定键的元素范围。("unordered_set"类模板和"unordered_map"类模板类似)
			a.常见函数原型
				a'.std::pair<iterator, iterator> equal_range( const Key& key );。
				b'.std::pair<const_iterator, const_iterator> equal_range( const Key& key ) const;。
			b.返回容器中所有拥有给定关键的元素范围，范围以二个迭代器定义，第一个指向所需范围的首元素，而第二个指向范围的尾后一位元素。
			c.返回含一对定义所需范围的迭代器的"pair"对象。若无这种元素，则将"end()"作为"pair"的两个元素返回。
			d.复杂度：平均情况与带关键"key"的元素数成线性级别，最坏情况与容器大小成线性级别。
*/

////无序关联容器与查找相关的成员函数示例："equal_range"成员函数的使用。
//int main()
//{
//	std::unordered_map<int, char> unordered_map = {{ 1, 'a' },
//												   { 1, 'b' },
//												   { 1, 'd' },
//												   { 2, 'b' }};
//	auto range = unordered_map.equal_range(1);
//	for (auto it = range.first; it != range.second; ++it)
//	{
//		std::cout << it->first << ' ' << it->second << '\n';
//	}
//}

/**
	无序关联容器与桶接口相关的成员函数(不包括C++20起支持的成员函数)
		1."begin"、"end"、"cbegin"以及"cend"成员函数：返回一个迭代器，指向指定的桶的开始或者结束。(重载迭代器函数，使其适用于桶接口函数)
			a.函数原型
				a'.local_iterator begin( size_type n );。
				b'.const_local_iterator begin( size_type n ) const;
				c'.const_local_iterator cbegin( size_type n ) const;
				d'.local_iterator end( size_type n );
				e'.const_local_iterator end( size_type n ) const;
				f'.const_local_iterator cend( size_type n ) const;
			b.函数原型中，参数"n"表示要访问的桶的下标。
			c.返回值
				a'.对于"begin"和"cbegin"成员函数，返回指向下标为"n"的桶首元素的迭代器。
				b'.对于"end"和"cend"成员函数，返回后随下标为"n"的桶的最后元素的元素的迭代器(此元素表现为占位符，试图访问它会导致未定义行为)。
		2."bucket_count"成员函数：返回桶数。
			a.函数原型：size_type bucket_count() const;。
			b.返回容器中的桶数。
		3."max_bucket_count"成员函数：返回桶的最大数量。
			a.函数原型：size_type max_bucket_count() const;。
			b.返回容器由于系统或库实现限制的能保有的最大桶数。
		4."bucket_size"成员函数：返回在特定的桶中的元素数量。
			a.函数原型：size_type bucket_size( size_type n ) const;。
			b.返回下标为"n"的桶中的元素数，其中"n"表示要检验的桶的下标。
			c.复杂度：与桶"n"的大小成线性。
		5."bucket"成员函数：返回带有特定键的桶。
			a.函数原型：size_type bucket( const Key& key ) const;。
			b.返回关键"key"的桶的下标，始终会在此桶中找到关键等于"key"的元素(若存在)，返回值仅对"bucket_count()"返回相同值的容器实例合法。
			c.若"bucket_count()"为零则行为未定义。
*/

/**
	关联容器与哈希策略相关的成员函数
		1."load_factor"成员函数：返回每个桶的平均元素数量。
			a.函数原型：float load_factor() const;。
			b.返回每个桶元素的平均数，即"size()"除以"bucket_count()"。
		2."max_load_factor"成员函数：管理每个桶的平均元素数量的最大值。
			a.函数原型
				a'.float max_load_factor() const;。
					a''.返回最大加载因子。
				b'.void max_load_factor( float ml );。
					a''.设置最大加载因子为"ml"。
			b.管理最大加载因子(每个桶的平均元素数)，若加载因子超出此阈值，则容器自动增加桶数。
		3."rehash"成员函数：为至少为指定数量的桶预留存储空间并重新生成散列表。
			a.函数原型：void rehash( size_type count );。
			b.设置新的桶数为"count"并重哈希容器，即考虑桶总数已改变，再把元素放到适当的桶中。
			c.若新的桶数使加载因子大于最大加载因子("count < size() / max_load_factor()")，则新桶数至少为"size() / max_load_factor()"。
			d."rehash(0)"可用于强制无条件的重哈希，例如在通过临时增加"max_load_factor()"暂停自动重哈希之后。
			e.复杂度：平均与容器大小成线性级别，最坏情况成平方级别。
		4."reserve"成员函数：为至少为指定数量的元素预留存储空间并重新生成哈希表。
			a.函数原型：void reserve( size_type count );。
			b.设置桶数为适应至少"count"个元素，而不超出最大加载因子所需的数，并重哈希容器，即考虑桶数已更改后将元素放进适合的桶。
			c.等效地调用"rehash(std::ceil(count / max_load_factor()))"。
			d.复杂度：平均与容器大小成线性级别，最坏情况成平方级别。
*/

/**
	关联容器与观察器相关的成员函数
		1."hash_function"成员函数：返回用于对键散列的函数。
			a.函数原型：hasher hash_function() const;。
			b.返回对关键哈希的函数。
		2."key_eq"成员函数：返回用于比较键的相等性的函数。
			a.函数原型：key_equal key_eq() const;。
			b.返回比较关键相等性的函数。
*/

/**
	关联容器相关的非成员函数(不包含C++20起支持的函数)
		1."operator=="函数以及"operator!="函数：比较二个无序容器的内容。(C++20起"!="运算符从"=="运算符合成)
		2.特化标准库算法"swap"，使其支持容器的交换。
*/