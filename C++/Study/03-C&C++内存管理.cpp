#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>

/*
	C&C++内存管理
		1.C/C++内存分布
		2.C中的动态内存管理
		3.C++中的动态内存管理
		4.C中的动态内存管理和C++中的动态内存管理的区别
		5.内存泄漏
*/

/**
	C/C++内存分布：C/C++程序在虚拟进程地址空间中的内存分布，即C/C++程序的内存布局(内存区域划分)。(仅介绍主要内存区域)(以下规则可能在不同操作系统或编译器(链接器)中有所不同)
		1.栈区：即"Stack"内存区域，又被称为堆栈。(注意与数据结构的栈进行区分)
			a.栈区以后进先出(LIFO)的方式添加或删除数据，通常位于内存的较高部分(地址)，在标准的计算机架构中，栈区的地址从高到低增长。
			b.栈区由编译器自动分配释放，并且用于存放或构造非静态局部对象(具有自动存储期的对象)、调用函数时的参数和其他与函数相关的信息等数据。
			c.栈区分配内存的方式是发生在连续的内存块上的，访问数据速度快(相对于堆而言)。
			d.栈区的存储空间较小(相对于堆而言)，若栈区内存不足，会导致程序崩溃(栈溢出)。
		2.堆区：即"Heap"内存区域。(注意与数据结构的堆进行区分)
			a.堆区通常被用于存放程序运行时动态分配的内存，是供程序员分配和释放的内存空间，通常位于栈区的下方(即相对于栈区较低的部分(地址))，但堆区的地址是从低到高增长的。
			b.堆区分配的内存的方式是以随机顺序分配在内存块上的，并且堆上的数据也可能存储为不连续的内存块(已使用的内存块位于未使用的内存块之间)，导致存储在内存块的数据变得碎片化，访问数据速度慢(相对于栈而言)。
			c.堆区的存储空间较大(相对于栈而言)，若堆区内存不足，会导致分配失败。
			d.C/C++中堆区的数据需要程序员以编程的方式进行手动分配和释放，若分配后不释放，则会导致内存泄漏(保持运行的情况下)，直到程序结束才会被操作系统回收。
 		3.未初始化的数据段：即"Block Started by Symbol"段(简称为"BSS"段)。
			a."BSS"段通常存放着未初始化的静态变量(包括全局和局部)和全局变量，并且通常也存放着初始化为零的全局变量和静态变量(指针类型则为空值)。(对于内置类型而言)
			b.在程序开始执行之前(进入主函数前)，该段中的数据将被初始化为零(指针类型则为空值)，包含所有初始化为零或在源代码中没有显式初始化的全局变量和静态变量。
			c.存放在"BSS"段中的数据不会被写入到目标文件中，但会记录未初始化数据在程序装载时所需空间的大小。
			d."BSS"段存在于堆区的下方(相对于堆区较低的部分(地址))。
			e.通常情况下，"BSS"段并不存储以"const"限定符修饰的变量，除非是C语言中未初始化(不包含以隐式或显式的零初始化)的全局常变量(注意不是静态变量)。
				a'.在C语言中，被"const"关键词修饰的变量称之为常变量，实际上是变量而非常量，其只是在语法层面上限制不能被修改，并且在定义时可以不显式初始化。
				b'.在C语言中，若全局的常变量(非静态变量)没有被初始化，则其会被存储在"BSS"段中，但当其被初始化时(包括初始化为零)，则会被存储在已初始化数据段中。
				c'.在C++中，被"const"关键词修饰的变量必须在定义时初始化，所以其通常不会在"BSS"段中存储，即使它们被隐式或显式初始化为零。
		4.已初始化的数据段：即"Initialized Data Segment"段，通常简称为数据段(即"Data Segment"段或"Data"段)。
			a.已初始化的数据段存放着已被初始化的静态变量和全局变量(对于内置类型而言)。
			b.此段在内存区域所占的空间大小将由源代码中的初始化数据的大小决定，并且在运行时不会再改变。
			c.数据段是只读或可读写的，因为变量的值可以在运行时更改，所以该段又可以分为初始化只读区和初始化读写区。
				a'.初始化只读区存放的是由"const"限定符修饰的：静态变量、全局常变量，并且还存放着只读字符串常量等数据。
				b'.初始化读写区存放的是非"const"限定符修饰的：静态变量、全局变量。
			d.该段存在于未初始化的数据段的下方(相对于未初始化的数据段较低的部分(地址))。
		5.代码段：即"Text"段，又被称为文本段。
			a.代码段存放着程序的机器指令，即可执行的指令，即要执行的程序步骤的机器语言表示，其中包括了函数体的二进制代码等。
			b.代码段的大小通常是固定的，并且不可写入，以避免其他内存区域溢出等编程错误覆盖的风险。
*/

////C/C++内存分布示例一：以下为包含多种情况测试代码，请结合"size"命令、"objdump"命令以及编译器编译选项(链接选项)分步测试观测内存分布的情况。(不同操作系统或编译器(链接器)的结果可能不同)
////以零初始化的全局静态常变量：存储于已初始化的数据段中的初始化只读区中。
//const static int csg1 = 0;
//const static int csg2 = 0;
//
////已初始化的全局静态常变量：存储于已初始化的数据段中的初始化只读区中。
//const static int csg3 = 100;
//const static int csg4 = 100;
//
//////未初始化的全局静态常变量(C语言中允许，C++中不允许)：存储于已初始化的数据段中的初始化只读区中(仅对于C语言)。
////const static int csg5;
////const static int csg6;
//
////以零初始化的全局常变量：存储于已初始化的数据段中的初始化只读区中。
//const int cg1 = 0;
//const int cg2 = 0;
//
////已初始化的全局常变量：存储于已初始化的数据段中的初始化只读区中。
//const int cg3 = 100;
//const int cg4 = 100;
//
//////未初始化的全局常变量(C中允许，C++中不允许)：存储于未初始化的数据段中(仅对于C语言)。
////const int cg5;
////const int cg6;
//
////以零初始化的全局静态变量：存储于未初始化的数据段中。
//static int sg1 = 0;
//static int sg2 = 0;
//
////已初始化的全局静态变量：存储于已初始化的数据段中的初始化读写区中。
//static int sg3 = 100;
//static int sg4 = 100;
//
////未初始化的全局静态变量：存储于未初始化的数据段中。
//static int sg5;
//static int sg6;
//
////以零初始化的全局变量：存储于未初始化的数据段中。
//int g1 = 0;
//int g2 = 0;
//
////已初始化的全局变量：存储于已初始化的数据段中的初始化读写区中。
//int g3 = 100;
//int g4 = 100;
//
////未初始化的全局变量：存储于未初始化的数据段中。
//int g5;
//int g6;
//
////字符串字面量：存储于已初始化的数据段中的初始化只读区中。
//const char* cstrg1 = "hello world";//此处的指针为全局变量，存储于已初始化的数据段中的初始化读写区中。
//char* const strcg2 = "hello world";//此处的指针为全局常变量，存储于已初始化的数据段中的初始化只读区中。
//
//int main()
//{
//	//以零初始化的局部静态常变量：存储于已初始化的数据段中的初始化只读区中。
//	const static int csp1 = 0;
//	const static int csp2 = 0;
//
//	//已初始化的局部静态常变量：存储于已初始化的数据段中的初始化只读区中。
//	const static int csp3 = 100;
//	const static int csp4 = 100;
//
//	////未初始化的的局部静态常变量(C中允许，C++中不允许)：存储于已初始化的数据段中的初始化只读区中(仅对于C语言)。
//	//const static int csp5;
//	//const static int csp6;
//
//	//以零初始化的局部常变量：存储于栈中。
//	const int cp1 = 0;
//	const int cp2 = 0;
//
//	//已初始化的局部常变量：存储于栈中。
//	const int cp3 = 100;
//	const int cp4 = 100;
//
//	////未初始化的局部常变量(C中允许，C++中不允许)：存储于栈中(仅对于C语言)。
//	//const int cp5;
//	//const int cp6;
//
//	//以零初始化的局部静态变量：存储于未初始化的数据段中。
//	static int sp1 = 0;
//	static int sp2 = 0;
//
//	//已初始化的局部静态变量：存储于已初始化的数据段中的初始化读写区中。
//	static int sp3 = 100;
//	static int sp4 = 100;
//
//	//未初始化的局部静态变量：存储于未初始化的数据段中。
//	static int sp5;
//	static int sp6;
//
//	//以零初始化的局部变量：存储于栈中。
//	int p1 = 0;
//	int p2 = 0;
//
//	//已初始化的局部变量：存储于栈中。
//	int p3 = 100;
//	int p4 = 100;
//
//	//未初始化的局部变量：存储于栈中。
//	int p5;
//	int p6;
//
//	//字符串字面量：存储于已初始化的数据段中的初始化只读区中。
//	const char* cstrp1 = "hello world";//此处的指针为局部变量，存储于栈中。
//	char* const strcp2 = "hello world";//此处的指针为局部常变量，存储于栈中。
//
//	return 0;
//}

////C/C++内存分布示例二：关于指针是否带"const"修饰符的区别。
//int main()
//{
//	const int* ptr1;//注意"const int*"和"int* const"的区别，前者修饰的是指针所指向的值，代表不可通过指针修改其指向的值，而后者修饰的是指针本身，代表指针本身不可修改其指向。
//	int const* ptr2;//此处的"int const*"等价于"const int*"，都代表不可通过指针修改其指向的值，并且此处都为局部的指针变量，而不是局部的指针常变量，都存储于栈中。
//	//int* const ptr3;//错误，指针常变量"ptr3"必须进行初始化，但若是在C语言中，则允许这样的做法，C++中由"const"修饰符修饰的变量必须进行初始化。
//	int* const ptr4 = nullptr;//正确，此处的局部指针常变量"ptr4"进行了初始化，代表指针本身不可修改其指向，存储于栈中。
//	//const int* const ptr5;//错误，需要进行初始化。
//	const int* const ptr6 = nullptr;//正确，此处的局部指针常变量"ptr6"进行了初始化，代表指针本身不可修改其指向，且此处的指针所指向的值也被限定为不可通过指针修改。
//	return 0;
//}

////C/C++内存分布示例三：关于字符串字面量。
//int main()
//{
//	//字符串字面量：无前缀字符串字面量的类型为"const char[N]"，其中"N"代表了字符串字面量的元素个数，并且包括了字符串字面量的空终止符。(字符串字面量类型不同于C语言中的"char[N]")
//	const char* cstrp1 = "hello world";//此处字符串字面量的类型为"const char[12]"，并且其具有静态存储期，故存储于已初始化的数据段中的初始化只读区中。
//
//	//试图修改字符串字面量会导致未定义行为，它们通常存储于初始化只读区或与其他字符串字面量合并。
//	const char* cstrp2 = "Hello";
//	char* ptr1 = const_cast<char*>(cstrp2);//将字符串字面量的类型转换为"char*"，并将其赋值给指针变量"ptr"。
//	//ptr1[0] = 'A';//未定义行为。
//
//	//C++11前：字符串字面量可转换为且可赋值(初始化)给非"const"的指向"char"类型指针，以与C兼容，因为C中字符串字面量类型为"char[N]"，但在C++11起这种隐式转换被弃用。
//	//C++11起：字符串字面量不可转换为或赋值(初始化)给非"const"的指向"char"类型指针，若想要这种转换则需使用显式转型(例如：const_cast)。
//	//但是，因为有很多现有代码依赖于该隐式转换，若强制禁止该隐式转换则会导致大量的编译错误(破坏代码)，并且不兼容C语言。
//	char* ptr2 = "Hello";//警告，严格意义上为错误：C++11起不允许从字符串字面量转换为"char*"。
//	char* ptr3 = const_cast<char*>("Hello");//正确，使用显式转型，但并不安全。
//	const char* cstrp3 = "Hello";//正确，标准做法。
//
//	//计算字符串字面量的长度例一
//	const char* cstrp4 = "Hello";
//	size_t cstrp4_len = std::strlen(cstrp4);//计算字符串字面量的长度，不包括空终止符。
//	size_t cstrp4_size1 = sizeof(cstrp4);//注意此处的"sizeof"计算的是指针变量的大小，而非字符串字面量的大小。
//	size_t cstrp4_size2 = sizeof("Hello");//计算字符串字面量的大小，包括空终止符。
//	std::cout << "cstrp4_len = " << cstrp4_len << std::endl;//结果为：5。
//	std::cout << "cstrp4_size1 = " << cstrp4_size1 << std::endl;//结果为：4/8。(取决于平台)
//	std::cout << "cstrp4_size2 = " << cstrp4_size2 << std::endl;//结果为：6。
//
//	//计算字符串字面量的长度例二
//	const char* cstrp5 = "abc\0def";
//	size_t cstrp5_len = std::strlen(cstrp5);
//	size_t cstrp5_size = sizeof("abc\0def");
//	std::cout << "cstrp5_len = " << cstrp5_len << std::endl;//"strlen"函数遇到空终止符结束，并且不计入空终止符，故结果为：3。
//	std::cout << "cstrp5_size = " << cstrp5_size << std::endl;//结果为：8。
//
//	return 0;
//}

/**
	C中的动态内存管理
		1.C语言中的动态内存管理相关函数：即通过"malloc"函数、"calloc"函数、"realloc"函数和"free"函数来进行动态内存管理，不再赘述，详见C语言中的"动态内存管理"章节。
		2.关于"malloc"函数、"calloc"函数和"realloc"函数的区别
			a.通常来说，"malloc"函数和"calloc"函数的功能都是在堆区分配内存。
			b.首先就是其使用方法不同，传递参数的意义类似，但"malloc"函数只需传递一个参数，即要分配的内存块的字节数，而"calloc"函数需传递两个参数，即要分配的每个元素的大小和要分配的元素个数。
			c.其次是"calloc"函数会在分配内存后将以零初始化所有分配存储中的字节，即进行"memset"函数的以零填充内存块，而"malloc"函数则不会。
			d.当"malloc"函数与"calloc"函数分配相同大小的内存块时，若在进行"malloc"函数后进行"memset"以零填充内存块，也不代表两函数等价。
			e.比如"calloc(n, sizeof(int))"和"calloc(n * sizeof(int), 1)"并不是等价的，若当"n"小于或等于"SIZE_MAX / sizeof(int)"时确实等价，但一旦当"n"大于"SIZE_MAX / sizeof(int)"时，不等价。
			f.当"n"大于"SIZE_MAX / sizeof(int)"时，"calloc(n, sizeof(int))"会正确设置"errno"为"ENOMEM"并返回"NULL"，即分配失败。
			g.当"n"大于"SIZE_MAX / sizeof(int)"时，"calloc(n * sizeof(int), 1)"会返回"n * sizeof(int)"被截断后(即截断成"64"位的整数)大小的内存块，即分配成功。
			h.这也就说明了其实"malloc(n * sizeof(int))"是不安全的，一旦当"n"为"2 ^ 62"，相乘后变为"2 ^ 64"，超过"SIZE_MAX"，并且截断后为零，故会返回"NULL"或不可用于访问存储的非空指针(根据库定义)，即分配成功，但一旦试图写入而不传递给"free"函数，则会导致出错。
			i.而"calloc"函数设置为两个参数，而不是让用户预先使用"n * sizeof(int)"把它乘起来，是因为"calloc"函数会自动检测两个参数，判断两个参数相乘后是否会溢出，若溢出会正确设置"errno"为"ENOMEM"并返回"NULL"，即分配失败。
			j.所以，"calloc"函数不仅仅具有"memset"函数的以零填充内存块的功能，而且还具有乘法溢出安全检测的功能，但不要以为只要数值不大就无所谓，对于"Linux"内核而言，"n"是来着用户态的数据，可以是任意值，但如果用户态程序恶意输入值，内核可能会崩溃，甚至可能被窃取数据。
			k."relloc"函数的功能不再赘述，关于对于C以及C++不同标准下相关动态内存函数的区别，请参考相关文档，但大致相同。
		3.C语言中"malloc"函数、"calloc"函数、"realloc"函数和"free"函数的相关文档
			a."malloc"函数：https://zh.cppreference.com/w/c/memory/malloc。
			b."calloc"函数：https://zh.cppreference.com/w/c/memory/calloc。
			c."realloc"函数：https://zh.cppreference.com/w/c/memory/realloc。
			d."free"函数：https://zh.cppreference.com/w/c/memory/free。
		4.C++语言中"malloc"函数、"calloc"函数、"realloc"函数和"free"函数的相关文档
			a."malloc"函数：https://zh.cppreference.com/w/cpp/memory/c/malloc。
			b."calloc"函数：https://zh.cppreference.com/w/cpp/memory/c/calloc。
			c."realloc"函数：https://zh.cppreference.com/w/cpp/memory/c/realloc。
			d."free"函数：https://zh.cppreference.com/w/cpp/memory/c/free。
*/

////C中的动态内存管理示例一：关于"size_t"类型溢出的问题。
//int main()
//{
//	std::cout << SIZE_MAX << std::endl;//结果为：18,446,744,073,709,551,615。
//	std::cout << SIZE_MAX / sizeof(int) << std::endl;//结果为：4,611,686,018,427,387,903。(向零取整)
//	std::cout << (SIZE_MAX / sizeof(int) + 1) * sizeof(int) << std::endl;//结果为：0。
//	return 0;
//}

////C中的动态内存管理示例二：C++中使用C语言中的动态内存函数。
//int main()
//{
//	int* p1 = (int*)std::malloc(sizeof(int) * 10);
//	std::free(p1);
//
//	int* p2 = (int*)std::calloc(10, sizeof(int));
//	std::free(p2);
//
//	int* p3 = (int*)std::realloc(nullptr, sizeof(int) * 10);//此处相当于"malloc"函数。
//	p3 = (int*)std::realloc(p3, sizeof(int) * 100);//对"p3"指针指向的内存块进行扩容，并重新赋值给"p3"。
//	std::free(p3);
//
//	return 0;
//}

/**
	C++中的动态内存管理
		1.C++中对于动态内存的分配和释放
		2.分配函数和解分配函数
		3."new"运算符的分配和构造以及"delete"运算符的析构和解分配
		4.布置"new"表达式
*/

/***
	C++中对于动态内存的分配和释放：C语言的动态内存管理方式在C++中可以继续使用，但是C++中也提供了自己的动态内存管理方式，即"new"运算符和"delete"运算符。(当前阶段为不全面介绍，即有些规定是需要通过后续的学习才能了解的)
		1."new"运算符和"delete"运算符将以更好、更简单的方式执行分配和释放动态内存的任务。并在已申请的存储空间上，
		2."new"运算符：尝试在堆上申请存储空间，若有足够的空间(即申请成功)，那么"new"运算符会尝试构造(初始化)一个无名的对象或对象数组，并将处理完毕的内存空间的地址返回给指针变量，否则可能会抛出异常。(暂列举两种使用方式)
			a.使用方式一：通过":: new (类型) 初始化器"方式使用"new"运算符，其中"类型"可以是任意数据类型(已存在)，包括内置类型、自定义类型和数组类型，其中的"::"作用域限定符和"初始化器"是可选的(某些情况下必需提供)。
			b.使用方式二：通过":: new new类型 初始化器"方式使用"new"运算符，与上述的"a'"相同，但是"new类型"是不包含括号的，这种方式的好处是可以省略括号，类似于"sizeof int"的写法。
				a'.这种方式会有一些副作用，比如在创建一个复合的数据类型的对象时，可能会被解析成这种形式，导致语法错误，所以需要显式的加上括号变为"a'"的使用形式。
				b'.这种方式的"new"运算符是贪心的，它将尽量包含能够成为类型标识一部分的所有记号，直到遇到一个不能成为类型标识的记号为止。
			c."初始化器"是可选的，但在某些情况下是必需的，比如方式一中的"类型"和方式二中的"new类型"都是数组类型时，并且是未知边界(即"[]")数组时，必须提供"初始化器"。(C++11中可以使用"{}"来初始化数组)
		3."delete"运算符：销毁先前由"new"表达式分配的对象，并释放获得的内存区域，即从堆上释放已分配的内存。
			a.使用方式一：通过":: delete 表达式"方式使用"delete"运算符，表示销毁"new"创建的单个非数组对象，其中的"::"作用域限定符是可选的。
				a'."表达式"必须是指向对象类型的指针或是可以按语境隐式转换到这种类类型的指针，且它的值必须为空或指向"new"所创建的非数组对象的指针，也可以是"new"所创建的对象的基类子对象的指针(暂不考虑)，否则行为未定义。
				b'."表达式"的被指向类型必须与该对象(或基类子对象(暂不考虑))的类型匹配或相似，即如果"表达式"是其他不相干的值，包括它是通过"new"表达式的数组形式获得的指针的情况(应该使用方式二)，那么行为未定义。
			b.使用方式二：通过":: delete[] 表达式"方式使用"delete"运算符，与上述的"a'"类似，但其是表示销毁"new"创建的数组。
				a'."表达式"必须是空指针值或是先前由"new"所创建的数组形式所获得的指针值。
				b'."表达式"的被指向类型必须与数组对象的元素类型匹配，即如果"表达式"是其他不相干的值，包括它是通过"new"表达式的非数组形式获得的指针的情况(应该使用方式一)，那么行为未定义。
			c."delete"运算符的返回值是"void"类型，即不返回任何值。
		4.关于"new"运算符和"delete"运算符中，使用方式中的"::"作用域限定符具有的作用，以及"new"运算符和"delete"运算符在此阶段的更多细节，将会在下几个小节介绍。
*/

////C++中对于动态内存的分配和释放示例一：使用"new"和"delete"运算符。
//int main()
//{
//	//分配及释放单个"int"类型大小的存储空间，"new"运算符的使用方式一，"delete"运算符的使用方式一。
//	int* ptr1 = new (int);//不带有初始化器，在此处意为在堆上分配一个整型大小对象的空间，处理完毕后，返回的内存空间的地址用于初始化指针"ptr1"。
//	delete ptr1;//用于释放"new"运算符在堆上分配的内存，即释放"ptr1"指向的内存区域。
//
//	//分配及释放"int"类型的数组大小的存储空间，"new"运算符的使用方式一，"delete"运算符的使用方式二。
//	int* ptr2 = new (int[10]);//在堆上创建一个"int [10]"类型的数组，其元素类型为"int"，元素个数为"10"。
//	//delete ptr2;//未定义行为，此处是"delete"运算符的使用方式一，此处的"表达式"是通过"new"表达式的数组形式获得的指针，类型不匹配，应该使用方式二。
//	delete[] ptr2;//此处表示销毁"new"运算符在堆上创建的数组，即释放"ptr2"指向的内存区域。
//
//	//分配及释放单个"int"类型大小的存储空间，"new"运算符的使用方式二，"delete"运算符的使用方式一。
//	int* ptr3 = new int;
//	delete ptr3;
//
//	//分配及释放"int"类型的数组大小的存储空间，"new"运算符的使用方式二，"delete"运算符的使用方式二。
//	int* ptr4 = new int[10];
//	delete[] ptr4;
//
//	//附带圆括号初始化器，初始化存放单个"int"类型大小的存储空间。
//	int* ptr5 = new int(10);//在堆上分配一个整型大小对象的空间，并对该内存空间进行初始化，即将"10"赋值给该内存空间，处理完毕后，返回的内存空间的地址用于初始化指针"ptr5"。
//	int* ptr6 = new (int)(10);//等价于上一行，只是"new"运算符的使用方式不同。
//	std::cout << *ptr5 << std::endl;
//	std::cout << *ptr6 << std::endl;
//	delete ptr5;
//	delete ptr6;
//
//	//附带花括号初始化器，初始化存放"int"类型的数组。(C++11起)
//	int* ptr7 = new int[10]{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//	//int* ptr8 = new int[];//错误，必须指定数组的大小(C++11前)或提供初始化器(C++11起)。
//	int* ptr9 = new int[]{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };//正确，C++11起，可提供初始化器以确定数组的大小。
//	delete[] ptr7;
//	delete[] ptr9;
//
//	return 0;
//}

////C++中对于动态内存的分配和释放示例二："new"运算符使用方式二的副作用。
//int main()
//{
//	//解析错误示例
//	//auto ptr1 = new int(*[10])();//看起来像是在堆上创建了一个"int (*[10])()"类型的数组，其元素类型为"int (*)()"，即函数指针，但实际上是错误的语法，被编译器解释为"new int"后随"(*[10])()"。
//	auto ptr2 = new (int (* [10])());//正确的语法，表示在堆上创建一个"int (*[10])()"类型的数组，其元素类型为"int (*)()"，即函数指针。
//	delete[] ptr2;
//
//	//贪心解析示例
//	auto ptr3 = new int + 1;//根据贪心法，读入"int"后继续读入"+"发现无此类型标识，故被解析成"new int"，而后随的"+ 1"表示增加"new int"所返回的指针。
//	//auto ptr4 = new int * 1;//错误的语法，根据贪心法，读入"int"后继续读入"*"表示指针类型，即被解析为"new int *"，但是后面的"1"就无法解析了。
//	delete ptr3;
//
//	return 0;
//}

/***
	分配函数和解分配函数(仅讲解重要部分)
		1.分配函数：即"operator new"和"operator new[]"全局函数，它们具有多种形式的变体，用于尝试分配请求数量的字节，而且分配请求可能会失败(即使请求分配的字节数为零)。
			a.分配函数会被"new"运算符调用，以分配将被初始化的对象或对象数组所在的内存，它们也可以通过常规函数调用语法调用。
				a'.标准实现中多种形式变体的分配函数的第一个参数总是一个"size_t"类型的值，表示要分配的字节数。
				b'.标准实现中多种形式变体的分配函数的返回值总是一个"void*"类型的值，表示已分配的内存空间的地址，若分配失败则可能抛出异常或返回空指针。
			b.分配函数是由库中的实现提供的，被包含于"new"头文件中，但即使不包含该头文件，它们也会被编译器隐式声明，并且也可以自定义和重载这些函数，从而替换掉原有的标准库默认实现(需符合规定，并且有一些形式的分配函数不能被替换)。
			c.程序中可提供这些分配函数的全局和类特有替换函数，而::"作用域限定符就是用于忽略类中的这些替换函数的。
			d.在调用分配函数时，"new"运算符会将请求的字节数作为"std::size_t"类型的第一参数传递给它。
			e.分配函数的行为类似于"malloc"函数，甚至在一些库实现中会在分配函数中调用"malloc"函数，但是标准规定中是否产生任何对"malloc"函数的调用是未指定的。
			f.通常情况下，分配函数会在分配失败时抛出异常，而不是返回空指针，但这仅是分配函数众多形式的一部分，也有其他形式的分配函数会返回空指针。(异常处理机制将在后续章节中进行介绍)
		2.解分配函数：即"operator delete"和"operator delete[]"全局函数，它们也具有多种形式的变体，用于解分配先前由匹配的分配函数所分配的存储空间。
			a.解分配函数会被"delete"运算符与"new"运算符调用，以在析构(或构造失败)拥有动态存储期的对象后解分配内存，它们也可以用常规函数调用语法调用，并且标准实现中多种形式变体的解分配函数的第一个参数总是一个指向要解分配的内存块的无类型指针(即"void*")(也可以是指向空指针)。
			b.解分配函数同样被包含于"new"头文件中，并且与分配函数一样，也可以被自定义和重载，从而替换掉原有的标准库默认实现(需符合规定，并且有一些形式的解分配函数不能被替换)。
			c.在库实现的解分配函数的所有形式中，如果解分配函数接收的是空指针，那么标准库解分配函数不做任何事情，并且如果传递给标准库解分配函数的指针不是从对应的标准库分配函数取得的指针，那么行为未定义。
			d.在标准库解分配函数返回后，所有指向被解分配存储空间的任何部分的指针都变为非法，并且通过已因此方式变为非法的指针解引用，以及将它传递给解分配函数(双重"delete")是未定义行为。
			e.解分配函数也会在解分配失败时抛出异常，如果解分配函数以抛异常终止，那么行为未定义。
*/

////分配函数和解分配函数示例一：显式调用分配函数和解分配函数。
//int main()
//{
//	//显式调用分配函数，在堆上分配一个"int"类型大小的空间。
//	int* p = (int*)operator new(sizeof(int));//显式调用标准实现中多种形式变体的分配函数的其中一种(也是较为常见的一种)，并且接收此形式的分配函数的返回值需要进行强制类型转换。
//
//	//显式调用解分配函数，解分配堆上的内存。
//	operator delete(p);//显式调用标准实现中多种形式变体的解分配函数的其中一种(也是较为常见的一种)，标准实现中多种形式变体的解分配函数的第一个参数总是一个指向要解分配的内存块的无类型指针(即"void*")。
//
//	return 0;
//}

////分配函数和解分配函数示例二：当分配失败时会抛出异常的分配函数。(不必深究内存泄漏)
//void Test()
//{
//	while (1)
//	{
//		char* p1 = (char*)operator new(1024 * 1024 * 1024);//通常情况下，当分配函数分配失败时，会抛出异常。(仅代表标准库中可替换的分配函数形式，但一些形式的分配函数不抛出异常)
//		std::cout << (void*)p1 << std::endl;//不进行类型转换无法打印堆区地址。
//	}
//}
//
//int main()
//{
//	//以下是捕获异常的一种方式，暂不需要深入理解。
//	try
//	{
//		Test();
//	}
//	catch (const std::bad_alloc& e)
//	{
//		std::cout << e.what() << std::endl;//输出异常信息，即"std::bad_alloc"。
//	}
//
//	return 0;
//}

////分配函数和解分配函数示例三：自定义分配函数和解分配函数。
//void* operator new(std::size_t count)//可替换的分配函数形式中的一种，被非数组形式的"new"运算符调用，自定义此形式分配函数，替换掉标准库默认实现。
//{
//	std::printf("\"new\"运算符已调用分配函数，大小为：%zu。\n", count);
//
//	//避免调用"malloc"函数时传递的参数为零，导致可能会在分配成功时返回空指针。
//	if (count == 0)
//		++count;//此处为了排除"count"为零的情况，简单的将"count"加一，但这是为了此示例做出的简单处理，实际上应该根据实际情况来处理。
//
//	if (void* ptr = std::malloc(count))//检查"malloc"函数是否成功分配了内存，如果"malloc"返回空指针，那么不进入"if"语句体。
//		return ptr;
//
//	throw std::bad_alloc{};//"std::bad_alloc"是分配函数作为异常抛出的对象类型，以报告存储分配失败。(了解即可)
//}
//
//void operator delete(void* ptr)//可替换的解分配函数形式中的一种，被非数组形式的"delete"运算符调用，自定义此形式解分配函数，替换掉标准库默认实现。
//{
//	std::printf("\"delete\"运算符已调用解分配函数，释放内存块：%p。\n", ptr);
//	free(ptr);//调用标准库的"free"函数，解分配内存。
//}
//
//int main()
//{
//	int* p1 = new int;
//	delete p1;
//
//	auto p2 = new (int*);
//	delete p2;
//
//	return 0;
//}

/***
	"new"运算符的分配和构造以及"delete"运算符的析构和解分配
		1."new"运算符的分配和构造
			a."new"运算符通过调用合适的分配函数分配存储空间，并且其所创建的对象或数组会根据"初始化器"选择对应的初始化方式。
				a'.如果其"类型"或"new类型"是非数组类型，那么"new"运算符会调用函数名为"operator new"的分配函数分配内存，并且在所取得的内存区域中构造单个对象。
					a''.如果没有"初始化器"，那么对象会被默认初始化。
					b''.如果"初始化器"是带圆括号的实参列表，那么对象会被直接初始化。
					c''.如果"初始化器"是花括号包围的实参列表，那么对象会被列表初始化。(C++11起)
				b'.如果"类型"或"new类型"是数组类型，那么"new"运算符会调用函数名为"operator new[]"的分配函数分配内存，并且在所取得的内存区域初始化一个数组的对象。
					a''.如果没有"初始化器"，那么每个元素都会被默认初始化。
					b''.如果"初始化器"是一对空括号，那么每个元素被值初始化。
					c''.如果"初始化器"是花括号包围的实参列表，那么数组会被聚合初始化。(C++11起)
					d''.如果"初始化器"是带圆括号的实参列表，那么数组会被聚合初始化。(C++20起)
			b."new"运算符的内部行为
				a'.内置类型：如果"new"运算符被用于内置类型，那么它会调用对应的分配函数，若分配成功，根据初始化器初始化得到的内存空间(若无初始化器则不初始化)，随后返回内存空间的地址，否则抛出异常或返回空指针(视调用的分配函数的形式而定)。
				b'.自定义类型：大致与内置类型相同，但是在成功分配内存空间之后，会根据初始化器调用此类对应的构造函数(若无初始化器则调用默认构造函数)，从而完成存储在内存空间的类类型对象的初始化。
					a''.如果此处的"类型"或"new类型"是数组类型，成功分配内存空间之后，它会对数组的每个元素调用它的构造函数，即会调用"N"次构造函数，其中"N"是数组的元素个数。
				c'.标准库实现的分配函数存在相互调用的情况(仅在一些形式的分配函数中)，因为它们是可以相互利用的。(以下为不完全列举)(不同的标准库实现可能会有所不同)
					a''.抛出异常的"operator new[]"会调用抛出异常的"operator new"。
					b''.不抛出异常的"operator new"会调用抛出异常的"operator new"，并在失败时不传播异常而改为返回一个空指针。
					c''.不抛出异常的"operator new[]"会调用抛出异常的"operator new[]"，并在失败时不传播异常而改为返回一个空指针。
			c.如果初始化时因抛出异常而终止(例如来自构造函数)，那么"new"运算符会在已经分配了任何存储空间的情况下调用对应的解分配函数(以限定的域及规则查找)。
			d.与C语言类似，"new"运算符所创建的对象(存储在堆上，具有动态存储器的对象)的生命周期会持续到将"new"运算符所返回来的指针用于匹配的"delete"运算符之时，但如果指针的值丢失，那么对象不可达且无法解分配，即发生内存泄漏。
		2."delete"运算符的析构和解分配
			a."delete"运算符的内部行为
				a'.内置类型：如果"delete"运算符被用于内置类型，那么它会直接调用对应的解分配函数，释放对象的空间(若是空指针，则解分配函数什么都不做)。
				b'.自定义类型：如果"delete"运算符被用于自定义类型，并且"表达式"不是空指针，那么它会先调用此类对应的析构函数完成对象中资源的清理工作，然后再调用对应的解分配函数，释放对象的空间。
					a''.如果是以"delete[]"的方式释放数据，那么它对要被销毁的数组的每个元素，调用它的析构函数，即会调用"N"次析构函数，其中"N"是数组的元素个数。
					b''.无论析构函数是否抛出异常，都会调用对应的解分配函数。
			b.如果"delete"运算符的"表达式"求值为空指针值，那么不会调用析构函数，且可能会也可能不会调用解分配函数(未指明)，但默认的解分配函数保证在传递了空指针时不做任何事。
			c.如果"delete"运算符的"表达式"求值为指向"new"运算符所分配的对象的基类子对象的指针，那么基类的析构函数必须是虚函数，否则行为未定义。(暂不考虑)
*/

////"new"运算符的分配和构造以及"delete"运算符的析构和解分配示例："new"运算符的内部行为和"delete"运算符的内部行为。
//struct Test
//{
//	Test()
//	{
//		std::cout << "Test()" << std::endl;
//	}
//
//	~Test()
//	{
//		std::cout << "~Test()" << std::endl;
//	}
//};
//
//void* operator new(std::size_t count)
//{
//	std::printf("\"new\"运算符已调用分配函数，大小为：%zu。\n", count);
//
//	if (count == 0)
//		++count;
//
//	if (void* ptr = std::malloc(count))
//		return ptr;
//
//	throw std::bad_alloc{};
//}
//
//void operator delete(void* ptr)
//{
//	std::printf("\"delete\"运算符已调用解分配函数，释放内存块：%p。\n", ptr);
//	free(ptr);
//}
//
//int main()
//{
//	Test* p = new Test;
//	delete p;
//	return 0;
//}

/***
	布置"new"表达式：又称为定位"new"表达式。(了解即可)
		1.在常规"new"运算符的"类型"或"new类型"前，以及"::"作用域运算符之后，存在着"(布置参数)"，这就是使用布置"new"表达式的方式。
		2.当提供了布置参数，那么它们会作为额外实参传递给布置分配函数。
		3.标准库实现的布置分配函数通常不对布置参数做任何事情，但它会在分配函数中将布置参数传递给构造函数(适用于类)，从而达到在已分配的存储中构造对象的目的。
*/

////布置"new"表达式示例：使用布置"new"表达式。
//struct Test
//{
//	int x;
//
//	Test(int x = 0) : x(0)
//	{
//		std::cout << "Test()" << std::endl;
//	}
//
//	~Test()
//	{
//		std::cout << "~Test()" << std::endl;
//	}
//};
//
//int main()
//{
//	Test* p = (Test*)malloc(sizeof(Test));//使用"malloc"函数分配内存，不调用构造函数。
//
//	new(p)Test(1);//使用布置"new"表达式在已分配的内存中构造对象，布置分配函数中会调用构造函数(并且不对布置参数进行任何工作，结束调用后返回布置参数)，从而达到在已分配的内存中构造对象的目的。
//
//	delete p;
//
//	return 0;
//}

/**
	C中的动态内存管理和C++中的动态内存管理的区别
		1."malloc"函数和"new"运算符：都从堆上申请空间，并且都需要手动进行释放。
			a.一个为函数，而另一个为运算符。
			b."malloc"函数不会初始化存储空间，而"new"运算符会进行初始化，并且当构造类对象时，"malloc"函数不会调用构造函数，而"new"运算符在申请空间后会调用构造函数。
			c."malloc"函数申请空间时，需要手动计算空间大小并传递(不安全)，而"new"运算符并不需要，它会根据类型自动计算所需空间大小。
				a'.如果使用"new"运算符请求分配存储"char"和"unsigned char"类型的数组的空间时，它还可能从分配函数请求额外的内存，以保证所有不大于请求数组大小的类型的对象在放入所分配的数组中时能够正确对齐。
				b'.C++17起，"std::byte"类型的数组也同样会请求额外的内存。
			d.C++使用"malloc"函数需要进行类型转换，因其返回值为"void*"，C++中不允许将空类型指针隐式转换为其他任意指针类型(C中允许)，但可以从任意指针类型隐式转换为空类型指针，而直接使用"new"运算符申请空间时，并不需要进行类型转换，它返回准确的数据类型。
			e."new"运算符增加了异常安全性，当"new"运算符无法分配所需的内存时，它会抛出异常，而"malloc"函数则不会。
		2."free"函数和"delete"运算符：都用于释放堆上的空间。
			a.一个为函数，而另一个为运算符。
			b.对于自定义类型来说，"free"函数不会调用析构函数，而"delete"运算符在释放空间前会调用析构函数完成对内存空间中资源的清理。
			c."free"函数适用于解分配先前由"malloc"函数、"calloc"函数、"aligned_alloc"函数(C++17起)或"realloc"函数分配的内存空间或空指针，而"delete"运算符适用于解分配先前由"new"运算符分配的内存空间或空指针。
*/

/**
	内存泄漏：https://en.wikipedia.org/wiki/Memory_leak。
*/