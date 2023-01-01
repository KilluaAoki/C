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

////求"1 + 2 + 3 + ... + n"：https://www.nowcoder.com/practice/7a0da8fc483247ff8800059e12d7caf1。(方法一)
//class Solution
//{
//public:
//	int Sum_Solution(int n)
//	{
//		return (n + (int)std::pow(n, 2)) >> 1;
//	}
//};

////求"1 + 2 + 3 + ... + n"：https://www.nowcoder.com/practice/7a0da8fc483247ff8800059e12d7caf1。(方法二)
//class Solution
//{
//public:
//	int Sum_Solution(int n)
//	{
//		int sum = n;
//		sum && (sum += Sum_Solution(n - 1));
//		return sum;
//	}
//};

////求"1 + 2 + 3 + ... + n"：https://www.nowcoder.com/practice/7a0da8fc483247ff8800059e12d7caf1。(方法三)
//class Solution
//{
//public:
//	class Sum
//	{
//	public:
//		Sum()
//		{
//			sum_ += i_;
//			++i_;
//		}
//	};
//
//	int Sum_Solution(int n)
//	{
//		Sum arr[n];
//		return sum_;
//	}
//
//private:
//	static int i_;
//	static int sum_;
//};
//
//int Solution::i_ = 1;
//int Solution::sum_ = 0;

////打印日期：https://www.nowcoder.com/practice/b1f7a77416194fd3abd63737cdfcf82b。
//int main()
//{
//	int y, n;
//	int mouthDaySum[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
//	while (std::cin >> y >> n)
//	{
//		if ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0))
//		{
//			mouthDaySum[2] = 29;
//		}
//		else
//		{
//			mouthDaySum[2] = 28;
//		}
//		int mouth = 1;
//		while (n > 0)
//		{
//			if (n - mouthDaySum[mouth] <= 0)
//			{
//				break;
//			}
//			n -= mouthDaySum[mouth];
//			++mouth;
//		}
//		std::printf("%04d-%02d-%02d\n", y, mouth, n);
//	}
//	return 0;
//}

////日期累加：https://www.nowcoder.com/practice/eebb2983b7bf40408a1360efb33f9e5d。
//int GetMouthDay(int year, int mouth)
//{
//	static int mouthDaySum[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
//	if (mouth == 2 && ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)))
//	{
//		return 29;
//	}
//	return mouthDaySum[mouth];
//}
//
//int main()
//{
//	int m, year, mouth, day, n;
//
//	std::cin >> m;
//
//	while (m--)
//	{
//		std::cin >> year >> mouth >> day >> n;
//		if (day <= 0)
//			break;
//		day += n;
//		while (day > GetMouthDay(year, mouth))
//		{
//			day -= GetMouthDay(year, mouth);
//			++mouth;
//			if (mouth > 12)
//			{
//				mouth = 1;
//				++year;
//			}
//		}
//		std::printf("%04d-%02d-%02d\n", year, mouth, day);
//	}
//
//	return 0;
//}