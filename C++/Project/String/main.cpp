#include "String.h"

void Test_String_01()
{
	printf("******************************01******************************\n");

	Aoki::String str1;
	std::cout << str1 << std::endl;

	Aoki::String str2 = "KilluaAoki";
	std::cout << str2 << std::endl;

	Aoki::String str3("Killua", 6);
	std::cout << str3 << std::endl;

	Aoki::String str4(10, '6');
	std::cout << str4 << std::endl;

	Aoki::String str5(str2);
	std::cout << str5 << std::endl;

	Aoki::String str6(str2, 0, 6);
	std::cout << str6 << std::endl;

	printf("*****************************EXIT*****************************\n\n");
}

void Test_String_02()
{
	printf("******************************02******************************\n");

	Aoki::String str1, str2, str3, str4;

	str1 = "KilluaAoki";
	std::cout << str1 << std::endl;

	str2 = str1;
	std::cout << str2 << std::endl;

	str3 = 'A';
	std::cout << str3 << std::endl;

	str4 = str1;
	str4 = 'B';
	std::cout << str4 << std::endl;

	printf("*****************************EXIT*****************************\n\n");
}

void Test_String_03()
{
	printf("******************************03******************************\n");

	Aoki::String str1, str2, str3, str4, str5;

	str1.assign(10, '-');
	std::cout << str1 << std::endl;

	str2.assign(str1);
	std::cout << str2 << std::endl;

	str3.assign(str2, 0, -1);
	std::cout << str3 << std::endl;

	str4.assign("KilluaAoki", 6);
	std::cout << str4 << std::endl;

	str5.assign("KilluaAoki");
	std::cout << str5 << std::endl;

	printf("*****************************EXIT*****************************\n\n");
}

void Test_String_04()
{
	printf("******************************04******************************\n");

	Aoki::String str1("KilluaAoki");

	for (size_t i = 0; i < str1.size(); ++i)
	{
		std::cout << str1[i] << ' ';
	}
	std::cout << std::endl;

	for (Aoki::String::iterator it = str1.begin(); it != str1.end(); ++it)
	{
		std::cout << *it << ' ';
	}
	std::cout << std::endl;

	printf("*****************************EXIT*****************************\n\n");
}

int main()
{
	Test_String_01();
	Test_String_02();
	Test_String_03();
	Test_String_04();
	return 0;
}