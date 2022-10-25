#include "Sort.h"
#include "Test/Test.h"

void Test_Sort_01()
{
	printf("******************************01******************************\n");

	srand((unsigned int)time(NULL));
	size_t testTime = 1000;
	size_t maxSize = 10000;
	bool succeed = true;
	for (size_t i = 0; i < testTime; i++)
	{
		size_t size = rand() % maxSize + 1;
		SortDataType* arr = Generate_Random_Array(size);
		SortDataType* arr1 = Copy_Array(arr, size);
		SortDataType* arr2 = Copy_Array(arr, size);
		Heap_Sort(arr1, size);
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
	size_t maxSize = 10000;

	size_t size = rand() % maxSize + 1;
	SortDataType* arr1 = Generate_Random_Array(size);
	SortDataType* arr2 = Copy_Array(arr1, size);
	SortDataType* arr3 = Copy_Array(arr1, size);
	SortDataType* arr4 = Copy_Array(arr1, size);
	SortDataType* arr5 = Copy_Array(arr1, size);

	clock_t begin = clock();
	printf("Insertion_Sort：%lfs\n", Clock_Sort(arr1, size, Insertion_Sort));
	printf("Selection_Sort：%lfs\n", Clock_Sort(arr2, size, Selection_Sort));
	printf("Bubble_Sort：%lfs\n", Clock_Sort(arr3, size, Bubble_Sort));
	printf("Heap_Sort：%lfs\n", Clock_Sort(arr4, size, Heap_Sort));
	printf("qsort：%lfs\n", Contrast(arr5, size, Compare_Int));
	printf("Total Time：%lfs\n", (double)(clock() - begin) / CLOCKS_PER_SEC);

	free(arr1);
	free(arr2);
	free(arr3);
	free(arr4);
	free(arr5);

	printf("*****************************EXIT*****************************\n\n");
}

int main()
{
	Test_Sort_01();
	Test_Sort_02();
	return 0;
}