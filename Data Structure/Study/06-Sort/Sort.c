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
		for (size_t j = 0; j < i; ++j)
		{
			if (arr[j] > arr[j + 1])
			{
				Swap(&arr[j], &arr[j + 1]);
			}
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
		for (size_t j = i; j > 0 && arr[j] < arr[j - 1]; --j)
		{
			Swap(&arr[j], &arr[j - 1]);
		}
	}
}

//堆排序
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