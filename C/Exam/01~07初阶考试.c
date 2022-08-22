#include <stdio.h>
#include <string.h>

////求最小公倍数：https://www.nowcoder.com/practice/22948c2cad484e0291350abad86136c3。
//int GetFactor(int x, int y)
//{
//	return y ? GetFactor(y, x % y) : x;
//}
//
//int main()
//{
//	int x, y;
//	scanf("%d%d", &x, &y);
//	int ret = GetFactor(x, y);
//	printf("%d\n", x * y / ret);
//	return 0;
//}

////倒置字符串：https://www.nowcoder.com/practice/ee5de2e7c45a46a090c1ced2fdc62355。
//void ReverseString(char* left, char* right)
//{
//	while (left < right)
//	{
//		(*left ^ *right) && (*right ^= *left ^= *right, *left ^= *right);
//		left++;
//		right--;
//	}
//}
//
//int main()
//{
//	char arr[101] = { 0 };
//	gets(arr);
//	size_t len = strlen(arr);
//	ReverseString(arr, arr + len - 1);
//	char* start = arr;
//	while (*start)
//	{
//		char* end = start;
//		while (*end != ' ' && *end)
//		{
//			end++;
//		}
//		ReverseString(start, end - 1);
//		if (*end)
//		{
//			end++;
//		}
//		start = end;
//	}
//	printf("%s\n", arr);
//	return 0;
//}