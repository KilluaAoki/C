////轮转数组：https://leetcode-cn.com/problems/rotate-array/。(使用额外数组的方法)
//void rotate(int* nums, int numsSize, int k)
//{
//	int* tmp = (int*)malloc(sizeof(int) * numsSize);
//	for (int i = 0; i < numsSize; ++i)
//	{
//		tmp[i] = nums[i];
//	}
//	for (int i = 0; i < numsSize; ++i)
//	{
//		nums[(i + k) % numsSize] = tmp[i];
//	}
//	free(tmp);
//}

////轮转数组：https://leetcode-cn.com/problems/rotate-array/。(三步翻转法)
//void Swap(int* ptr1, int* ptr2)
//{
//	((*ptr1) ^ (*ptr2)) && ((*ptr2) ^= (*ptr1) ^= (*ptr2), (*ptr1) ^= (*ptr2));
//}
//
//void Reverse(int* nums, int x, int y)
//{
//	while (x < y)
//	{
//		Swap(&nums[x++], &nums[y--]);
//	}
//}
//
//void rotate(int* nums, int numsSize, int k)
//{
//	k %= numsSize;
//	Reverse(nums, 0, numsSize - 1);
//	Reverse(nums, k, numsSize - 1);
//	Reverse(nums, 0, k - 1);
//}

////轮转数组：https://leetcode-cn.com/problems/rotate-array/。(环状替换法)
//void Swap(int* ptr1, int* ptr2)
//{
//	((*ptr1) ^ (*ptr2)) && ((*ptr2) ^= (*ptr1) ^= (*ptr2), (*ptr1) ^= (*ptr2));
//}
//
//void rotate(int* nums, int numsSize, int k)
//{
//	k %= numsSize;
//	for (int start = 0, count = 0; start < numsSize && count < numsSize; ++start)
//	{
//		int cur = start;
//		do
//		{
//			int next = (cur + k) % numsSize;
//			Swap(&nums[start], &nums[next]);
//			cur = next;
//			++count;
//		} while (start != cur);
//	}
//}

////消失的数字：https://leetcode-cn.com/problems/missing-number-lcci/。(方法一)
//int missingNumber(int* nums, int numsSize)
//{
//	int total = numsSize * (numsSize + 1) / 2;
//	int sum = 0;
//	for (int i = 0; i < numsSize; ++i)
//	{
//		sum += nums[i];
//	}
//	return total - sum;
//}

////消失的数字：https://leetcode-cn.com/problems/missing-number-lcci/。(方法二)
//int missingNumber(int* nums, int numsSize)
//{
//	int xor = 0;
//	for (int i = 0; i < numsSize; ++i)
//	{
//		xor ^= i;
//		xor ^= nums[i];
//	}
//	return (xor ^= numsSize);
//}

////移除元素：https://leetcode.cn/problems/remove-element/。
//int removeElement(int* nums, int numsSize, int val)
//{
//	int j = 0;
//	for (int i = 0; i < numsSize; ++i)
//	{
//		if (nums[i] != val)
//		{
//			nums[j++] = nums[i];
//		}
//	}
//	return j;
//}

////删除有序数组中的重复项：https://leetcode.cn/problems/remove-duplicates-from-sorted-array/。
//int removeDuplicates(int* nums, int numsSize)
//{
//	if (numsSize < 2)
//	{
//		return numsSize;
//	}
//	int j = 0;
//	for (int i = 1; i < numsSize; ++i)
//	{
//		if (nums[i] != nums[j])
//		{
//			nums[++j] = nums[i];
//		}
//	}
//	return ++j;
//}

////合并两个有序数组：https://leetcode.cn/problems/merge-sorted-array/。
//void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n)
//{
//	int x = m + n - 1;
//	while (n)
//	{
//		if (m == 0 || nums1[m - 1] <= nums2[n - 1])
//		{
//			nums1[x--] = nums2[--n];
//		}
//		else
//		{
//			nums1[x--] = nums1[--m];
//		}
//	}
//}