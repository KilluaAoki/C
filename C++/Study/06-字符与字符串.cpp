#include <iostream>
#include <string>//注意区分C语言的"string.h"头文件(包含C语言关于字符串的函数等)，此处的头文件指代C++字符串库。
#include <cassert>

/*
	字符与字符串
		1.计算机中表达字符的方式
		2.关于C/C++的字符串字面量和字符串
		3.C++字符串库介绍
		4."string"模板类的介绍与使用
		5."string"模板类对象的元素访问
		6."string"模板类中与容量相关的成员函数
		7."string"模板类中与操作相关的成员函数
*/

/**
	计算机中表达字符的方式
		1."ASCII"码："American Standard Code for Information Interchange"缩写，即美国信息交换标准代码，是电子通讯的字符编码标准。
			a.在计算机中，所有的数据在存储和运算时都要使用二进制数表示，那么字符也不例外，但用哪些二进制数字表示哪个符号就成了问题，这也就是俗称的编码问题。
			b.在不同计算机上，可以使用不同的编码标准，但是为了互通而不造成混乱，就需要有一种统一的编码方式，于是美国有关的标准化组织就推出了"ASCII"编码。
			c."ASCII"码规定，每个英文字符(包括大小写字母、数字、特殊符号)都对应着一个整数，在计算机里只要存储这个的整数，就能代表这个字符了。
			d."ASCII"码可分为控制字符和可打印字符，控制字符是用于控制显示设备的显示方式(换行、回车、退格等)，而可打印字符是用于显示的字符(包括字母、数字等)。
			e."ASCII"码局限在于只能显示基本拉丁字母("26"个)、阿拉伯数字和英式标点符号，只适用于英文，但使用计算机的人不仅仅是英文使用者，其不能解决其他语言该如何表示的问题。
		2."Unicode"标准：又被称为统一码或万国码等，是一种信息技术标准，用于对世界上大多数书写系统中表达的文本进行一致的编码、表示和处理。
			a."Unicode"标准由统一码联盟负责维护，此标准伴随着通用字符集的标准而发展，并且"Unicode"至今仍在不断增修，每个新版本都加入更多新的字符。
			b."Unicode"标准定义了三种和其他几种存在的编码方式，主要是"UTF-8"、"UTF-16"、"UTF-32"编码方式。("UTF"是"Unicode Transformation Format"的缩写，即把"Unicode"标准转做某种格式的意思)
				a'."UTF-8"编码方式：一种可变长度的编码方式，它可以使用一至四个字节表示一个符号，根据不同的符号而变化字节长度，兼容"ASCII"码。
				b'."UTF-16"编码方式：一种可变长度的编码方式，大部分字符都以固定长度的字节("2"字节)储存，但"UTF-16"无法兼容"ASCII"码。
				c'."UTF-32"编码方式：一种固定长度的编码方式，每个字符都用"4"字节储存，并不常用，也无法兼容"ASCII"码。
			c.普遍采用"UTF-8"编码方式，因为它兼容"ASCII"码，而且可以节省空间。
		3."GB18030"字符集：由中华人民共和国国家标准所规定的变长多字节字符集，适用于简体中文和繁体中文等，并且包含了"27484"个汉字。
			a.采用变长多字节编码，每个字可以由多个字节("1"个字节、"2"个字节或"4"个字节)组成，编码空间庞大，最多可定义"161"万个字符。
			b.支持中国国内少数民族文字、中日韩和繁体汉字以及"emoji"等字符。
			c."GB18030"字符集兼容"GB2312"编码、"GBK"编码以及"ASCII"码，并且其取代了旧发布的"GB2312"编码和"GBK"编码。
				a'."GB2312"编码于1980年发布，适用于汉字处理、汉字通信等系统之间的信息交换，共收入"6763"个汉字和非汉字图形字符"682"个，随后有了"GBK"编码。
				b'."GBK"编码是"GB2312"的扩展，于1995年发布，对"GB2312"编码进行了扩充，是中国和地区提供的第三大流行编码。
			d."GB18030"字符集算的上是"Unicode"的一种变换格式。
		4.C++中对各大编码格式的支持："char"类型、"wchar_t"类型、"char8_t"类型(C++20)、"char16_t"类型(C++11)、"char32_t"类型(C++11)。
			a."char"类型(编码格式随系统而改变)
				a'.大小为一字节，编码格式随系统默认编码格式而变。
				b''.字符串类型对应"string"类，字符串常量语法为："Hello"。
			b."wchar_t"类型(Windows平台)
				a'.大小为两个字节，编码格式为"UTF-16"。
				b''.字符串类型对应"wstring"类，字符串常量语法为：L"Hello"。
			c."wchar_t"类型(Linux平台)
				a'.大小为四个字节，编码格式为"UTF-32"。
				b'.字符串类型对应"wstring"类，字符串常量语法为：L"Hello"。
			d."char8_t"类型(C++20)
				a'.大小为一个字节，编码格式为"UTF-8"。
				b'.字符串类型对应"u8string"类，字符串常量语法为：u8"Hello"。
			e."char16_t"类型(C++11)
				a'.大小为两个字节，编码格式为"UTF-16"。
				b'.字符串类型对应"u16string"类，字符串常量语法为：u"Hello"。
			f."char32_t"类型(C++11)
				a'.大小为四个字节，编码格式为"UTF-32"。
				b'.字符串类型对应"u32string"类，字符串常量语法为：U"Hello"。
*/

////计算机中表达字符的方式示例：输出"ASCII"码中的可打印字符。
//int main()
//{
//	std::cout << "Printable ASCII:\n";
//	for (char i = 32; i < 127; ++i)
//	{
//		std::cout << i << ' ';
//		if (i % 16 == 15)
//			std::cout << '\n';
//	}
//}

/**
	关于C/C++的字符串字面量和字符串
		1.关于C/C++的字符串字面量
			a.C语言中无前缀的字符串字面量类型为"char[N]"，其中"N"代表了字符串字面量的元素个数，并且包括了字符串字面量的空终止符。
			b.C++中无前缀字符串字面量的类型为"const char[N]"，其中"N"代表了字符串字面量的元素个数，并且包括了字符串字面量的空终止符。
			c.C++11前：字符串字面量可转换为且可赋值(初始化)给非"const"的指向"char"类型指针，以与C兼容，因为C中字符串字面量类型为"char[N]"。
			d.C++11起：字符串字面量不可转换为或赋值(初始化)给非"const"的指向"char"类型指针，若想要这种转换则需使用显式转型(例如：const_cast)。
			e.因为有很多现有代码依赖于C++11前的字符串字面量类型的隐式转换，若采用C++11起的强制禁止隐式转换，则会导致大量的编译错误(破坏代码)，并且不兼容C语言。
		2.关于C/C++的字符串
			a.C语言中的字符串可初始化或赋值给指针以及数组(类型不再赘述)，并且其包含了字符串的空终止符作为字符串的结束标志。
			b.C语言中关于字符以及字符串的函数，详见：https://zh.cppreference.com/w/c/string/byte。
			c.C++中的字符串通常指的是"string"模板类，是为操作任何字符类型的字符串设计的模板类。
			d.C++的"string"类中有着一个成员变量，用于指代字符串的长度，所以其可不需要像C语言中的字符串那样以空终止符作为字符串的结束标志(取决于标准与实现)。
*/

/**
	C++字符串库介绍
		1.C++标准字符串库支持的三种通用字符串类型："basic_string"、"basic_string_view"(C++17起)、空终止字符串。
			a."basic_string"：模板类，用于通用化字符序列的操作以及存储，即字符串的创建、操作及析构全部为便利的类方法集合与相关函数所处理，定义于头文件"string"中。
				a'.标准库中提供了对于"basic_string"的多种对常用类型(详见"C++中对各大编码格式的支持")的数种特化，即某种特定类型下的具体实现，并使用"typedef"关键词进行了重定义。
				b'.本章节主要介绍"basic_string"模板类中特化的"string"类，其定义为"basic_string<char>"。
				c'.该类既不依赖字符类型，亦不依赖该类型上的原生操作。
			b."basic_string_view"(C++17起)：模板类，提供一个轻量对象，它的接口类似于"basic_string"，提供对字符串一部分的只读访问，也提供了多种对常用类型的数种特化。
			c."空终止字符串"：以特殊的空字符终止的字符数组，包含"空终止字节字符串"、"空终止多字节字符串"和"空终止宽字符字符串"。
				a'."空终止字节字符串"：以空终止字节终止的字节序列，即"char"类型数组，此字符串的每个字节都是一些字符集的编码("ASCII"编码)。
				b'."空终止多字节字符串"：以空终止多字节终止的多字节序列，即"char"类型数组，但存储于该字符串中的每个字符可能占用多于一个字节，字符的编码是由本地环境限定的。
				c'."空终止宽字符字符串"：以空终止宽字符终止的宽字符序列，即"wchar_t"类型数组，视本地环境而定，宽字符可能是两个或四个字节。
		2.附加支持的"char_traits"模板类：为"basic_string"和"basic_string_view"(C++17起)定义类型和函数。(了解)
		3."string"类与STL：最狭义的看法可能会认为"string"类不属于STL，因为尽管现在它属于"basic_string"模板类的特化，但它在C++有模板之前就出现了。
		4.关于"size_t"类型和"size_type"类型
			a."size_t"类型：无符号整数类型，是"sizeof"运算符、"sizeof..."运算符(C++11起)及"alignof"运算符(C++11起)的返回类型，通常用于表示对象的大小，是为了方便系统之间的移植而定义的。
				a'."size_t"类型是根据实现进行"typedef"运算符对对应的类型进行重定义的(通常情况下，"32"位为"unsigned int"类型，"64"位为"unsigned long long"类型)，"size_t"类型的宽度不小于"16"位(C++11起)。
				b'."size_t"类型可以存放下理论上可能存在的对象的最大大小，该对象可以是任何类型(包括数组)，"size_t"类型也可以存放任何非成员的指针的值。
				c'."size_t"类型通常用于数组索引和循环计数，使用其他类型来进行数组索引操作的程序可能会在某些情况下出错(如"64"位系统中使用"unsigned int"类型进行索引时，如果索引号超过此类型的最大值是，或若依赖于"32"位取模运算，程序就会出错)。
			b."size_type"类型：无符号整数类型，是"string"、"vector"等C++容器中定义的数据类型(配套类型)，它的使用依赖于容器。
				a'."size_type"类型同样是根据实现定义的，它与"size_t"一样都是使用"typedef"运算符对对应的类型进行重定义后的类型。
				b'.在对诸如"string"、"vector"等C++容器进行索引操作时，正确的类型是该容器的成员中的"size_type"配套类型，而该类型通常被定义为与"size_t"相同。
				c'.在"string"模板类中，"size_type"类型足以表示任何可能的字符串的大小。
*/

/**
	"string"模板类的介绍与使用：来自于"basic_string"模板类对于"char"类型的特化，定义于头文件"string"中，简称为"string"类。
		1."string"类的定义："string"类使用"typedef"关键词进行了重定义，即"typedef basic_string<char> string;"(此处忽略了命名空间)，故"string"类的定义实际上为"basic_string<char>"。
		2."string"类的常见构造函数的函数原型(以下函数原型忽略命名空间、分号以及分配器等)
			a."string()"：构造空"string"，由此构造函数构造出的对象拥有零大小和未指定的容量。
				a'.复杂度为常数级别。
			b."string(const char* s)"：以"s"所指向的空终止字符串的副本所初始化的内容构造"string"类对象，并以首个空终止符确定字符串的长度。
				a'.若区间"[s, s + char_traits<char>::length(s))"不是合法范围(例如当"s"是空指针时，则不是合法范围)，则行为未定义。("char_traits<char>::length(s)"表示"s"所指向的空终止字符串的长度，暂时不用理解)
				b'.复杂度与"s"的长度成线性级别。
			c."string(const char* s, size_type count)"：以"s"所指向的字符串的首"count"个字符构造"string"类对象，并且"s"可能含有空终止符，"string"类对象的长度为"count"。
				a'.若区间"[s, s + count)"不是合法范围，则行为未定义。
				b'.复杂度与"count"成线性级别。
			d."string(size_type count, char ch)"：构造拥有字符"ch"的"count"个副本的"string"类对象。
				a'.复杂度与"count"成线性级别。
			e."string(const string& other)"：拷贝构造函数，用于构造拥有"other"对象的内容副本的"string"类对象，即构造出的"string"类对象与"other"对象相同。
				a'.复杂度与"other"的大小(长度)成线性级别。
			f."string(const string& other, size_type pos, size_type count = npos)"：以"other"的位置区间"[pos, pos + count)"所对应的子串构造"string"类对象。
				a'."pos"代表的是位置，是要包含的首字符位置，位置从零开始，而"count"代表的是个数，是产生的字符串(对象)的长度，个数从一开始，注意区分两者。
				b'."npos"为特殊值，是"basic_string"类中的静态成员常变量，类型为"size_type"，其用于表示"size_type"类型的最大值，即"-1"。
				c'.若"count"与"npos"相等或未指定"count"，或请求的子串越过了此字符串的结尾(越过结尾表示越过字符串的长度减一所对应的位置)，则产生的子串的位置区间为"[pos, other.size())"。
				d'.复杂度与"count"成线性级别。
*/

////"string"模板类的介绍与使用示例一：使用"string"模板类。
//int main()
//{
//	std::string s1("Hello World!");//使用此模板类需包含"string"头文件，此处等价于"std::basic_string<char> s1("Hello World!");"。
//	std::basic_string<char> s2("Hello World!");
//
//	std::cout << s1 << std::endl;
//	std::cout << s2 << std::endl;
//
//	return 0;
//	return 0;
//}

////"string"模板类的介绍与使用示例二：使用"string"模板类的常见构造函数。
//int main()
//{
//	std::string s1;//调用默认构造函数。
//	assert(s1.empty() && (s1.length() == 0) && (s1.size() == 0));//各成员函数的用法将会在后面介绍，此处断言为真，表示此构造函数构造出的对象拥有零大小和未指定的容量。
//
//	std::string s2("C Style\0String");//调用的构造函数原型为："string(const char* s)"。
//	std::cout << s2 << '\n';//输出"C Style"，因为此字符串中含有空终止符，此构造函数会以首个空终止符确定字符串的长度。
//
//	std::string s3("C Style String", 7);//调用的构造函数原型为："string(const char* s, size_type count)"。
//	std::cout << s3 << '\n';//输出"C Style"，只使用了"C-style string"空终止字符串的首"7"个字符构造了"s3"对象。
//
//	std::string s4(4, '=');//调用的构造函数原型为："string(size_type count, char ch)"。
//	std::cout << s4 << '\n';//输出"===="，此构造函数构造包含了"4"个"="字符的"s4"对象。
//
//	std::string const other1("Killua Aoki");
//	std::string s5(other1);//调用的构造函数原型为："string(const string& other)"，即调用拷贝构造函数。
//	std::cout << s5 << '\n';//输出"Killua Aok"，构造出的"s5"对象与"other1"对象相同。
//
//	std::string const other2("Killua Aoki");
//	std::cout << other2.length() << '\n';//输出字符串中的字符个数，输出"11"。
//	std::string s6(other2, 0, other2.length() - 1);//调用的构造函数原型为："string(const string& other, size_type pos, size_type count = npos)"。
//	std::cout << s6 << '\n';//输出"Killua Aok"，构造出的"s6"对象的位置区间为"[pos, pos + count)"，即"[0, 10)"，故生成的范围区间是对应"other2"对象的位置区间"[0, 9]"。
//
//	std::string const other3("Killua Aoki");
//	std::cout << other3.size() << '\n';//输出字符串中的字符个数，输出"11"。
//	std::string s7(other3, 0);//调用的构造函数原型为："string(const string& other, size_type pos, size_type count = npos)"，但此处未指定"count"，故默认为"npos"。
//	std::cout << s7 << '\n';//未指定"count"，产生的子串的位置区间为"[pos, other.size())"，即"[0, 11)"，故生成的范围区间是对应"other3"对象的位置区间"[0, 10]"。
//
//	std::string const other4("Killua Aoki");
//	std::cout << other4.size() << '\n';//输出字符串中的字符个数，输出"11"。
//	std::string s8(other4, 0, 999);//调用的构造函数原型为："string(const string& other, size_type pos, size_type count = npos)"，此处"count"表示的位置越过了字符串结尾位置。
//	std::cout << s8 << '\n';//请求的子串越过了此字符串的结尾，产生的子串的位置区间为"[pos, other.size())"，即"[0, 11)"，故生成的范围区间是对应"other3"对象的位置区间"[0, 10]"。
//
//	std::string const other5("Killua Aoki");
//	std::cout << other5.size() << '\n';//输出字符串中的字符个数，输出"11"。
//	std::string s9(other5, 0, -1);//调用的构造函数原型为："string(const string& other, size_type pos, size_type count = npos)"，此处"count"与"npos"的值相同。
//	std::cout << s9 << '\n';//"count"与"npos"相等，产生的子串的位置区间为"[pos, other.size())"，即"[0, 11)"，故生成的范围区间是对应"other3"对象的位置区间"[0, 10]"。
//
//	return 0;
//}

/**
	"string"模板类对象的元素访问(仅介绍常见的元素访问相关函数)
		1."[]"下标成员访问运算符：访问指定字符，内部是关于"operator[]"的运算符重载函数。
			a.函数原型(C++20前)
				a'.reference operator[]( size_type pos );。
				b'.const_reference operator[]( size_type pos ) const;。(注意此处的构造函数被"const"限定符修饰)
			b.参数"pos"表示要访问以及返回的字符位置，位置从零开始。
			c.返回值"reference"表示对字符的引用，而"const_reference"表示对字符的常引用。(以下所指的字符串大小是不包括空终止符的)
				a'.被引用的对象的类型根据模板类"basic_string"所特化的类型而定，对于"string"模板类而言，其引用类型为"char&"和"const char&"。
				b'.在"pos"位置小于对应字符串的大小时，返回到位于指定位置"pos"的字符的引用(实际上是"*(begin() + pos)"，"begin"函数将在之后的迭代器进行介绍)。
				c'.在"pos"位置等于对于字符串的大小时，返回空字符的引用，不进行边界检查。
					a''.C++11前，对于函数原型"a''"，如果"pos"位置等于对应字符串的大小，那么行为未定义。
					b''.C++11起，对于函数原型"a''"，如果"pos"位置等于对应字符串的大小，若对返回的引用指代的对象被修改成空字符以外的值时，那么行为未定义。
				d'.在"pos"位置大于对应字符串的大小时，行为未定义。
			d.复杂度为常数级别。
		2."at"成员函数：访问指定字符，有边界检查，返回到位于指定位置的字符的引用。
			a.函数原型(C++20前)
				a'.reference at( size_type pos );。
				b'.const_reference at( size_type pos ) const;。
			b.进行边界检查，非法访问时会抛出异常：当"pos"位置大于或等于对应字符串的大小时，抛出异常。
			c.复杂度为常数级别。
		3."front"成员函数和"back"成员函数：C++11起支持，分别用于访问首字符和最后的字符。
			a.函数原型(C++20前)
				a'.char& front();。("front"成员函数)
				b'.const char& front() const;。("front"成员函数)
				c'.char& back();。("back"成员函数)
				d'.const char& back() const;。("back"成员函数)
			b.返回值"char&"表示对字符的引用，而"const char&"表示对字符的常引用。
			c.对于"front"成员函数，返回到字符串中首字符的引用，对于"back"成员函数，返回字符串中的末字符的引用。
			d.若字符串为空，则行为未定义。
			e.复杂度为常数级别。
		4."data"成员函数：返回指向字符串首字符的指针，即返回指向作为字符存储工作的底层数组的指针。(了解)
			a.函数原型
				a'.C++11前：const char* data() const;。
				b'.C++20起：constexpr char* data() noexcept;。
			b.返回的指针满足对应的范围，且其中的值对应存储于字符串的值。
				a'.C++11前：[data(); data() + size())，为合法范围。
				b'.C++11起：[data(); data() + size()]，为合法范围。
			c.C++11前，不要求返回的数组是空终止的，若字符串为空，则指针指向不应解引用的非空指针。
			d.C++11起，返回的数组是空终止的(与"c_str"成员函数相同)，若字符串为空，则指针指向单个空字符。
			e.复杂度为常数级别。
		5."c_str"成员函数：返回字符串的不可修改的C字符数组版本，即返回指向拥有数据等价于存储于字符串中的空终止字符数组的指针。(了解)
			a.函数原型(C++11前)：const char* c_str() const;。
			b.该指针有范围"[c_str(); c_str() + size()]"为合法，且其中的值对应存储于字符串的值，且在最后位置有个附加的空终止字符。
			c.通过"c_str"写入字符数组是未定义行为。
			d.从"c_str"获得的指针可以只当做一个指向空终止字符串的指针，若"string"对象不含其他空字符。
			e.复杂度为常数级别。
		6.适用于"string"模板类的迭代器
			a.初步了解迭代器
				a'.迭代器是指向容器内元素的对象，类似于指针，它可以遍历C++标准库容器中的元素并提供对单个位置的元素进行访问。
				b'.C++标准库容器都提供迭代器，以便算法可以以标准方式访问它们的元素，而不必关心元素存储在的容器类型，它是一种通用的访问机制。
				c'.迭代器通常的使用形式类似于指针，指针可以指向数组中的元素，并可以使用自增运算符遍历它们，但需要注意的是，并非所有迭代器都具有与指针类似的功能。
			b.使用"string"模板类中的迭代器
				a'."begin"成员函数：返回指向起始的迭代器。
					a''.函数原型(C++11前)
						a'''.iterator begin();。
						b'''.const_iterator begin() const;。
					b''.返回类型为"iterator"或"const_iterator"("string"模板类中的配套类型(迭代器类型))，代表返回指向字符串首字符的迭代器。
					c''."begin"成员函数可以返回可变的或不可变的迭代器，取决于调用它的对象是否具有常性(即取决于"this"指针指向的对象是否具有常性)。
					d''.复杂度为常数级别。
				b'."end"成员函数：返回指向末尾的迭代器。
					a''.函数原型(C++11前)
						a'''.iterator end();。
						b'''.const_iterator end() const;。
					b''.返回指向后随字符串末字符的字符的迭代器(即字符串最后一个字符的下一个字符)，此字符表现为占位符，试图访问它导致未定义行为。
					c''.复杂度为常数级别。
				c'."rbegin"成员函数：返回指向起始的逆向迭代器。
					a''.函数原型(C++11前)
						a'''.reverse_iterator rbegin();。
						b'''.const_reverse_iterator rbegin() const;。
					b''.返回类型为"reverse_iterator"或"const_reverse_iterator"("string"模板类中的配套类型(逆向迭代器类型))。
					c''.返回指向逆转字符串首字符的逆向迭代器，它对应非逆向字符串的末字符(即非逆向的字符串的最后一个字符)。
					d''.复杂度为常数级别，也代表着实际上字符串没有被逆转，只是返回的逆向迭代器指向了字符串的末字符(对于"rbegin"成员函数而言)。
				d'."rend"成员函数：返回指向末尾的逆向迭代器。
					a''.函数原型(C++11前)
						a'''.reverse_iterator rend();。
						b'''.const_reverse_iterator rend() const;。
					b''.返回指向后随逆向字符串末字符的字符的逆向迭代器(即逆向字符串的最后一个字符的下一个字符)，它对应前驱非逆向字符串首字符的字符(即非逆向的字符串的首字符的前一个字符)，此字符表现为占位符，试图访问它会导致未定义行为。
					c''.复杂度为常数级别，同样代表着实际上字符串没有被逆转，只是返回的逆向迭代器指向了字符串的首字符的前一个字符(对于"rend"成员函数而言)，也就是占位符。
				e'.C++11起支持的"cbegin"成员函数和"cend"成员函数以及"crbegin"成员函数和"crend"成员函数：除成员函数名不相同外，等价分别对应于没有"c"前缀的返回不可变的迭代器的成员函数(如："cbegin"成员函数等价于返回不可变的迭代器的"begin"成员函数)。
*/

////"string"模板类对象的元素访问示例一：通过下标成员访问运算符遍历字符串中的字符。
//int main()
//{
//	std::string str = "Hello World!";
//	for (int i = 0; i < str.size(); i++)
//	{
//		std::cout << str[i] << " ";
//	}
//	std::cout << std::endl;
//	return 0;
//}

////"string"模板类对象的元素访问示例二：通过基于范围的"for"循环遍历字符串中的字符。
//int main()
//{
//	std::string str = "Hello World!";
//	for (auto c: str)
//	{
//		std::cout << c << " ";
//	}
//	std::cout << std::endl;
//	return 0;
//}

////"string"模板类对象的元素访问示例三：使用"at"成员函数遍历字符串中的字符。
//int main()
//{
//	std::string str = "Hello World!";
//	for (int i = 0; i < str.size(); i++)
//	{
//		std::cout << str.at(i) << " ";
//	}
//	return 0;
//}

////"string"模板类对象的元素访问示例四：使用"front"成员函数和"back"成员函数。(C++11)
//int main()
//{
//	std::string str = "Hello World!";
//	std::cout << str.front() << std::endl;
//	std::cout << str.back() << std::endl;
//	return 0;
//}

////"string"模板类对象的元素访问示例五：使用迭代器遍历字符串中的字符(正向与逆向)。
//int main()
//{
//	std::string str = "Hello World!";
//
//	//正向遍历
//	for (auto it = str.begin(); it != str.end(); it++)
//	{
//		std::cout << *it << " ";
//	}
//	std::cout << std::endl;
//
//	//逆向遍历
//	for (auto it = str.rbegin(); it != str.rend(); it++)
//	{
//		std::cout << *it << " ";
//	}
//	std::cout << std::endl;
//
//	return 0;
//}

/**
	"string"模板类中与容量相关的成员函数
		1."empty"成员函数：检查字符串是否为空。
			a.函数原型(C++11前)：bool empty() const;。
			b.用于检查字符串是否无字符，即"begin() == end()"。
			c.返回值为布尔类型，当字符串为空时返回"true"，否则返回"false"。
			d.复杂度为常数级别。
		2."size"成员函数和"length"成员函数：返回字符数。
			a.函数原型(C++11前)
				a'.size_type size() const;。("size"成员函数)
				b'.size_type length() const;。("length"成员函数)
			b."size"成员函数和"length"成员函数没有区别，两者为同义词，并且等价。
				a'.在引入STL之前，"length"作为"string"模板类的唯一用于返回字符数的成员函数。
				b'.在引入STL之后，为了兼容其他容器库，又引入了"size"成员函数。
			c.返回字符串中的"char"类型的元素数(若编码格式为多字节编码，则它与字符不同)。
			d.复杂度在C++11前是未指定的，而在C++11起为常数级别。
		3."max_size"成员函数：返回字符数的最大值。
			a.函数原型(C++11前)：size_type max_size() const;。
			b.返回"string"由于保有系统或库实现限制所能保有的最大元素数。
			c.复杂度为常数级别。
		4."reserve"成员函数：保留存储(请求更改容量)。
			a.函数原型(C++20前)：void reserve( size_type new_cap = 0 );。
				a'.函数头"void"表示此函数不返回任何值。
				b'.函数参数"size_type"：将无符号整型类型作为参数；在此函数中意为"string"的新容量。
			b.告知"string"类对象大小的有计划更改，使得它能准确地管理存储分配。
				a'.若"new_cap"大于当前"capacity"成员函数的返回值，则分配新存储，并令容量大于或等于"new_cap"。
				b'.若"new_cap"小于当前"capacity"成员函数的返回值，则这是非强制的收缩请求。(C++20前)
				c'.若"new_cap"小于当前"capacity"成员函数的返回值，则这是非强制的收缩到适合请求(，等价于"shrink_to_fit"成员函数的返回值(C++11起))。(C++20前)
				d'.若"new_cap"小于或等于当前"capacity"成员函数的返回值，则无效果。(C++20起)
				e'.若发生对象的容量("capacity")发生了更改，则非法化所有迭代器与引用，包含尾后迭代器。
			c.若"new_cap"大于当前"max_size"成员函数的返回值，则抛出异常。
			d.复杂度至多与当前对象的大小("size")成线性级别。
		5."capacity"成员函数：返回当前对象分配的存储空间能保存的字符数量。
			a.函数原型(C++11前)：size_type capacity() const;。
			b.用于返回当前已为字符串分配的存储空间的字符数(当前分配的存储空间为可用于存储元素的存储的容量)。
			c.从分配器获得，但不可用于存储任何元素的内存位置不计入分配的存储，注意空终止符不是"basic_string"模板类的元素。(暂忽略分配器)
			c.复杂度为常数级别。
		6."shrink_to_fit"成员函数：通过释放不使用的内存，减少内存的使用，即请求移除未使用的容量。(C++11)
			a.函数原型(C++11前)：void shrink_to_fit();。
			b.这是减少容量("capacity")到大小("size")的非强制请求。
			c.若"capacity"成员函数的返回值小于或等于"size"成员函数的返回值，则无效果。
			d.当(且仅当)发生重分配是，则非法化所有指针、引用和迭代器。
			e.复杂度在C++17前是未指定的，而在C++17起至多与当前对象的大小("size")成线性级别。
*/

////"string"模板类中与容量相关的成员函数示例一：使用"empty"成员函数。
//int main()
//{
//	std::string s;
//	std::cout << "s.empty()：" << s.empty() << "\t s：\"" << s << "\"\n";
//	s = "Exemplar";
//	std::cout << "s.empty()：" << s.empty() << "\t s：\"" << s << "\"\n";
//	s = "";
//	std::cout << "s.empty()：" << s.empty() << "\t s：\"" << s << "\"\n";
//	return 0;
//}

////"string"模板类中与容量相关的成员函数示例二：使用"size"成员函数和"length"成员函数。
//int main()
//{
//	std::string s;
//	std::cout << "s = \"" << s << "\"\n";
//	std::cout << "s.size() = " << s.size() << "\n";
//	std::cout << "s.length() = " << s.length() << "\n\n";
//	s = "Exemplar";
//	std::cout << "s = \"" << s << "\"\n";
//	std::cout << "s.size() = " << s.size() << "\n";
//	std::cout << "s.length() = " << s.length() << "\n\n";
//	s = "";
//	std::cout << "s = \"" << s << "\"\n";
//	std::cout << "s.size() = " << s.size() << "\n";
//	std::cout << "s.length() = " << s.length() << "\n\n";
//	return 0;
//}

////"string"模板类中与容量相关的成员函数示例三：使用"max_size"成员函数。
//int main()
//{
//	std::string s;
//	std::cout << "Maximum size of a string is " << s.max_size() << "\n";
//	return 0;
//}

////"string"模板类中与容量相关的成员函数示例四：使用"reserve"成员函数和"capacity"成员函数。
//int main()
//{
//	std::string s;
//
//	std::cout << "s.size() = " << s.size() << "\n";
//	std::cout << "s.capacity() = " << s.capacity() << "\n\n";
//
//	s.reserve(100);
//	std::cout << "s.reserve(100)" << "\n";
//	std::cout << "s.size() = " << s.size() << "\n";
//	std::cout << "s.capacity() = " << s.capacity() << "\n\n";
//
//	s.reserve(10);
//	std::cout << "s.reserve(10)" << "\n";
//	std::cout << "s.size() = " << s.size() << "\n";
//	std::cout << "s.capacity() = " << s.capacity() << "\n\n";
//
//	s.reserve(1000);
//	std::cout << "s.reserve(1000)" << "\n";
//	std::cout << "s.size() = " << s.size() << "\n";
//	std::cout << "s.capacity() = " << s.capacity() << "\n\n";
//
//	return 0;
//}

////"string"模板类中与容量相关的成员函数示例五：测试容量的增长策略。
//int main()
//{
//	std::string s;
//	size_t capacity = s.capacity();
//	std::cout << "making s grow:\n";
//	for (int i = 0; i < 2000; ++i)
//	{
//		s.push_back('c');//后附字符到结尾，将会在之后进行详细讲解。
//		if (capacity != s.capacity())
//		{
//			capacity = s.capacity();
//			std::cout << "\tcapacity changed: " << capacity << '\n';
//		}
//	}
//	return 0;
//}

////"string"模板类中与容量相关的成员函数示例六：利用"reserve"成员函数提高插入数据的效率，避免增容带来的开销。
//int main()
//{
//	std::string s;
//	s.reserve(1000);//预留足够的空间，避免增容带来的开销。
//	size_t capacity = s.capacity();
//	std::cout << "making s grow:\n";
//	for (int i = 0; i < 2000; ++i)
//	{
//		s.push_back('c');
//		if (capacity != s.capacity())
//		{
//			capacity = s.capacity();
//			std::cout << "\tcapacity changed: " << capacity << '\n';//显著减少了增容的次数。
//		}
//	}
//	return 0;
//}

////"string"模板类中与容量相关的成员函数示例七：使用"shrink_to_fit"成员函数。
//int main()
//{
//	std::string s;
//	s.reserve(1000);
//	std::cout << "s.capacity() = " << s.capacity() << "\n";
//	s.shrink_to_fit();
//	std::cout << "s.shrink_to_fit()\n";
//	std::cout << "s.capacity() = " << s.capacity() << "\n";//释放不使用的内存，减少内存的使用。
//	return 0;
//}

/**
	"string"模板类中与操作相关的成员函数(仅介绍常见的与操作相关的成员函数)
		01."clear"成员函数：清除内容。
			a.函数原型：void clear();。
			b.从字符串中移除所有字符。
			c.非法化所有指针、引用及迭代器。
			d.字符串的大小在调用此函数后被清零，需要注意的是标准中不显式要求此函数改变容量。
			e.复杂度与当前对象的大小成线性(存在实现在常数时间内的操作)。
		02."insert"成员函数：插入字符。
			a.常见函数原型
				a'.string& insert( size_type index, size_type count, char ch );。(C++20前)
					a''.在"index"位置插入"count"个"ch"字符的副本。
					b''.返回值：*this。
				b'.string& insert( size_type index, const char* s );。(C++20前)
					a''. 在"index"位置插入"s"所指向的空终止字符串，字符串的长度由首个空字符通过"char_traits<char>::length(s)"确定。
					b''. 返回值：*this。
				c'.string& insert( size_type index, const char* s, size_type count );。(C++20前)
					a''.在"index"位置插入范围"[s, s + count)"中的字符，范围能含有空字符。
					b''.返回值：*this。
				d'.string& insert( size_type index, const string& str );。(C++20前)
					a''.在"index"位置插入字符串"str"，注意"str"是一个"string"模板类的对象的引用，而不是一个指针，不同于"const char* s"指代的C风格的字符串。
					b''.返回值：*this。
				e'.string& insert( size_type index, const string& str, size_type index_str, size_type count );。(C++14前)
					a''.在"index"位置插入由"str.substr(index_str, count)"获得的字符串。
					b''.插入"str"的子字符串的副本，而子字符串是"str"的一部分，它从"index"字符位置开始并跨越"count"个字符。
					c''.在C++14起直至C++20前，此函数的原型为：string& insert( size_type index, const string& str, size_type index_str, size_type count = npos );。
					d''.默认值"count = npos"表示当"count"未指定或"count"与"npos"值相等，或请求的子字符串超出了"str"的结尾时，那么将直到"str"的结尾为止。
					e''.返回值：*this。
				f'.iterator insert( iterator pos, char ch );。(C++11前)
					a''.在"pos"所指向的字符前插入字符"ch"。
					b''.在C++11起直至C++20前，此函数的原型为：iterator insert( const_iterator pos, char ch );。
					c''.注意"pos"的类型是"iterator"(C++11前)或"const_iterator"(C++11起)，而不是"reverse_iterator"，即正向迭代器。
					b''.返回值：指代被插入字符的迭代器，即返回一个指向插入的字符的迭代器。
				g'.void insert( iterator pos, size_type count, char ch );。(C++11前)
					a''.在"pos"所指向的元素(如果存在)前插入"count"个字符"ch"的副本。
					b''.在C++11起直至C++20前，此函数的原型为：iterator insert( const_iterator pos, size_type count, char ch );。
					c''.在C++11前，此函数不返回任何值，而在C++11起直至C++20前，此函数返回一个指向插入的第一个字符的迭代器，当未插入任何字符时("count"为零)，返回"pos"。
			b.关于"insert"成员函数的常见函数原型中的异常处理
				a'.常见函数原型中的"a'"、"b'"、"c'"、"d'"会在"index"位置大于被插入字符串的大小时抛出异常。
				b'.常见函数原型中的"e'"会在在"index"位置大于被插入字符串的大小或"index_str"大于"str"的大小时抛出异常。
				c'.在所有情况下，在被插入字符串的大小与将要插入的字符数("count")之和大于字符串的"max_size"时，都会抛出异常。
				d'.C++11起，在任何情况下，如果因为任何原因抛出异常，那么此函数无效果(强异常保证)。
		03."erase"成员函数：移除字符，即从字符串移除指定的字符。
			a.常见函数原型
				a'.string& erase( size_type index = 0, size_type count = npos );。(C++20前)
					a''.移除从"index"位置开始的"count"或此字符串的大小减去"index"位置个字符(两者取较小值)。
					b''.返回值：*this。
					c''.当"index"位置大于此字符串的大小时抛出异常。
				b'.iterator erase( iterator position );。(C++11前)
					a''.移除位于"position"的字符，"position"是指向要移除的字符的迭代器。
					b''.返回指向立即后随被擦除字符的迭代器，或者在不存在这种字符的情况下返回"end"成员函数的返回值。
					c''.不抛出异常。
				c'.iterator erase( iterator first, iterator last );。(C++11前)
					a''.移除范围"[first, last)"中的字符，"first"是指向要移除的首个字符的迭代器，而"last"是指向后随字符串末字符的字符的迭代器。
					b''.返回指向擦除前"last"指向的字符的迭代器，或者在不存在这种字符的情况下返回"end"成员函数的返回值。
					c''.不抛出异常。
			b.C++11起，在任何情况下，如果因为任何原因抛出异常，那么此函数无效果(强异常保证)。
		04."push_back"成员函数：后附字符到结尾，即后附给定的字符到字符串尾。
			a.函数原型(C++20前)：void push_back( char ch );。
			b.C++11起，在任何情况下，如果因为任何原因抛出异常，那么此函数无效果(强异常保证)。
			c.如果操作会导致当前字符串的大小大于当前"max_size"成员函数的返回值，则抛出异常。
			d.均摊复杂度为常数级别。
		05."pop_back"成员函数：移除末尾字符，即从字符串移除末字符。(C++11)
			a.函数原型(C++20前)：void pop_back();。
			b.调用此函数等价于调用"erase(end() - 1)"(除两成员函数的返回值类型不相同)，若字符串为空则行为未定义。
			c.不抛出异常。
			d.复杂度为常数级别。
		06."append"成员函数：后附字符到结尾，即后附额外字符到字符串。
			a.常见的函数原型
				a'.string& append( size_type count, char ch );。(C++20前)
					a''.后附"count"个字符"ch"的副本。
				b'.string& append( const string& str );。(C++20前)
					a''.后附字符串"str"。
				c'.string& append( const string& str, size_type pos, size_type count );。(C++14前)
					a''.后附"str"的子串，要后附的首个字符下标为"pos"，要后附的字符数为"count"，后附的子串的范围为"[pos, pos + count)"。
					b''.在C++14起直至C++20前，此函数的原型为：string& append( const string& str, size_type pos, size_type count = npos );。
					c''.若请求的子串越过当前字符串结尾，或当"count == npos"时(C++14起)，则后附的子串的范围为"[pos, size())"。
					d''.若"pos > str.size()"，则抛出异常。
				d'.string& append( const char* s, size_type count );。(C++20前)
					a''.后附范围为"[s, s + count)"中的字符，此范围能含有空字符。
				e'.string& append( const char* s );。(C++20前)
					a''.后附"s"所指向的空终止字符串，字符串的长度由首个空字符通过"char_traits<char>::length(s)"确定。
			b.返回值：*this。
			c.如果操作会导致当前字符串的大小大于当前"max_size"成员函数的返回值，则抛出异常。
			d.C++11起，在任何情况下，如果因为任何原因抛出异常，那么此函数无效果(强异常保证)。
		07."+="加法赋值运算符：后附字符到结尾(对于"string"类(类对象)而言)，即后附额外字符到字符串，内部是关于"operator+="的运算符重载函数。
			a.常见的函数原型(C++20前)
				a'.string& operator+=( const string& str );。
					a''.后附字符串"str"。
				b'.string& operator+=( char ch );。
					a''.后附字符"ch"。
					b''.能接收任何可隐式类型转换为"char"的类型。
					c''.对于通过"char"类型特化的"string"模板类，其可接受类型的集合包含任何算术类型，这会导致一些非意图的效果。
				c'.string& operator+=( const char* s );。
					a''.后附"s"所指向的空终止字符串。
			b.返回值：*this。
			c.如果操作会导致当前字符串的大小大于当前"max_size"成员函数的返回值，则抛出异常。
			d.C++11起，在任何情况下，如果因为任何原因抛出异常，那么此函数无效果(强异常保证)。
		08."compare"成员函数：比较二个字符串，即比较两个字符序列。
			a.常见的函数原型
				a'.int compare( const string& str ) const;。(C++11前)
					a''.比较此字符串与"str"。
				b'.int compare( size_type pos1, size_type count1, const string& str ) const;。(C++20前)
					a''.比较此字符串范围为"[pos1, pos1 + count1)"的子串与"str"。
					b''."pos1"指此字符串中要比较的首字符的位置，"count1"指此字符串要比较的字符数。
					c''.如果"count1 > size() - pos1"，那么子串的范围是"[pos1, size())"。
				c'.int compare( size_type pos1, size_type count1, const string& str, size_type pos2, size_type count2 ) const;。(C++14前)
					a''.比较此字符串范围为"[pos1, pos1 + count1)"的子串与"str"范围为"[pos2, pos2 + count2)"的子串。
					b''."pos2"指给定字符串的要比较的首字符位置，"count2"指给定字符串要比较的字符数。
					c''.对于此字符串而言，如果"count1 > size() - pos1"，那么子串的范围是"[pos1, size())"。
					d''.对于要比较的另一字符串("str")而言，如果"count2 > str.size() - pos2"，那么子串的范围是"[pos2, str.size())"。
					e''.在C++14起直至C++20前，此函数的原型为：int compare( size_type pos1, size_type count1, const string& str, size_type pos2, size_type count2 = npos ) const;。
				d'.int compare( const char* s ) const;。(C++20前)
					a''.比较此字符串与始于"s"所指向字符的长度为"char_traits<char>::length(s)"的空终止字符序列。
				e'.int compare( size_type pos1, size_type count1, const char* s ) const;。(C++20前)
					a''.比较此字符串范围为"[pos1, pos1 + count1)"的子串与始于"s"所指向字符的长度为"char_traits<char>::length(s)"的空终止字符序列。
					b''.如果"count1 > size() - pos1"，那么子串的范围是"[pos1, size())"。
				f'.int compare( size_type pos1, size_type count1, const CharT* s, size_type count2 ) const;。(C++20前)
					a''.比较此字符串范围为"[pos1, pos1 + count1)"的子串与"s"范围为"[s, s + count2)"中的字符。
					b''."s"范围为"[s, s + count2)"中的字符可包含空字符。
			b.比较两个字符串以字符字典序(实际实现可能分为多个函数进行)
				a'.获取要比较的字符串(称为"s1"和"s2")，以及要比较来自"s1"与"s2"的字符数(称为"count1"和"count2")，计算并比较字符串"s1"与"s2"的首"count"个字节，比较按字典序进行。
					a''.即比较始于"data1"的"count1"个字符组成的字符序列与始于"data2"的"count2"个字符组成的字符序列。
					b''.计算要比较的字符数"count"：求出"count1"和"count2"中较小的一个。
				b'.若"count"为"0"或比较完"count"个字符均相等，则继续比对"s1"与"s2"的大小，若依旧相等则返回"0"，若不相等则通过"s1"与"s2"的大小差得出结论。
					a''.若"size1 < size2"则认为"s1 < s2"，返回负值。
					b''.若"size1 > size2"则认为"s1 > s2"，返回正值。
				c'.若进行比较字典序的过程中出现不相等的字符，则直接得出结论而不再比较大小。
					a''.若"s1[i] < s2[i]"则认为"s1 < s2"，返回负值。
					b''.若"s1[i] > s2[i]"则认为"s1 > s2"，返回正值。
		09."replace"成员函数：替换字符串的指定部分，即以新字符串替换"[pos, pos + count)"或"[first, last)"所指示的"string"类(类对象)部分。
			a.常见的函数原型
				a'.string& replace( size_type pos, size_type count, const string& str );、string& replace( const_iterator first, const_iterator last, const string& str );。(C++20前)
					a''.新字符串是"str"。
				b'.string& replace( size_type pos, size_type count, const string& str, size_type pos2, size_type count2 );。(C++14前)
					a''.在C++14起直至C++20前，此函数的原型为：string& replace( size_type pos, size_type count, const string& str, size_type pos2, size_type count2 = npos );。
					b''.新字符串是"str"的子串，"str"的范围为"[pos2, pos2 + count2)"，但若"count2 == npos"或若它可能越过"str"的大小时(C++14起)，则使用"[pos2, str.size())"范围。
				c'.string& replace( size_type pos, size_type count, const char* cstr, size_type count2 );、string& replace( const_iterator first, const_iterator last, const char* cstr, size_type count2 );。(C++20前)
					a''.新字符串是"cstr"的子串，"cstr"的范围为"[cstr, cstr + count2)"。
				d'.string& replace( size_type pos, size_type count, const char* cstr );、string& replace( const_iterator first, const_iterator last, const char* cstr );。(C++20前)
					a''.新字符串是"cstr"范围为"[cstr, cstr + char_traits<char>::length(cstr))"中的字符。
				e.string& replace( size_type pos, size_type count, size_type count2, char ch );、string& replace( const_iterator first, const_iterator last, size_type count2, char ch );。(C++20前)
					a''.新字符串是"count2"个字符"ch"组成的字符串。
			b.返回值：*this。
			c.若"pos > length()"或"pos2 > str.length()"，则抛出异常。
			d.若产生的字符串将超出最大可能的字符串长度("max_size() - 1")，则抛出异常。
			e.C++11起，在任何情况下，如果因为任何原因抛出异常，那么此函数无效果(强异常保证)。
		10."substr"成员函数：返回子串。
			a.函数原型(C++20前)：string substr( size_type pos = 0, size_type count = npos ) const;。
			b.返回子串的范围为"[pos, pos + count)"，但若请求的子串越过当前字符串结尾，即"count"大于"size() - pos"时(例如当"count"等于"npos"以及"count"未指定时)，则返回的子串的范围为"[pos, size())"。
			c.返回值：包含子串的"string"类(类对象)，子串范围为"[pos, pos + count)"或为"[pos, size())"。
			d.若"pos > size()"，则抛出异常。
			e.复杂度与"count"成线性级别。
		11."copy"成员函数：复制字符。
			a.函数原型(C++20前)：size_type copy( char* dest, size_type count, size_type pos = 0 ) const;。
				a'.参数"dest"表示指向目标字符串的指针。
			b.复制子串范围为"[pos, pos+count)"到"dest"所指向的字符串。
			c.请求的子串越过当前字符串结尾，或若"count == npos"(生成子串时)，则复制的子串的范围为"[pos, size())"，产生的字符串不是空终止的。
			d.若"pos > size()"，则抛出异常。
		12."resize"成员函数：更改存储的字符数。
			a.函数原型(C++20前)
				a''.void resize( size_type count );。
				b''.void resize( size_type count, char ch );。
			b.重设当前字符串的大小以含有"count"个字符。
			c.若当前字符串大小小于"count"，则后附额外的字符"ch"，若当前大小大于"count"，则缩减当前字符串到为其首"count"个元素。
			d.若"count > max_size()"，则抛出异常。
			e.C++11起，在任何情况下，如果因为任何原因抛出异常，那么此函数无效果(强异常保证)。
		13."swap"成员函数：交换内容。
			a.函数原型(C++17前)：void swap( string& other );。
			b.交换当前字符串和"other"的内容。
			c.可能会非法化所有迭代器和引用。
			d.复杂度为常数。
*/

////"string"模板类中与操作相关的成员函数示例一：使用"clear"成员函数。
//int main()
//{
//	std::string s{ "Exemplar" };
//	std::string::size_type const capacity = s.capacity();
//	s.clear();
//	assert(s.capacity() == capacity);
//	assert(s.empty());
//	assert(s.size() == 0);
//	return 0;
//}

////"string"模板类中与操作相关的成员函数示例二：使用"insert"成员函数。
//int main()
//{
//	std::string s1 = "KilluaAoki";
//	std::cout << "s1 = " << s1 << std::endl;
//	s1.insert(10, 1, '!');
//	std::cout << "s1 = " << s1 << std::endl << std::endl;
//
//	std::string s2 = "Killua";
//	std::cout << "s2 = " << s2 << std::endl;
//	s2.insert(6, "Aoki!");
//	std::cout << "s2 = " << s2 << std::endl << std::endl;
//
//	std::string s3 = "Killua";
//	std::cout << "s3 = " << s3 << std::endl;
//	s3.insert(6, "Aoki!", 4);//"Aoki!"中的"!"不会被插入。
//	std::cout << "s3 = " << s3 << std::endl << std::endl;
//
//	std::string s4 = "->!";
//	std::cout << "s4 = " << s4 << std::endl;
//	s4.insert(2, s3);
//	std::cout << "s4 = " << s4 << std::endl << std::endl;
//
//	std::string s5 = "Killua";
//	std::cout << "s5 = " << s5 << std::endl;
//	s5.insert(6, s3, 6, 5);
//	std::cout << "s5 = " << s5 << std::endl << std::endl;
//
//	std::string s6 = "Killua";
//	std::cout << "s6 = " << s6 << std::endl;
//	s6.insert(s6.end(), '!');
//	std::cout << "s6 = " << s6 << std::endl << std::endl;
//
//	std::string s7 = "Killua";
//	std::cout << "s7 = " << s7 << std::endl;
//	s7.insert(s7.end(), 5, '!');
//	std::cout << "s7 = " << s7 << std::endl << std::endl;
//
//	return 0;
//}

////"string"模板类中与操作相关的成员函数示例三：使用"erase"成员函数。
//int main()
//{
//	std::string s1 = "KilluaAoki";
//	std::cout << "s1 = " << s1 << std::endl;
//	s1.erase(6, 4);
//	std::cout << "s1 = " << s1 << std::endl << std::endl;
//
//	std::string s2 = "KilluaAoki!";
//	std::cout << "s2 = " << s2 << std::endl;
//	s2.erase(s2.end() - 1);
//	std::cout << "s2 = " << s2 << std::endl << std::endl;
//
//	std::string s3 = "KilluaAoki!";
//	std::cout << "s3 = " << s3 << std::endl;
//	s3.erase(s3.begin() + 6, s3.end() - 1);
//	std::cout << "s3 = " << s3 << std::endl << std::endl;
//
//	return 0;
//}

////"string"模板类中与操作相关的成员函数示例四：使用"push_back"成员函数。
//int main()
//{
//	std::string s = "KilluaAoki";
//	std::cout << "s = " << s << std::endl;
//	s.push_back('!');
//	std::cout << "s = " << s << std::endl << std::endl;
//	return 0;
//}

////"string"模板类中与操作相关的成员函数示例五：使用"pop_back"成员函数(C++11)。
//int main()
//{
//	std::string s1 = "KilluaAoki!";
//	std::cout << "s1 = " << s1 << std::endl;
//	s1.pop_back();//等价于"s1.erase(s.end() - 1)"(除两成员函数的返回值类型不相同)。
//	std::cout << "s = " << s1 << std::endl << std::endl;
//
//	std::string s2 = "KilluaAoki!";
//	std::cout << "s2 = " << s2 << std::endl;
//	s2.erase(s2.end() - 1);
//	std::cout << "s2 = " << s2 << std::endl << std::endl;
//
//	return 0;
//}

////"string"模板类中与操作相关的成员函数示例六：使用"append"成员函数。
//int main()
//{
//	std::string str = "string";
//	const char* cptr = "C-string";
//	const char carr[] = "Two and one";
//	std::string output;
//
//	//后附一个"char"类型的字符，共附加"3"个，调用的对应函数原型为：string& append( size_type count, char ch )。
//	output.append(3, '*');
//	std::cout << output << std::endl << std::endl;
//
//	//后附整个字符串("string"类型的对象)，调用的对应函数原型为：string& append( const string& str )。
//	output.append(str);
//	std::cout << output << std::endl << std::endl;
//
//	//后附字符串的一部分，调用的对应函数原型为：string& append( const string& str, size_type pos, size_type count )。
//	output.append(str, 3, 3);
//	std::cout << output << std::endl << std::endl;
//
//	//后附C风格字符串的一部分，调用的对应函数原型为：string& append( const char* s, size_type count )。
//	output.append(1, ' ').append(carr, 4);//链式调用，因为"append"成员函数的返回值为"*this"。
//	std::cout << output << std::endl << std::endl;
//
//	//后附整个C风格字符串，调用的对应函数原型为：string& append( const char* s )。
//	output.append(cptr);
//	std::cout << output << std::endl << std::endl;
//
//	return 0;
//}

//"string"模板类中与操作相关的成员函数示例七：对"string"类对象使用"+="加法赋值运算符。
