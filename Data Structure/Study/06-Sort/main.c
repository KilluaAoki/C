#include "Sort.h"
#include "Test/Test.h"

void Test_Sort_01()
{
	printf("******************************01******************************\n");

	srand((unsigned int)time(NULL));
	size_t testTime = 1000;
	size_t maxSize = 10000;//随机数组的长度范围为：[0, maxSize]。
	bool succeed = true;
	for (size_t i = 0; i < testTime; i++)
	{
		size_t size = rand() % maxSize + 1;
		SortDataType* arr = Generate_Integer_Random_Array(size);
		SortDataType* arr1 = Copy_Array(arr, size);
		SortDataType* arr2 = Copy_Array(arr, size);
		Shell_Sort(arr1, size);
		Contrast(arr2, size, Compare_Int);
		if (!Is_Equal(arr1, arr2, size))
		{
			succeed = false;
			for (int j = 0; j < size; j++)
			{
				printf("%d ", arr1[j]);
			}
			printf("\n");
			break;
		}
		free(arr);
		free(arr1);
		free(arr2);
	}
	succeed ? printf("Good Luck!\n") : printf("Oops!\n");

	printf("*****************************EXIT*****************************\n\n");
}

void Test_Sort_02()
{
	printf("******************************02******************************\n");

	srand((unsigned int)time(NULL));

	size_t size = 50000;
	SortDataType* arr1 = Generate_Integer_Random_Array(size);
	SortDataType* arr2 = Copy_Array(arr1, size);
	SortDataType* arr3 = Copy_Array(arr1, size);
	SortDataType* arr4 = Copy_Array(arr1, size);
	SortDataType* arr5 = Copy_Array(arr1, size);
	SortDataType* arr6 = Copy_Array(arr1, size);
	SortDataType* arr7 = Copy_Array(arr1, size);
	SortDataType* arr8 = Copy_Array(arr1, size);
	SortDataType* arr9 = Copy_Array(arr1, size);
	SortDataType* arr10 = Copy_Array(arr1, size);

	clock_t begin = clock();
	printf("Insertion_Sort：%lfs\n", Clock_Sort(arr1, size, Insertion_Sort));
	printf("Selection_Sort：%lfs\n", Clock_Sort(arr2, size, Selection_Sort));
	printf("Bubble_Sort：%lfs\n", Clock_Sort(arr3, size, Bubble_Sort));
	printf("Shell_Sort：%lfs\n", Clock_Sort(arr4, size, Shell_Sort));
	printf("Heap_Sort：%lfs\n", Clock_Sort(arr5, size, Heap_Sort));
	printf("Merge_Sort_Recursive：%lfs\n", Clock_Sort(arr6, size, Merge_Sort_Recursive));
	printf("Merge_Sort_UnRecursive：%lfs\n", Clock_Sort(arr7, size, Merge_Sort_UnRecursive));
	printf("Quick_Sort_Recursive：%lfs\n", Clock_Sort(arr8, size, Quick_Sort_Recursive));
	printf("Quick_Sort_UnRecursive：%lfs\n", Clock_Sort(arr9, size, Quick_Sort_UnRecursive));
	printf("qsort：%lfs\n", Contrast(arr10, size, Compare_Int));
	printf("Total Time：%lfs\n", (double)(clock() - begin) / CLOCKS_PER_SEC);

	free(arr1);
	free(arr2);
	free(arr3);
	free(arr4);
	free(arr5);
	free(arr6);
	free(arr7);
	free(arr8);
	free(arr9);
	free(arr10);

	printf("*****************************EXIT*****************************\n\n");
}

void Test_Sort_03()
{
	printf("******************************03******************************\n");

	srand((unsigned int)time(NULL));
	size_t testTime = 100000;
	size_t maxSize = 1000;//随机数组的长度范围为：[0, maxSize]。
	size_t maxValue = 100;//随机数组的数值范围为：[0, maxValue]。
	bool succeed = true;
	for (size_t i = 0; i < testTime; i++)
	{
		size_t size = rand() % maxSize + 1;
		SortDataType* arr = Generate_Natural_Random_Array(size, maxValue);
		SortDataType* arr1 = Copy_Array(arr, size);
		SortDataType* arr2 = Copy_Array(arr, size);
		Radix_Sort(arr1, size);
		Contrast(arr2, size, Compare_Int);
		if (!Is_Equal(arr1, arr2, size))
		{
			succeed = false;
			for (int j = 0; j < size; j++)
			{
				printf("%d ", arr1[j]);
			}
			printf("\n");
			break;
		}
		free(arr);
		free(arr1);
		free(arr2);
	}
	succeed ? printf("Good Luck!\n") : printf("Oops!\n");

	printf("*****************************EXIT*****************************\n\n");
}

void Test_Sort_04()
{
	printf("******************************04******************************\n");

	srand((unsigned int)time(NULL));

	size_t size = 10000000;
	size_t maxValue = 1000;
	SortDataType* arr1 = Generate_Natural_Random_Array(size, maxValue);
	SortDataType* arr2 = Copy_Array(arr1, size);
	SortDataType* arr3 = Copy_Array(arr1, size);

	clock_t begin = clock();
	printf("Count_Sort：%lfs\n", Clock_Sort(arr1, size, Count_Sort));
	printf("Radix_Sort：%lfs\n", Clock_Sort(arr2, size, Radix_Sort));
	printf("qsort：%lfs\n", Contrast(arr3, size, Compare_Int));
	printf("Total Time：%lfs\n", (double)(clock() - begin) / CLOCKS_PER_SEC);

	free(arr1);
	free(arr2);
	free(arr3);

	printf("*****************************EXIT*****************************\n\n");
}

int main()
{
	//测试基于比较的排序算法
	Test_Sort_01();//测试排序算法的正确性。
	Test_Sort_02();//测试排序算法的性能。

	//测试基于非比较的排序算法
	Test_Sort_03();//测试排序算法的正确性。
	Test_Sort_04();//测试排序算法的性能。

	return 0;
}