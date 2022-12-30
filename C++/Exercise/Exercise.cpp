#include <iostream>
#include <cmath>

////计算日期到天数转换：https://www.nowcoder.com/practice/769d45d455fe40b385ba32f97e7bcded。
//int main()
//{
//	size_t year, mouth, day;
//
//	std::cin >> year >> mouth >> day;
//
//	size_t mouthDaySum[13] = { 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365 };
//
//	size_t n = mouthDaySum[mouth - 1] + day;
//
//	if (mouth > 2 && ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)))
//	{
//		n += 1;
//	}
//
//	std::cout << n << std::endl;
//
//	return 0;
//}

////日期差值：https://www.nowcoder.com/practice/ccb7383c76fc48d2bbc27a2a6319631c。
//int CompareDate(int x, int y)
//{
//	int mouthDaySum[13] = { 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365 };
//
//	if (x > y)
//	{
//		std::swap(x, y);
//	}
//
//	int year1 = x / 10000, mouth1 = x % 10000 / 100, day1 = x % 10000 % 100;
//	int year2 = y / 10000, mouth2 = y % 10000 / 100, day2 = y % 10000 % 100;
//
//	int n1 = mouthDaySum[mouth1 - 1] + day1;
//	if (mouth1 > 2 && ((year1 % 4 == 0 && year1 % 100 != 0) || (year1 % 400 == 0)))
//	{
//		n1 += 1;
//	}
//
//	int n2 = mouthDaySum[mouth2 - 1] + day2;
//	if (mouth2 > 2 && ((year2 % 4 == 0 && year2 % 100 != 0) || (year2 % 400 == 0)))
//	{
//		n2 += 1;
//	}
//
//	int sum = 0;
//
//	for (int i = year1; i < year2; ++i)
//	{
//		sum += (((i % 4 == 0 && i % 100 != 0) || (i % 400 == 0)) ? 366 : 365);
//	}
//
//	return sum + n2 - n1;
//}
//
//int main()
//{
//	int x, y;
//	std::cin >> x >> y;
//	std::cout << CompareDate(x, y) + 1 << std::endl;
//	return 0;
//}