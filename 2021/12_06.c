#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

////关机程序
//int main()
//{
//	char input[20] = { 0 };
//	system("shutdown -s -t 60"); //system可执行系统命令；引用头文件“stdlib.h”。
//	//goto语句：只能在一个函数范围内跳转，不能跨函数；常见的用法为终止程序在某些深度嵌套的结构的处理过程，其余情况不推荐使用，本代码只做展示。
//again:
//	printf("\n请注意！您的系统即将在一分钟后关机！\n请输入“Aoki”，终止关机操作。\n>>");
//	scanf_s("%s", input,20);
//	if (strcmp(input, "Aoki") == 0)//两个字符串比较不能使用”==“，应使用“strcmp”；引用头文件“string.h”。
//	{
//		system("shutdown -a");
//	}
//	else
//	{
//		goto again;
//	}
//	return 0;
//}

//函数：库函数以及自定义函数。
//	1.库函数
//		a.使用库函数，需要引用对应的头文件。
//		b.使用查询工具，学习并了解库函数。
//	2.自定义函数
//		a.与库函数一样，同样具有函数名、返回值类型、函数参数。

////库函数
//int main()
//{
//	char arr1[5] = { 0 };
//	char arr2[5] = "Aoki";
//	char arr3[] = "------ Aoki";
//	strcpy_s(arr1, 5, arr2);//复制字符串：将“arr2”复制到“arr1”。
//	memset(arr3, '?', 6);//设置内存块：将缓冲区设置到指定的字符；将"arr3"前6个字符设置成“?”。
//	printf("%s\n", arr1);
//	puts(arr3);//输出字符串：将字符串写入stdout（默认输出目标）并附加一个换行字符“\n”。
//	printf("6666");
//	return 0;
//}

////自定义函数：自定义返回类型、自定义函数名、自定义函数参数、括号为函数体、括号内为语句项。
//void name(para1, para2)
//{
//	return 0;
//}

//写一个函数可以找出两个整数中的最大值。
//int get_max(int x,int y)
//{
//	int z = 0;
//	if (x<y)
//	{
//		z = y;
//	}
//	else
//	{
//		z = x;
//	}
//	return z;//返回较大值
//}
//int main()
//{
//	int a = 0, b = 0;
//	scanf_s("%d %d", &a, &b);
//	int max = get_max(a, b);//令”max“等于函数“get_max”调用后返回的值。
//	printf("较大值为：%d。\n", max);
//	return 0;
//}

////写一个函数可以交换两个整形变量的内容
//void Swap1(int x, int y)//void：表示这个函数不返回任何值，也不需要返回；
//{
//	x += y;
//	y = x - y; 
//	x = x - y;
//}
//void Swap2(int* px, int* py)//void：表示这个函数不返回任何值，也不需要返回；
//{
//	*px += *py;
//	*py = *px - *py;
//	*px = *px - *py;
//}
////实参：真实传给函数的参数；在进行函数调用时，它们都必须有确定的值，以便把这些值传送给形参。
////形参：指函数名后括号中的变量，只有在函数被调用的过程中才实例化（分配内存单元），形式参数只在函数中有效；形参实例化之后其实相当于实参的一份临时拷贝。
//int main()
//{
//	int a = 0, b = 0;
//	scanf_s("%d %d", &a, &b);
//
//	printf("调用Swap1函数交换前a=%d，b=%d。\n", a, b);
//	Swap1(a, b);//传值调用：函数的形参和实参分别占有不同内存块，对形参的修改不会影响实参。
//	printf("调用Swap1函数交换后a=%d，b=%d。\n", a, b);//结果并没有被改变。
//
//	printf("\n调用Swap2函数交换前a=%d，b=%d。\n", a, b);
//	Swap2(&a, &b); //传址调用：把函数外部创建变量的内存地址传递给函数参数的一种调用函数的方式；这种传参方式可以让函数和函数外边的变量建立起真正的联系，也就是函数内部可以直接操作函数外部的变量。
//	printf("调用Swap2函数交换后a=%d，b=%d。\n", a, b);//结果被改变了。
//
//	return 0;
//}

////使用函数判断一个数是不是素数
//int Add(int x)
//{
//	int i = 0;
//	for (i = 2; i <= sqrt(x); i++)
//	{
//		if (x%i==0)
//		{
//			return 0;
//		}
//	}
//	return 1;
//}
//int main()
//{
//	int a = 0;
//	scanf_s("%d", &a);
//	int b = Add(a);
//	if (b == 0)
//	{
//		printf("%d不是素数", a);
//	}
//	if (b == 1)
//	{
//		printf("%d是素数", a);
//	}
//	return 0;
//}

////使用函数判断一年是不是闰年
//int Add(int x)
//{
//	return ((x % 4 == 0 && x % 100 != 0) || (x % 400 == 0));
//}
//int main()
//{
//	//for (int year = 1000; year <= 2000; year++)
//	//{
//	//	if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
//	//	{
//	//		printf("%d ", year);
//	//	}
//	//}
//
//	//for (int year = 1000; year <= 2000; year++)
//	//{
//	//	if (Add(year)==1)
//	//	{
//	//		printf("%d ", year);
//	//	}
//	//}
//
//	int year = 0;
//	scanf_s("%d", &year);
//	if (Add(year)==1)
//	{
//		printf("\n%d是闰年", year);
//	}
//	if (Add(year)==0)
//	{
//		printf("\n%d不是闰年", year);
//	}
//
//	return 0;
//}

////使用函数实现整形有序数组的二分查找
//int Find(char arr[],int num1,int size)
//{
//	int left = 0; int right = size - 1;
//	while (left<=right)
//	{
//		int middle = (left + right) / 2;
//		if (arr[middle]<num1)
//		{
//			left = middle + 1;
//		}
//		else if (arr[middle]>num1)
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
//int main()
//{
//	char arr[] = { 1,2,3,4,5,6,7,8,9,10 }; int num1 = 7;
//	int size = sizeof(arr) / sizeof(arr[0]);//数组传参，传过去的不是数组的本身，是数组首元素的地址；当数组为形参时，在子函数中sizeof的值相当于指针的sizeof值。
//	int num2 = Find(arr, num1, size);
//	if (num2==-1)
//	{
//		printf("\n错误！无法找到你所定义的数字。\n");
//	}
//	else
//	{
//		printf("\n成功！你所定义的数字为：%d。\n", arr[num2]);
//	}
//	return 0;
//}

////每调用一次函数，num 的值增加1。
//void increased(int *num)
//{
//	(*num)++;
//}
//int main()
//{
//	int num = 0;
//	for (int i = 0; i < 10; i++)
//	{
//		increased(&num);
//	}
//	printf("\n调用了%d次函数。\n",num);
//	return 0;
//}

//函数的嵌套调用和链式访问
// 1.嵌套调用
//		a.C语言中不能嵌套定义。比如在“main”函数括号中再定义一个函数，这样是不被允许的。
//		b.函数可以被嵌套调用。比如在“main”函数中调用“test1”函数，“test1”函数中再调用“test2”函数。
// 2.链式访问
//		a.把一个函数的返回值作为另外一个函数的参数。

////链式访问
//int main()
//{
//	char arr1[20];
//	strcpy_s(arr1, 20, "Killua");//strcpy：将字符串复制到数组中，包括终止空字符（并在该点停止）。
//	strcat_s(arr1, 20, "Aoki");//strcat：将字符串副本附加到目标字符串。原数组中的“\0”被字符串副本的第一个字符覆盖，并且在两字符串连接后形成的新字符串的末尾包含一个空字符。
//	printf("\n首次进行strcpy和strcat后的字符串为“%s”\n", arr1);//打印出“KilluaAoki”。
//	printf("\n再进行链式访问后字符串为：“%s”，字符串长度为：“%d”\n", arr1, (int)strlen(strcat(arr1, "-666")));
//	printf("%d\n", printf("%d", printf("\n%d", 43)));//printf函数的返回值是打印在屏幕上字符的个数，故打印4331（“\n”也算哦~）。
//	return 0;
//}

////函数的声明：告知函数名称、参数和返回类型；具体是否存在，函数声明无法决定；函数声明一般在函数的使用之前；函数的声明一般用于头文件中。
////以下代码中，自定义函数“Add”在主函数的后面，如若不声明会跳出警告称未定义“Add”函数；假如“Add”函数定义在前面，则无需声明。
//int main()
//{
//	int a = 10;int b = 20;
//	int Add(int, int);//声明函数
//	int c = Add(a, b);
//	printf("%d\n", c);
//	return 0;
//}
////函数的定义：指函数的具体实现，交待函数的功能实现；决定函数是否存在。
//int Add(int x, int y)
//{
//	return x + y;
//}

//项目
// 1.在一个项目中，存在多人协作的情况，每人编写不同的.h和.c文件，实现不同的功能。
//		a.假如A编写某程序的某模块，一般在属于他的“A.c”文件中实现此模块功能（函数定义），并在“A.h”文件中声明（函数声明）。
//		b.若要将A编写的模块集成到总程序中，引用其头文件（#include "A.c"），再编写即可。
//		c.#include "A.c"实际上就是替换了函数声明。
// 2.假如A编写的程序并不想公开源码，其余人要使用A编写的程序时，A要怎么做呢？
//		a.A将其程序生成静态库“A.lib”文件，将“A.lib”文件和“A.h”文件给到其余人。
//		b.其余人只需将文件导入到工程，引用头文件（#include "A.h"）并导入静态库（#pragma comment(lib, "A.lib")）即可编写使用。