#include<stdio.h>

////C99 标准中引用一个概念：变长数组（支持数组创建的时候，用变量指定大小的，但是这个数组不能初始化）。
////VS2019 不支持C99中的变长数组，如下代码。
//int main()
//{
//	int n = 10;
//	int arr[n] = { 0 };//提示“n”需要为常量值。
//	return 0;
//}

////写一个函数，输出较大值。
//int Max(int x, int y)
//{
//	if (x>y)
//	{
//		return x;
//	}
//	else
//	{
//		return y;
//	}
//}
//int main()
//{
//	int a = 0, b = 0;
//	scanf_s("%d %d", &a,&b);
//	int m = Max(a, b);
//	printf("较大值为：%d。",	m);
//	return 0;
//}

////探究static。
//int Sum(int a)
//{
//	int c = 0;
//    static int b = 3;
//    c += 1;b += 2;
//    return (a + b + c);
//}
//int main()
//{
//	int a = 2;
//	for (int i = 0; i < 5; i++)
//	{
//		printf("%d ", Sum(a));
//	}
//	return 0;
//}

/*
C语言是结构化的程序设计语言：顺序结构（即从头走到尾）、选择结构、循环结构。
C语言语句可分为以下五类：表达式语句、函数调用语句、控制语句、复合语句、空语句。
本项目重点介绍控制语句。
*/

/*
控制语句用于控制程序的执行流程，以实现程序的各种结构方式，它们由特定的语句定义符组成，C语言有如下三类共九种控制语句。
1. 条件判断语句（分支语句）：if语句、switch语句。
2. 循环执行语句：do while语句、while语句、for语句。
3. 转向语句：break语句、goto语句、continue语句、return语句。
*/

////if语句：中老年判断器
//int main()
//{
//	int age = 0;
//	scanf_s("%d", &age);
//
//	//如果表达式的结果为真，则语句执行。
//	//表达式不可写成“1<age<3”的形式，因为会先判断“1<age”，若age=20，前半段判断结果为“1（真）”，代入到后半段“1<3”表达式成立，显然不正确。（正确写法见代码）
//	//在C语言中0表示为假，非0表示为真(如-1表示为真)。
//
//	if (18 >= age)//括号内即为表达式。
//	{
//		printf("少年\n");
//	}
//	else if (age > 18 && age <= 26)//else if：如果上条if语句表达式判断为0，则执行此条if语句。
//	{
//		printf("青少年\n");
//	}
//	else if (age > 26 && age <= 40)//else的匹配：else是和它离的最近的if匹配的。
//	{
//		printf("中年\n");
//	}	
//	else if (age > 40 && age <= 60)
//	{
//		printf("壮年\n");
//	}
//	else if (age > 60 && age <= 100)
//	{
//		printf("老年\n");
//	}
//	else
//	{
//		printf("神仙\n");
//	}
//
//	//代码书写风格：查阅高质量C编程指南或Google编程规范。
//	int num = 0;
//	if (5==num)//高质量写法，避免出错（防止少写一个等号）。
//	{
//		return 0;
//	}
//
//	return 0;
//}

////判断一个数是否为奇数
//int main()
//{
//	int a = 0;
//	scanf_s("%d", &a);
//	
//	if (a % 2 == 1)
//	{
//		printf("这个数是奇数");
//	}
//	else
//	{
//		printf("这个数不是奇数");
//	}
//
//	return 0;
//}

////打印1-100的奇数
//int main()
//{
//	for (int i = 1; i < 100; i+=2)
//	{
//		printf("%d ", i);
//	}
//	return 0;
//}

////switch语句：常用于多分支情况；switch允许嵌套使用。
//int main()
//{
//	int day = 0;
//	scanf("%d", &day);
//	switch (day)
//	{
//	case 1://要求为整型常量表达式。
//		printf("星期1\n");
//		break;//跳出。
//	case 2:
//		printf("星期2\n");
//		break;
//	case 3:
//		printf("星期3\n");
//		break;
//	case 4:
//		printf("星期4\n");
//		break;
//	case 5:
//		printf("星期5\n");
//		break;
//	case 6:
//		printf("星期6\n");
//		break;
//	case 7:
//		printf("星期天\n");
//		break;
//	}
//	return 0;
//}
//
//在最后一个case语句的后面加上一条break语句（之所以这么写是可以避免出现在以前的最后一个case语句后面忘了添加break语句）。
//
//int main()
//{
//	int day = 0;
//	scanf("%d", &day);
//	switch (day)
//	{
//	case 1:
//	case 2:
//	case 3:
//	case 4:
//	case 5:
//		printf("工作日\n");
//		break;
//	case 6:
//	case 7:
//		printf("休息日\n");
//		break;
//	default://当switch表达式的值并不匹配所有case标签的值时，这个default子句后面的语句就会执行；位置无所谓。
//		printf("输入错误\n");
//		break;
//	}
//	return 0;
//}
//
//在每个switch语句中都放一条default子句是个好习惯，甚至可以在后边再加一个break。
//

////while语句
//int main()
//{
//	int i = 1;
//	while (i<=10)
//	{
//		if (i==5)
//		{
//			continue;//跳过本次循环continue后边的代码（直接去判断部分，看是否进行下一次循环）：这时候i一直等于5了。
//			break;//永久终止循环。
//		}
//		printf("%d ", i);
//		i++;
//	}
//	return 0;
//}

////getchar：从缓冲区读取字符，键盘输入字符到缓冲区，实际上键盘输入”A\n“，第一次getchar拿到A，第二次拿到\n。
//int main()
//{
//	int ch = 0;
//	while ((ch = getchar()) != EOF)//getchar：从键盘获取一个字符（ascill码值），所以存储为整型；EOF：读到错误或文件结束标志，右键转到定义发现是“-1”。
//	{
//		putchar(ch);//putchar：输出一个字符。
//	}
//	return 0;
//}