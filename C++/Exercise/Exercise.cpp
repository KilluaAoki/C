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

////字符串相加：https://leetcode.cn/problems/add-strings/。
//class Solution
//{
//public:
//	string addStrings(string num1, string num2)
//	{
//		string::iterator it1 = num1.end() - 1;
//		string::iterator it2 = num2.end() - 1;
//		string res;
//		int carry = 0;
//		int sum = 0;
//		while (it1 >= num1.begin() || it2 >= num2.begin())
//		{
//			sum = carry;
//			if (it1 >= num1.begin())
//			{
//				sum += *it1 - '0';
//				--it1;
//			}
//			if (it2 >= num2.begin())
//			{
//				sum += *it2 - '0';
//				--it2;
//			}
//			carry = sum / 10;
//			res.push_back(sum % 10 + '0');
//		}
//		if (carry > 0)
//		{
//			res.push_back(carry + '0');
//		}
//		reverse(res.begin(), res.end());
//		return res;
//	}
//};

////反转字符串：https://leetcode.cn/problems/reverse-string/。
//void reverseString(vector<char>& s)
//{
//	vector<char>::size_type size = s.size();
//	for (vector<char>::size_type left = 0, right = size - 1; left < right; ++left, --right)
//	{
//		swap(s[left], s[right]);
//	}
//}

////反转字符串中的单词 III：https://leetcode.cn/problems/reverse-words-in-a-string-iii/。
//class Solution
//{
//public:
//	string reverseWords(string s)
//	{
//		string::iterator itL = s.begin();
//		string::iterator itR = s.begin();
//		while (itR != s.end())
//		{
//			if (*itR == ' ')
//			{
//				reverse(itL, itR);
//				itL = itR + 1;
//			}
//			++itR;
//		}
//		reverse(itL, itR);
//		return s;
//	}
//};

////字符串相乘：https://leetcode.cn/problems/multiply-strings/。
//class Solution
//{
//public:
//	string multiply(string num1, string num2)
//	{
//		string::size_type n1 = num1.length();
//		string::size_type n2 = num2.length();
//		string res(n1 + n2, '0');
//		for (string::size_type i = n1; i > 0; --i)
//		{
//			for (string::size_type j = n2; j > 0; --j)
//			{
//				int mul = (num1[i - 1] - '0') * (num2[j - 1] - '0');
//				int sum = mul + (res[i + j - 1] - '0');
//				res[i + j - 1] = sum % 10 + '0';
//				res[i + j - 2] += sum / 10;
//			}
//		}
//		for (string::size_type i = 0; i < n1 + n2; ++i)
//		{
//			if (res[i] != '0')
//			{
//				return res.substr(i);
//			}
//		}
//		return "0";
//	}
//};

////字符串最后一个单词的长度：https://www.nowcoder.com/practice/8c949ea5f36f422594b306a2300315da。(类似力扣第"58"题)
//int lengthOfLastWord(string s)
//{
//	string::size_type i = s.size();
//	while (i > 0 && s[i - 1] == ' ')
//	{
//		--i;
//	}
//	string::size_type j = i;
//	while (j > 0 && s[j - 1] != ' ')
//	{
//		--j;
//	}
//	return static_cast<int>(i - j);
//}
//
//int main()
//{
//	string s;
//	getline(cin, s);
//	cout << lengthOfLastWord(s) << '\n';
//	return 0;
//}

////只出现一次的数字：https://leetcode.cn/problems/single-number/。
//class Solution
//{
//public:
//	int singleNumber(vector<int>& nums)
//	{
//		int res = 0;
//		for (int num : nums)
//		{
//			res ^= num;
//		}
//		return res;
//	}
//};

////杨辉三角：https://leetcode.cn/problems/pascals-triangle/。
//class Solution
//{
//public:
//	vector<vector<int>> generate(int numRows)
//	{
//		vector<vector<int>> ans;
//		for (vector<vector<int>>::size_type i = 0; i < numRows; ++i)
//		{
//			vector<int> row(i + 1, 1);
//			for (vector<int>::size_type j = 1; j < i; ++j)
//			{
//				row[j] = ans[i - 1][j - 1] + ans[i - 1][j];
//			}
//			ans.push_back(row);
//		}
//		return ans;
//	}
//};

////只出现一次的数字 II：https://leetcode.cn/problems/single-number-ii/。
//class Solution
//{
//public:
//	int singleNumber(vector<int>& nums)
//	{
//		vector<int> help(32, 0);
//		for (int num: nums)
//		{
//			for (vector<int>::size_type i = 0; i < 32; ++i)
//			{
//				help[i] += (num >> i) & 1;
//			}
//		}
//		int ans = 0;
//		for (vector<int>::size_type i = 0; i < 32; ++i)
//		{
//			help[i] %= 3;
//			if (help[i] != 0)
//			{
//				ans |= 1 << i;
//			}
//		}
//		return ans;
//	}
//};

////数组中出现次数超过一半的数字：https://www.nowcoder.com/practice/e8a1b01a2df14cb2b228b30ee6a92163。(类似力扣第"169"题)
//class Solution
//{
//public:
//	int MoreThanHalfNum_Solution(vector<int> numbers)
//	{
//		int candidate = 0;
//		int hitPoint = 0;
//		for (vector<int>::size_type i = 0; i < numbers.size(); ++i)
//		{
//			if (hitPoint == 0)
//			{
//				candidate = numbers[i];
//				++hitPoint;
//			}
//			else if (candidate == numbers[i])
//			{
//				++hitPoint;
//			}
//			else
//			{
//				--hitPoint;
//			}
//		}
//		return candidate;
//	}
//};

////删除排序数组中的重复项：https://leetcode.cn/problems/remove-duplicates-from-sorted-array/。
//class Solution
//{
//public:
//	int removeDuplicates(vector<int>& nums)
//	{
//		if (nums.size() < 2)
//		{
//			return static_cast<int>(nums.size());
//		}
//		auto itSolw = nums.begin();
//		auto itFast = nums.begin() + 1;
//		while (itFast != nums.end())
//		{
//			if (*itSolw != *itFast && ++itSolw != itFast)
//			{
//				*itSolw = *itFast;
//			}
//			++itFast;
//		}
//		return static_cast<int>(itSolw - nums.begin() + 1);
//	}
//};

////只出现一次的数字 III：https://leetcode.cn/problems/single-number-iii/。
//class Solution
//{
//public:
//	vector<int> singleNumber(vector<int>& nums)
//	{
//		int xorSum = 0;
//		for (int num: nums)
//		{
//			xorSum ^= num;
//		}
//		int differenceNum = xorSum == INT_MIN ? xorSum : (xorSum & (-xorSum));
//		int x = 0, y = 0;
//		for (int num: nums)
//		{
//			if ((num & differenceNum) == 0)
//			{
//				x ^= num;
//			}
//			else
//			{
//				y ^= num;
//			}
//		}
//		return vector<int>{ x, y };
//	}
//};

////电话号码的字母组合：https://leetcode.cn/problems/letter-combinations-of-a-phone-number/。
//class Solution
//{
//public:
//	vector<string> letterCombinations(string digits)
//	{
//		vector<string> ans;
//		if (digits.empty())
//		{
//			return ans;
//		}
//		string path(digits.length(), ' ');
//		process(digits, 0, path, ans);
//		return ans;
//	}
//
//	void process(string& str, string::size_type index, string& path, vector<string>& ans)
//	{
//		if (index == str.length())
//		{
//			ans.push_back(path);
//		}
//		else
//		{
//			string cands = phone[str[index] - '2'];
//			for (char cur: cands)
//			{
//				path[index] = cur;
//				process(str, index + 1, path, ans);
//			}
//		}
//	}
//
//private:
//	static vector<string> phone;
//};
//
//vector<string> Solution::phone = { "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };

////最小栈：https://leetcode.cn/problems/min-stack/。
//class MinStack
//{
//public:
//	MinStack()
//	{
//	}
//
//	void push(int val)
//	{
//		if (minStack.empty() || val <= minStack.top())
//		{
//			minStack.push(val);
//		}
//		dataStack.push(val);
//	}
//
//	void pop()
//	{
//		if (dataStack.top() == minStack.top())
//		{
//			minStack.pop();
//		}
//		dataStack.pop();
//	}
//
//	int top()
//	{
//		return dataStack.top();
//	}
//
//	int getMin()
//	{
//		return minStack.top();
//	}
//
//	stack<int> dataStack;
//	stack<int> minStack;
//};

////栈的压入、弹出序列：https://www.nowcoder.com/practice/d77d11405cc7470d82554cb392585106。
//class Solution {
//public:
//    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
//        stack<int> st;
//        for (vector<int>::size_type i = 0, j = 0; i < pushV.size(); ++i)
//        {
//            st.push(pushV[i]);
//            while (!st.empty() && st.top() == popV[j])
//            {
//                st.pop();
//                ++j;
//            }
//        }
//        return st.empty();
//    }
//};

////逆波兰表达式求值：https://leetcode-cn.com/problems/evaluate-reverse-polish-notation/。
//class Solution
//{
//public:
//	int evalRPN(vector<string>& tokens)
//	{
//		stack<int> stack;
//		for (string str: tokens)
//		{
//			if (str == "+" || str == "-" || str == "*" || str == "/")
//			{
//				compute(stack, str[0]);
//			}
//			else
//			{
//				stack.push(stoi(str));
//			}
//		}
//		return stack.top();
//	}
//
//	void compute(stack<int>& stack, char op)
//	{
//		int num2 = stack.top();
//		stack.pop();
//		int num1 = stack.top();
//		stack.pop();
//		int ans = 0;
//		switch (op)
//		{
//		case '+':
//			ans = num1 + num2;
//			break;
//		case '-':
//			ans = num1 - num2;
//			break;
//		case '*':
//			ans = num1 * num2;
//			break;
//		case '/':
//			ans = num1 / num2;
//			break;
//		}
//		stack.push(ans);
//	}
//};