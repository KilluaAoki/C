#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>

/*
   分支和循环语句
		1.关于C语言的结构和语句
			a.C语言是结构化的程序设计语言，可分为三种结构：顺序结构(即从头走到尾)、选择结构和循环结构。
			b.C语言语句可分为五类语句：表达式语句、函数调用语句、控制语句、复合语句、空语句。
		2.控制语句：用于控制程序的执行流程，以实现程序的各种结构方式，它们由特定的语句定义符组成，C语言有如下三类共九种控制语句。
			a.条件判断语句(分支语句)："if"语句、"switch"语句。
			b.循环执行语句："do while"语句、"while"语句、"for"语句。
			c.转向语句："break"语句、"goto"语句、"continue"语句、"return"语句。
*/

/*
	"if"语句：
		1.如果"if"语句后的括号内表达式的结果为真，则语句执行。
		2.在C语言中"0"(整型)表示为假(即"false")，非"0"(整型)表示为真(即"true")，即使是负数也表示为真(重点在于非"0")。
		3.C语言中并无内置"true"和"false"(即布尔类型)，如需使用"true"和"false"需要引用头文件："stdbool.h"。
		4."else"语句："else"语句只匹配离它最近的"if"语句，并且"else"语句仅在"if"语句以及"else if"语句(如果有的话)语句中的表达式的值为假时执行。
		5."else if"语句：如果离它最近的"if"语句(包括"else if"语句)的表达式判断为假，则执行此语句；注意多"if"语句和"if"语句配合"else"语句的含义是不一样的。
		6."if"语句后的分号：在C语言中，分号预示着一条语句的结尾，但并不是每条C语言语句都需要分号作为结尾，在"if"语句的表达式后加上括号会解析成空语句，故"if"语句的表达式后一般不需要加上分号。
*/

////"if"语句示例：中老年判断器。
//int main()
//{
//	int age = 0;
//	scanf_s("%d", &age);
//
//	if (18 >= age)//"if"关键字后的括号内即为表达式，若表达式整体为真，则执行代码块内的语句，否则不执行。
//	{
//		printf("少年\n");
//	}
//	else if (age > 18 && age <= 26)//注意表达式不可写成类似"1<age<3"的这种形式，因为此表达式会先判断"1<age"，若此时假设"age=20"，"1<age"判断结果为"1"("true"默认为"1")，代入到后半段"1<3"表达式成立，显然不正确。
//	{
//		printf("青少年\n");
//	}
//	else if (age > 26 && age <= 40)
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
//	return 0;//"return"语句：用来终止一个函数并返回其后面跟着的值，若在主函数"main"中使用则表示退出程序；每个函数只能返回一个值或无返回值("return"表示终止函数)，但函数可有多个接收参数。
//}

////高质量表达式判断写法示例：可查阅《高质量C编程指南》或《Google编程规范》规范自身代码。
//int main()
//{
//	int num = 0;
//	if (5 == num)//为了避免出错(防止少写一个等号)，故采用变量在后的写法。
//	{
//		return 1;
//	}
//	return 0;
//}

////"if"语句练习题例一：判断输入的数是否为奇数。(以下两方法思维不同，故写法不同)
//int main()
//{
//	int a = 0;
//	scanf_s("%d", &a);
//
//	//方法一
//	if (a % 2 == 1)
//	{
//		printf("这个数是奇数。\n");
//	}
//	else
//	{
//		printf("这个数不是奇数。\n");
//	}
//
//	//方法二
//	if (a % 2 == 0)
//	{
//		printf("这个数不是奇数。\n");
//	}
//	else
//	{
//		printf("这个数是奇数。\n");
//	}
//	
//	return 0;
//}

////"if"语句练习题例二：打印1~100之间的奇数。
//int main()
//{
//	for (int i = 1; i <= 100; i+=2)
//	{
//		printf("%d ", i);
//	}
//	return 0;
//}

/*
	"switch"语句：常用于多分支情况。
		1."switch"语句依照语句后的括号内表达式的整型值进入语句项，而语句项即为"case"语句，"case"语句后的整型或字符型的常量或常量表达式对应着值。
		2."switch"语句后的括号内的表达式必须为整型表达式，而"switch"语句中的"case"语句后的表达式必须为整型或字符型的常量或常量表达式。
		3.若"switch"语句后的括号内表达式的整型值进入代码块后没有对应的"case"语句，则若有"default"语句，则执行"default"语句代码块的内容。
		4.若"case"语句中没有"break"语句用于跳出本层的"switch"语句，则会根据顺序继续执行下一个"case"语句或"default"语句或跳出"switch"语句(当此"case"语句为最后一个分支时)。
		5."default"语句可以放在"switch"语句代码块中的任意位置，而且语句流会像执行一个case标签一样执行default子句。。
		6.若"case"语句或"default"语句中没有使用"{}"表示代码块，则不能声明变量，故要在"switch"语句内声明变量需要在子句的"{}"内声明，但注意离开"{}"变量的生命周期即结束。
		7."switch"语句允许嵌套使用，同时"break"语句可跳出本层的"switch"语句。
		8.在最后一个"case"语句的后面加上一条"break"语句，可以避免出现在以前的最后一个"case"语句后面忘了添加"break"语句。
*/

////"switch"语句使用示例一
//int main()
//{
//	int day = 0;
//	scanf_s("%d", &day);
//	switch (day)
//	{
//	case 1:
//		printf("星期一\n");
//		break;
//	case 2:
//		printf("星期二\n");
//		break;
//	case 3:
//		printf("星期三\n");
//		break;
//	case 4:
//		printf("星期四\n");
//		break;
//	case 5:
//		printf("星期五\n");
//		break;
//	case 6:
//		printf("星期六\n");
//		break;
//	case 7:
//		printf("星期日\n");
//		break;
//	}
//	return 0;
//}

////"switch"语句使用示例二
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
//	default:
//		printf("输入错误\n");
//		break;
//	}
//	return 0;
//}

/*
	"while"语句：需用重复执行多次的代码块常使用循环执行语句。
		1."while"语句的执行顺序：先判断"while"语句后括号内表达式的值，如果为真则执行代码块内的语句，否则不执行，当执行完代码块内的语句再次进行判断，以此反复。
		2."while"语句内的"break"语句用于跳出本层循环，而"continue"语句表示终止本次(本轮)循环，当代码执行到"continue"语句时，本轮的循环终止，直接进行判断，进入下一轮循环。
		3."while(1)"表示死循环，表示若无跳出语句，则一直重复运行代码块内的语句；死循环常应用于单片机或特殊程序。
*/

////"while"语句使用示例
//int main()
//{
//	int i = 1;
//	while (i<=10)
//	{
//		if (i==5)
//		{
//			continue;//"continue"语句会跳过本次循环continue后边的代码(直接去判断部分，看是否进行下一次循环)：这时候"i"无法调整就会一直等于"5"，造成死循环。
//			break;//直接跳出本层的"while"循环语句，但因为"continue"语句会导致这条语句永不执行。
//		}
//		printf("%d ", i);
//		i++;
//	}
//	return 0;
//}

/*
	"getchar"函数：从标准输入流(键盘)(stdin)读取下一个字符。(理解)
		1.头文件："stdio.h"。
		2.函数声明：int getchar(void);。
			a.函数头"int"表示此函数的返回值是整型类型；在此函数中意为成功获取字符是返回获取的字符(Ascill码值)，失败时为"EOF"。
			b.函数参数"void"：不接收任何参数。
		3.等价于从标准输入流获取字符的"getc"函数，即"getc(stdin)"。
	"putchar"函数：写字符到标准输出流(屏幕)(stdout)。(理解)
		1.头文件："stdio.h"。
		2.函数声明：int putchar(int ch);。
			a.函数头"int"表示此函数的返回值是整型类型；在此函数中意为成功获取字符是返回写入的字符(Ascill码值)，失败时为"EOF"。
			b.函数参数"int ch"：将整型类型作为参数；在此函数中意为要被写入的字符(Ascill码值)。
		3.在"putchar"函数的内部，字符于写入前被转换到"unsigned char"类型，即被转到到无符号字符类型。
		4.等价于写字符到标准输出流的"putc"函数，即"putc(ch, stdout)"。
*/

////"getchar"函数使用示例：从缓冲区读取字符，键盘输入字符到缓冲区，键盘输入"A"并回车，实际上键盘是输入"A\n"，第一次"getchar"函数拿到"A"，第二次拿到"\n"。
//int main()
//{
//	int ch = 0;
//	while ((ch = getchar()) != EOF)//"getchar"函数：从键盘获取一个字符(Ascill码值)，所以存储为整型；"EOF"：读到错误或文件结束标志，右键转到定义发现是"-1"。
//	{
//		putchar(ch);//"putchar"函数：在屏幕上输出一个字符。
//	}
//	return 0;
//}

////确认密码示例(不必深究修改了密码)
//int main()
//{
//	//假设输入"123456"以及回车。
//	char password[20] = { 0 };
//	printf("请输入密码:>");
//	scanf_s("%s", password,20);//数组本身就是地址，不需要取地址；此时读取了"123456"；"scanf_s"函数要求在输入字符或字符串或集合字符时，添加最大长度作为参数。
//
//	printf("请确定密码（Y/N）:>");
//
//	////清理缓冲区：重复使用"getchar"函数，拿取不需要的字符，而且不使用获取的字符。
//	////getchar();//只使用一次"getchar"函数只能拿取一个字符，所以使用循环清除缓冲区更彻底；"gets"函数可获取一整行的字符串。
//	//int tmp = 0;
//	//while ((tmp = getchar()) != '\n')
//	//{
//	//    ;//空语句
//	//}
//
//	int ch = getchar();//若不清理缓冲区，"getchar"函数就会直接拿取了"\n"，导致直接打印出"确认失败"，故需要清除掉"\n"。
//	if (ch == 'Y')//字符用单引号引起来
//	{
//		printf("确认成功\n");
//	}
//	else
//	{
//		printf("确认失败\n");//若读取了回车就会直接打印出"确认失败"。
//	}
//	
//	return 0;
//}

////打印数字字符示例
//int main()
//{
//	int ch = 0;//初始化部分：初始化循环变量。
//	while ((ch = getchar()) != EOF)//括号内为条件判断部分：判断循环时候终止。
//	{
//		if (ch < '0' || ch > '9')
//		{
//			continue;//意为：除了数字字符，其余字符都跳过本次循环体中余下尚未执行的语句，直接重新到条件判断部分。
//		}
//		putchar(ch);
//	}
//	return 0;
//}

////"while"循环语句练习题一
//int main()
//{
//	int i = 1;
//	while (i <= 10)
//	{
//		if (i == 5)
//			continue;
//		printf("%d ", i);//程序结果为：1 2 3 4 ...(死循环)。
//		i = i + 1;
//	}
//	return 0;
//}

////"while"循环语句练习题二
//int main()
//{
//	int i = 1;
//	while (i <= 10)
//	{
//		i = i + 1;
//		if (i == 5)
//			continue;
//		printf("%d ", i);//程序结果为：2 3 4 6 7 8 9 10 11 。
//	}
//	return 0;
//}

/*
	"for"语句：包含初始化部分、条件判断部分、调整部分。
		1."for(;;)"可表 示为死循环，这条语句省略了"for"语句的三个部分，导致恒为真。
		2."for"语句的执行顺序
			a.先执行初始化部分的语句，再执行条件判断部分的语句，若判断结果为真，则进入代码块，若为假会跳过调整部分，并且不进入代码块。
			b.当条件判断部分判断结果为真时，执行完代码块内的语句会执行调整部分的语句，并且再次执行条件判断部分的语句，以此反复。
		3."for"循环语句易操控，并且可以易推断出循环次数，故常使用"for"循环语句。
		4.建议"for"语句的循环控制变量的取值采用"前闭后开区间"写法，更易于推断循环次数。
		5.在C语言标准C99中，"for"语句的初始化部分可定义并初始化变量，等同于在一个局部代码块内定义变量，但此变量的生命周期只存在于"for"语句的三大部分和代码块内，一旦离开便销毁。
		6."for"语句的初识化部分只在条件判断部分前执行一次。
		7."for"语句的三大部分分别都可省略，但需要考虑省略后的后果。
*/

////"for"循环语句使用示例一：打印1~10。
//int main()
//{
//	//方法一
//	int i = 0;
//	for (i = 1; i < 11; i++)//判断部分为前闭后开区间写法。
//	{
//		printf("%d ", i);
//	}
//
//	printf("\n");
//
//	//方法二
//	for (int i = 1; i <= 10; i++)//初识化部分可同时定义变量，但需要注意在C99标准前不可使用；判断部分为前闭后闭区间写法。
//	{
//		printf("%d ", i);
//	}
//	return 0;
//}

////"for"循环语句使用示例二
//int main()
//{
//	int i = 0;
//	for (i = 1; i <= 10; i++)
//	{
//		if (i == 5)
//			break;
//		printf("%d ", i);//程序结果为：1 2 3 4 。
//	}
//	return 0;
//}

////"for"循环语句使用示例三
//int main()
//{
//	int i = 0;
//	for (i = 1; i <= 10; i++)
//	{
//		if (i == 5)
//			continue;//当"i"等于"5"时则不执行后面的语句，但会直接执行"for"循环语句的调整部分，所以不会和"while"语句一样可能造成死循环。
//		printf("%d ", i);//程序结果为：1 2 3 4 6 7 8 9 10 。
//	}
//	return 0;
//}

////"for"循环语句练习题例一
//int main()
//{
//	////代码一：如下代码，程序运行的结果是什么？
//	//for (;;)
//	//{
//	//	printf("Aoki\n");//死循环打印："Aoki"及换行。
//	//}
//
//	////代码二：如下代码，打印多少个"Aoki"及换行？
//	//int i = 0;
//	//int j = 0;
//	//for (i = 0; i < 10; i++)
//	//{
//	//	for (j = 0; j < 10; j++)
//	//	{
//	//		printf("Aoki\n");//一共打印"100"个"Aoki"及换行。
//	//	}
//	//}
//
//	////代码三：如下代码，打印多少个"Aoki"及换行？
//	//int i = 0;
//	//int j = 0;
//	//for (; i < 10; i++)
//	//{
//	//	for (; j < 10; j++)//省略了初始化部分，当"i = 1"和"j = 10"时，"j"只会一直为"10"不会重置，导致不会进入代码块。
//	//	{
//	//		printf("Aoki\n");//一共打印"10"个"Aoki"及换行。
//	//	}
//	//}
//	
//	////代码四：如下代码，打印多少个"Aoki"及换行？
//	//int x, y;
//	//for (x = 0, y = 0; x < 2 && y < 5; ++x, y++)//使用多个变量控制循环
//	//{
//	//	printf("Aoki\n");//一共打印"2"个"Aoki"及换行。
//	//}
//
//	return 0;
//}

////"for"循环语句练习题例二
//int main()
//{
//	int i = 0;
//	int k = 0;
//	for (i = 0, k = 0; k = 0; i++, k++)//不会进入代码块，因判断部分为"k = 0"，整个表达式的结果为假。
//	{
//		k++;
//	}
//	return 0;
//}

/*
	"do while"语句：重复执行代码块内的语句，直到条件判断部分内的表达式为假。
		1."do while"语句的执行顺序：此循环语句会直接进入代码块，当执行完代码块内的语句时，再执行条件判断部分内的表达式，为真继续，为假不再执行，故此循环语句至少循环一次。
		2.常应用于主函数"main"中使用，但其他应用场景较少。
*/

////"do while"循环语句使用示例一
//int main()
//{
//	int i = 10;
//	do
//	{
//		if (5 == i)
//			break;
//		printf("%d ", i);//程序结果为：10 。
//	} while (i < 10);//循环体内只执行了一次。
//	return 0;
//}

////"do while"循环语句使用示例二
//int main()
//{
//	int i = 1;
//	do 
//	{
//		if (i == 5)
//			continue;
//		printf("%d ", i);//程序结果为：1 2 3 4 ...(死循环)。
//		i++;
//	} while (i <= 10);
//	return 0;
//}

////循环练习题例一：计算输入的数的阶乘。
//int main()
//{
//	int num = 0, factorial = 1;
//	printf("请输入一个数>>");
//	scanf_s("%d", &num);
//	for (int i = 1; i <= num; i++)
//	{
//		factorial *= i;
//	}
//	printf("%d!\t=\t%d\n", num, factorial);
//	return 0;
//}

////循环练习题例二：计算"1!+2!+3!+……+10!"。
//int main()
//{
//	int sum = 0, factorial = 1;
//	for (int i = 1; i <= 10; i++)
//	{
//		factorial *= i;
//		sum += factorial;
//		printf("%d!\t=\t%d\n", i, factorial);
//	}
//	printf("\n1!+2!+3!+……+10! = %d\n", sum);
//	return 0;
//}

////循环练习题例三：二分查找。
//int main()
//{
//	int num = 7;
//	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//	int left = 0, right = sizeof(arr) / sizeof(arr[0]) - 1;
//	while (left <= right)
//	{
//		int middle = ((right - left) >> 1) + left;
//		if (arr[middle] > num)
//		{
//			right = middle - 1;
//		}
//		else if (arr[middle] < num)
//		{
//			left = middle + 1;
//		}
//		else
//		{
//			printf("%d\n", middle);
//			break;
//		}
//	}
//	if (left > right)
//	{
//		printf("找不到\n");
//	}
//	return 0;
//}

////循环练习题例四：多个字符从两端移动向中间汇聚。
//int main()
//{
//	char arr1[] = "KilluaAoki";
//	char arr2[] = "##########";
//	int Left = 0;
//	int Right = (int)strlen(arr2) - 1;
//	printf("\n%s\n", arr2);
//	while (Left<=Right)
//	{
//		arr2[Left] = arr1[Left];
//		arr2[Right] = arr1[Right];
//		Sleep(500);
//		system("cls");
//		Left++; Right--;
//		printf("\n%s\n", arr2);
//	}
//	return 0;
//}

////循环练习题例五：模拟用户登录情景(最多输入三次密码)。
//int main()
//{
//	int i = 0;
//	char password[20] = { 0 };
//	for (i = 0; i < 3; i++)
//	{
//		printf("\n请输入您的密码>>");
//		scanf_s("%s", password, 20);
//		if (strcmp(password, "88888888") == 0)
//		{
//			printf("\n恭喜您，登陆成功！\n");
//			break;
//		}
//		else
//		{
//			printf("\n密码输入错误！请重新输入！\n请注意：累计错误三次将踢出程序！\n");
//		}
//	}
//	if (i == 3)
//	{
//		printf("\n密码输入错误3次，退出程序！\n");
//	}
//	return 0;
//}

////循环练习题例六：猜数字游戏。
//void Menu()
//{
//	printf("*****************************\n");
//	printf("********** 1. Play **********\n");
//	printf("********** 0. Exit **********\n");
//	printf("*****************************\n");
//}
//
//void Game()
//{
//	int randNum = rand() % 100 + 1;
//	int input = 0;
//	system("cls");
//	while (1)
//	{
//		printf("请输入0~100之间的数字>>");
//		scanf_s("%d", &input);
//		if (input > randNum)
//		{
//			printf("猜大了。\n");
//		}
//		else if (input < randNum)
//		{
//			printf("猜小了。\n");
//		}
//		else
//		{
//			printf("\n恭喜你猜对了！\n\n五秒后返回主菜单...\n");
//			Sleep(5000);
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
//		system("cls");
//		Menu();
//		printf("Please Enter>>");
//		scanf_s("%d", &input);
//		switch (input)
//		{
//		case 1:
//			Game();
//			break;
//		case 0:
//			printf("\nExit!\n");
//			break;
//		default:
//			printf("\nInput Error! Please Enter Again\n\n");
//			system("pause");
//			break;
//		}
//	} while (input);
//	return 0;
//}

/*
	"goto"语句：将控制无条件转移跳转到标签位置。
		1.较少情况使用，常用于终止程序在某些深度嵌套的结构的处理过程。
		2.标签是一个标识符，后跟一个冒号和一个语句(C23标准前)。
		3.标签是仅有的拥有函数作用域的标识符：能在其所出现于的函数中的任何位置使用它们(在"goto"语句中)，并且任何语句前可以有多个标号。
		4.只能在一个函数范围内跳转，不能跨函数。
*/

////"goto"语句使用示例：关机程序。
//int main()
//{
//	char input[20] = { 0 };
//	system("shutdown -s -t 60"); //"system"函数：可执行系统命令；使用需引用头文件"stdlib.h"。
//again:
//	printf("\n请注意！您的系统即将在一分钟后关机！\n请输入\"Aoki\"，终止关机操作。\n>>");
//	scanf_s("%s", input, 20);
//	if (strcmp(input, "Aoki") == 0)//两个字符串比较不能使用"=="，应使用"strcmp"函数；使用"strcmp"函数需引用头文件"string.h"；若两字符串相等"strcmp"函数返回整型"0"。
//	{
//		system("shutdown -a");
//		printf("恭喜你！输入成功！退出程序ing...\n");
//		system("pause");
//	}
//	else
//	{
//		printf("你输入错误了哦~\n");
//		system("pause");
//		system("cls");
//		goto again;
//	}
//	return 0;
//}

////关机程序(循环版)
//int main()
//{
//	char arr[20] = { 0 };
//	system("shutdown -s -t 60");
//	while (1)
//	{
//		printf("\n请注意！您的系统即将在一分钟后关机！\n请输入\"Aoki\"，终止关机操作。\n>>");
//		scanf_s("%s", arr, 20);
//		if (strcmp(arr, "Aoki") == 0)
//		{
//			system("shutdown -a");
//			printf("恭喜你！输入成功！退出程序ing...\n");
//			break;
//		}
//		else
//		{
//			printf("\n你输错了哦~\n惩罚你等5秒钟！\n");
//			Sleep(5000);
//			system("cls");
//		}
//	}
//	return 0;
//}