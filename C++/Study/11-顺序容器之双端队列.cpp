#include <iostream>
#include <deque>
#include <cassert>

/*
	顺序容器之双端队列
		1."deque"类模板的介绍
		2."deque"类模板的使用
		3."deque"类模板的元素访问
		4."deque"类模板中与容量相关的成员函数
		5."deque"类模板中与修改器相关的成员函数
		6."deque"类模板相关的非成员函数
*/

/**
	"deque"类模板的介绍："std::deque"是有下标顺序容器，它允许在它的首尾两端快速插入及删除，定义于头文件"deque"中，简称为"deque"。
		1."deque"的定义与特性
			a."deque"是一个类模板，它的定义为：template< class T, class Allocator = std::allocator<T> > class deque;。
				a'."T"是元素的类型。
				b'."Allocator"用于获取或释放内存及构造或析构内存中元素的分配器，此阶段暂不考虑此模板形参。
			b."deque"是一个双端队列，在"deque"任一端插入或删除不会使指向其余元素的指针或引用失效。
			c.与"vector"相反，"deque"的元素不是相接存储的，以下是它的典型实现：
				a'.用单独分配的固定尺寸数组的序列，外加额外的登记，这表示下标访问必须进行二次指针解引用，与之相比"vector"的下标访问只进行一次。
				b'."deque"的存储按需自动扩展及收缩，扩张"deque"比扩张"vector"更优，因为它不涉及到复制已存元素到新内存位置。
				c'."deque"典型地拥有较大的最小内存开销，比如：只保有一个元素的"deque"必须分配它的整个内部数组。
				d'.虽然可以通过双链表实现双端队列，但双端队列的实现通常是以指针数组为基础实现的，这样的好处是内存使用率较低，并且可以以相当高的效率进行随机访问。
			d.双端队列确实允许在容器的两端添加和删除值，但它通常不用于此类操作，而是用作更灵活的向量版本。
			e.双端队列支持随机访问，并且可以在任何地方插入元素，而不仅仅是在前面和后面。
			f."deque"常见操作的时间复杂度(效率)
				a'.随机访问：常数级别时间复杂度，即"O(1)"。
				b'.在结尾或起始插入或移除元素：常数级别时间复杂度，即"O(1)"。
				c'.插入或移除元素：线性级别时间复杂度，即"O(n)"。
			g.对于"deque"容器的迭代器失效问题(不讨论引用)
				a'.使用标准算法库中的"swap"函数模板对"deque"类模板的特化以及"deque"中的"swap"成员函数，可能使"end"成员函数返回的迭代器失效(由实现定义)。
				b'.使用"clear"成员函数、"shrink_to_fit"成员函数(C++11)，将始终使所有迭代器失效。
				c'.使用"insert"成员函数、"emplace"成员函数(C++11)，将始终使所有迭代器失效。
				d'.使用"push_front"成员函数、"push_back"成员函数、"emplace_front"成员函数(C++11)、"emplace_back"成员函数(C++11)，将始终使所有迭代器失效。
				e'.使用"erase"成员函数
					a''.如果在起始擦除元素(尾元素未被擦除)，那么只有指向被擦除元素的迭代器失效。
					b''.如果在末尾擦除元素，那么只有指向被擦除元素的迭代器和尾后迭代器失效(C++11起：指明尾后迭代器处于此条件下将会失效)。
					c''.否则所有迭代器失效。
				f'.使用"resize"成员函数
					a''.如果新尺寸小于旧尺寸，那么只有指向被擦除元素的迭代器和尾后迭代器失效。
					b''.如果新尺寸大于旧尺寸，那么所有迭代器失效。
					c''.否则无迭代器失效。
				g'.使用"pop_front"成员函数，将使指向被擦除元素的迭代器失效，如果元素是容器的最后元素，那么尾后迭代器也会失效(C++11起)。
				h'.使用"pop_back"成员函数，将使指向被擦除元素的迭代器和尾后迭代器失效。
		2."deque"的常见成员类型(省略分配器相关的类型和逆向迭代器相关的类型)
			a."value_type"成员类型：定义为"deque"的模板形参"T"。
			b."size_type"成员类型：无符号整数类型，通常定义为"std::size_t"。
			c."difference_type"成员类型：有符号整数类型，通常定义为"std::ptrdiff_t"。
			d."reference"成员类型：定义为"deque"的模板形参"T"的左值引用类型，即"value_type&"。
			e."const_reference"成员类型：定义为"deque"的模板形参"T"的常量左值引用类型，即"const value_type&"。
			f."iterator"成员类型：定义为指向"value_type"的迭代器类型。
			g."const_iterator"成员类型：定义为指向"const value_type"的迭代器类型。
*/

/**
	"deque"类模板的使用
		1."deque"的常见构造函数的函数原型(以下部分函数原型忽略命名空间、分号以及分配器等)
			a."explicit deque()"：默认构造函数，构造拥有默认构造的分配器的空容器，即空的"deque"。(C++14前)
				a'.在C++14起，此构造函数被分为两个构造函数：默认构造函数和拥有给定分配器的空容器的构造函数。
					a''.默认构造函数：deque()。
					b''.构造拥有给定分配器"alloc"的空容器：explicit deque(const Allocator& alloc)。
				b'.复杂度为常数级别。
			b."explicit deque( size_type count, const T& value = T())"：构造拥有"count"个有值"value"的元素的容器。(C++11前)
				a'.在C++11起，此函数的原型为：deque( size_type count, const T& value)。
				b'.复杂度与"count"成线性级别。
			c."template< class InputIt > deque( InputIt first, InputIt last)"：构造拥有范围"[first, last)"内容的容器。
				a'.复杂度与"first"和"last"的距离成线性级别。
			d."deque( const deque& other )"：复制构造函数，构造拥有"other"内容的容器。
				a'.复杂度与"other"的大小成线性级别。
		2."deque"的析构函数的函数原型：~deque();。
			a.销毁"deque"，调用元素的析构函数，然后解分配所用的存储(若元素是指针，则不销毁所指向的对象)。
			b.复杂度与"deque"的大小成线性级别。
		3."deque"赋值相关成员函数
			a."operator="成员函数：赋值给容器，即替换容器内容。
				a'.常见函数原型：deque& operator=( const deque& other );。
					a''.拷贝赋值运算符，以"other"的副本替换内容。
					b''.返回值：*this。
					c''.复杂度与"*this"和"other"的大小成线性级别。
					d''.可能抛出实现定义的异常。
			b."assign"成员函数：将值赋给容器，即替换容器的内容。
				a'.常见函数原型
					a''.void assign( size_type count, const T& value );。
						a'''.以"count"份"value"的副本替换内容。
						b'''.复杂度与"count"成线性级别。
					b''.template< class InputIt > void assign( InputIt first, InputIt last );。
						a'''.以范围"[first, last)"中元素的副本替换内容，若任一参数是指向"*this"中的迭代器则行为未定义。
						b'''.复杂度与"first"和"last"间的距离成线性级别。
				b'.所有指向容器元素的迭代器、指针及引用均被非法化。
*/

////"deque"类模板的使用示例一：使用"deque"的常见构造函数。
//int main()
//{
//	//默认构造函数，调用函数原型为：deque();。(C++14起)
//	std::deque<int> v1;//创建一个空的"deque"，其元素类型为"int"。
//	assert(v1.empty() && (v1.size() == 0));//断言结果均为真。
//
//	//构造拥有"count"个有值"value"的元素的容器，调用函数原型为：deque( size_type count, const T& value);。(C++11起)
//	std::deque<int> v2(5, 1);//创建一个拥有"5"个元素的"deque"，其元素类型为"int"，且每个元素的值均为"1"。
//	for (auto i: v2)
//	{
//		std::cout << i << " ";
//	}
//	std::cout << std::endl;
//
//	//构造拥有范围"[first, last)"内容的容器，调用函数原型为：template< class InputIt > deque( InputIt first, InputIt last);。
//	std::deque<int> v3(v2.begin(), v2.end());//创建一个拥有"v2"内容的"deque"，其元素类型为"int"。
//	for (auto i: v3)
//	{
//		std::cout << i << " ";
//	}
//	std::cout << std::endl;
//
//	//复制构造函数，调用函数原型为：deque( const deque& other );。
//	std::deque<int> v4(v3);//创建一个拥有"v3"内容的"deque"，其元素类型为"int"。
//	for (auto i: v4)
//	{
//		std::cout << i << " ";
//	}
//	std::cout << std::endl;
//
//	return 0;
//}

////"deque"类模板的使用示例二：使用"operator="成员函数。
//int main()
//{
//	std::deque<int> v1(5, 1);
//	std::deque<int> v2(3, 2);
//	std::deque<int> v3(2, 3);
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

////"deque"类模板的使用示例三：使用"assign"成员函数。
//int main()
//{
//	std::deque<int> v1(5, 1);
//	std::deque<int> v2(3, 2);
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
	"deque"类模板的元素访问
		1."[]"下标成员访问运算符：访问指定的元素。
			a.函数原型
				a'.reference operator[]( size_type pos );。
				b'.const_reference operator[]( size_type pos ) const;。
			b.参数"pos"表示要返回的元素的位置。
			c.返回值为到所需元素的引用，即返回位于指定位置"pos"的元素的引用，不进行边界检查。
			d.此运算符决不插入新元素到容器，并且通过此运算符访问不存在的元素是未定义行为。
			e.复杂度为常数级别。
		2."at"成员函数：访问指定的元素，同时进行越界检查。
			a.函数原型
				a'.reference at( size_type pos );。
				b'.const_reference at( size_type pos ) const;。
			b.返回位于指定位置"pos"的元素的引用，有边界检查。
			c.复杂度为常数级别。
			d.若"!(pos < size())"为真，则抛出异常。
		3."front"成员函数：访问第一个元素。
			a.函数原型
				a'.reference front();。
				b'.const_reference front() const;。
			b.返回到容器首元素的引用，在空容器上调用此函数是未定义的。
			c.复杂度为常数级别。
			d.对于一个容器"c"，表达式"c.front()"等价于表达式"*c.begin()"。
		4."back"成员函数：访问最后一个元素。
			a.函数原型
				a'.reference back();。
				b'.const_reference back() const;。
			b.返回到容器中最后一个元素的引用，在空容器上调用此函数将导致未定义行为。
			c.复杂度为常数级别。
		3.使用"deque"中的迭代器
			a."begin"成员函数：返回指向起始的迭代器。
				a'.函数原型(C++11前)
					a''.iterator begin();。
					b''.const_iterator begin() const;。
				b'.返回指向"deque"首元素的迭代器，若"deque"为空，则返回的迭代器将等于"end"成员函数的返回值。
				c'.复杂度为常数级别。
			b."end"成员函数：返回指向末尾的迭代器。
				a'.函数原型(C++11前)
					a''.iterator end();。
					b''.const_iterator end() const;。
				b'.返回指向"deque"末元素后一元素的迭代器，此元素表现为占位符，试图访问它导致未定义行为。
				c'.复杂度为常数级别。
			c."rbegin"成员函数：返回指向起始的逆向迭代器。
				a'.函数原型(C++11前)
					a''.reverse_iterator rbegin();。
					b''.const_reverse_iterator rbegin() const;。
				c'.返回指向逆向"deque"首元素的逆向迭代器，它对应非逆向"deque"的末元素，若"deque"为空，则返回的迭代器等于"rend"成员函数的返回值。
				d'.复杂度为常数级别。
			d."rend"成员函数：返回指向末尾的逆向迭代器。
				a'.函数原型(C++11前)
					a''.reverse_iterator rend();。
					b''.const_reverse_iterator rend() const;。
				b'.返回指向逆向"deque"末元素后一元素的逆向迭代器，它对应非逆向"deque"首元素的前一元素，此元素表现为占位符，试图访问它会导致未定义行为。
				c'.复杂度为常数级别。
			e.C++11起支持的"cbegin"成员函数和"cend"成员函数以及"crbegin"成员函数和"crend"成员函数：除成员函数名不相同外，等价分别对应于没有"c"前缀的返回不可变的迭代器的成员函数(如："cbegin"成员函数等价于返回不可变的迭代器的"begin"成员函数)。
*/

////"deque"类模板的元素访问示例一：使用"[]"下标成员访问运算符。
//int main()
//{
//	std::deque<int> v1(10, 1);
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

////"deque"类模板的元素访问示例二：使用"at"成员函数访问元素。
//int main()
//{
//	std::deque<int> data(6, 0);
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

////"deque"类模板的元素访问示例三：使用"front"成员函数和"back"成员函数。
//int main()
//{
//	std::deque<int> v1(10, 1);
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
//
//	return 0;
//}

////"deque"类模板的元素访问示例四：使用迭代器遍历"deque"容器中的元素(正向与逆向)。
//int main()
//{
//	std::deque<int> v(10, 1);
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
	"deque"类模板中与容量相关的成员函数
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
		4."shrink_to_fit"成员函数：通过释放未使用的内存减少内存的使用，即请求移除未使用的容量。(C++11)
			a.函数原型：void shrink_to_fit();。
			b.此函数是减少使用内存而不更改序列的大小非强制性请求，请求是否达成依赖于实现。
			c.所有迭代器和引用都会失效，包括尾后迭代器。
			d.复杂度至多与容器大小成线性级别。
*/

////"deque"类模板的容量相关成员函数示例一：使用"empty"成员函数。
//int main()
//{
//	std::deque<int> v1;
//	std::deque<int> v2(10, 1);
//
//	std::cout << "v1.empty() = " << v1.empty() << std::endl;
//	std::cout << "v2.empty() = " << v2.empty() << std::endl;
//
//	return 0;
//}

////"deque"类模板的容量相关成员函数示例二：使用"size"成员函数和"max_size"成员函数。
//int main()
//{
//	std::deque<int> v1;
//	std::deque<int> v2(10, 1);
//
//	std::cout << "v1.size() = " << v1.size() << std::endl;
//	std::cout << "v2.size() = " << v2.size() << std::endl;
//
//	std::cout << "v1.max_size() = " << v1.max_size() << std::endl;
//	std::cout << "v2.max_size() = " << v2.max_size() << std::endl;
//
//	return 0;
//}

////"deque"类模板的容量相关成员函数示例三：使用"shrink_to_fit"成员函数。
//int main()
//{
//	std::deque<int> nums(1000, 100);
//
//	nums.push_front(0);
//	nums.pop_front();
//
//	nums.clear();//"nums"现在不含项目，但它仍保有分配的内存。
//
//	nums.shrink_to_fit();//调用"shrink_to_fit"可能会释放任何不使用的内存。
//
//	return 0;
//}

/**
	"deque"类模板中与修改器相关的成员函数(暂不介绍C++11起支持的"emplace"、"emplace_back"和"emplace_front"成员函数)
		1."clear"成员函数：清除内容。
			a.函数原型：void clear();。(C++11前)
			b.从容器擦除所有元素，调用此函数后"size"成员函数返回零。
			c.非法化任何指代所含元素的引用、指针或迭代器，包括任何尾后迭代器也都会失效。
			d.复杂度与当前容器的大小，即元素数成线性级别。
		2."insert"成员函数：插入元素，即插入元素到容器中的指定位置，常见函数原型如下：
			a.iterator insert( const_iterator pos, const T& value );。
				a'.在"pos"前插入一个值为"value"的元素，其中"pos"指代将内容插入到它前面的迭代器("pos"可以是"end"成员函数返回的迭代器)。
				b'.返回指向被插入"value"的迭代器。
				c'.复杂度为常数级别，加上与"pos"和容器两端距离的较小者成线性级别。
			b.iterator insert( const_iterator pos, size_type count, const T& value );。
				a'.在"pos"前插入"count"个值为"value"的副本。
				b'.返回指向首个被插入元素的迭代器，或者在"count == 0"时返回"pos"。
				c'.复杂度与"count"成线性级别，加上与"pos"和容器两端距离的较小者成线性级别。
			c.template< class InputIt > iterator insert( const_iterator pos, InputIt first, InputIt last );。
				a'.在"pos"前插入来自范围"[first, last)"中的元素，其中"first"和"last"指代要插入的元素范围，如果"first"和"last"是指向"*this"中的迭代器，那么行为未定义。
				b'.返回指向首个被插入元素的迭代器，或者在"first == last"时返回"pos"。
				c'.复杂度与"std::distance(first, last)"(从"first"走到"last"所需的自增数)成线性级别，加上与"pos"和容器两端距离的较小者成线性级别。
		3."erase"成员函数：擦除元素，即从容器擦除指定的元素。
			a.函数原型(C++11前)
				a'.iterator erase( iterator pos );。
					a''.移除位于"pos"的元素，其中"pos"是指向要移除的元素的迭代器。
					b''.在C++11起，此函数的原型为：iterator erase( const_iterator pos );。
					c''.迭代器"pos"必须合法且可解引用，因此不能以"end"成员函数返回的迭代器(即使合法，但其依旧不可解引用)作为"pos"的值。
					d''.返回值为最后移除元素之后的迭代器，如果"pos"指代末元素，那么返回"end()"迭代器。
				b'.iterator erase( iterator first, iterator last );。
					a''.移除范围"[first, last)"中的元素，其中"first"和"last"指代要移除的元素范围。
					b''.在C++11起，此函数的原型为：iterator erase( const_iterator first, const_iterator last );。
					c''.如果"first == last"，那么迭代器"first"不需要可解引用：擦除空范围是无操作。
					d''.返回值为最后移除元素之后的迭代器。
						a'''.如果在移除前"last == end()"，那么返回更新的"end"成员函数返回的迭代器。
						b'''.如果范围"[first, last)"为空，那么返回"last"。
			b.所有迭代器和引用都会失效，除非被擦除的元素在容器的开头或末尾，此时只有指向被擦除元素的迭代器或引用会失效。
				a'.C++11前：未指明尾后迭代器是否会失效。
				b'.C++11起：尾后迭代器也会失效，除非被擦除元素在容器开头，而尾元素未被擦除。
			c.复杂度为线性级别：调用"T"析构函数的次数与被擦除的元素数相同，调用"T"赋值运算符的次数不多于被擦除元素前的元素数和被擦除元素后的元素数。
		4."push_back"成员函数：将元素添加到容器末尾，即后附给定元素到容器尾。
			a.常见函数原型：void push_back( const T& value );。
				a'.初始化新元素为"value"的副本，其中"value"是要后附的元素值。
			b.所有迭代器(包含尾后迭代器)都会失效，但没有引用会失效。
			c.复杂度为常数级别。
			d.若此函数抛出异常，则此函数无效果(强异常保证)。
		5."pop_back"成员函数：移除末元素，即移除容器的末元素。
			a.函数原型：void pop_back();。
			b.在空容器上调用"pop_back"导致未定义行为。
			c.关于此函数的迭代器和引用失效规则
				a'.C++11前：指向被擦除元素的迭代器和引用会失效，但未指明尾后迭代器是否会失效，其他迭代器和引用不受影响。
				b'.C++11起：指向被擦除元素的迭代器和引用会失效，并且尾后迭代器也会失效，其他迭代器和引用不受影响。
			d.复杂度为常数级别。
			e.不抛出异常。
		6."push_front"成员函数：插入元素到容器起始，即前附给定元素到容器起始。
			a.常见函数原型：void push_front( const T& value );。
			b.所有迭代器(包含尾后迭代器)都会失效，但没有引用会失效。
			c.复杂度为常数级别。
			d.若此函数抛出异常，则此函数无效果(强异常保证)。
		7."pop_front"成员函数：移除首元素，即移除容器首元素。
			a.函数原型：void pop_front();。
			b.若容器中无元素，则行为未定义。
			c.关于此函数的迭代器和引用失效规则
				a'.C++11前：指向被擦除元素的迭代器和引用会失效，如果该元素是容器中的最后元素，那么未指明尾后迭代器是否会失效，其他迭代器和引用不受影响。
				b'.C++11起：指向被擦除元素的迭代器和引用会失效，如果该元素是容器中的最后元素，那么尾后迭代器也会失效，其他迭代器和引用不受影响。
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
			a.函数原型(C++17前)：void swap( deque& other );。
			b.将内容与"other"的交换，不在单独的元素上调用任何移动、复制或交换操作，其中"other"是要与之交换内容的容器。
			c.所有迭代器和引用保持有效，而尾后迭代器会失效。
			d.复杂度为常数级别。
*/

////"deque"类模板中与修改器相关的成员函数示例一：使用"clear"成员函数。
//int main()
//{
//	std::deque<int> container(10, 100);
//
//	std::cout << "container of v: " << container.size() << std::endl;
//
//	container.clear();
//
//	std::cout << "container of v: " << container.size() << std::endl;
//
//	return 0;
//}

////"deque"类模板中与修改器相关的成员函数示例二：使用"insert"成员函数。
//void print(int id, const std::deque<int>& container)
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
//	std::deque<int> c1(3, 100);
//	print(1, c1);
//
//	auto it = c1.begin();
//	it = c1.insert(it, 50);
//	print(2, c1);
//
//	c1.insert(it, 2, 0);
//	print(3, c1);
//
//	it = c1.begin();
//
//	std::deque<int> c2(2, -100);
//	c1.insert(it, c2.begin(), c2.end());
//	print(4, c1);
//
//	return 0;
//}

////"deque"类模板中与修改器相关的成员函数示例三：使用"erase"成员函数。
//void print_container(const std::deque<int>& c)
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
//	std::deque<int> c;
//
//	for (int i = 0; i < 10; ++i)
//	{
//		c.push_back(i);
//	}
//	print_container(c);
//
//	c.erase(c.begin());
//	print_container(c);
//
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
//	return 0;
//}

////"deque"类模板中与修改器相关的成员函数示例四：使用"push_back"成员函数、"pop_back"成员函数、"push_front"成员函数、"pop_front"成员函数。
//int main()
//{
//	std::deque<std::string> letters;
//
//	letters.push_back("---");
//
//	letters.push_front("123");
//	letters.push_front("456");
//	letters.push_back("abc");
//	letters.push_back("def");
//
//	std::cout << "letters: ";
//	for (const std::string& x: letters)
//	{
//		std::cout << x << ' ';
//	}
//	std::cout << '\n';
//
//	letters.pop_back();
//	letters.pop_front();
//
//	std::cout << "letters: ";
//	for (const std::string& x: letters)
//	{
//		std::cout << x << ' ';
//	}
//	std::cout << '\n';
//
//	return 0;
//}

////"deque"类模板中与修改器相关的成员函数示例五：使用"resize"成员函数。
//int main()
//{
//	std::deque<int> c(3, 10);
//	std::cout << "deque 持有：";
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
//	return 0;
//}

////"deque"类模板中与修改器相关的成员函数示例六：使用"swap"成员函数。
//int main()
//{
//	std::deque<int> v1(5, 10);
//	std::deque<int> v2(10, 5);
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
//	return 0;
//}

/**
	"deque"类模板相关的非成员函数(常见)
		1.按照字典顺序比较"deque"中的值(函数模板)。
			a.将各个用于比较的运算符进行重载，以便于比较二个"deque"的内容。
			b.常见函数原型(省略了模板声明、模板参数、分配器和命名空间等细节)
				a'.bool operator==( const deque& lhs, const deque& rhs );。
					a''.若"deque"内容相等则为"true"，否则为"false"。
				b'.bool operator!=( const deque& lhs, const deque& rhs );。(C++20前)
					a''.若"deque"内容不相等则为"true"，否则为"false"。
				c'.bool operator<( const deque& lhs, const deque& rhs );。(C++20前)
					a''.若"lhs"的内容按字典序小于"rhs"的内容则为"true"，否则为"false"。
				d'.bool operator<=( const deque& lhs, const deque& rhs );。(C++20前)
					a''.若"lhs"的内容按字典序小于或等于"rhs"的内容则为"true"，否则为"false"。
				e'.bool operator>( const deque& lhs, const deque& rhs );。(C++20前)
					a''.若"lhs"的内容按字典序大于"rhs"的内容则为"true"，否则为"false"。
				f'.bool operator>=( const deque& lhs, const deque& rhs );。(C++20前)
					a''.若"lhs"的内容按字典序大于或等于"rhs"的内容则为"true"，否则为"false"。
			c.运算符"=="以及"!="意为检查"lhs"与"rhs"的内容是否相等，即它们是否拥有相同数量的元素且"lhs"中每个元素与"rhs"的同位置元素比较相等。
				a'.这些运算符的复杂度为：若"lhs"与"rhs"的大小不同则为常数级别，否则与"deque"的大小成线性级别。
			d.运算符"<"、"<="、">"以及">="意为按字典序比较"lhs"与"rhs"的内容。
				a'.这些运算符的复杂度与"deque"的大小成线性级别。
		2."swap"非成员函数：标准算法库中的"swap"函数模板对"deque"类模板的特化，用于交换两个"deque"的内容。(函数模板)
			a.常见函数原型：void swap( deque& lhs, deque& rhs );。(C++17前)(省略了模板声明、模板参数、分配器和命名空间等细节)
			b."lhs"、"rhs"参数：要交换内容的容器。
			c.调用"lhs.swap(rhs)"。
			d.复杂度为常数级别。
*/

////"deque"类模板相关的非成员函数示例一：使用比较运算符比较"deque"中的值。
//int main()
//{
//	std::deque<int> alice(3, 1);
//	std::deque<int> bob(4, 2);
//	std::deque<int> eve(3, 1);
//
//	std::cout << std::boolalpha;
//
//	//比较不相等的容器
//	std::cout << "alice == bob returns " << (alice == bob) << '\n';
//	std::cout << "alice != bob returns " << (alice != bob) << '\n';
//	std::cout << "alice <  bob returns " << (alice < bob) << '\n';
//	std::cout << "alice <= bob returns " << (alice <= bob) << '\n';
//	std::cout << "alice >  bob returns " << (alice > bob) << '\n';
//	std::cout << "alice >= bob returns " << (alice >= bob) << '\n';
//
//	std::cout << '\n';
//
//	//比较相等的容器
//	std::cout << "alice == eve returns " << (alice == eve) << '\n';
//	std::cout << "alice != eve returns " << (alice != eve) << '\n';
//	std::cout << "alice <  eve returns " << (alice < eve) << '\n';
//	std::cout << "alice <= eve returns " << (alice <= eve) << '\n';
//	std::cout << "alice >  eve returns " << (alice > eve) << '\n';
//	std::cout << "alice >= eve returns " << (alice >= eve) << '\n';
//
//	return 0;
//}

////"deque"类模板相关的非成员函数示例二：使用"swap"非成员函数。
//int main()
//{
//	std::deque<int> v1(5, 10);
//	std::deque<int> v2(10, 5);
//
//	std::cout << "v1: ";
//	for (const auto& el: v1) std::cout << el << ' ';
//
//	std::cout << "\nv2: ";
//	for (const auto& el: v2) std::cout << el << ' ';
//
//	std::cout << '\n';
//
//	std::swap(v1, v2);
//
//	std::cout << "v1: ";
//	for (const auto& el: v1) std::cout << el << ' ';
//
//	std::cout << "\nv2: ";
//	for (const auto& el: v2) std::cout << el << ' ';
//
//	std::cout << '\n';
//
//	return 0;
//}