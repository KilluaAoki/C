#include "Sort.h"

//比较器
int Compare_Int(const void* p1, const void* p2)
{
	return *(int*)p1 - *(int*)p2;
}

//交换元素
void Swap(SortDataType* ptr1, SortDataType* ptr2)
{
	(*ptr1 ^ *ptr2) && (*ptr2 ^= *ptr1 ^= *ptr2, *ptr1 ^= *ptr2);
}

//冒泡排序
void Bubble_Sort(SortDataType* arr, size_t size)
{
	if (arr == NULL || size < 2)
	{
		return;
	}
	for (size_t i = size - 1; i >= 1; --i)
	{
		bool flag = false;
		for (size_t j = 0; j < i; ++j)
		{
			if (arr[j] > arr[j + 1])
			{
				flag = true;
				Swap(&arr[j], &arr[j + 1]);
			}
		}
		if (!flag)
		{
			break;
		}
	}
}

//选择排序
void Selection_Sort(SortDataType* arr, size_t size)
{
	if (arr == NULL || size < 2)
	{
		return;
	}
	for (size_t i = 0; i < size - 1; ++i)
	{
		size_t minIndex = i;
		for (size_t j = i + 1; j < size; ++j)
		{
			minIndex = arr[minIndex] < arr[j] ? minIndex : j;
		}
		Swap(&arr[minIndex], &arr[i]);
	}
}

//插入排序
void Insertion_Sort(SortDataType* arr, size_t size)
{
	if (arr == NULL || size < 2)
	{
		return;
	}
	for (size_t i = 1; i < size; ++i)
	{
		size_t j = i;
		SortDataType tmp = arr[i];
		for (; j > 0 && tmp < arr[j - 1]; --j)
		{
			arr[j] = arr[j - 1];
		}
		arr[j] = tmp;
	}
}

//希尔排序
void Shell_Sort(SortDataType* arr, size_t size)
{
	if (arr == NULL || size < 2)
	{
		return;
	}
	size_t gap = 1;
	while (gap < size / 3)
	{
		gap = 3 * gap + 1;
	}
	while (gap >= 1)
	{
		for (size_t i = gap; i < size; ++i)
		{
			for (size_t j = i; j >= gap && arr[j] < arr[j - gap]; j -= gap)
			{
				Swap(&arr[j], &arr[j - gap]);
			}
		}
		gap /= 3;
	}
}

//适用于大根堆的向下调整函数
void Ify_Max_Heap(SortDataType* arr, size_t index, size_t size)
{
	size_t left = index * 2 + 1;
	while (left < size)
	{
		size_t largest = left + 1 < size && arr[left + 1] > arr[left] ? left + 1 : left;
		largest = arr[index] < arr[largest] ? largest : index;
		if (index == largest)
		{
			break;
		}
		Swap(&arr[index], &arr[largest]);
		index = largest;
		left = index * 2 + 1;
	}
}

//堆排序
void Heap_Sort(SortDataType* arr, size_t size)
{
	if (arr == NULL || size < 2)
	{
		return;
	}
	for (int i = (int)size - 1; i >= 0; --i)
	{
		Ify_Max_Heap(arr, i, size);
	}
	size_t heapSize = size;
	Swap(&arr[0], &arr[--heapSize]);
	while (heapSize > 0)
	{
		Ify_Max_Heap(arr, 0, heapSize);
		Swap(&arr[0], &arr[--heapSize]);
	}
}

//归并排序核心函数
void Merge(SortDataType* arr, size_t left, size_t middle, size_t right)
{
	SortDataType* help = (SortDataType*)malloc(sizeof(SortDataType) * (right - left + 1));
	size_t i = 0;
	size_t p1 = left, p2 = middle + 1;
	while (p1 <= middle && p2 <= right)
	{
		help[i++] = arr[p1] <= arr[p2] ? arr[p1++] : arr[p2++];
	}
	while (p1 <= middle)
	{
		help[i++] = arr[p1++];
	}
	while (p2 <= right)
	{
		help[i++] = arr[p2++];
	}
	for (size_t j = 0; j < i; ++j)
	{
		arr[left + j] = help[j];
	}
	free(help);
}

//归并排序递归过程函数
void Merge_Sort_Recursive_Process(SortDataType* arr, size_t left, size_t right)
{
	if (left == right)
	{
		return;
	}
	size_t middle = left + ((right - left) >> 1);
	Merge_Sort_Recursive_Process(arr, left, middle);
	Merge_Sort_Recursive_Process(arr, middle + 1, right);
	Merge(arr, left, middle, right);
}

//归并排序(递归实现)
void Merge_Sort_Recursive(SortDataType* arr, size_t size)
{
	if (arr == NULL || size < 2)
	{
		return;
	}
	Merge_Sort_Recursive_Process(arr, 0, size - 1);
}

//归并排序(非递归实现)
void Merge_Sort_UnRecursive(SortDataType* arr, size_t size)
{
	if (arr == NULL || size < 2)
	{
		return;
	}
	size_t stepSize = 1;
	while (stepSize < size)
	{
		size_t left = 0;
		while (left < size)
		{
			size_t middle = left + stepSize - 1;
			if (middle >= size)
			{
				break;
			}
			size_t right = middle + stepSize < size - 1 ? middle + stepSize : size - 1;
			Merge(arr, left, middle, right);
			left = right + 1;
		}
		if (stepSize > size / 2)
		{
			break;
		}
		stepSize <<= 1;
	}
}

//快速排序核心函数
void Partition(SortDataType* arr, int left, int right, int* pkeyLight, int* pkeyRight)
{
	if (left > right)
	{
		*pkeyLight = -1, *pkeyRight = -1;
		return;
	}
	if (left == right)
	{
		*pkeyLight = left, *pkeyRight = right;
		return;
	}
	int less = left - 1;
	int more = right;
	int index = left;
	while (index < more)
	{
		if (arr[index] == arr[right])
		{
			index++;
		}
		else if (arr[index] < arr[right])
		{
			Swap(&arr[index++], &arr[++less]);
		}
		else
		{
			Swap(&arr[index], &arr[--more]);
		}
	}
	Swap(&arr[more], &arr[right]);
	*pkeyLight = less + 1, *pkeyRight = more;
}

//快速排序递归过程函数
void Quick_Sort_Recursive_Process(SortDataType* arr, int left, int right)
{
	if (left >= right)
	{
		return;
	}
	Swap(&arr[left + (rand() % (right - left + 1))], &arr[right]);
	int keyLeft, keyRight;
	Partition(arr, left, right, &keyLeft, &keyRight);
	Quick_Sort_Recursive_Process(arr, left, keyLeft - 1);
	Quick_Sort_Recursive_Process(arr, keyRight + 1, right);
}

//快速排序(递归实现)
void Quick_Sort_Recursive(SortDataType* arr, size_t size)
{
	if (arr == NULL || size < 2)
	{
		return;
	}
	Quick_Sort_Recursive_Process(arr, 0, (int)size - 1);
}

//快速排序(非递归实现)
void Quick_Sort_UnRecursive(SortDataType* arr, size_t size)
{
	if (arr == NULL || size < 2)
	{
		return;
	}
	Stack help;
	Init_Stack(&help);
	Swap(&arr[rand() % size], &arr[size - 1]);
	int keyLeft, keyRight;
	Partition(arr, 0, (int)size - 1, &keyLeft, &keyRight);
	Push_Stack(&help, 0);
	Push_Stack(&help, keyLeft - 1);
	Push_Stack(&help, keyRight + 1);
	Push_Stack(&help, (int)size - 1);
	while (!Empty_Stack(&help))
	{
		int right = Pop_Stack(&help);
		int left = Pop_Stack(&help);
		if (left < right)
		{
			Swap(&arr[left + (rand() % (right - left + 1))], &arr[right]);
			Partition(arr, left, right, &keyLeft, &keyRight);
			Push_Stack(&help, left);
			Push_Stack(&help, keyLeft - 1);
			Push_Stack(&help, keyRight + 1);
			Push_Stack(&help, right);
		}
	}
	Destroy_Stack(&help);
}

//计数排序
void Count_Sort(SortDataType* arr, size_t size)
{
	if (arr == NULL || size < 2)
	{
		return;
	}
	SortDataType max = arr[0];
	for (size_t i = 0; i < size; ++i)
	{
		max = arr[i] > max ? arr[i] : max;
	}
	SortDataType* help = (SortDataType*)calloc(max + 1, sizeof(SortDataType));
	for (int i = 0; i < size; ++i)
	{
		help[arr[i]]++;
	}
	for (int i = 0, j = 0; i < max + 1; ++i)
	{
		while (help[i]-- > 0)
		{
			arr[j++] = i;
		}
	}
	free(help);
}

//获取数组中最大值的十进制位数
size_t Get_Max_Decimal_Bits_Digit(const SortDataType* arr, size_t size)
{
	SortDataType max = arr[0];
	for (size_t i = 0; i < size; ++i)
	{
		max = arr[i] > max ? arr[i] : max;
	}
	size_t digit = 0;
	while (max != 0)
	{
		digit++;
		max /= 10;
	}
	return digit;
}

//获取当前位数上的值(数字)
SortDataType Get_Digit_Value(SortDataType num, size_t digit)
{
	while (--digit)
	{
		num /= 10;
	}
	return num % 10;
}

//基数排序核心函数
void Radix(SortDataType* arr, int left, int right, size_t digit)
{
	const size_t radix = 10;
	int i, j;
	SortDataType* help = (SortDataType*)calloc(right - left + 1, sizeof(SortDataType));
	for (size_t d = 1; d <= digit; ++d)
	{
		SortDataType* count = (SortDataType*)calloc(radix, sizeof(SortDataType));
		for (i = left; i <= right; ++i)
		{
			j = Get_Digit_Value(arr[i], d);
			count[j]++;
		}
		for (i = 1; i < radix; ++i)
		{
			count[i] = count[i] + count[i - 1];
		}
		for (i = right; i >= left; --i)
		{
			j = Get_Digit_Value(arr[i], d);
			help[count[j] - 1] = arr[i];
			count[j]--;
		}
		for (i = left, j = 0; i <= right; ++i, ++j)
		{
			arr[i] = help[j];
		}
		free(count);
	}
	free(help);
}

//基数排序
void Radix_Sort(SortDataType* arr, size_t size)
{
	if (arr == NULL || size < 2)
	{
		return;
	}
	Radix(arr, 0, (int)size - 1, Get_Max_Decimal_Bits_Digit(arr, size));
}