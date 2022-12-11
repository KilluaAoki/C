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

	printf("*****************************EXIT*****************************\n\n");
}

int main()
{
	Test_String_01();
	Test_String_02();
	return 0;
}