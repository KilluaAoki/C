#include <time.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <Windows.h>

////计算输入的数的阶乘
//int main()
//{
//	int a = 0; int sum = 1;
//	scanf_s("%d", &a);
//	for (int i = 1; i <= a; i++)
//	{
//		sum = i * sum;
//	}
//	printf("%d!=%d\n", a, sum);
//	return 0;
//}

////计算1-10的所有数的阶乘总和
//int main()
//{
//	int a = 0; int sum = 1;
//	for (int i = 1; i <= 10; i++)
//	{
//		sum = i * sum;
//		a = a + sum;
//		printf("%d!\t=\t%d\n", i, sum);
//	}
//	printf("\n1-10的所有数的阶乘总和为：%d。\n", a);
//	return 0;
//}

////二分查找
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 }; int num = 117; int Left = 0; int Right = sizeof(arr) / sizeof(arr[0]) - 1;
//	while (Left<=Right)
//	{
//		int Middle = (Left + Right) / 2;
//		if (arr[Middle]<num)
//		{
//			Left = Middle + 1;
//		}
//		else if (arr[Middle]>num)
//		{
//			Right = Middle - 1;
//		}
//		else if (arr[Middle]=num)
//		{
//			printf("\n您找的数字的下标是：%d\n", Middle);
//			break;
//		}
//	}
//	if (Left>Right)
//	{
//		printf("\n错误：无法找到这个数字的下标\n");
//	}
//	return 0;
//}

////多个字符从两端移动向中间汇聚
//int main()
//{
//	char arr1[] = "KilluaAoki"; char arr2[] = "##########"; int Left = 0; int Right = strlen(arr2) - 1;
//	printf("\n%s\n", arr2);
//	while (Left<=Right)
//	{
//		arr2[Left] = arr1[Left];
//		arr2[Right] = arr1[Right];
//		Sleep(500);system("cls");
//		Left++; Right--;
//		printf("\n%s\n", arr2);
//	}
//	return 0;
//}

////模拟用户登录情景，最多输入三次密码。
//int main()
//{
//	int i = 0; char password[20] = { 0 };//88888888
//	for (i = 0; i < 3; i++)
//	{
//		printf("\n请输入您的密码>>");
//		scanf_s("%s", password, 20);
//		if (strcmp(password,"88888888")==0)
//		{
//			printf("\n恭喜您，登陆成功！\n");
//			break;	
//		}
//		else
//		{
//			printf("\n密码输入错误！请重新输入！\n请注意：累计错误三次将踢出程序！\n");
//		}
//	}
//	if (i==3)
//	{
//		printf("\n密码输入错误3次，踢出程序！\n");
//	}
//	return 0;
//}

////写一个猜数字游戏
////1. 自动产生一个1-100之间的随机数。
////2. 猜数字
////	a. 猜对了，则游戏结束。
////	b. 猜错了，会告诉你猜大了或猜小了，让你继续猜，直到猜对为止。
////3. 游戏可以一直玩，除非退出游戏。
//void menu()
//{
//	printf("****************************\n");
//	printf("********** 1.Play **********\n");
//	printf("********** 0.Exit **********\n");
//	printf("****************************\n");
//}
//
//void game()
//{
//	int num1 = rand() % 100 + 1; int num2 = 0;
//	//printf("%d\n", num1);
//	while (1)
//	{
//		printf("请猜数字>>");
//		scanf_s("%d", &num2);
//		if (num2<num1)
//		{
//			printf("猜小了\n");
//		}
//		else if (num2>num1)
//		{
//			printf("猜大了\n");
//		}
//		else
//		{
//			printf("恭喜你猜对了\n");
//			break;
//		}
//	}
//}
//
//int main()
//{
//	int input = 0;
//	srand((unsigned int)time(NULL));
//	do
//	{
//		menu();
//		printf("请选择>>");
//		scanf_s("%d", &input);
//		switch (input)
//		{
//		case 1:
//			game();
//			break;
//		case 0:
//			printf("退出游戏。\n");
//			break;
//		default:
//			printf("输入错误，请重新选择。\n");
//			break;
//		}
//	} while (input);
//	return 0;
//}