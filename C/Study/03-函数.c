#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

/*
	函数
		1.函数的定义
		2.C语言中函数的分类
			a.库函数
			b.自定义函数
		3.函数的参数
			a.实际参数(实参)
			b.形式参数(形参)
		4.函数的调用
			a.传值调用
			b.传址调用
		5.函数的嵌套调用和链式访问
			a.嵌套调用
			b.链式访问
		6.函数的声明和定义
			a.函数声明
			b.函数定义
			c.不同文件下的函数声明和定义(项目)
		7.函数递归
			a.递归的两个必要条件
			b.递归的注意事项
			c.递归与迭代
			d.递归的使用场景
			e.递归栈溢出的解决方法
			f.汉诺塔问题和爬楼梯问题
*/

/**
	函数的定义
		1.在计算机科学中，函数(子程序)是一个大型程序中的某部分代码，由一个或多个语句块组成；它负责完成某项特定任务，而且相较于其他代码，具备相对的独立性。
		2.函数一般会有输入参数并有返回值，提供对过程的封装和细节的隐藏，这些代码通常被集成为软件库。
		3.函数在面向过程的语言中已经出现(C语言)，是结构(struct)和类(class)的前身，本身就是对具有相关性语句的归类和对某过程的抽象。
		4.函数的构成一般由函数头(返回值类型)、函数名、函数参数(接收参数)、函数体(实现函数功能)构成。
		5.函数的返回值只能有一个(若有)，但函数的接收参数可以有多个(若有)。
*/

////函数使用示例
//int Add(int x, int y)//"Add"是函数的名称、"Add"前的"int"是函数头，表示函数的返回值类型、"Add"后的括号是函数参数，表示函数的接收参数。
//{
//	return x + y;//由"{}"表示函数的代码块，即函数体，函数体内的语句项，表示函数的功能或实现。
//}
//
//int main()//"main"函数是整个程序的入口，称之为主函数，一个程序只有一个"main"函数，并且"main"函数的位置可以任意。
//{
//	int a = 0, b = 0;
//	scanf_s("%d%d", &a, &b);
//	int c = Add(a, b);
//	printf("%d + %d = %d\n", a, b, c);
//	return 0;
//}

/**
	C语言中函数的分类
		1.库函数
			a.将需要众多程序员需要重复使用的功能封装成库函数，便于程序的开发，并且支持可移植性和提高程序的效率。
			b.库函数常具有程序的基础功能，通常由库函数的	实现者实现，程序员无需自己重复实现，降低程序错误的可能性，并且库函数通常为较优解。
			c.库函数常分为七大类的函数：输入/输出函数("I/O函数")、字符串操作函数、字符操作函数、内存操作函数、时间/日期函数、数学函数、其他库函数。
			d.在使用库函数时需要使用"#include"预处理指令引用库函数对应的头文件，如："#include <math.h>"，此头文件具有众多数学函数。
			e.通过文档、查询工具以及标准库源码，可以学习并了解库函数的使用，如："cppreference"、"uClibc-ng"、"glibc"等。
			f.于"VS2022"中禁止使用部分不安全的库函数，如"scanf"函数，若要使用不安全函数屏蔽警告需在文件首行使用"#define _CRT_SECURE_NO_WARNINGS"。
		2.自定义函数
			a.库函数并不能满足大多数程序的全部功能，这样就需要自定义函数，自定义函数的形式与库函数相同，不同的是自定义函数是有程序员自己设计的。
			b.与库函数相同，自定义函数也可以单独放在".c"文件实现、放在".h"文件声明，但库函数的函数实现一般被封装成了静态库。
			c.若使用不同文件下的自定义函数，同样需要引用头文件，若头文件在源文件目录下需要使用双引号引用头文件。(符号区别详见程序环境和预处理章节)
			d.自定义函数中的任何部分都是可以由自己定义的。
*/

////库函数的使用示例：因"strcpy"函数不安全，此处以"strcpy_s"进行演示复制字符串操作，但其返回值和参数与"strcpy"不相同，"strcpy_s"具体使用方法请查看文档。
//int main()
//{
//	char arr1[] = "Killua";
//	char arr2[] = "Aoki";
//	char arr3[] = "Killua Aoki";
//
//	printf("%s\n", arr1);//打印函数：将格式化数据打印到标准输出流，文档：https://zh.cppreference.com/w/c/io/fprintf。
//	strcpy_s(arr1, 5, arr2);//复制字符串函数：将"arr2"复制到"arr1"，文档：https://zh.cppreference.com/w/c/string/byte/strcpy。
//	printf("%s\n", arr1);
//
//	puts(arr3);//输出字符串函数：将字符串写入标准输出流(屏幕)，并附加一个换行字符"\n"，文档：https://zh.cppreference.com/w/c/io/puts。
//	memset(arr3, '-', 6);//填充内存块函数：将缓冲区设置到指定的字符；将"arr3"前"6"个字符设置成"?"，文档：https://zh.cppreference.com/w/c/string/byte/memset。
//	puts(arr3);
//
//	return 0;
//}

////自定义函数示例：写一个函数可以找出两个整数中的最大值。
//int Max(int x, int y)
//{
//	////方法一
//	//if (x > y)
//	//{
//	//	return x;//若"x"变量大于"y"变量，则返回"x"变量的值。
//	//}
//	//else
//	//{
//	//	return y;//反之返回"y"变量的值。
//	//}
//	
//	//方法二
//	return x > y ? x : y;//使用三目操作符。
//}
//
//int main()
//{
//	int a = 0, b = 0;
//	scanf_s("%d%d", &a, &b);
//	int max = Max(a, b);//令"max"变量等于"Max"函数调用后返回的值。
//	printf("较大值为：%d\n。", max);
//	return 0;
//}

/**
	函数的参数
		1.实际参数(实参)
			a.即真实传递给函数的参数，当然是当你有参数时才需要传参，若函数的接收参数为"void"(空)，则意为不接收任何传递参数(无需传参)。
			b.实参可以为常量、变量、函数、表达式等。
			c.无论实参是何种类型的值，在进行有参数的函数调用的时候，它们都必须要有确定的值，以便将值传递给形参。
		2.形式参数(形参)
			a.即函数名后的括号中的变量(接收参数)，并且形参的名称可以与实参相同。
			b.形式参数只有在函数被调用的过程中才实例化(分配内存单元)，形式参数当函数调用完成之后就自动销毁了，因此形式参数只在此函数中才有效。
			c.形参实例化后相当于实参的一份临时拷贝，分别存在于不同的内存单元(地址)，对形参的修改不会影响实参。
*/

////函数的参数示例
//void Change(int num)//函数头"void"表示这个函数不返回任何值，也不需要返回。
//{
//	num = 10;//此函数中的"num"变量(形参)相当于"main"函数"num"变量(实参)的一份临时拷贝，对形参的修改不会影响实参。
//}
//
//int main()//在C语言中"main"函数后的括号空着代表着编译器对是否接受参数保持沉默，若传递参数给"main"函数，编译器会允许此行为，但若在"main"函数后的括号加上"void"，则编译器报警告。
//{
//	int num = 0;
//	printf("调用函数前：num = %d。\n", num);
//	Change(num);
//	printf("调用函数后：num = %d。\n", num);//发现函数调用后结果依旧为"0"，说明对形参的修改不会影响实参。
//	return 0;
//}

////拓展："main"函数的参数。
//int main(int argc, char* argv[], char *envp[])//标准的"main"函数，但并不常见，一般都是将"main"函数后的括号空着。
//{
//	return 0;
//}


/**
	函数的调用
		1.传值调用：将属于实参的值传递给形参，但函数的形参和实参分别占有不同内存块，形参只是获取了实参的值，所以形参的修改并不会影响实参。
		2.传址调用：本质上依旧是传值调用，但是是将实参的地址传递给形参，而形参为指针接收了这个实参的地址，利用指针从而达到在别处修改实参的目的。
			a.调用函数时需要注意是否要修改实参，若要修改实参，常用方法是将实参的地址传递给形参的指针变量，即由形参指向实参，从而到达修改实参的目的。
			b.利用函数的返回值，可以将修改后的形参返回给实参接收，从而达到修改实参的目的。
*/

////函数的调用示例：写一个函数可以交换两个整形变量的内容。
//void Swap1(int x, int y)
//{
//	//使用创建中间变量的方法交换变量(注意在此函数不能达成效果)
//	int tmp = x;
//	x = y;
//	y = tmp;
//}
//
//void Swap2(int* px, int* py)
//{
//	////方法一：通过数学方法交换变量。
//	//*px = *px + *py;
//	//*py = *px - *py;
//	//*px = *px - *py;
//
//	//方法二：通过异或方法交换变量。(详见操作符)
//	*px = *px ^ *py;
//	*py = *px ^ *py;
//	*px = *px ^ *py;
//}
//
//int main()
//{
//	int a = 0, b = 0;
//	scanf_s("%d %d", &a, &b);
//
//	printf("调用\"Swap1\"函数交换前a = % d，b = % d。\n", a, b);
//	Swap1(a, b);//将变量"a"和变量"b"的值(实参)传递给了"Swap1"函数的接收参数(形参)。
//	printf("调用\"Swap1函数\"交换后a = % d，b = % d。\n", a, b);//结果并没有被改变。
//
//	printf("\n调用\"Swap2\"函数交换前a = % d，b = % d。\n", a, b);
//	Swap2(&a, &b);//将变量"a"和变量"b"的地址(实参)传递给了"Swap2"函数的接收参数(形参)。
//	printf("调用\"Swap2\"函数交换后a = % d，b = % d。\n", a, b);//结果被改变了。
//
//	return 0;
//}

////函数的调用练习题例一：写一个函数，判断输入的数是不是闰年。
//bool JudgmentLeapYear(int year)
//{
//	if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0))
//	{
//		return true;
//	}
//	return false;
//}
//
//int main()
//{
//	int year = 0;
//	scanf_s("%d", &year);
//	if (JudgmentLeapYear(year))
//	{
//		printf("Yes!\n");
//	}
//	else
//	{
//		printf("No!\n");
//	}
//	return 0;
//}

////函数的调用练习题例二：写一个函数，实现一个整形有序数组的二分查找。
//int FineArrayNumber(int arr[], int size, int num)
//{
//	int left = 0;
//	int right = size - 1;
//	while (left <= right)
//	{
//		int middle = ((right - left) >> 1) + left;
//		if (arr[middle] < num)
//		{
//			left = middle + 1;
//		}
//		else if (arr[middle] > num)
//		{
//			right = middle - 1;
//		}
//		else
//		{
//			return middle;
//		}
//	}
//	return -1;
//}
//
//int main()
//{
//	int num = 7;
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int size = sizeof(arr) / sizeof(arr[0]);
//	int subscript = FineArrayNumber(arr, size, num);
//	if (subscript != -1)
//	{
//		printf("找到了！下标为：%d。\n", subscript);
//	}
//	else
//	{
//		printf("找不到\n");
//	}
//	return 0;
//}

////函数的调用练习题例三：写一个函数，每调用一次这个函数，就会使整型"count"自增。
//void Count(int* count)
//{
//	(*count)++;
//}
//
//int main()
//{
//	int count = 0;
//	for (int i = 0; i < 10; i++)
//	{
//		Count(&count);
//	}
//	printf("count = %d\n", count);
//	return 0;
//}

/**
	函数的嵌套调用和链式访问
		1.嵌套调用
			a.C语言中函数允许嵌套调用，即在一个函数中调用另一个函数。
			b.C语言不允许函数的嵌套定义，即在一个函数内再定义另一个函数。
		2.链式访问
			a.即把一个函数的返回值作为另外一个函数的参数。
			b.链式访问内的函数返回值类型不能为"void"，否则编译器报错。
*/

////函数的嵌套调用和链式访问使用示例
//double MyIntPow(int num, int exponent)
//{
//	if (exponent < 0)
//	{
//		int x = num;
//		for (int i = 0; i < (-exponent) - 1; i++)
//		{
//			num = x * num;
//		}
//		return 1.0 / num;
//	}
//	else if (exponent == 0)
//	{
//		return 1;
//	}
//	else
//	{
//		int x = num;
//		for (int i = 0; i < exponent - 1; i++)
//		{
//			num = x * num;
//		}
//		return num;
//	}
//}
//
//int main()
//{
//	int num = 0;
//	int exponent = 0;
//	scanf_s("%d%d", &num, &exponent);
//	printf("pow(%d,%d) = %lf\n", num, exponent, MyIntPow(num, exponent));//将"MyIntPow"函数的返回值当做"printf"函数的参数，即嵌套调用和链式访问。
//	return 0;
//}

////函数的嵌套调用和链式访问练习例题
//int main()
//{
//	printf("%d", printf("%d", printf("%d", 43)));//打印结果为：4321。
//	return 0;
//}

/**
	函数的声明和定义
		1.函数声明：即告知编译器函数头(返回值类型)、函数名和函数参数(接收参数)。
			a.函数即使声明，但函数具体是否存在，函数声明无法决定。
			b.函数声明一般在函数的使用之前，并且函数的声明一般用于头文件中。
			c.假如自定义函数的函数定义在主函数的后面，若不声明函数，则编译器会跳出警告称未定义函数；假如自定义函数定义在前面，则无需声明。
			d."extern"关键字可用于跨文件的变量或函数声明，以表明变量或函数的定义在别的文件，并且使用"extern"关键字时也可以定义变量或函数。
			e.函数声明与定义的区分：若函数具有函数体则表示声明并定义函数，若函数没有函数体则表示声明函数。
		2.函数定义：即函数的具体实现，交待函数的功能实现，并且函数定义决定函数是否存在。
			a.函数的声明可以有多个，但函数的定义只能有一个。
			b.定义也属于一种声明。
		3.不同文件下的函数声明和定义(项目)
			a.在一个项目中，存在多人协作的情况，每人编写不同的".h"和".c"文件，实现不同的功能。
			b.假如甲人员编写某程序的某模块，一般在属于他的".c"文件中实现此模块功能(函数定义)，并在"A.h"文件中声明(函数声明)。
			c.若要将甲人员编写的模块集成到总程序中，引用其头文件".h"，再使用甲人员编写的函数，头文件实际上就是代替了声明。
			d.假如甲人员编写的程序并不想公开源码，其他人要使用甲人员编写的程序时，甲人员需将其程序生成静态库文件".lib"文件，并将".lib"和".h"文件交于其他人。
			e.其余人需将文件导入到工程，引用头文件甲人员的头文件以及导入静态库(在工程文件中使用"#pragma comment(lib, ".lib")"指令)，即可编写使用。·
*/

////函数的声明和定义示例
//double MyIntPow(int num, int exponent);//"MyIntPow"函数的声明。
//
//int main()
//{
//	int num = 0;
//	int exponent = 0;
//	scanf_s("%d%d", &num, &exponent);
//	printf("pow(%d,%d) = %lf\n", num, exponent, MyIntPow(num, exponent));//因程序是由上至下执行，若没有声明"MyIntPow"函数，则"main"函数在调用"MyIntPow"函数时会认为未定义函数。
//	return 0;
//}
//
//double MyIntPow(int num, int exponent)//"MyIntPow"函数的定义及声明(多次声明)位于"main"函数的下方。
//{
//	if (exponent < 0)
//	{
//		int x = num;
//		for (int i = 0; i < (-exponent) - 1; i++)
//		{
//			num = x * num;
//		}
//		return 1.0 / num;
//	}
//	else if (exponent == 0)
//	{
//		return 1;
//	}
//	else
//	{
//		int x = num;
//		for (int i = 0; i < exponent - 1; i++)
//		{
//			num = x * num;
//		}
//		return num;
//	}
//}

/**
	函数递归：一个过程或函数在其定义或说明中有直接或间接调用自身的一种方法称之为递归，同样是一种编程技巧。
		1.递归的两个必要条件
			a.存在限制条件，当满足这个限制条件的时候，递归便不再继续。
			b.每次递归调用之后越来越接近这个限制条件。
		2.递归的注意事项
			a.即使满足递归的两个必要条件，程序也不一定正确，但不满足一定错误。
			b.错误将会导致栈溢出(内存栈区存放着函数的形参，死递归将重复分配栈区空间至溢出)。
			c.为了防止错误，递归层次不能太深。
			d.递归是一种以空间换取时间的方法，但若递归的层次过深，时间也会过久，如：斐波那契数列。
			e.递归即先传递参数调用自身，直到满足递归的限制条件后，则再回归上一层函数。
		3.递归与迭代
			a.循环是一种迭代的实现，但迭代并不完全是由循环实现。
			b.函数可以用递归的方式实现，也可以用非递归即循环(迭代)的方式实现。
			c.递归可能会导致问题，如栈溢出、效率低下等。
			d.许多问题是以递归的形式进行解释的，这只是因为它比非递归的形式更为清晰。
			e.当一个问题相当复杂，难以用迭代实现时，此时递归实现的简洁性便可以补偿它所带来的运行时开销。
			f.迭代实现往往比递归实现效率更高。
		4.递归的使用场景
			a.当使用递归时，实现功能简单，并且没有明显的缺陷，这时候往往使用递归的方式实现。
			b.当使用递归时，实现功能简单，但是有明显的缺陷，如：栈溢出、效率低下等，这时候就需要使用非递归的方式实现。
		5.递归栈溢出的解决方法
			a.将递归改写成非递归。
			b.使用"static"对象替代"nonstatic"局部对象，减少每次递归调用和返回时产生和释放"nonstatic"对象的开销，并且可保存递归调用的中间状态为各个调用层所访问。(依旧可能造成栈溢出)
		6.汉诺塔问题和爬楼梯问题(详见下方注释)
*/

////死递归示例
//int main()
//{
//	printf("Aoki\n");
//	main();//不满足两个必要条件，为死递归，将使得栈溢出。
//	return 0;
//}

////递归练习题例一：接收一个无符号整型值，按照输入顺序打印它的每一位。
//void print(unsigned int num)
//{
//	if (num > 9)//递归的限制条件，当"num > 9"为假时，递归边不再继续。
//	{
//		print(num / 10);//使用递归。
//	}
//	printf("%u ", num % 10);//"%u"：用于输出"unsigned int"类型，即以无符号整型的格式输出。
//}
//
//int main()
//{
//	unsigned int num = 0;
//	scanf_s("%u", &num);
//	print(num);
//	return 0;
//}

////递归练习题例二：如下程序的运行后会产生什么现象？
//void Test(int x)
//{
//	if (x < 10000)//满足递归的两个条件，但分配空间过大导致栈溢出，运行可发现编译器报错(Stack overflow)。
//	{
//		Test(x + 1);
//	}
//}
//
//int main()
//{
//	int num = 10;
//	Test(num);
//	return 0;
//}

////递归练习题例三：使用迭代的方式，模拟实现"strlen"函数。
//size_t MyStrlen(const char* str)//"size_t"：右键转到定义可发现"size_t"为无符号整型使用"typedef"重命名后的别名；"const"：此处意为"*str"不能被改变(详见调试技巧)。
//{
//	size_t count = 0;
//	while (*str++ != '\0')
//	{
//		count++;
//	}
//	return count;
//}
//
//int main()
//{
//	char arr[] = "KilluaAoki";
//	printf("%zu\n", strlen(arr));//"%zu"：用于输出"size_t"类型(别名)，即以无符号整型的格式输出。
//	printf("%zu\n", MyStrlen(arr));//可发现程序的结果都为：10。
//	return 0;
//}

////递归练习题例四：使用递归的方式，模拟实现"strlen"函数。
//size_t MyStrlen(const char* str)
//{
//	if (*str == '\0')
//	{
//		return 0;
//	}
//	return 1 + MyStrlen(str + 1);//此处"str + 1"不建议写成"++"的写法，不论是前置或后置都具有副作用。
//}
//
//int main()
//{
//	char arr[] = "KilluaAoki";
//	printf("%zu\n", strlen(arr));
//	printf("%zu\n", MyStrlen(arr));//可发现程序的结果都为：10。
//	return 0;
//}

////递归练习题例五：使用递归求输入的数的阶乘，不考虑溢出问题。
//size_t Factorial(int x)
//{
//	if (x <= 1)
//	{
//		return 1;
//	}
//	return x * Factorial(x - 1);
//}
//
//int main()
//{
//	int input = 0;
//	scanf_s("%d", &input);
//	printf("%d! = %zu\n", Factorial(input));
//	return 0;
//}

////递归练习题例六：使用递归求输入的数的斐波那契数，不考虑溢出问题。
//size_t FibonacciSequence(int x)
//{
//	if (x <= 2)
//	{
//		return 1;
//	}
//	return FibonacciSequence(x - 1) + FibonacciSequence(x - 2);//效率太低，如果数字太大，将会进行大量的重复运算，导致出现问题。
//}
//
//int main()
//{
//	int input = 0;
//	scanf_s("%d", &input);
//	printf("%zu\n", FibonacciSequence(input));
//	return 0;
//}

////递归练习题例七：使用迭代(循环)求输入的数的斐波那契数。
//size_t FibonacciSequence(int num)
//{
//	size_t x = 1, y = 1, sum = 1;
//	while (num-- >= 3)
//	{
//		sum = x + y;
//		x = y;
//		y = sum;
//	}
//	return sum;
//}
//
//int main()
//{
//	int input = 0;
//	scanf_s("%d", &input);
//	printf("%zu\n", FibonacciSequence(input));//运行发现比递归效率更高。
//	return 0;
//}

/***
	汉诺塔问题和爬楼梯问题
		1.汉诺塔问题
			a.维基百科：https://zh.wikipedia.org/wiki/%E6%B1%89%E8%AF%BA%E5%A1%94。
			b.仅要求使用递归方法求解。
		2.爬楼梯问题
			a."LeetCode"链接：https://leetcode.cn/problems/climbing-stairs/。
			b."NowCoder"链接：https://www.nowcoder.com/practice/ebf04de0e02c486099d78b7c3aaec255。
			c.使用递归以及迭代的方法进行求解。
			d.若是使用"LeetCode"在线编辑，使用递归将会超出时间限制，需进行优化。
*/

////汉诺塔问题(递归)
//void Move(char pos1, char pos2)
//{
//	printf("%c -> %c\n", pos1, pos2);
//}
//
//void Hanoi(int x, char pos1, char pos2, char pos3)
//{
//	if (x == 1)
//	{
//		Move(pos1,pos3);
//	}
//	else
//	{
//		Hanoi(x - 1, pos1, pos3, pos2);
//		Move(pos1, pos3);
//		Hanoi(x - 1, pos2, pos1, pos3);
//	}
//}
//
//int main()
//{
//	int input = 0;
//	scanf_s("%d", &input);
//	Hanoi(input, 'A', 'B', 'C');
//	return 0;
//}

////爬楼梯问题(递归)
//size_t ClimbStairs(size_t x)
//{
//	return x <= 2 ? x : ClimbStairs(x - 1) + ClimbStairs(x - 2);
//}
//
//int main()
//{
//	size_t input = 0;
//	scanf_s("%zu", &input);
//	printf("%zu", ClimbStairs(input));
//	return 0;
//}

////爬楼梯问题(循环)
//size_t ClimbStairs(size_t x)
//{
//	size_t a = 1, b = 1, sum = 1;
//	while (x-- >= 2)
//	{
//		sum = a + b;
//		a = b;
//		b = sum;
//	}
//	return sum;
//}
//
//int main()
//{
//	size_t input = 0;
//	scanf_s("%zu", &input);
//	printf("%zu", ClimbStairs(input));
//	return 0;
//}