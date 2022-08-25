////轮转数组：https://leetcode-cn.com/problems/rotate-array/。
//void Swap(int* ptr1, int* ptr2)
//{
//	((*ptr1) ^ (*ptr2)) && ((*ptr2) ^= (*ptr1) ^= (*ptr2), (*ptr1) ^= (*ptr2));
//}
//
//void Reverse(int* nums, int begin, int end)
//{
//	while (begin < end)
//	{
//		Swap(nums + begin, nums + end);
//		begin++;
//		end--;
//	}
//}
//
//void rotate(int* nums, int numsSize, int k)
//{
//	if (k >= numsSize)
//	{
//		k %= numsSize;
//	}
//	Reverse(nums, 0, numsSize - k - 1);
//	Reverse(nums, numsSize - k, numsSize - 1);
//	Reverse(nums, 0, numsSize - 1);
//}

////消失的数字：https://leetcode-cn.com/problems/missing-number-lcci/。
//int missingNumber(int* nums, int numsSize)
//{
//	int arr_sum = 0;
//	int n_sum = ((0 + numsSize) * (numsSize + 1)) / 2;
//	for (int i = 0; i < numsSize; ++i)
//	{
//		arr_sum += nums[i];
//	}
//	return n_sum - arr_sum;
//}