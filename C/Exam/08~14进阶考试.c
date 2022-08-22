#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

////Fibonacci数列：https://www.nowcoder.com/practice/18ecd0ecf5ef4fe9ba3f17f8d00d2d66。
//int main()
//{
//	int input = 0;
//	scanf("%d", &input);
//	int a = 0;
//	int b = 1;
//	int c = a + b;
//	while (1)
//	{
//		if (input == b)
//		{
//			printf("%d", 0);
//			break;
//		}
//		else if (input < b)
//		{
//			if (abs(a - input) < abs(b - input))
//			{
//				printf("%d\n", abs(a - input));
//			}
//			else
//			{
//				printf("%d\n", abs(b - input));
//			}
//			break;
//		}
//		a = b;
//		b = c;
//		c = a + b;
//	}
//	return 0;
//}

////替换空格：https://www.nowcoder.com/practice/0e26e5551f2b489b9f58bc83aa4b6c68。
//char* replaceSpace(char* s)
//{
//	size_t len = strlen(s);
//	size_t spaceCount = 0;
//	char* cur = s;
//	while (*cur)
//	{
//		if (*cur == ' ')
//		{
//			++spaceCount;
//		}
//		++cur;
//	}
//	char* str = (char*)malloc(sizeof(char) * len + (spaceCount * 2) + 1);
//	cur = s + len - 1;
//	char* end = str + (len + (spaceCount * 2));
//	*end-- = '\0';
//	while (len--)
//	{
//		if (*cur == ' ')
//		{
//			*(end - 0) = '0';
//			*(end - 1) = '2';
//			*(end - 2) = '%';
//			end -= 3;
//			--cur;
//		}
//		else
//		{
//			*end-- = *cur--;
//		}
//	}
//	return str;
//}