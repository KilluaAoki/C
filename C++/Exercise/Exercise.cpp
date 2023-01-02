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

////验证回文串：https://leetcode.cn/problems/valid-palindrome/。
//class Solution
//{
//public:
//	bool isPalindrome(string s)
//	{
//		if (s.empty())
//		{
//			return true;
//		}
//		string::size_type left = 0;
//		string::size_type right = s.length() - 1;
//		while (left < right)
//		{
//			if (isalnum(s[left]) && isalnum(s[right]))
//			{
//				if (!equal(s[left++], s[right--]))
//				{
//					return false;
//				}
//			}
//			else
//			{
//				left += isalnum(s[left]) ? 0 : 1;
//				right -= isalnum(s[right]) ? 0 : 1;
//			}
//		}
//		return true;
//	}
//
//	bool equal(char c1, char c2)
//	{
//		if (isdigit(c1) || isdigit(c2))
//		{
//			return c1 == c2;
//		}
//		return (c1 == c2) || (max(c1, c2) - min(c1, c2) == 32);
//	}
//};

////字符串中的第一个唯一字符：https://leetcode.cn/problems/first-unique-character-in-a-string/。
//class Solution
//{
//public:
//	int firstUniqChar(string s)
//	{
//		if (s.length() < 2)
//		{
//			return static_cast<int>(s.length()) - 1;
//		}
//		vector<int> countArray(26, 0);
//		for (auto item: s)
//		{
//			++countArray[item - 97];
//		}
//		for (string::size_type i = 0; i < s.length(); ++i)
//		{
//			if (countArray[s[i] - 97] == 1)
//			{
//				return static_cast<int>(i);
//			}
//		}
//		return -1;
//	}
//};

////反转字符串 II：https://leetcode.cn/problems/reverse-string-ii/。
//class Solution
//{
//public:
//	string reverseStr(string s, int k)
//	{
//		string::iterator it = s.begin();
//		string::size_type n = s.length();
//		for (int i = 0; i < n; i += 2 * k)
//		{
//			reverse(it + i, it + min(i + k, static_cast<int>(n)));
//		}
//		return s;
//	}
//};

////把字符串转换成整数：https://www.nowcoder.com/practice/1277c681251b4372bdef344468e4f26e。
//class Solution
//{
//public:
//	int StrToInt(string str)
//	{
//		if (str.empty())
//		{
//			return 0;
//		}
//
//		bool flag = str[0] != '-';
//		int minQ = INT_MIN / 10;
//		int minR = INT_MIN % 10;
//		int cur = 0;
//		int res = 0;
//
//		for (string::size_type i = (str[0] == '+' || str[0] == '-') ? 1 : 0; i < str.length(); ++i)
//		{
//			if (!isdigit(str[i]))
//			{
//				return 0;
//			}
//			cur = '0' - str[i];
//			if (res < minQ || (res == minQ && cur < minR))
//			{
//				return 0;
//			}
//			res = res * 10 + cur;
//		}
//
//		if (flag && res == INT_MIN)
//		{
//			return 0;
//		}
//
//		return flag ? -res : res;
//	}
//};

////字符串转换整数 (atoi)：https://leetcode.cn/problems/string-to-integer-atoi/。(附加)
//class Solution
//{
//public:
//	int myAtoi(string s)
//	{
//		if (s.empty())
//		{
//			return 0;
//		}
//
//		string::size_type i = 0;
//
//		while (s[i] == ' ')
//		{
//			++i;
//		}
//
//		bool flag = s[i] != '-';
//		int minQ = INT_MIN / 10;
//		int minR = INT_MIN % 10;
//		int res = 0;
//		int cur = 0;
//
//		for (i = (s[i] == '+' || s[i] == '-') ? i + 1 : i; isdigit(s[i]) && i < s.length(); ++i)
//		{
//			cur = '0' - s[i];
//			if ((res < minQ) || (res == minQ && cur < minR))
//			{
//				return flag ? INT_MAX : INT_MIN;
//			}
//			res = res * 10 + cur;
//		}
//
//		if (flag && res == INT_MIN)
//		{
//			return INT_MAX;
//		}
//
//		return flag ? -res : res;
//	}
//};