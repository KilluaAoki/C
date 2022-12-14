#include "String.h"
#include <string>

void Test_String_01()
{
	printf("******************************01******************************\n");

	Aoki::String str1;
	assert(str1.empty() && (str1.length() == 0) && (str1.size() == 0));
	std::cout << str1 << std::endl;

	Aoki::String str2(10, '6');
	std::cout << str2 << std::endl;

	Aoki::String str3(str2, 0, 10);
	std::cout << str3 << std::endl;

	Aoki::String str4(str2, 0, -1);
	std::cout << str4 << std::endl;

	Aoki::String str5(str2, 0);
	std::cout << str5 << std::endl;

	Aoki::String str6(str2, 0, 1000);
	std::cout << str6 << std::endl;

	Aoki::String str7("Killua", 6);
	std::cout << str7 << std::endl;

	Aoki::String str8("C Style\0String");
	std::cout << str8 << '\n';

	Aoki::String str9 = "KilluaAoki";
	std::cout << str9 << std::endl;

	Aoki::String str10(str5);
	std::cout << str10 << std::endl;

	printf("*****************************EXIT*****************************\n\n");
}

void Test_String_02()
{
	printf("******************************02******************************\n");

	Aoki::String str1, str2, str3, str4, str5;

	str1 = "KilluaAoki";
	std::cout << str1 << std::endl;

	str2 = str1;
	std::cout << str2 << std::endl;

	str3 = 'A';
	std::cout << str3 << std::endl;

	str4 = str1;
	str4 = 'B';
	std::cout << str4 << std::endl;

	str5 = str1;
	str5 = "--------------------";
	std::cout << str5 << std::endl;

	str1.assign(10, 'A');
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

void Test_String_03()
{
	printf("******************************03******************************\n");

	Aoki::String str1, str2, str3, str4, str5, str6;
	std::string str7, str8, str9, str10, str11, str12;

	std::cout << "str1[0] = " << str1[0] << std::endl;
	std::cout << "str7[0] = " << str7[0] << std::endl << std::endl;

	str2 = "Aoki";
	for (Aoki::String::size_type i = 0; i < str2.size(); ++i)
	{
		std::cout << "str2[" << i << "] = " << str2[i] << " ";
	}
	std::cout << std::endl;
	str8 = "Aoki";
	for (std::string::size_type i = 0; i < str8.size(); ++i)
	{
		std::cout << "str8[" << i << "] = " << str8[i] << " ";
	}
	std::cout << std::endl << std::endl;

	str3 = "Aoki";
	for (Aoki::String::size_type i = 0; i < str3.size(); ++i)
	{
		std::cout << "str3.at(" << i << ") = " << str3.at(i) << " ";
	}
	std::cout << std::endl;
	str9 = "Aoki";
	for (std::string::size_type i = 0; i < str9.size(); ++i)
	{
		std::cout << "str9.at(" << i << ") = " << str9.at(i) << " ";
	}
	std::cout << std::endl << std::endl;

	str4 = "Aoki";
	std::cout << "str4.front() = " << str4.front() << std::endl;
	std::cout << "str4.back() = " << str4.back() << std::endl;
	std::cout << "str4.c_str() = " << str4.c_str() << std::endl;
	std::cout << "str4.data() = " << str4.data() << std::endl;
	std::cout << "||" << std::endl;
	str10 = "Aoki";
	std::cout << "str10.front() = " << str10.front() << std::endl;
	std::cout << "str10.back() = " << str10.back() << std::endl;
	std::cout << "str10.c_str() = " << str10.c_str() << std::endl;
	std::cout << "str10.data() = " << str10.data() << std::endl;
	std::cout << std::endl;

	str5 = "Aoki";
	std::cout << "*str5.begin() = " << *str5.begin() << std::endl;
	std::cout << "*str5.end() = " << *str5.end() << std::endl;
	for (auto it = str5.begin(); it != str5.end(); it++)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl << "||" << std::endl;
	str11 = "Aoki";
	std::cout << "*str11.begin() = " << *str11.begin() << std::endl;
	std::cout << "*str11.end() = " << *str11.end() << std::endl;
	for (auto it = str11.begin(); it != str11.end(); it++)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl << std::endl;

	str6 = "Aoki";
	for (auto e: str6)
	{
		std::cout << e << " ";
	}
	std::cout << std::endl;
	str12 = "Aoki";
	for (auto e: str12)
	{
		std::cout << e << " ";
	}
	std::cout << std::endl;

	printf("*****************************EXIT*****************************\n\n");
}

void Test_String_04()
{
	printf("******************************04******************************\n");

	Aoki::String s1;
	std::cout << "s1.empty()：" << s1.empty() << "\t s：\"" << s1 << "\"\n";
	s1 = "Exemplar";
	std::cout << "s1.empty()：" << s1.empty() << "\t s：\"" << s1 << "\"\n";
	s1 = "";
	std::cout << "s1.empty()：" << s1.empty() << "\t s：\"" << s1 << "\"\n\n";

	Aoki::String s2;
	std::cout << "s2 = \"" << s2 << "\"\n";
	std::cout << "s2.size() = " << s2.size() << "\n";
	std::cout << "s2.length() = " << s2.length() << "\n\n";

	s2 = "Exemplar";
	std::cout << "s2 = \"" << s2 << "\"\n";
	std::cout << "s2.size() = " << s2.size() << "\n";
	std::cout << "s2.length() = " << s2.length() << "\n\n";

	s2 = "";
	std::cout << "s2 = \"" << s2 << "\"\n";
	std::cout << "s2.size() = " << s2.size() << "\n";
	std::cout << "s2.length() = " << s2.length() << "\n\n";

	Aoki::String s3;
	std::cout << "s3 = \"" << s3 << "\"\n";
	std::cout << "s3.max_size() = " << s3.max_size() << "\n\n";

	Aoki::String s4;
	std::cout << "s4 = \"" << s4 << "\"\n";
	std::cout << "s4.size() = " << s4.size() << "\n";
	std::cout << "s4.capacity() = " << s4.capacity() << "\n\n";

	s4.reserve(100);
	std::cout << "s4.reserve(100)" << "\n";
	std::cout << "s4.size() = " << s4.size() << "\n";
	std::cout << "s4.capacity() = " << s4.capacity() << "\n\n";

	s4.reserve(10);
	std::cout << "s4.reserve(10)" << "\n";
	std::cout << "s4.size() = " << s4.size() << "\n";
	std::cout << "s4.capacity() = " << s4.capacity() << "\n\n";

	s4.reserve(1000);
	std::cout << "s4.reserve(1000)" << "\n";
	std::cout << "s4.size() = " << s4.size() << "\n";
	std::cout << "s4.capacity() = " << s4.capacity() << "\n\n";

	s4.shrink_to_fit();
	std::cout << "s4.shrink_to_fit()" << "\n";
	std::cout << "s4.size() = " << s4.size() << "\n";
	std::cout << "s4.capacity() = " << s4.capacity() << "\n\n";

	printf("*****************************EXIT*****************************\n\n");
}

void Test_String_05()
{
	printf("******************************05******************************\n");

	Aoki::String s{ "Exemplar" };
	Aoki::String::size_type const capacity = s.capacity();
	s.clear();
	assert(s.capacity() == capacity);
	assert(s.empty());
	assert(s.size() == 0);

	Aoki::String s1 = "KilluaAoki";
	std::cout << "s1 = " << s1 << std::endl;
	s1.insert(10, 1, '!');
	std::cout << "s1 = " << s1 << std::endl << std::endl;

	Aoki::String s2 = "Killua";
	std::cout << "s2 = " << s2 << std::endl;
	s2.insert(6, "Aoki!");
	std::cout << "s2 = " << s2 << std::endl << std::endl;

	Aoki::String s3 = "Killua";
	std::cout << "s3 = " << s3 << std::endl;
	s3.insert(6, "Aoki!", 4);
	std::cout << "s3 = " << s3 << std::endl << std::endl;

	Aoki::String s4 = "->!";
	std::cout << "s4 = " << s4 << std::endl;
	s4.insert(2, s3);
	std::cout << "s4 = " << s4 << std::endl << std::endl;

	Aoki::String s5 = "Killua";
	std::cout << "s5 = " << s5 << std::endl;
	s5.insert(6, s3, 6, 5);
	std::cout << "s5 = " << s5 << std::endl << std::endl;

	Aoki::String s6 = "Killua";
	std::cout << "s6 = " << s6 << std::endl;
	s6.insert(s6.end(), '!');
	std::cout << "s6 = " << s6 << std::endl << std::endl;

	Aoki::String s7 = "Killua";
	std::cout << "s7 = " << s7 << std::endl;
	s7.insert(s7.end(), 5, '!');
	std::cout << "s7 = " << s7 << std::endl << std::endl;

	Aoki::String s8 = "KilluaAoki";
	std::cout << "s8 = " << s8 << std::endl;
	s8.erase(6, 4);
	std::cout << "s8 = " << s8 << std::endl << std::endl;

	Aoki::String s9 = "KilluaAoki!";
	std::cout << "s9 = " << s9 << std::endl;
	s9.erase(s9.end() - 1);
	std::cout << "s9 = " << s9 << std::endl << std::endl;

	Aoki::String s10 = "KilluaAoki!";
	std::cout << "s10 = " << s10 << std::endl;
	s10.erase(s10.begin() + 6, s10.end() - 1);
	std::cout << "s10 = " << s10 << std::endl << std::endl;

	printf("*****************************EXIT*****************************\n\n");
}

void Test_String_06()
{
	printf("******************************06******************************\n");

	Aoki::String s("KilluaAoki");

	//String& insert(size_type index, size_type count, char ch);
	Aoki::String s1;
	s1.insert((Aoki::String::size_type)0, 10, '-');
	std::cout << "s1 = " << s1 << std::endl;
	s1.insert((Aoki::String::size_type)10, 10, '!');
	std::cout << "s1 = " << s1 << std::endl;
	s1.insert(s1.size() - 1, 10, '*');
	std::cout << "s1 = " << s1 << std::endl << std::endl;

	//String& insert(size_type index, const char* s);
	Aoki::String s2;
	s2.insert(0, "KilluaAoki");
	std::cout << "s2 = " << s2 << std::endl;
	s2.insert(10, "KilluaAoki");
	std::cout << "s2 = " << s2 << std::endl;
	s2.insert(s2.size() - 1, "KilluaAoki");
	std::cout << "s2 = " << s2 << std::endl << std::endl;

	//String& insert(size_type index, const char* s, size_type count);
	Aoki::String s3;
	s3.insert(0, "KilluaAoki", 10);
	std::cout << "s3 = " << s3 << std::endl;
	s3.insert(10, "KilluaAoki", 10);
	std::cout << "s3 = " << s3 << std::endl;
	s3.insert(s3.size() - 1, "KilluaAoki", 10);
	std::cout << "s3 = " << s3 << std::endl;
	s3.insert(0, "KilluaAoki", 0);
	std::cout << "s3 = " << s3 << std::endl << std::endl;

	//String& insert(size_type index, const String& str);
	Aoki::String s4;
	s4.insert(0, s);
	std::cout << "s4 = " << s4 << std::endl;
	s4.insert(10, s);
	std::cout << "s4 = " << s4 << std::endl;
	s4.insert(s4.size() - 1, s);
	std::cout << "s4 = " << s4 << std::endl << std::endl;

	//String& insert(size_type index, const String& str, size_type index_str, size_type count);
	Aoki::String s5;
	s5.insert(0, s, 0, 10);
	std::cout << "s5 = " << s5 << std::endl;
	s5.insert(10, s, 0, 10);
	std::cout << "s5 = " << s5 << std::endl;
	s5.insert(s5.size() - 1, s, 0, 10);
	std::cout << "s5 = " << s5 << std::endl;
	s5.insert(0, s, 0, 0);
	std::cout << "s5 = " << s5 << std::endl;
	s5.clear();
	s5.insert(0, s, 10, 10);
	std::cout << "s5 = " << s5 << std::endl;
	s5.insert(0, s, s.size() - 1, 10);
	std::cout << "s5 = " << s5 << std::endl;
	s5.clear();
	s5.insert(0, s, 0, 10000);
	std::cout << "s5 = " << s5 << std::endl << std::endl;

	//String& erase(size_type index = 0, size_type count = npos);。
	Aoki::String s6(s);
	std::cout << "s6 = " << s6 << std::endl;
	s6.erase(0, 10);
	std::cout << "s6 = " << s6 << std::endl;
	s6 = s;
	s6.erase(10, 10);
	std::cout << "s6 = " << s6 << std::endl;
	s6 = s;
	s6.erase(s6.size() - 1, 10);
	std::cout << "s6 = " << s6 << std::endl;
	s6 = s;
	s6.erase(0, 10000);
	std::cout << "s6 = " << s6 << std::endl;
	s6 = s;
	s6.erase(10, 10000);
	std::cout << "s6 = " << s6 << std::endl;
	s6 = s;
	s6.erase(s6.size() - 1, 10000);
	s6 = s;
	s6.erase(0, 1);
	std::cout << "s6 = " << s6 << std::endl;
	s6 = s;
	s6.erase(10, 1);
	std::cout << "s6 = " << s6 << std::endl;
	s6 = s;
	s6.erase(s6.size() - 1, 1);
	std::cout << "s6 = " << s6 << std::endl << std::endl;

	printf("*****************************EXIT*****************************\n\n");
}

void Test_String_07()
{
	printf("******************************07******************************\n");

	std::string s1;
	std::string::size_type capacity1 = s1.capacity();
	std::cout << "(std::string(push_back))making s grow:\n";
	for (size_t i = 0; i < 2000; ++i)
	{
		s1.push_back('c');
		if (capacity1 != s1.capacity())
		{
			capacity1 = s1.capacity();
			std::cout << "\tcapacity changed: " << capacity1 << '\n';
		}
	}
	std::cout << std::endl;

	Aoki::String s2;
	Aoki::String::size_type capacity2 = s2.capacity();
	std::cout << "(Aoki::String(push_back))making s grow:\n";
	for (size_t i = 0; i < 2000; ++i)
	{
		s2.push_back('c');
		if (capacity2 != s2.capacity())
		{
			capacity2 = s2.capacity();
			std::cout << "\tcapacity changed: " << capacity2 << '\n';
		}
	}
	std::cout << std::endl;

	Aoki::String s3("KilluaAoki!");
	std::cout << "s3 = " << s3 << std::endl;
	auto size = s3.size();
	for (Aoki::String::size_type i = 0; i < size; ++i)
	{
		s3.pop_back();
		std::cout << "s3 = " << s3 << std::endl;
	}
	std::cout << std::endl;

	printf("*****************************EXIT*****************************\n\n");
}

void Test_String_08()
{
	printf("******************************08******************************\n");

	Aoki::String s1("Killua");
	std::cout << "s1 = " << s1 << std::endl;
	Aoki::String s2("Aoki");
	std::cout << "s2 = " << s2 << "\n\n";

	Aoki::String s3;
	s3.append(10, '-');
	std::cout << "s3 = " << s3 << std::endl;
	std::cout << "s3.size() = " << s3.size() << "\n\n";

	Aoki::String s4;
	s4.append(s1);
	std::cout << "s4 = " << s4 << std::endl;
	s4.append(s2);
	std::cout << "s4 = " << s4 << std::endl;
	std::cout << "s4.size() = " << s4.size() << "\n\n";

	Aoki::String s5;
	s5.append(s1, 0, -1);
	std::cout << "s5 = " << s5 << std::endl;
	s5.append(s2, 0, -1);
	std::cout << "s5 = " << s5 << std::endl;
	s5.append(s3, 5, 5);
	std::cout << "s5 = " << s5 << std::endl;
	std::cout << "s5.size() = " << s5.size() << "\n\n";

	Aoki::String s6;
	s6.append("Killua", 6);
	std::cout << "s6 = " << s6 << std::endl;
	s6.append("Aoki", 4);
	std::cout << "s6 = " << s6 << std::endl;
	s6.append("!!!!!!!!!!", 10);
	std::cout << "s6 = " << s6 << std::endl;
	std::cout << "s6.size() = " << s6.size() << "\n\n";

	Aoki::String s7;
	s7.append("Killua");
	std::cout << "s7 = " << s7 << std::endl;
	s7.append("Aoki");
	std::cout << "s7 = " << s7 << std::endl;
	s7.append("!!!!!!!!!!");
	std::cout << "s7 = " << s7 << std::endl;
	std::cout << "s7.size() = " << s7.size() << "\n\n";

	Aoki::String s8;
	s8 += s1;
	std::cout << "s8 = " << s8 << std::endl;
	s8 += s2;
	std::cout << "s8 = " << s8 << std::endl;
	std::cout << "s8.size() = " << s8.size() << "\n\n";

	Aoki::String s9;
	s9 += 'A';
	std::cout << "s9 = " << s9 << std::endl;
	s9 += 'o';
	std::cout << "s9 = " << s9 << std::endl;
	s9 += 'k';
	std::cout << "s9 = " << s9 << std::endl;
	s9 += 'i';
	std::cout << "s9 = " << s9 << std::endl;
	std::cout << "s9.size() = " << s9.size() << "\n\n";

	Aoki::String s10;
	s10 += "Killua";
	std::cout << "s10 = " << s10 << std::endl;
	s10 += "Aoki";
	std::cout << "s10 = " << s10 << std::endl;
	std::cout << "s10.size() = " << s10.size() << "\n\n";

	printf("*****************************EXIT*****************************\n\n");
}

void Test_String_09()
{
	printf("******************************09******************************\n");

	std::string s1("Killua");
	std::string s2("Aoki");

	s1.replace(6, 0, s2);

	std::cout << "s1 = " << s1 << std::endl;

	printf("*****************************EXIT*****************************\n\n");
}

int main()
{
	Test_String_01();
	Test_String_02();
	Test_String_03();
	Test_String_04();
	Test_String_05();
	Test_String_06();
	Test_String_07();
	Test_String_08();
	Test_String_09();
	return 0;
}