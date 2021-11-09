#include <stdio.h>

////乘法口诀表（上到下）
//int main()
//{
//	int a = 0;
//	for ( a = 1; a <= 9; a++)
//	{
//		int b = 0;
//		for ( b = 1; b <= a; b++)
//		{
//			printf("%d*%d=%2d ", b, a, a * b);
//		}
//		printf("\n");
//	}
//	return 0;
//}

////乘法口诀表（下到上）
//int main()
//{
//	int a = 0;
//	for ( a = 9; a >= 1; a--)
//	{
//		int b = 0;
//		for ( b = 1; b <=a  ; b++)
//		{
//			printf("%d*%d=%2d ", a, b, a * b);
//		}
//		printf("\n");
//	}
//	return 0;
//}

////判断1000年-2000年之间的闰年
//int main()
//{
//	int a = 0;
//	int b = 4;
//	int c = 100;
//	int d = 400;
//	int e = 0;
//	for ( a = 1000; a <= 2000; a++)
//	{
//		if (a%b==0)
//		{
//			if (a%c!=0)
//			{
//				printf("%d ", a);
//				e++;
//			}
//			if (a%d==0)
//			{
//				printf("%d ", a);
//				e++;
//			}
//		}
//	}
//	printf("\n闰年一共有%d个", e);
//	return 0;
//}

////判断1000年-2000年之间的闰年（优化）
//int main()
//{
//	int a = 0;
//	int b = 0;
//	for ( a = 1000; a <= 2000; a++)
//	{
//		if ((a%4==0) && (a%100!=0) || (a%400==0))
//		{
//			printf("%d ", a);
//			b++;
//		}
//	}
//	printf("\n闰年的个数为%d ", b);
//	return 0;
//}