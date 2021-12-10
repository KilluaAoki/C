#include <stdio.h>//引用头文件；快捷键Ctrl+F5编译并运行。

//int main()
//{
//	printf("打印的第一串代码\n");//printf - 库函数 - 在屏幕上打印信息的；printf 的使用需要引用头文件 stdio.h。
//	printf("打印的第二串代码\n");//\n为换行的意思。
//	printf("打印的第三串代码\n");
//	return 0;
//}

//int main()
//{
//	printf("%d\n",sizeof(char));//打印字符数据类型的大小；打印一个整型 - %d；sizeof - 关键字 - 操作符 - 计算类型或者变量所占空间的大小-单位为字节byte。
//	printf("%d\n",sizeof(short));//打印短整型的大小。
//	printf("%d\n",sizeof(int));//打印整型的大小。
//	printf("%d\n",sizeof(long));//打印长整型的大小；C语言标准规定sizeof(long)>=sizeof(int)，所以long与int大小都为4字节。
//	printf("%d\n",sizeof(long long));//打印更长整型的大小。
//	printf("%d\n",sizeof(float));//打印单精度浮点数的大小。
//	printf("%d\n",sizeof(double));//打印双精度浮点数的大小。
//	return 0;
//}

//int main()
//{
//	printf("Aoki\n");
//	int age = 18;//创建一个变量的格式：类型 变量的名字=0或者不给值。
//	float weight = 60.5;
//	age = age + 1;//改变你的变量。
//	printf("%d\n", age);//证明变量是可以被改变的。
//	weight = weight + 5;
//	printf("%lf\n", weight);//打印一个单浮点 - %lf。
//	return 0;
//}

//int a = 100;//全局变量，在括号外部定义的。
//int main()
//{
//	int a = 10;//局部变量，在括号内部定义的。
//	printf("%d\n", a);//当全局变量和局部变量名字相同的情况下，局部变量优先；不建议把全局变量和局部变量的名字写成一样的。
//	return 0;
//}

////写一个代码求2个整数的和。
//int main()
//{
//	int num = 0;
//	int num1 = 0;
//	int num2 = 0;
//	scanf_s("%d %d", &num1,&num2);//scanf函数是输入函数。
//	num = num1 + num2;//要放在scanf的下面。
//	//printf("%d", num1);
//	//printf("+");
//	//printf("%d", num2);
//	//printf("=");
//	//printf("%d\n", num);
//	printf("%d+%d=%d\n", num1,num2,num);
//	return 0;
//}

////打印100~200之间的素数
//int main()
//{
//	int a = 0;
//	int c = 0;
//	for (a = 100; a < 200; a++)
//	{
//		int b = 0;
//		for (b = 2; b < a; b++)
//		{
//			if (a%b==0)
//			{
//				break;
//			}
//		}
//		if (a==b)
//		{
//			printf("%d ", a);
//			c++;
//		}
//	}
//	printf("\n素数一共有%d个\n", c);
//	return 0;
//}