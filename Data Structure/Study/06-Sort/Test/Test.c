#include "Test.h"

//生成一个包含整数(正数和负数和零)的随机数组，"size"的值超过"rand"函数的最大值则无效。
SortDataType* Generate_Integer_Random_Array(size_t size)
{
	SortDataType* arr = (SortDataType*)malloc(sizeof(SortDataType) * size);
	if (arr == NULL)
	{
		perror("Generate_Integer_Random_Array");
		exit(EXIT_FAILURE);
	}
	for (int i = 0; i < size; ++i)
	{
		arr[i] = (rand() - rand());
	}
	return arr;
}

//生成一个包含自然数(不含负数的整数)的随机数组，"maxValue"用于限定数值最大值，"size"的值超过"rand"函数的最大值则无效。
SortDataType* Generate_Natural_Random_Array(size_t size, size_t maxValue)
{
	SortDataType* arr = (SortDataType*)malloc(sizeof(SortDataType) * size);
	if (arr == NULL)
	{
		perror("Generate_Natural_Random_Array");
		exit(EXIT_FAILURE);
	}
	for (int i = 0; i < size; ++i)
	{
		arr[i] = rand() % maxValue + 1;
	}
	return arr;
}

//复制数组
SortDataType* Copy_Array(const SortDataType* arr, size_t size)
{
	SortDataType* copyArray = (SortDataType*)malloc(sizeof(SortDataType) * size);
	for (int i = 0; i < size; ++i)
	{
		copyArray[i] = arr[i];
	}
	return copyArray;
}

//判断两数组是否一样
bool Is_Equal(const SortDataType* arr1, const SortDataType* arr2, size_t size)
{
	for (int i = 0; i < size; ++i)
	{
		if (arr1[i] != arr2[i])
		{
			return false;
		}
	}
	return true;
}

//对照函数(即库函数"qsort"，并返回排序所用时间(单位：秒))
double Contrast(SortDataType* arr, size_t size, int(* Compare)(const void*, const void*))
{
	clock_t begin = clock();
	qsort(arr, size, sizeof(SortDataType), Compare);
	return (double)(clock() - begin) / CLOCKS_PER_SEC;
}

//测试排序算法的时间(单位：秒)
double Clock_Sort(SortDataType* arr, size_t size, void(* Sort)(SortDataType*, size_t))
{
	clock_t begin = clock();
	Sort(arr, size);
	return (double)(clock() - begin) / CLOCKS_PER_SEC;
}