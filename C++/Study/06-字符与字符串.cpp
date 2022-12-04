#include <iostream>
#include <string>//注意区分C语言的"string.h"头文件(包含C语言关于字符串的函数等)，此处的头文件指代C++字符串库。
#include <cassert>

/*
	字符与字符串
		1.计算机中表达字符的方式
		2.关于C/C++的字符串字面量和字符串
		3.C++字符串库介绍
		4."string"模板类
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
	"string"模板类：来自于"basic_string"模板类对于"char"类型的特化，定义于头文件"string"中，简称为"string"类。
		1."string"类的定义："string"类使用"typedef"关键词进行了重定义，即"typedef basic_string<char> string;"(此处忽略了命名空间)，故"string"类的定义实际上为"basic_string<char>"。
		2."string"类的常见构造函数的函数原型(以下函数原型忽略命名空间、分号以及分配器等)
			a."string()"：构造空"string"，由此构造函数构造出的对象拥有零大小和未指定的容量。
				a'.复杂度为常数级别。
			b."string(const char* s)"：以"s"所指向的空终止字符串的副本所初始化的内容构造"string"，并以首个空终止符确定字符串的长度。
				a'.若区间"[s, s + char_traits<char>::length(s))"不是合法范围(例如当"s"是空指针时，则不是合法范围)，则行为未定义。("char_traits<char>::length(s)"表示"s"所指向的空终止字符串的长度，暂时不用理解)
				b'.复杂度与"s"的长度成线性级别。
			c."string(const char* s, size_type count)"：以"s"所指向的字符串的首"count"个字符构造"string"，并且"s"可能含有空终止符，"string"的长度为"count"。
				a'.若区间"[s, s + count)"不是合法范围，则行为未定义。
				b'.复杂度与"count"成线性级别。
			d."string(size_type count, char ch)"：构造拥有字符"ch"的"count"个副本的"string"。
				a'.复杂度与"count"成线性级别。
			e."string(const string& other)"：拷贝构造函数，用于构造拥有"other"内容副本的"string"，即构造出的"string"与"other"相同。
				a'.复杂度与"other"的大小(长度)成线性级别。
			f."string(const string& other, size_type pos, size_type count = npos)"：以"other"的位置区间"[pos, pos + count)"所对应的子串构造"string"。
				a'."pos"代表的是位置，是要包含的首字符位置，位置从零开始，而"count"代表的是个数，是产生的"string"长度，个数从一开始，注意区分两者。
				b'."npos"为特殊值，是"basic_string"类中的静态成员常变量，类型为"size_type"，其用于表示"size_type"类型的最大值，即"-1"。
				c'.若"count"与"npos"相等或未指定"count"，或请求的子串越过了此字符串的结尾(越过结尾表示越过字符串的长度减一所对应的位置)，则产生的子串的位置区间为"[pos, other.size())"。
				d'.复杂度与"count"成线性级别。
		3."string"类对象的元素访问以及遍历方式
			a."[]"下标成员访问运算符：用于访问"string"类对象中指定位置的字符，内部是关于"operator[]"的运算符重载函数。
				a'.函数原型(C++20前)
					a''.reference operator[]( size_type pos );。
					b''.const_reference operator[]( size_type pos ) const;。(注意此处的构造函数被"const"限定符修饰)
				b'.参数"pos"表示要访问以及返回的字符位置，位置从零开始。
				c'.返回值"reference"表示对字符的引用，而"const_reference"表示对字符的常引用。(以下所指的字符串大小是不包括空终止符的)
					a''.被引用的对象的类型根据模板类"basic_string"所特化的类型而定，对于"string"模板类而言，其引用类型为"char&"和"const char&"。
					b''.在"pos"位置小于对应字符串的大小时，返回到位于指定位置"pos"的字符的引用(实际上是"*(begin() + pos)"，"begin"函数将在之后的迭代器进行介绍)。
					c''.在"pos"位置等于对于字符串的大小时，返回空字符的引用，不进行边界检查。
						a'''.C++11前，对于函数原型"a''"，如果"pos"位置等于对应字符串的大小，那么行为未定义。
						b'''.C++11起，对于函数原型"a''"，如果"pos"位置等于对应字符串的大小，若对返回的引用指代的对象被修改成空字符以外的值时，那么行为未定义。
					d''.在"pos"位置大于对应字符串的大小时，行为未定义。
				d'.复杂度为常数级别。
*/

////"string"模板类示例一：使用"string"模板类。
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

////"string"模板类示例二：使用"string"模板类的常见构造函数。
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