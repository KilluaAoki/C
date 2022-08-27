#include <stdio.h>

/*
	程序环境和预处理
		1.程序的翻译环境和执行环境
		2.C语言程序的编译与链接
		3.预定义符号介绍
		4.预处理指令"#define"宏定义
		5.预处理指令"#undef"移除宏定义
		6.命令行定义
		7.条件编译
		8.预处理指令"#include"包含头文件
		9.其他预处理指令
*/

/**
	程序的翻译环境和执行环境
		1.翻译环境：在这个环境中源代码被转换为可执行的机器指令。
			a.组成一个程序的每个源文件通过编译过程分别转换成目标代码(object code)。
			b.每个目标文件由链接器(linker)捆绑在一起，形成一个单一而完整的可执行程序。
			c.链接器同时也会引入C标准库中任何被该程序所用到的函数，而且它可以搜索程序员个人的程序库，将其需要的函数也链接到程序中。
		2.执行环境(运行环境)：用于实际执行代码。
			a.程序必须载入内存中。
				a'.在具有操作系统的环境中：程序的载入一般由操作系统完成。
				b'.在独立环境中：程序的载入必须手工安排，也可能是通过可执行代码置入只读内存来完成。
			b.开始执行程序，即调用"main"函数。
			c.执行程序代码，程序将使用一个运行时堆栈(stack)，存放内存函数的局部变量和返回地址；程序同时也可以使用静态(staic)内存，存储于静态内存中的变量，并在整个执行过程中一直保留他们的值。
			d.终止程序：正常终止"main"函数，也有可能程序是意外终止。
*/

/**
	C语言程序的编译与链接：详解源文件如何变成可执行程序。
		1.在翻译环境下，源代码程序首先经由编译器进行编译操作。
			a.首先进行预处理操作(预编译)(文本操作)，在此阶段会完成"#include"头文件的包含、"#define"定义的符号和宏的替换、删除注释。
			b.完成预处理操作后进入编译操作，即将源代码转换成汇编代码，在此阶段会完成语法分析、词法分析、语义分析、符号汇总。
			c.完成编译操作后正式进入汇编操作，即将汇编代码转换成机器指令(二进制代码)，在此阶段会生成符号表。
		2.在翻译环境下，编译器操作完成，交由链接器进行链接操作，即将多个目标文件与链接库进行链接。
			a.完成合并段表操作，即把相关文件对应的段链接到一起。
			b.完成符号表的合并和符号表的重定位。
		3.完成翻译环境，进入执行环境。
*/

/**
	预处理符号介绍
		1."__FILE__"：进行编译的源文件路径(文件名)。
		2."__LINE__"：当前的行号。
		3."__DATE__"：文件被编译的日期。
		4."__TIME__"：文件被编译的时间。
		5."__STDC__"：如果编译器遵循"ANSI C"标准，则其值为"1"，否则行为未定义。
		6."__FUNCTION__"：返回所在函数的函数名。
*/

////预处理符号使用示例
//int main()
//{
//	//printf("%d\n", __STDC__);//于"VS2022"中无法使用。
//	printf("%s\n", __FILE__);
//	printf("%d\n", __LINE__);
//	printf("%s\n", __DATE__);
//	printf("%s\n", __TIME__);
//	printf("%s\n", __FUNCTION__);
//	return 0;
//}

////使用预处理符号生成日志文件
//int main()
//{
//	FILE* ptr;
//	fopen_s(&ptr, "Log.txt", "w+");
//	if (ptr == NULL)
//	{
//		perror("fopen");
//		return 1;
//	}
//
//	fprintf(ptr, "Log->%s %s %s %s.\n", __FILE__, __FUNCTION__, __DATE__, __TIME__);
//
//	fclose(ptr);
//	ptr = NULL;
//	return 0;
//}

/**
	预处理指令"#define"宏定义：在预处理阶段，由"#define"定义的宏等，会进行替换，即允许把参数替换到文本中，这种实现通常称为宏或定义宏。
		1.定义标识符常量
			a.在定义标识符常量时一般无需加上分号，若加上分号容易导致问题，因为预处理操作替换后多出的分号会被当成空语句，可能会导致语法错误。
			b.不可用于替换注释符号。
		2.定义宏
			a.宏的声明方式为："#define name(parament-list) stuff"。
				a'.其中的"parament-list"是一个由逗号隔开的符号表，它们可能出现在"stuff"中。
				b'.参数列表的左括号必须与"name"相邻，如果两者之间有任何空白存在，参数列表就会被解释为"stuff"的一部分。
			b.用于对数值表达式进行求值的宏定义需要加上括号，避免在使用宏时由于参数中的操作符或邻近操作符之间产生的不可预料的相互作用。
		3."#define"的替换规则
			a."#define"的替换步骤
				a'.在调用宏时，首先对参数进行检查，寻找是否包含任何由"#define"定义的符号，如果是，它们首先被替换。
				b'.替换文本随后被插入到程序中原来文本的位置；对于宏，参数名则被他们的值所替换。
				c'.最后，再次对结果文件进行扫描，寻找是否包含任何由"#define"定义的符号，如果是，就重复上述处理过程。
			b.宏参数以及"#define"定义中可以出现其他"#define"定义的变量，但是宏不能出现递归。
			c.当预处理器搜索"#define"定义的符号时，字符串常量中的内容并不被搜索。
		4.预处理符号"#"和"##"
			a."#"预处理符号可将一个宏参数变成对应的字符串(名称)。
			b."##"预处理符号可以把位于它两边的符号合成一个符号，它允许宏定义从分离的文本片段创建标识符，并且这样的连接必须产生一个合法的标识符，否则行为未定义。
		5.带副作用的宏参数：当宏参数在宏的定义中出现超过一次的时候，如果参数带有副作用(表达式求值的时候出现的永久性效果)，那么你在使用这个宏的时候就可能导致不可预测的后果。
		6.宏和函数的对比
			a.代码长度：宏每次使用时，宏代码都会被插入到程序中，除了非常小的宏之外，程序的长度会大幅度增长；而函数的函数代码只出现于一个地方，每次使用函数时，都调用那个地方的同一份代码。
			b.执行速度：宏相对于函数较快，因为函数的调用和返回存在额外的开销，所以相对慢一些。
			c.操作符优先级：宏参数的求值是在所有周围表达式的上下文环境里，邻近操作符的优先级可能会产生不可预料的后果；函数参数只在函数调用的时候求值一次，它的结果值传递给函数，表达式的求值结果更容易预测。
			d.带有副作用的参数：参数可能被替换到宏体中的多个位置，所以带有副作用的参数求值可能会产生不可预料的结果；函数参数只在传参的时候求值一次，结果更容易控制。
			e.参数类型：宏的参数与类型无关，只要对参数的操作是合法的，它就可以使用于任何参数类型；函数的参数是与类型有关的，如果参数的类型不同，就需要不同的函数，尽管它们执行的任务是不同的。
			f.调试：宏是不方便调试的；函数可以逐语句进行调试。
			g.递归：宏是不能递归的；函数是可以递归的。
		7.宏的命名规则：宏的名称一般为全大写。
*/

////"define"定义标识符常量示例
//#define MAX 100//定义数值宏常量。
//#define REG register//定义字符串宏常量。
//#define DO_FOREVER for(;;)//用更形象的符号来替换一种实现。
//#define DEBUG_PRINT printf("File:%s Line:%d \
//Date:%s Time:%s\n",\
//__FILE__,__LINE__ ,\
//__DATE__,__TIME__ )//"\"：若一条语句过长，可使用接续符"\"连接上下两行，实际上就是转义了回车符号。
//#define BSC //
//
//int main()
//{
//	printf("%d\n", MAX);
//
//	REG int fast = 0;
//	printf("fast:%d.\n", fast);
//
//	DEBUG_PRINT;
//
//	//DO_FOREVER;//死循环。
//
//	//BSC My Single-line Comment//注释先于预处理指令被处理，当预处理被展开成"//"时，注释已处理完毕，故发生错误；因此，试图用宏开始或结束一段注释是不行的；"/**/"注释同理。
//
//	return 0;
//}

////"#define"定义宏示例：得出以下代码的运行结果，并进行解释。
//#define SQUARE1(X) X*X
//#define SQUARE2(X) (X)*(X)
//#define DOUBLE1(X) (X)+(X)
//#define DOUBLE2(X) ((X)+(X))
//
//int main()
//{
//	int num = 10;
//	printf("%d\n", SQUARE1(num + 1));//编译替换后代码为：10+1*10+1，故输出结果为：21。
//	printf("%d\n", SQUARE2(num + 1));//编译替换后代码为：(10+1)*(10+1)，故输出结果为：121。
//	printf("%d\n", 10 * DOUBLE1(num + 1));//编译替换后代码为：10*(10+1)+(10+1)，故输出结果为：121。
//	printf("%d\n", 10 * DOUBLE2(num + 1));//编译替换后代码为：10*((10+1)+(10+1))，故输出结果为：220。
//	return 0;
//}

////"#define"替换规则示例
//#define NUM 100
//#define MAX(X, Y) (((X)>(Y))?(X):(Y))
//
//int main()
//{
//	printf("%d\n", MAX(10, NUM));//宏参数可以出现其他"#define"定义的变量。
//	printf("NUM = %d\n", NUM);//字符串常量中的内容并不被搜索。
//}

////预处理符号"#"和"##"使用示例
//#define PRINT(X, FORMAT) printf("The value of "#X" is "FORMAT"\n",X)//"#"预处理符号可将一个宏参数变成对应的字符串(名称)。
//#define CAT(W, X, Y, Z) W##X##Y##Z//"##"预处理符号可以把位于它两边的符号合成一个符号，它允许宏定义从分离的文本片段创建标识符。
//
//int main()
//{
//	//预处理符号"#"使用示例：如何将变量名插入到字符串中？
//	int a = 1, b = 2, c = 3;
//	float d = 3.14f;
//	PRINT(a, "%d");//等价于"printf("The value of ""a"" is ""%d""\n",a);"。
//	PRINT(b, "%d");//等价于"printf("The value of ""b"" is ""%d""\n",b);"。
//	PRINT(c, "%d");//等价于"printf("The value of ""c"" is ""%d""\n",c);"。
//	PRINT(d, "%f");//等价于"printf("The value of ""d"" is ""%f""\n",d);"。
//
//	//预处理符号"##"使用示例
//	int minutesOfAnHour = 60 * 1;
//	printf("%d\n", CAT(minutes, Of, An, Hour));//等价于"printf("%d\n",minutesOfAnHour);"。
//
//	return 0;
//}

////带副作用的宏参数示例
//#define MAX(X, Y) (((X)>(Y))?(X):(Y))
//
//int main()
//{
//	int a = 0, b = 0;
//
//	a = 5, b = 8;
//	int num = MAX(a++, b++);//注意宏定义本质上为替换，故此行等价于"int num = (((a++)>(b++))?(a++):(b++));"。
//	printf("a = %d,b = %d,num = %d\n", a, b, num);//得出结果为：a = 6,b = 10,num = 9。
//
//	a = 5, b = 8;
//	num = (((a++) > (b++)) ? (a++) : (b++));
//	printf("a = %d,b = %d,num = %d\n", a, b, num);//得出结果为：a = 6,b = 10,num = 9。
//
//	return 0;
//}

////预处理指令"#define"宏定义例题：模拟实现"offsetof"宏。
//#define OFFSETOF(type, member) ((size_t)(&(((type*)0)->member)))
//
//struct MyStruct
//{
//	char x;
//	int y;
//	char z;
//};
//
//int main()
//{
//	struct MyStruct myStruct = { 0 };
//
//	printf("%zu\n", OFFSETOF(struct MyStruct, x));
//	printf("%zu\n", OFFSETOF(struct MyStruct, y));
//	printf("%zu\n", OFFSETOF(struct MyStruct, z));
//
//	return 0;
//}

/**
	预处理指令"#undef"移除宏定义：取消定义标识符，即取消先前由#define指令定义的标识符；如果标识符没有关联的宏，则忽略该指令。
*/

////使用预处理指令"#undef"移除宏定义示例
//int main()
//{
//#define NUM 100
//	printf("%d\n", NUM);
//#undef NUM
//	//printf("%d\n", NUM);//取消此行注释会发现编译器报错，因为"#undef"取消了"#define"宏定义的标识符常量"NUM"。
//	return 0;
//}

/**
	命令行定义：大部分的C编译器提供了一种能力，允许在命令行中定义符号，用于启动编译过程，如：GCC编译器等。
*/

////命令行定义示例(以下代码段请使用GCC编译器编译演示，编译命令为：gcc 文件名 -D ARRAY_SIZE=10)
//int main()
//{
//	int array[ARRAY_SIZE];
//	int i = 0;
//	for (i = 0; i < ARRAY_SIZE; i++)
//	{
//		array[i] = i;
//	}
//	for (i = 0; i < ARRAY_SIZE; i++)
//	{
//		printf("%d ", array[i]);
//	}
//	printf("\n");
//	return 0;
//}

/**
	条件编译：使用条件编译指令，可以在编译一个程序的时候选择将一条语句(一组语句)编译或者放弃。
		1.条件预处理块由"#if"、"#ifdef"或"#ifndef"指令开始，然后可选地包含任意多个"#elif"、"#elifdef"或"#elifndef"指令，接下来是最多一个可选的"#else"指令，并以"#endif"指令结束。
		2.嵌套的条件预处理块会被单独处理。
		3.文档
			a."https://zh.cppreference.com/w/c/preprocessor/conditional"。
			b."https://docs.microsoft.com/zh-cn/cpp/preprocessor/hash-if-hash-elif-hash-else-and-hash-endif-directives-c-cpp?view=msvc-170"。
			c."https://docs.microsoft.com/zh-cn/cpp/preprocessor/hash-ifdef-and-hash-ifndef-directives-c-cpp?view=msvc-170"。
*/

////条件编译示例一
//#if 1//此行若为真，则参与编译"#if"和"#endif"之间的代码，若为假，则不参与编译。
//
//int main()
//{
//#if 1 == 2
//	printf("哈哈哈\n");
//#elif 2 == 3
//	printf("嘻嘻嘻\n");
//#else
//	printf("略略略\n");
//#endif
//	return 0;
//}
//
//#endif

////条件编译示例二
//#define TEST 0
//#define HEHE 1
//int main()
//{
////如果"TEST"定义了，则参与编译"#ifdef"和"#endif"之间的代码。
//#ifdef TEST
//	printf("TEST1\n");
//#endif
//
////如果"TEST"定义了，则参与编译"#if"和"#endif"之间的代码。
//#if defined(TEST)
//	printf("TEST2\n");
//#endif
//
////如果"HEHE"没有被定义，则参与编译"#ifndef"和"#endif"之间的代码。
//#ifndef HEHE
//	printf("HEHE1\n");
//#endif
//
////如果"HEHE"没有被定义，则参与编译"#if"和"#endif"之间的代码。
//#if !defined(HEHE)
//	printf("HEHE2\n");
//#endif
//
//	return 0;
//}

/**
	预处理指令"#include"包含头文件：预处理器先删除预处理指令"#include"，并用包含文件的内容替换。
		1.符号的区别
			a." < > "表示在标准库下查找文件，若无法找到则编译错误。
			b." " " "表示先在源文件所在目录下查找文件，若无法找到则在标准库下查找文件，若再无法找到则编译错误。
		2.若一个文件被包含多次，则就实际被编译多次，可能会导致错误，比如重复声明，故需要防止重复包含头文件。
			a.使用条件编译防止头文件被重复包含。
			b.使用预处理指令"#pragma once"保证头文件被编译一次。
*/

////防止头文件被重复包含示例一
//#ifndef __TEST_H__ //如果没有定义"__TEST_H__"，则参与编译"#ifndef"和"#endif"之间的代码。
//#define __TEST_H__ //定义"__TEST_H__"标识符常量。
///*在此处包含头文件*/
//#endif
//
////防止头文件被重复包含示例二
//#pragma once
///*在此处包含头文件*/

/**
	其他预处理指令
		1."#error"：编译程序时，只要遇到"#error"就会生成一个编译错误的提示信息，并且停止编译。
		2."#pragma"：设定编译器的状态或者是指示编译器完成一些特定的动作。
		3."#line"：改变当前行数和文件名称。
*/