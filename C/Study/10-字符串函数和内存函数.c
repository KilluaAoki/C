#include <stdio.h>
#include <ctype.h>
#include <string.h>

/*
	字符串函数和内存函数
		1.字符串函数
			a.获取字符串长度："strlen"函数。
			b.长度不受限制的字符串函数："strcpy"函数、"strcat"函数、"strcmp"函数。
			c.长度受限制的字符串函数："strncpy"函数、"strncat"函数、"strncmp"函数。
			d.字符串查找："strstr"函数、"strtok"函数。
			e.错误信息报告："strerror"函数。
			f.字符操作函数
		2.内存函数
			a.内存操作函数："memcpy"函数、"memmove"函数、"memset"函数、"memcmp"函数。
*/

/**
	"strlen"函数：获取字符串长度。
		1.头文件："string.h"。
		2.函数声明：size_t strlen(const char* str);。
			a.函数头"size_t"表示此函数的返回值是无符号整型类型，在此函数中表示返回以"\0"结尾的字符串"str"的长度(不包含"\0")。
			b.函数参数"const char* str"：将字符指针作为参数，并转换为由"const"修饰的"char*"类型(const char*)；在此函数中意为指向字符串的指针。
		3.函数参数"const char* str"指向的字符串必须以"\0"结尾，否则结果不准确。
*/

////使用"strlen"函数示例
//int main()
//{
//	char* str = "KilluaAoki";
//	char arr1[] = "Aoki";
//	char arr2[] = { 'A','o','k','i' };
//	printf("%zu\n", strlen(str));
//	printf("%zu\n", strlen(arr1));
//	printf("%zu\n", strlen(arr2));//打印出随机值：使用单引号创建的数组不会默认添加"\0"作为结束标志。
//	return 0;
//}

////模拟实现"strlen"函数
//size_t My_Strlen_Count(const char* str)
//{
//	int count = 0;
//	while (*str++)
//	{
//		count++;
//	}
//	return count;
//}
//
//size_t My_Strlen_Recursion(const char* str)
//{
//	if (!*str)
//	{
//		return 0;
//	}
//	return 1 + My_Strlen_Recursion(str + 1);
//}
//
//size_t My_Strlen_Pointer(const char* str)
//{
//	const char* tmp = str;
//	while (*tmp++);
//	return tmp - str - 1;
//}
//
//int main()
//{
//	char* str = "KilluaAoki";
//
//	//计数：创建临时变量。
//	printf("%zu\n", My_Strlen_Count(str));
//
//	//递归：不创建临时变量。
//	printf("%zu\n", My_Strlen_Recursion(str));
//
//	//指针：指针运算。
//	printf("%zu\n", My_Strlen_Pointer(str));
//
//	return 0;
//}

////"strlen"函数例题
//int main()
//{
//	printf("%zu\n", strlen("abc") - strlen("abcdef"));//会打印出很大的数，因为"strlen"的返回值类型为无符号整型，就会将"-3"以无符号整型类型进行打印。
//	return 0;
//}

/**
	"strcpy"函数：复制字符串。
		1.头文件："string.h"。
		2.函数声明：char* strcpy(char* destination, const char* source);。
			a.函数头"char*"表示此函数的返回值是字符指针类型，在此函数中表示返回"destination"指针所指向的字符串的起始地址。
			b.函数参数"char* destination"：将字符指针作为参数；在此函数中意为指向要复制内容的目标数组首元素的指针(数组名)。
			c.函数参数"const char* source"：将字符指针作为参数，并转换为由"const"修饰的"char*"类型(const char*)；在此函数中意为指向作为复制来源的字符串的指针(此字符串需包含"\0")。
		3.未定义情况
			a.若目标空间数组长度不足(即空间过小)，无法容纳作为复制来源的字符串，则行为未定义。
			b.若字符串重叠，即"destination"在内存中与"source"重叠，则行为未定义。
			c.若"destination"不是指向字符数组元素的指针或"source"不是指向包含"\0"的字符串的指针，则行为未定义。
		4.复制"source"所指向的空终止字节字符串，包含空终止符，到首元素为"destination"所指的字符数组。
*/

////使用"strcpy"函数示例：于"VS2022"中无法使用"strcpy"，若要使用需使用"_CRT_SECURE_NO_WARNINGS"，此处以"strcpy_s"进行演示复制字符串操作，但其返回值和参数与"strcpy"不相同，"strcpy_s"具体使用方法请查看文档。
//int main()
//{
//	char arr1[15] = "XXXXXXXXXX";
//	char arr2[] = "KilluaAoki";
//	strcpy_s(arr1, 15, arr2);
//	printf("%s\n", arr1);
//	return 0;
//}

////模拟实现"strcpy"函数
//char* My_Strcpy(char* destination, const char* source)
//{
//	char* tmp = destination;
//	while ((*tmp++ = *source++));
//	return destination;
//}
//
//int main()
//{
//	char arr1[15] = "XXXXXXXXXX";
//	char arr2[] = "KilluaAoki";
//	printf("%s\n", My_Strcpy(arr1, arr2));
//	return 0;
//}

/**
	"strcat"函数：连接字符串，即将源字符串的副本附加到目标字符串。
		1.头文件："string.h"。
		2.函数声明：char* strcat(char* destination, const char* source);。
			a.函数头"char*"表示此函数的返回值是字符指针类型，在此函数中表示返回"destination"指针所指向的字符串的起始地址。
			b.函数参数"char* destination"：将字符指针作为参数；在此函数中意为指向要附加到的以"\0"字符结尾的字符串的指针。
			c.函数参数"const char* source"：将字符指针作为参数，并转换为由"const"修饰的"char*"类型(const char*)；在此函数中意为指向作为追加来源的字符串的指针(此字符串需包含"\0")。
		3.未定义情况
			a.若目标空间数组长度不足以存放对于"source"和"destination"的内容以及空终止符，则行为未定义。
			b.若字符串重叠，即"destination"在内存中与"source"重叠，则行为未定义。
			c.若"destination"或"source"不是指向包含"\0"的字符串的指针，则行为未定义。
		4."destination"中的终止空字符被"source"的第一个字符覆盖，并且在"destination"中两者连接形成的新字符串的末尾包含一个空字符。
*/

////使用"strcat"函数示例：于"VS2022"中无法使用"strcat"，若要使用需使用"_CRT_SECURE_NO_WARNINGS"，此处以"strcat_s"进行演示追加字符串操作，但其返回值和参数与"strcat"不相同，"strcat_s"具体使用方法请查看文档。
//int main()
//{
//	char arr1[20];
//	char arr2[] = "Aoki";
//	strcpy_s(arr1, 20, "Killua");
//	strcat_s(arr1, 20, arr2);
//	printf("%s\n", arr1);
//	return 0;
//}

////模拟实现"strcat"函数
//char* My_Strcat(char* destination, const char* source)
//{
//	char* tmp = destination;
//	while (*tmp++);
//	--tmp;
//	while ((*tmp++ = *source++));
//	return destination;
//}
//
//int main()
//{
//	char arr1[20];
//	char arr2[] = "Aoki";
//	strcpy_s(arr1, 20, "Killua");
//	printf("%s\n", My_Strcat(arr1, arr2));
//	return 0;
//}

/**
	"strcmp"函数：以字典序比较二个字符串的字符，此函数从两个字符串的第一个字符开始比较，如果它们彼此相等，则继续向后比较，直到两字符的字符不同或到达终止空字符。
		1.头文件："string.h"。
		2.函数声明：int strcmp(const char* str1, const char* str2);。
			a.函数头"int"表示此函数的返回值是整型类型。
			b.函数参数"const char* str1"和"const char* str2"：将字符指针作为参数，并转换为由"const"修饰的"char*"类型(const char*)；在此函数中意为指向两个要比较的字符串的指针(字符串都需包含"\0")。
		3."strcmp"函数的返回值设计
			a.若第一个不匹配的字符在"str1"中的值小于在"str2"中的值(在字典序中)，则返回"<0"(负值)。
			b.若两个字符串的内容相等(在字典序中)，则返回"=0"(0)。
			c.若第一个不匹配的字符在"str1"中的值大于在"str2"中的值(在字典序中)，则返回">0"(正值)。
		4.未定义情况：若"str1"或"str2"不是指向包含"\0"的字符串的指针，则行为未定义。
*/

////使用"strcmp"函数示例
//int main()
//{
//	char Key[] = "KilluaAoki";
//	char Get[20] = { 0 };
//	int i = 0;
//	for (i = 0; i < 3; i++)
//	{
//		printf("请输入密码>>");
//		scanf_s("%s", Get, 20);
//		if (strcmp(Key, Get) == 0)
//		{
//			printf("\n密码输入正确！\n");
//			break;
//		}
//		else
//		{
//			if (i == 2)
//			{
//				continue;
//			}
//			printf("\n密码输入错误！请重新输入！\n\n请注意：累计错误三次将踢出程序！\n\n");
//		}
//	}
//	if (i == 3)
//	{
//		printf("\n密码输入错误次数过多，退出程序！\n");
//	}
//	return 0;
//}

////模拟实现"strcmp"函数
//int My_Strcmp(const char* str1, const char* str2)
//{
//	int ret = 0;
//	while (((ret = ((int)(*((unsigned char*)str1))) - *((unsigned char*)str2++)) == 0) && *str1++);
//	return ret;
//}
//
//int main()
//{
//	char Key[] = "KilluaAoki";
//	char Get[20] = { 0 };
//	int i = 0;
//	for (i = 0; i < 3; i++)
//	{
//		printf("请输入密码>>");
//		scanf_s("%s", Get, 20);
//		if (My_Strcmp(Key, Get) == 0)
//		{
//			printf("\n密码输入正确！\n");
//			break;
//		}
//		else
//		{
//			if (i == 2)
//			{
//				continue;
//			}
//			printf("\n密码输入错误！请重新输入！\n\n请注意：累计错误三次将踢出程序！\n\n");
//		}
//	}
//	if (i == 3)
//	{
//		printf("\n密码输入错误次数过多，退出程序！\n");
//	}
//	return 0;
//}

/**
	"strncpy"函数：从字符串中复制字符，并可指定复制的字符个数。
		1.头文件："string.h"。
		2.函数声明：char *strncpy(char* destination, const char* source, size_t count);。
			a.函数头"char*"表示此函数的返回值是字符指针类型，在此函数中表示返回"destination"指针所指向的字符串的起始地址。
			b.函数参数"char* destination"：将字符指针作为参数；在此函数中意为指向要复制内容的目标数组首元素的指针(数组名)。
			c.函数参数"const char* source"：将字符指针作为参数，并转换为由"const"修饰的"char*"类型(const char*)；在此函数中意为指向作为复制来源的字符串的指针(此字符串需包含"\0")。
			d.函数参数"size_t count"：将无符号整型类型作为参数；在此函数中意为要复制的最大字符数。
		3.函数说明
			a.复制"source"所指向的字符数组的至多"count"个字符(包含空终止字符，但不包含后随空字符的任何字符)到"destination"所指向的字符数组。
			b.若在完全复制整个"source"数组前抵达"count"，则结果的字符数组不是空终止的。
			c.若在复制来自"source"的空终止字符后未抵达"count"，则写入额外的空字符到"destination"，直至写入总共"count"个字符。
		4.未定义情况
			a.若字符数组重叠，则行为未定义。
			b.若"destination"或"source"不是指向字符数组的指针(包括空指针)，则行为未定义。
			c.若"destination"所指向的数组大小小于"count"或"source"所指向的数组大小小于"count"且它不含空字符，则行为未定义。
*/

////使用"strncpy"函数示例：采用模拟的"strncpy"实现，因"strncpy_s"不同于"strncpy"，无法使用"strncpy_s"进行演示。
//char* My_Strncpy(char* destination, const char* source, size_t count)
//{
//	char* start = destination;
//	while (count--)
//	{
//		if ((*destination++ = *source))
//		{
//			++source;
//		}
//	}
//	return start;
//}
//
//int main()
//{
//	char arr1[20] = "XXXXXXAoki";
//	char arr2[] = "Killua";
//	printf("%s\n", My_Strncpy(arr1, arr2, 10));
//	return 0;
//}

/**
	"strncat"函数：从字符串追加字符，并可指定追加的字符个数。
		1.头文件："string.h"。
		2.函数声明：char *strncat(char* destination, const char* source, size_t count);。
			a.函数头"char*"表示此函数的返回值是字符指针类型，在此函数中表示返回"destination"指针所指向的字符串的起始地址。
			b.函数参数"char* destination"：将字符指针作为参数；在此函数中意为指向要追加到的以"\0"字符结尾的字符串的指针。
			c.函数参数"const char* source"：将字符指针作为参数，并转换为由"const"修饰的"char*"类型(const char*)；在此函数中意为指向作为追加来源的字符串的指针(此字符串需包含"\0")。
			d.函数参数"size_t count"：将无符号整型类型作为参数；在此函数中意为要追加的最大字符数。
		3.函数说明
			a.追加来自"source"所指向的字符数组的至多"count"个字符到"destination"所指向的空终止字节字符串的末尾，若找到空字符则停止。
			b."source"指向的首元素将替换位于"destination"末尾的空终止符。
			c.始终追加终止空字符到末尾，故函数可写入的最大字节数是"const + 1"。
			d.如果"count"大于"source"的长度，则会使用"source"的长度代替"count"。
		4.未定义情况
			a.若目标数组没有足够的空间容纳对于"destination"和"source"的"count"个字符以及终止空字符，则行为未定义。
			b.若字符串重叠，即"destination"在内存中与"source"重叠，则行为未定义。
			c.若"destination"不是指向空终止字节字符串的指针或"source"不是指向字符数组的指针，则行为未定义。
*/

////使用"strncat"函数示例：于"VS2022"中无法使用"strncat"，若要使用需使用"_CRT_SECURE_NO_WARNINGS"，此处以"strncat_s"进行演示追加字符串操作，但其返回值和参数与"strncat"不相同，"strncat_s"具体使用方法请查看文档。
//int main()
//{
//	char arr1[20];
//	char arr2[] = "Aoki";
//	strcpy_s(arr1, 20, "Killua");
//	strncat_s(arr1, 20, arr2, 5);
//	printf("%s\n", arr1);
//	return 0;
//}

////模拟实现"strncat"函数
//char* My_Strncat(char* destination, const char* source, size_t count)
//{
//	char* tmp = destination;
//	while (*tmp++);
//	--tmp;
//	while (count-- && (*tmp = *source++))
//	{
//		++tmp;
//	}
//	*tmp = '\0';
//	return destination;
//}
//
//int main()
//{
//	char arr1[20];
//	char arr2[] = "Aoki";
//	strcpy_s(arr1, 20, "Killua");
//	printf("%s\n", My_Strncat(arr1, arr2, 10));
//	return 0;
//}

/*
	"strncmp"函数：以字典序比较二个字符串的字符，并可指定比较的字符个数。
		1.头文件："string.h"。
		2.函数声明：int strncmp(const char* str1, const char* str2, size_t count);。
			a.函数头"int"表示此函数的返回值是整型类型。
			b.函数参数"const char* str1"和"const char* str2"：将字符指针作为参数，并转换为由"const"修饰的"char*"类型(const char*)；在此函数中意为指向两个要比较的字符串的指针(两个字符串可能需包含"\0")。
			c.函数参数"size_t count"：将无符号整型类型作为参数；在此函数中意为要比较的最大字符数。
		3.函数说明
			a.将字符串"str1"的最多"count"个字符与字符串"str2"的字符进行比较(按字典序进行比较)，不比较空字符后的字符。
			b.此函数从两个字符串的第一个字符开始比较，如果它们彼此相等，则继续向后比较，直到字符不同或到达终止空字符或两个字符串中的"const"个字符匹配，以先发生者为准。
		4."strncmp"函数的返回值设计
			a.若第一个不匹配的字符在"str1"中的值小于在"str2"中的值(在字典序中)，则返回"<0"(负值)。
			b.若两个字符串的内容相等(在字典序中)或"count"为零，则返回"=0"(0)。
			c.若第一个不匹配的字符在"str1"中的值大于在"str2"中的值(在字典序中)，则返回">0"(正值)。
		5.未定义情况
			a.若出现越过"str1"或"str2"结尾的访问，则行为未定义。
			b.若"str1"或"str2"为空指针，则行为未定义。
*/

////使用"strncmp"函数示例
//int main()
//{
//	char Key[] = "KilluaAoki";
//	char Get[20] = { 0 };
//	int i = 0;
//	for (i = 0; i < 3; i++)
//	{
//		printf("请输入密码>>");
//		scanf_s("%s", Get, 20);
//		if (strncmp(Key, Get,20) == 0)
//		{
//			printf("\n密码输入正确！\n");
//			break;
//		}
//		else
//		{
//			if (i == 2)
//			{
//				continue;
//			}
//			printf("\n密码输入错误！请重新输入！\n\n请注意：累计错误三次将踢出程序！\n\n");
//		}
//	}
//	if (i == 3)
//	{
//		printf("\n密码输入错误次数过多，退出程序！\n");
//	}
//	return 0;
//}

////模拟实现"strncmp"函数
//int My_Strncmp(const char *str1, const char *str2, size_t count)
//{
//	int ret = 0;
//	while (count-- && ((ret = ((int)(*((unsigned char*)str1))) - *((unsigned char*)str2++)) == 0) && *str1++);
//	return ret;
//}
//
//int main()
//{
//	char Key[] = "KilluaAoki";
//	char Get[20] = { 0 };
//	int i = 0;
//	for (i = 0; i < 3; i++)
//	{
//		printf("请输入密码>>");
//		scanf_s("%s", Get, 20);
//		if (My_Strncmp(Key, Get,20) == 0)
//		{
//			printf("\n密码输入正确！\n");
//			break;
//		}
//		else
//		{
//			if (i == 2)
//			{
//				continue;
//			}
//			printf("\n密码输入错误！请重新输入！\n\n请注意：累计错误三次将踢出程序！\n\n");
//		}
//	}
//	if (i == 3)
//	{
//		printf("\n密码输入错误次数过多，退出程序！\n");
//	}
//	return 0;
//}

/**
	"strstr"函数：查找字符串，在主串中定位字串。
		1.头文件："string.h"。
		2.函数声明：char *strstr(const char* str, const char* substr);。
			a.函数头"char*"表示此函数的返回值是字符指针类型；在此函数中表示返回指向"substr"中指定的整个字符序列中第一次出现在"str"中的指针；如果该序列不存在于"str"中，则返回空指针；若"substr"指向空字符串，则返回"str"。
			b.函数参数"const char* str"：将字符指针作为参数，并转换为由"const"修饰的"char*"类型(const char*)；在此函数中意为指向要检验的空终止字节字符串的指针(此字符串需包含"\0")。
			c.函数参数"const char* substr"：将字符指针作为参数，并转换为由"const"修饰的"char*"类型(const char*)；在此函数中意为指向要查找的空终止字节字符串的指针(此字符串需包含"\0")。
		3.函数说明
			a.查找"substr"所指的空终止字节字符串在"str"所指的空终止字节字符串中的首次出现。
			b.匹配过程不包括终止的空字符，但它会停在那里。
		4.未定义情况：若"str"或"substr"不是指向空终止字节字符串的指针，则行为未定义。
*/

////使用"strstr"函数示例
//int main()
//{
//	char arr1[] = "XXXXXXAoki";
//	char arr2[] = "Aoki";
//	printf("%s\n", strstr(arr1, arr2));
//	return 0;
//}

////模拟实现"strstr"函数
//char* My_Strstr(const char* str, const char* substr)
//{
//	const char* str1 = str;
//	const char* str2 = substr;
//	do
//	{
//		if (*str2 == '\0')
//		{
//			return (char*)str;
//		}
//		if (*str1 == *str2)
//		{
//			str1++;
//			str2++;
//		}
//		else
//		{
//			str2 = substr;
//			if (*str1 == '\0')
//			{
//				return NULL;
//			}
//			str1 = ++str;
//		}
//	} while (1);
//}
//
//int main()
//{
//	char arr1[] = "XXXXXXAoki";
//	char arr2[] = "Aoki";
//	printf("%s\n", My_Strstr(arr1, arr2));
//	return 0;
//}

/**
	"strtok"函数：以标记拆分字符串。
		1.头文件："string.h"。
		2.函数声明：char* strtok(char* str, const char* delimiters);。
			a.函数头"char*"表示此函数的返回值是字符指针类型；在此函数中意为返回指向下个记号起始的指针，以及当无更多记号时返回空指针。
			b.函数参数"char* str"：将字符指针作为参数；在此函数中意为指向要记号化的字符串的指针(此字符串需包含"\0")。
			c.函数参数"const char* delimiters"：将字符指针作为参数，并转换为由"const"修饰的"char*"类型(const char*)；在此函数中意为指向标识分隔符的字符串的指针(此字符串需包含"\0")。
		3.函数说明：由"delimiters"所指向的字符串鉴别分隔字符，寻找"str"所指向的字符串中的下个记号，此函数被设计为调用多次以从同一字符串获得相继的记号。
		4.函数的返回值设计
			a.若"str"不是空指针，则调用被当做"strtok"对此特定字符串的首次调用，函数搜索首个不含于"delimiters"的字符。
				a'.若找不到这种字符，则"str"中完全没有记号，而函数返回空指针。
				b'.若找到这种字符，则它是记号的起始。然后函数从该点搜索首个含于"delimiters"的字符。
					a''.若找不到这种字符，则"str"只有一个记号，而将来对"strtok"的调用将返回空指针。
					b''.若找到这种字符，则用"\0"替换它(故此函数是破坏性的)，并将指向下个字符的指针存储于静态位置，以为后继调用所用。
				c'.而后函数返回指向记号起始的指针。
			b.若"str"为空指针，则将调用当做对"strtok"的后继调用，函数从先前调用中它剩下的位置开始，行为如同将先前存储的指针作为"str"传递。
		5.未定义情况：若"str"或"delimiters"不是指向空终止字节字符串的指针，则行为未定义。
*/

////使用"strtok"函数示例：于"VS2022"中无法使用"strtok"，若要使用需使用"_CRT_SECURE_NO_WARNINGS"，此处以"strtok_s"进行演示拆分字符串操作，但其返回值和参数与"strtok"不相同，"strtok_s"具体使用方法请查看文档。
//int main()
//{
//	char arr1[] = "https://Killua.TOP";
//	char tmp[20] = { 0 };
//	char* mem = NULL;
//	strcpy_s(tmp, 20, arr1);
//	printf("拆分前的字符串：\"%s\"。\n", tmp);
//	for (char* i = strtok_s(tmp, "https://.", &mem); i != NULL; i = strtok_s(NULL, "https://.", &mem))
//	{
//		printf("拆分后的字符串：\"%s\"。\n", i);
//	}
//	return 0;
//}

/**
	"strerror"函数：获取指向错误消息字符串的指针。
		1.头文件："string.h"(包含"strerror"函数)、"errno.h"(包含全局整型变量"errno")。
		2.函数声明：char* strerror(int errnum);。
			a.函数头"char*"表示此函数的返回值是字符指针类型；在此函数中意为返回指向"errno"错误代码("errnum")对应的字符串的指针(将错误码转换为错误信息)。
			b.函数参数"int errnum"：将整型类型作为参数；通常情况下在此函数中意为引用C语言中全局整型变量"errno"存放的错误代码的整数值，但函数也可接受任意整型类型值。
		3.函数说明
			a.获取指向错误消息字符串的指针，并返回不能被程序修改的字符串，但可以被随后的"strerror"函数调用覆盖重写。
			b.不要求"strerror"是线程安全的。
			c.实现可能会返回指向静态只读字符串文字的不同指针或者反复返回指向静态缓冲区的同一指针，"strerror"放置字符串于该静态缓冲区中。
*/

////使用"strerror"函数示例：于"VS2022"中无法使用"strerror"，若要使用需使用"_CRT_SECURE_NO_WARNINGS"，此处以"strerror_s"进行演示，但其返回值和参数与"strerror"不相同，"strerror_s"具体使用方法请查看文档。
//int main()
//{
//	////使用"strerror"函数打开无效文件并打印错误信息
//	//FILE* ptr = NULL;
//	//fopen_s(&ptr, "test.txt", "r");//以只读方式打开"test.txt"文件，打开文件成功会将有效指针写入"ptr"，打开文件失败会将空指针写入"ptr"。
//	//char buffer[50] = { 0 };
//	//if (ptr == NULL)
//	//{
//	//	strerror_s(buffer, 20, errno);
//	//	printf("错误码->%d：%s。\n", errno, buffer);
//	//	return 1;//"return 1"代表程序异常退出。
//	//}
//	
//	////使用"perror"函数打开无效文件并打印错误信息
//	//FILE* ptr = NULL;
//	//fopen_s(&ptr, "test.txt", "r");
//	//char buffer[50] = { 0 };
//	//if (ptr == NULL)
//	//{
//	//	perror("fopen_s->错误信息");//直接拿取错误码并转换为错误信息，并打印错误信息(包括自定义信息)。
//	//	return 1;
//	//}
//
//	//关闭文件
//	fclose(ptr);
//	ptr = NULL;
//	
//	return 0;
//}

/**
	字符操作函数
		1.字符分类函数
			a."iscntrl"：任何控制字符。
			b."isspace"：空白字符(空格' '、换页'\f'、换行'\n'、回车'\r'、制表符'\t'、垂直制表符'\v')。
			c."isdigit"：十进制数字(0~9)。
			d."isxdigit"：十六进制数字，包括所有十进制数字、小写字母(a~f)、大写字母(A~F)。
			e."islower"：小写字母(a~z)。
			f."isupper"：大写字母(A~Z)。
			g."isalpha"：大写字母(A~Z)、小写字母(a~z)。
			h."isalnum"：大写字母(A~Z)、小写字母(a~z)、十进制数字(0~9)。
			i."ispunct"：标点符号，任何不属于数字或者字母的图形字符(可打印)。
			j."isgraph"：任何图形字符。
			k."isprint"：任何可打印字符，包括图形字符和空白字符。
		2.字符转换函数
			a."tolower"：将大写字母转换为小写字母。
			b."toupper"：将小写字母转换为大写字母。
*/

/***
	字符分类函数
		1.头文件："ctype.h"。
		2.函数声明除函数名外，其他参数相同，函数头类型都为"int"，函数参数类型都为"int"(字符类型转换为"int"或"EOF")。
			a.函数头类型"int"表示函数的返回值是整型类型，在这些函数意为若函数的参数符合条件则返回非零的值(真)，反之返回零(假)。
			b.函数参数类型"int"：将整型类型作为参数；在这些函数意为以整型类型的形式接收要检查的字符(即以字符的ASCII码值接收)。
		3.未定义行为：若函数接收参数的值不能表示为"unsigned char"且不等于"EOF"，则行为未定义。
*/

////字符分类函数使用示例：判断某字符是不是空白字符，是则打印真，否则打印假。
//int main()
//{
//	char ch = ' ';
//	if (isspace(ch))
//	{
//		printf("真\n");
//	}
//	else
//	{
//		printf("假\n");
//	}
//	return 0;
//}

/***
	字符转换函数
		1.头文件："ctype.h"。
		2.函数声明除函数名外，其他参数相同，函数头类型都为"int"，函数参数类型都为"int"(字符类型转换为"int"或"EOF")。
			a.函数头类型"int"表示函数的返回值是整型类型，在这些函数意为返回被转换的字符的ASCII码值，若无转换后对应的版本列于当前的C本地环境，则返回不修改的字符的ASCII码值。
			b.函数参数类型"int"：将整型类型作为参数；在这些函数意为以整型类型的形式接收要转换的字符(即以字符的ASCII码值接收)。
		3.未定义行为：若函数接收参数的值不能表示为"unsigned char"且不等于"EOF"，则行为未定义。
*/

////字符转换函数使用示例：将字符串小写字母转换为大写字母，大写字母转换为小写字母，并打印。
//int main()
//{
//	char ch[] = "aA bB cC dD eE fF gG hH iI jJ kK lL mM nN oO pP qQ rR sS tT uU vV wW xX yY zZ";
//	printf("转换前：%s。\n", ch);
//	for (int i = 0; i < strlen(ch); i++)
//	{
//		if (isupper(ch[i]))
//		{
//			ch[i] = tolower(ch[i]);
//		}
//		else
//		{
//			ch[i] = toupper(ch[i]);
//		}
//	}
//	printf("转换后：%s。\n", ch);
//	return 0;
//}

/**
	"memcpy"函数：复制内存块。(C标准库要求此函数只需实现复制不重叠内存块即可，但"VS2022"编译器中"memcpy"函数同时实现了可复制重叠内存块功能)
		1.头文件："string.h"。
		2.函数声明：void* memcpy(void* destination, const void* source, size_t num);。
			a.函数头"void*"表示此函数的返回值是无类型指针，可返回任意类型的指针变量；在此函数中意为返回"destination"指针所指向的起始地址。
			b.函数参数"void* destination"：将无类型指针作为参数，可接收任意类型的指针变量；在此函数中意为指向要复制内容的目标数组的指针(类型转换为void*)。
			c.函数参数"const void* source"：将无类型指针作为参数，可接收任意类型的指针变量，并转换为由"const"修饰的"void*"类型(const void*)；在此函数中意为指向要复制的数据源的指针(类型转换为const void*)。
			d.函数参数"size_t num"：将无符号整型类型作为参数；在此函数中意为要复制的字节数。
		3.函数说明
			a.将"num"字节的值从"source"指向的位置直接复制到"destination"指向的内存块(两个对象都被转译成"unsigned char"的数组)。
			b.指针指向的对象的底层类型与此函数无关，结果是数据的二进制副本。
			c.该函数不检查源中的任何终止空字符，它将直接精确复制"num"个字节数据。
			d.可用于设置分配函数所获得对象的有效类型。
			e.该函数是复制内存到内存最快的子程序，它通常比必须扫描其所复制数据的"strcpy"函数或必须预防以处理重叠输入的"memmove"函数更高效。
			f.一些C编译器将合适的内存复制循环转换为"memcpy"函数调用。
			g.在严格别名禁止检验同一内存作为两种不同类型的值的情况下，可用"memcpy"函数转换值。
		4.未定义情况
			a.若访问发生在"destination"数组结尾后，则行为未定义。
			b.若对象为重叠的内存块(源数据有可能会被目标数据覆盖)，则行为未定义(对于重叠的内存块，使用"memmove"函数是一种更安全的方法)。
			c.若"destination"或"source"为非法或空指针，则行为未定义。
			d.为避免溢出，目标数组和数据源参数指向的数组的大小应至少为"num"字节。
*/

////使用"memcpy"函数示例
//int main()
//{
//	int arr1[10] = { 0 };
//	int arr2[10] = { 0,1,2,3,4,5,6,7,8,9 };
//	memcpy(arr1, arr2, sizeof(arr2));
//	for (int i = 0; i < sizeof(arr1)/sizeof(arr1[0]); i++)
//	{
//		printf("%d ", arr1[i]);
//	}
//	return 0;
//}

////模拟实现"memcpy"函数
//void* My_Memcpy(void* destination, const void* source, size_t num)
//{
//	unsigned char* str1 = destination;
//	const unsigned char* str2 = source;
//	while (num--)
//	{
//		*str1++ = *str2++;
//	}
//	return destination;
//}
//
//int main()
//{
//	int arr1[10] = { 0 };
//	int arr2[10] = { 0,1,2,3,4,5,6,7,8,9 };
//	My_Memcpy(arr1, arr2, sizeof(arr2));
//	for (int i = 0; i < sizeof(arr1)/sizeof(arr1[0]); i++)
//	{
//		printf("%d ", arr1[i]);
//	}
//	return 0;
//}

/**
	"memmove"函数：移动内存块。
		1.头文件："string.h"。
		2.函数声明：除函数名外其余于"memcpy"函数相同。
		3.函数说明：
			a.将"num"字节的值从"source"指向的位置直接复制到"destination"指向的内存块(两个对象都被转译成"unsigned char"的数组)。
			b.指针指向的对象的底层类型与此函数无关，结果是数据的二进制副本。
			c.该函数不检查源中的任何终止空字符，它将直接精确复制"num"个字节数据。
			d.可用于设置分配函数所获得对象的有效类型。
			e.区别于"memcpy"函数，"memmove"函数允许目标空间和源空间重叠，但不如"memcpy"函数高效。
			f.尽管说明了"如同"使用临时缓冲区，但此函数的实际实现不会带来二次复制或额外内存的开销。
			g.在严格别名禁止检验同一内存作为两种不同类型的值的情况下，可用"memmove"函数转换值。
			h.若目标在源之前开始，则从缓冲区开始正向复制，否则从末尾反向复制，完全无重叠时回落到更高效的"memcpy"函数。
		4.未定义情况
			a.若访问发生在"destination"数组结尾后，则行为未定义。
			b.若"destination"或"source"为非法或空指针，则行为未定义。
			c.为避免溢出，目标数组和数据源参数指向的数组的大小应至少为"num"字节。
*/

////使用"memmove"函数示例
//int main()
//{
//	int arr[10] = { 5,6,7,8,9,0,1,2,3,4 };
//	memmove(arr, arr + 5, sizeof(arr[0]) * 5);
//	for (int i = 0; i < sizeof(arr)/sizeof(arr[0]); i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}

////模拟实现"memmove"函数
//void* My_Memmove(void* destination, const void* source, size_t num)
//{
//	unsigned char* ptr1 = (unsigned char*)destination;
//	const unsigned char* ptr2 = (const unsigned char*)source;
//
//	if (ptr1 > ptr2)
//	{
//		while (num--)
//		{
//			ptr1[num] = ptr2[num];
//		}
//	}
//	else
//	{
//		while (num--)
//		{
//			*ptr1++ = *ptr2++;
//		}
//	}
//
//	return destination;
//}
//
//int main()
//{
//	int arr[10] = { 5,6,7,8,9,0,1,2,3,4 };
//	My_Memmove(arr + 1, arr + 4, sizeof(arr[0]) * 4);
//	for (int i = 0; i < sizeof(arr)/sizeof(arr[0]); i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}

/**
	"memcmp"函数：以字典序比较两个内存块，并可指定比较的字节大小。
		1.头文件："string.h"。
		2.函数声明：int memcmp(const void* ptr1, const void* ptr2, size_t num);。
			a.函数头"int"表示此函数的返回值是整型类型。
			b.函数参数"const char* ptr1"和"const char* ptr2"：将字符指针作为参数，并转换为由"const"修饰的"char*"类型(const char*)；在此函数中意为指向两个要比较的内存块的指针。
			c.函数参数"size_t num"：将无符号整型类型作为参数；在此函数中意为要比较的字节数。
		3.函数说明
			a.将"ptr1"指向的内存块的前"num"字节与"ptr2"指向的前"num"字节进行比较(按字典序进行比较)。
			b.结果的符号是在被比较对象中相异的首对字节的值(都转译成"unsigned char")的差。
			c.与"strcmp"函数不同，该函数在找到空字符后不会停止比较。
		4."memcmp"函数的返回值设计
			a.两个内存块中不匹配的第一个字节在"ptr1"中的值低于在"ptr2"中的值(在字典序中)，则返回"<0"(负值)。
			b.若两个内存块的内容相等(在字典序中)，则返回"=0"(0)。
			c.两个内存块中不匹配的第一个字节在"ptr1"中的值大于在"ptr2"中的值(在字典序中)，则返回">0"(正值)。
		5.未定义情况
			a.若在"ptr1"和"ptr2"所指向的任一对象结尾后出现访问，则行为未定义。
			b.若"ptr1"或"ptr2"为空指针，则行为未定义。
*/

////使用"memcmp"函数示例
//int main()
//{
//	char buffer1[] = "KilluaAoki";
//	char buffer2[] = "killuaaoki";
//
//	int n = memcmp(buffer1, buffer2, sizeof(buffer1));
//
//	if (n > 0)
//	{
//		printf("'%s' is greater than '%s'.\n", buffer1, buffer2);
//	}
//	else if (n < 0)
//	{
//		printf("'%s' is less than '%s'.\n", buffer1, buffer2);
//	}
//	else
//	{
//		printf("'%s' is the same as '%s'.\n", buffer1, buffer2);
//	}
//
//	return 0;
//}

////模拟实现"memcmp"函数
//int My_Memcmp(const void* ptr1, const void* ptr2, size_t num)
//{
//	int ret = 0;
//	const unsigned char* p1 = (const unsigned char*)ptr1;
//	const unsigned char* p2 = (const unsigned char*)ptr2;
//	while (num-- && ((ret = ((int)(*p1++)) - *p2++) == 0));
//	return ret;
//}
//
//int main()
//{
//	char buffer1[] = "KilluaAoki";
//	char buffer2[] = "KilluaAoki";
//
//	int n = memcmp(buffer1, buffer2, sizeof(buffer1));
//
//	if (n > 0)
//	{
//		printf("'%s' is greater than '%s'.\n", buffer1, buffer2);
//	}
//	else if (n < 0)
//	{
//		printf("'%s' is less than '%s'.\n", buffer1, buffer2);
//	}
//	else
//	{
//		printf("'%s' is the same as '%s'.\n", buffer1, buffer2);
//	}
//
//	return 0;
//}

/**
	"memset"函数：填充内存块。
		1.头文件："string.h"。
		2.函数声明：void* memset(void* ptr, int value, size_t num);。
			a.函数头"void*"表示此函数的返回值是无类型指针，可返回任意类型的指针变量；在此函数中意为返回"ptr"指针所指向的起始地址。
			b.函数参数"void* ptr"：将无类型指针作为参数，可接收任意类型的指针变量；在此函数中意为指向要填充的内存块的指针(类型转换为void*)。
			c.函数参数"int value"：将整型类型作为参数；在此函数中意为要设置的值，该值作为整型传递，但该函数会将该值转换为无符号字符类型填充内存块。
			d.函数参数"size_t num"：将无符号整型类型作为参数；在此函数中意为设置要填充的字节数。
		3.函数说明
			a.将值"value"(类型转换为"unsigned char")复制到"ptr"所指向对象的最前面"num"个字节中。
			b.会将输入范围中的每个字节都填充为值"value"，并且是以值"value"的低八位进行赋值。
		4.未定义情况
			a.若在"ptr"所指向的对象结尾后出现访问，则行为未定义。
			b.若"ptr"为空指针，则行为未定义。
*/

////使用"memset"函数示例一
//int main()
//{
//	char str[] = "KilluaAoki";
//	memset(str + 1, '*', sizeof(char) * 8);
//	puts(str);
//	return 0;
//}

////使用"memset"函数示例二
//int main()
//{
//	int arr[10];
//
//	size_t size = sizeof(arr) / sizeof(arr[0]);
//	
//	My_Memset(arr, 0, sizeof(arr));//只会将"value"二进制的低八位赋值给所输范围的每个字节。
//	
//	PrintArray(arr, size);
//
//	My_Memset(arr, 1, sizeof(arr));//会将输入范围中的每个字节都填充为值"value"。
//
//	PrintArray(arr, size);
//	
//	return 0;
//}

////模拟实现"memset"函数
//void* My_Memset(void* ptr, int value, size_t num)
//{
//	unsigned char* tmp = (unsigned char*)ptr;
//	while (num--)
//	{
//		*tmp++ = (unsigned char)value;
//	}
//	return ptr;
//}
//
//void PrintArray(int arr[], size_t size)
//{
//	for (size_t i = 0; i < size; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//}
//
//int main()
//{
//	int arr[10];
//
//	size_t size = sizeof(arr) / sizeof(arr[0]);
//	
//	My_Memset(arr, 0, sizeof(arr));
//	
//	PrintArray(arr, size);
//	
//	return 0;
//}