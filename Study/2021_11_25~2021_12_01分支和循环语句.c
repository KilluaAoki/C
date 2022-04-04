#include <time.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <Windows.h>

/*
    关于C语言的结构和语句
        1.C语言是结构化的程序设计语言：顺序结构（即从头走到尾）、选择结构、循环结构。
        2.C语言语句可分为以下五类：表达式语句、函数调用语句、控制语句、复合语句、空语句。
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
//	
//	int num = 0;
//	if (5==num)//高质量写法，避免出错（防止少写一个等号）；代码书写风格：查阅高质量C编程指南或Google编程规范。
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
//		break;//在最后一个case语句的后面加上一条break语句（之所以这么写是可以避免出现在以前的最后一个case语句后面忘了添加break语句）。
//	}
//	return 0;
//}

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
//		break;//在每个switch语句中都放一条default子句是个好习惯，甚至可以在后边再加一个break。
//	}
//	return 0;
//}

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

////getchar：输入函数；从缓冲区拿取数据。
////实例如下代码（不必深究修改了密码，只是举了个例子）。
//int main()
//{
//	char password[20] = { 0 };//输入123456以及回车（\n）。
//	printf("请输入密码:>");
//	scanf_s("%s", password, 20);//数组本身就是地址，不需要取地址；此时读取了123456；scanf_s要求在输入char或字符串数组时，添加最大长度作为参数。
// //gets函数拿取一行的代码。
//	printf("请确定密码（Y/N）:>");
//
//	////清理缓冲区：再用getchar，拿取不需要的字符，而且不用它。
//	//getchar();//只能拿取一个字符，使用循环除了缓冲区更彻底。
//	int tmp = 0;
//	while ((tmp=getchar())!='\n')
//	{
//		;//空语句
//	}
//
//	int ch = getchar();//直接拿取了“\n”；需要清除掉\n。
//	if (ch=='Y')//字符用单引号引起来
//	{
//		printf("确认成功\n");
//	}
//	else
//	{
//		printf("确认失败\n");//读取了回车直接确认失败了。
//	}
//	return 0;
//}

//int main()
//{
//	int ch = 0;//初始化部分：初始化循环变量。
//	while ((ch=getchar())!=EOF)//括号内为条件判断部分：判断循环时候终止。
//	{
//		if (ch<'0' || ch>'9')
//		{
//			continue;//意为：除了数字字符，其余字符都跳过本次循环体中余下尚未执行的语句，直接重新到条件判断部分。
//		}
//		putchar(ch);
//	}//此while语句没有调整部分；调整部分：循环条件的调整（如i++）。
//	return 0;
//}

////for循环语句：初始化部分、条件判断部分（如果为假则不执行（赋值为0即为假））、调整部分都在一起。
////不可在for 循环体内修改循环变量，防止 for 循环失去控制。
////建议for语句的循环控制变量的取值采用“前闭后开区间”写法（可以推断循环几次）。
////for循环中的初始化部分、判断部分（省略的话即为恒为真，可能导致死循环）、调整部分是可以省略的，但是不建议省略，容易导致问题。
//int main()
//{
//	for (int i = 1; i <= 10; i++)
//	{
//		
//		//if (i==5)
//		//{
//		//	break;//终止整个循环。
//		//}
//
//		//if (i==5)
//		//{
//		//	continue;//当i等于时则不执行下面的打印命令，但还是会执行for循环的调整部分，所以不会和while一样可能造成死循环。
//		//}
//
//		printf("%d \n", i);
//	}
//	return 0;
//}

////do...while()循环语句：不光三七二十一肯定会执行一次。
//int main()
//{
//	int i = 1;
//	do
//	{
//		//if (i==5)
//		//{
//		//	break;
//		//}
//
//		//if (i == 5)
//		//{
//		//	continue;//死循环。
//		//}
//
//		printf("%d ", i);
//		i++;
//	} while (i<=10);
//	return 0;
//}

////计算n的阶乘。
//int main()
//{
//	int a = 0; int sum = 1;
//	printf("请输入一个数：");
//	scanf_s("%d", &a);
//	for (int i = 1; i <= a; i++)
//	{
//		sum = sum * i;
//	}
//	printf("这个数的阶乘是：%d\n", sum);
//	return 0;
//}

////1-10的所有阶乘。
//int main()
//{
//	int a, b;
//	for ( a=b = 1; a <= 10; a++)
//	{
//		b = b * a;
//		printf("%d\t%d\n", a, b);
//	}
//	return 0;
//}

////1-10的所有阶乘相加。
//int main()
//{
//	int a, b,c=0;
//	for ( a=b = 1; a <= 10; a++)
//	{
//		b = b * a;
//		c = c + b;
//	}
//	printf("1-10的阶乘总和为：%d\n", c);
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