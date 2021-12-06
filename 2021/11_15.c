#include<stdio.h>

////求十个整数中的最大值
//int main()
//{
//	int arr[10] = {-1,-2,-3,-4,-5,-6,-7,-8,-9,-10};int i = 0;int max = arr[0];
//	for ( i = 1; i < sizeof(arr)/sizeof(arr[0]); i++)
//	{
//		if (arr[i]>max)
//		{
//			max = arr[i];
//		}
//	}
//	printf("%d\n", max );
//	return 0;
//}

////将随机三个数按从大到小输出
//void Swap(int *px, int *py)
//{
//	int Add = *px;
//	*px = *py;
//	*py = Add;
//}
//int main()
//{
//	int a = 0; int b = 0; int c = 0;
//	scanf_s("%d %d %d", &a, &b, &c);
//	if (a<b)
//	{
//		//int Add = a;
//		//a = b;
//		//b = Add;
//		Swap(&a, &b);
//	}
//	if (a<c)
//	{
//		//int Add = a;
//		//a = c;
//		//c = Add;
//		Swap(&a, &c);
//	}
//	if (b<c)
//	{
//		//int Add = b;
//		//b = c;
//		//c = Add;
//		Swap(&b, &c);
//	}
//	printf("%d %d %d\n", a, b, c);
//	return 0;
//}

////求两个数的最大公约数和最小公倍数
//int main()
//{
//	int a = 0; int b = 0; int i = 0;
//	scanf_s("%d %d", &a, &b);
//	int c = a * b;
//	while ((i=a%b)!=0)
//	{
//		a = b;
//		b = i;
//	}
//	c = c / b;
//	printf("最大公约数为：%d。\n", b);
//	printf("最小公倍数为：%d。\n", c);
//	return 0;
//}

////操作符：“~“按二进制位取反（把所有二进制位中的数字，1变成0，0变成1）
//int main()
//{
//	int a = 0;
//	//一个整数的二进制表示有三种：原码、反码、补码；整数在内存中储存的是补码；整型变量是4字节=32bit位。
//	//正数：原码、反码、补码相同
//	//负数：最高符号位1表示为负数；负数的原码变反码则是符号位不变，其余按位取反为反码；反码加1为补码。
//	printf("%d\n", ~a);//打印的是原码，内存存储的是补码。
//	return 0;
//}

////操作符：“++“和“--”（只列举++的例子，--同理）
//int main()
//{
//	int a = 10;
//
//	//int b = ++a;//前置++：先加后使用；
//	//printf("%d\n", b);//11
//	//printf("%d\n", a);//11
//
//	//int b = a++;//后置++：先使用后加；
//	//printf("%d\n", b);//10
//	//printf("%d\n", a);	//11
//
//	return 0;
//}

////操作符：“(类型)”强制类型转换
//int main()
//{
//	//int a = 3.14;//Ctrl+F7报警告：从“double”转换到“int”，可能丢失数据。
//	int a = (int)3.14;//强制转换double类型为int类型。
//	printf("%d\n", a);
//	return 0;
//}

////逻辑操作符：“&&”逻辑与和“||”逻辑或
//int main()
//{
//	//int a = 1; int b = 1; int c = a && b;
//	//printf("%d\n", c);//结果为1，意思为当a和b中都为真则为真。
//
//	//int a = 1; int b = 0; int c = a && b;
//	//printf("%d\n", c);//结果为0，意思为当a和b中只要有一个为假则都为假。
//
//	//int a = 1; int b = 0; int c = a || b;
//	//printf("%d\n", c);//结果为1，意思为当a和b中只要有一个为真则为真。
//	return 0;
//}

////条件操作符：“else1?else2:else3”；又名三目操作符；意为当else1成立则采用else2的结果，否则采用else3的结果。
//int main()
//{
//	int a = 0;
//	int b = 3;
//	int max = 0;
//
//	//if (a>b)
//	//{
//	//	max = a;
//	//}
//	//else
//	//{
//	//	max = b;
//	//}
//
//	max = a > b ? a : b;//如果a>b成立这结果为a否则为b，将值赋给max变量。
//	
//	printf("%d\n", max);
//
//	return 0;
//}

////逗号表达式：逗号隔开的一串表达式；从左向右依次计算的，整个表达式的结果是最后一个表达式的结果。
//int main()
//{
//	int a = 0;int b = 3;int c = 5;
//	int d = (a = b + 2, c = a - 4, b = c + 2);//依次计算，b的值赋给了d。
//	printf("%d\n", d);//结果为3。
//	return 0;
//}

////下标引用操作符
//int main()
//{
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	printf("%d\n", arr[5]);
//	return 0;
//}

////函数调用操作符：调用函数的时候，函数名后边的括号就是函数调用操作符。
//int main()
//{
//	printf("%d", 666);
//	return 0;
//}

////关键字：由C语言提供的，不能自己创建关键字；变量名不能是关键字。
//int main()
//{
//	//extern：声明外部符号（比如跨文件的全局变量，需要使用extern声明一下）。
//
//	//void无或者空的意思。
//
//	//auto关键字：每个局部变量都有auto修饰，但省略掉了；auto在新的C语言语法中也有其他用法，暂时不考虑。
//	{
//		auto int a = 0;//自动创建，自动销毁的，即为自动变量。
//		int b = 0;//auto省略掉了。
//	}
//	
//	//register关键字：大量或频繁被使用的数据，放在寄存器中可提升效率；
//	{
//		register int a = 0;//建议num的值存放在寄存器中（编译器说的算，只是建议）；寄存器存在于速度金字塔顶尖。
//	}
//						 
//	//define和include不是关键字，是预处理指令。
//	//define可定义标识符常量、可定义宏。
//	{
//		#define MAX 1000//定义标识符常量。
//		printf("%d\n", MAX); 
//	}
//	{
//		#define ADD(X,Y) ((X)+(Y))//定义宏；注意这里的括号。
//		printf("%d\n", 4 * ADD(2, 3));//先乘除后加减，若上行不加括号则打印结果为11。
//	}
//
//	//typedef：类型重定义，即类型重命名。
//	{
//		typedef unsigned int u_int;//将”unsigned“起了个别名叫“u_int“；意义在于缩短了名字，不用打那么多（可是我有自动补全呀呜呜）。
//		unsigned int a = 100;//unsigned：无符号的。
//		u_int b = 100;//可以发现同时起作用。
//	}
//	 
//	//存储的类型分为栈区（局部变量和函数参数）、堆区（动态内存分配的）、静态区（全局变量、静态变量、static修饰的变量）。
//	//static：静态的，用来修饰变量和函数的；static修饰局部变量、全局变量、函数。
//	//static修饰的局部变量，由栈区转变成了静态区。
//	//static修饰的全局变量，使得这个全局变量只能在自己所在的源文件（.c）内部可以使用（extern声明也没用了）;本质是把全局变量的外部链接属性更改为内部连接属性。
//	//static修饰的函数同全局变量（上一行）。
//	{
//		int i = 0;
//		while (i < 10)
//		{
//			static int a = 1;//static修饰的局部变量出局部变量后被保留了，改变了局部变量的生命周期（本质上是改变了变量的存储类型）。
//			a++;
//			printf("%d ", a);//2 3 4 5 6 7 8 9 10 11。
//			i++;
//		}
//	}
//	
//	return 0;
//}

////指针：地址。
//int main()
//{
//	//使用实例
//	int a = 10;//a在内存中分配的空间为4个字节。
//	printf("%p\n", &a);//%p：打印地址，%p是以地址的形式打印。
//	int *pa = &a;//pa是用来存放地址的；在C语言中pa叫指针变量；“*”说明 pa是指针变量；int说明pa指向的对象是int类型的；*pa就是通过pa里边的地址，找到a；取出的是第一个字节的地址（较小的地址）。
//	*pa = 20; //“*”：间接访问操作符，又称解引用操作符。
//	printf("%d\n", a);
//
//	//计算指针变量的大小
//	printf("%d\n", sizeof(char*));
//	printf("%d\n", sizeof(short*));
//	printf("%d\n", sizeof(int*));
//	printf("%d\n", sizeof(long*));
//	printf("%d\n", sizeof(long long*));
//	printf("%d\n", sizeof(float*));
//	printf("%d\n", sizeof(double*));
//	//指针变量的大小取决于地址的大小。
//	//32位平台下地址是32个bit位（即4个字节）。
//	//64位平台下地址是64个bit位（即8个字节）。
//	//指针大小在32位平台是4个字节，64位平台是8个字节。
//	
//	return 0;
//}	

////结构体：结构体使得C语言有能力描述复杂类型，而且可以让C语言创建新的类型出来。
//struct Stu//struct：创建类型。
//{
//	char name[20];//名字
//	int age; //年龄
//	double score;//成绩
//};
//struct Book
//{
//	char name[20];//名字
//	float price;//价格
//	char id;//页面号
//};
//int main()
//{
//	struct Stu s={"Aoki",19,99.9};//结构体的创建和初始化。
//	printf("1：%s %d %lf\n", s.name, s.age, s.score);//“.”操作符：结构成员访问操作符。
//	
//	struct Stu *ps = &s;//把结构交给指针变量。
//	printf("2：%s %d %lf\n", (*ps).name, (*ps).age, (*ps).score);
//
//	printf("3：%s %d %lf\n", ps->name, ps->age, ps->score);//结构体指针->成员变量名。
//
//	return 0;
//}