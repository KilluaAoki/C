////轮转数组：https://leetcode-cn.com/problems/rotate-array/。
//void Swap(int* ptr1, int* ptr2)
//{
//	((*ptr1) ^ (*ptr2)) && ((*ptr2) ^= (*ptr1) ^= (*ptr2), (*ptr1) ^= (*ptr2));
//}
//
//void rotate(int* nums, int numsSize, int k)
//{
//	int* left = nums;
//	int* right = nums + k;
//	while (left < right)
//	{
//		Swap(left, right);
//		left++;
//		right--;
//	}
//	left = nums + numsSize - k;
//	right = nums + numsSize - 1;
//	while (left <= right)
//	{
//		Swap(left, right);
//		left++;
//		right--;
//	}
//	left = nums;
//	right = nums + numsSize - 1;
//	while (left <= right)
//	{
//		Swap(left, right);
//		left++;
//		right--;
//	}
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