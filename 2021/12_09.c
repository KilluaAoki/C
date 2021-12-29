#include <stdio.h>
#include <string.h>

//函数递归：一个过程或函数在其定义或说明中有直接或间接调用自身的一种方法称之为递归；同样是一种编程技巧。
// 1.递归的两个必要条件
//		a.存在限制条件，当满足这个限制条件的时候，递归便不再继续。
//		b.每次递归调用之后越来越接近这个限制条件。
// 2.即使满足递归的两个必要条件，程序也不一定正确，但不满足一定错误。
//		a.错误将会导致栈溢出（内存栈区存放着函数的形参，死递归将重复分配栈区空间至溢出）。
//		b.为了防止错误，递归层次不能太深。
// 3.函数可以用递归的方式实现，也可以用非递归即循环（迭代）的方式实现。
//		a.递归可能会导致问题，如栈溢出、效率低下等。
//		b.许多问题是以递归的形式进行解释的，这只是因为它比非递归的形式更为清晰。
//		c.当一个问题相当复杂，难以用迭代实现时，此时递归实现的简洁性便可以补偿它所带来的运行时开销。
//		d.迭代实现往往比递归实现效率更高。
// 4.何时使用递归以及何时使用非递归的方式实现功能呢？
//		a.当使用递归时，实现功能简单，并且没有明显的缺陷，这时候往往使用递归的方式实现。
//		b.当使用递归时，实现功能简单，但是有明显的缺陷，如栈溢出、效率低下等，这时候就需要使用非递归的方式实现。

////死递归示例
//int main()
//{
//	printf("Aoki\n");
//	main();//不满足两个必要条件，为死递归，将使得栈溢出。
//	return 0;
//}

////接收一个无符号整型值，按照输入顺序打印它的每一位。
//void print(unsigned int num)
//{
//	if (num > 9)
//	{
//		print(num / 10);//使用递归。
//	}
//	printf("%u ", num % 10);
//}
//int main()
//{
//	unsigned int num = 0;//定义一个无符号整型值。
//	scanf_s("%u", &num);//%u：无符号的10进制整数。
//	print(num);//调用自定义print函数。
//	return 0;
//}

////满足递归的两个条件，但分配空间过大导致栈溢出（Stack overflow）。
//void test(int a)
//{
//	if (a < 10000)
//	{
//		test(a + 1);
//	}
//}
//int main()
//{
//	int a = 10;
//	test(a);
//	return 0;
//}

////使用递归求字符串的长度
//int my_strlen(char* arr)
//{
//	if (*arr != '\0')
//	{
//		return 1 + my_strlen(arr + 1);//不建议使用++。
//	}
//	else
//	{
//		return 0;
//	}
//}
//int main()
//{
//	char arr[] = "Aoki";
//	printf("%d\n", my_strlen(arr));
//	return 0;
//}

////使用递归求输入的数的阶乘，不考虑溢出问题。
//int Fac(int num1)
//{
//	if (num1<=1)
//	{
//		return 1;
//	}
//	else
//	{
//		return num1 * Fac(num1 - 1);
//	}
//}
//int main()
//{
//	int num1 = 0;
//	scanf_s("%d", &num1);
//	int num2 = Fac(num1);
//	printf("%d\n",num2);
//	return 0;
//}

////使用递归求第n个斐波那契数，不考虑溢出问题。
//int Fib(int num1)
//{
//	if (num1<=2)
//	{
//		return 1;
//	}
//	else
//	{
//		return Fib(num1 - 1) + Fib(num1 - 2);//效率太低，如果数字太大，将会进行大量的重复运算，导致出现问题。
//	}
//}
//int main()
//{
//	int num1 = 0;
//	scanf_s("%d", &num1);
//	int num2 = Fib(num1);
//	printf("%d\n", num2);
//	return 0;
//}

////使用循环（迭代）求第n个斐波那契数
//int Fib(int num1)
//{
//	int a = 1, b = 1, c = 1;
//	for ( num1; num1 > 2; num1--)
//	{
//		c = a + b;
//		a = b;
//		b = c;
//	}
//	return c;
//}
//int main()
//{
//	int num1 = 0;
//	scanf_s("%d", &num1);
//	int num2 = Fib(num1);
//	printf("%d\n", num2);//运行发现比递归效率更高。
//	return 0;
//}

//探究汉诺塔问题以及青蛙跳台阶问题。