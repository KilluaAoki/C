#include "Heap.h"

void Test_Heap_01()
{
	printf("******************************01******************************\n");
	Heap heap;
	Init_Heap(&heap);

	Push_Heap(&heap, 0, Insert_Max_Heap);
	printf("%d\n", Top_Heap(&heap));
	Push_Heap(&heap, 1, Insert_Max_Heap);
	Push_Heap(&heap, 2, Insert_Max_Heap);
	Push_Heap(&heap, 3, Insert_Max_Heap);
	Push_Heap(&heap, 4, Insert_Max_Heap);
	Push_Heap(&heap, 5, Insert_Max_Heap);
	Push_Heap(&heap, 6, Insert_Max_Heap);
	Push_Heap(&heap, 7, Insert_Max_Heap);
	Push_Heap(&heap, 8, Insert_Max_Heap);
	Push_Heap(&heap, 9, Insert_Max_Heap);
	printf("\nSize = %zu\n", Size_Heap(&heap));
	Print_Heap(heap.array_ptr, heap.size);
	Pop_Heap(&heap, Ify_Max_Heap);
	Print_Heap(heap.array_ptr, heap.size);
	Pop_Heap(&heap, Ify_Max_Heap);
	Print_Heap(heap.array_ptr, heap.size);
	Pop_Heap(&heap, Ify_Max_Heap);
	Print_Heap(heap.array_ptr, heap.size);
	Pop_Heap(&heap, Ify_Max_Heap);
	Print_Heap(heap.array_ptr, heap.size);
	Pop_Heap(&heap, Ify_Max_Heap);
	Print_Heap(heap.array_ptr, heap.size);
	Pop_Heap(&heap, Ify_Max_Heap);
	Print_Heap(heap.array_ptr, heap.size);
	Pop_Heap(&heap, Ify_Max_Heap);
	Print_Heap(heap.array_ptr, heap.size);
	Pop_Heap(&heap, Ify_Max_Heap);
	Print_Heap(heap.array_ptr, heap.size);
	Pop_Heap(&heap, Ify_Max_Heap);
	Print_Heap(heap.array_ptr, heap.size);
	printf("\nSize = %zu\n", Size_Heap(&heap));

	Destroy_Heap(&heap);
	printf("*****************************EXIT*****************************\n\n");
}

void Test_Heap_02()
{
	printf("******************************02******************************\n");
	Heap heap;
	Init_Heap(&heap);

	Push_Heap(&heap, 9, Insert_Min_Heap);
	printf("%d\n", Top_Heap(&heap));
	Push_Heap(&heap, 8, Insert_Min_Heap);
	Push_Heap(&heap, 7, Insert_Min_Heap);
	Push_Heap(&heap, 6, Insert_Min_Heap);
	Push_Heap(&heap, 5, Insert_Min_Heap);
	Push_Heap(&heap, 4, Insert_Min_Heap);
	Push_Heap(&heap, 3, Insert_Min_Heap);
	Push_Heap(&heap, 2, Insert_Min_Heap);
	Push_Heap(&heap, 1, Insert_Min_Heap);
	Push_Heap(&heap, 0, Insert_Min_Heap);
	printf("\nSize = %zu\n", Size_Heap(&heap));
	Print_Heap(heap.array_ptr, heap.size);
	Pop_Heap(&heap, Ify_Min_Heap);
	Print_Heap(heap.array_ptr, heap.size);
	Pop_Heap(&heap, Ify_Min_Heap);
	Print_Heap(heap.array_ptr, heap.size);
	Pop_Heap(&heap, Ify_Min_Heap);
	Print_Heap(heap.array_ptr, heap.size);
	Pop_Heap(&heap, Ify_Min_Heap);
	Print_Heap(heap.array_ptr, heap.size);
	Pop_Heap(&heap, Ify_Min_Heap);
	Print_Heap(heap.array_ptr, heap.size);
	Pop_Heap(&heap, Ify_Min_Heap);
	Print_Heap(heap.array_ptr, heap.size);
	Pop_Heap(&heap, Ify_Min_Heap);
	Print_Heap(heap.array_ptr, heap.size);
	Pop_Heap(&heap, Ify_Min_Heap);
	Print_Heap(heap.array_ptr, heap.size);
	Pop_Heap(&heap, Ify_Min_Heap);
	Print_Heap(heap.array_ptr, heap.size);
	printf("Size = %zu\n", Size_Heap(&heap));

	Destroy_Heap(&heap);
	printf("*****************************EXIT*****************************\n\n");
}

void Test_Heap_03()
{
	printf("******************************03******************************\n");
	Heap heap;
	Init_Heap(&heap);

	Push_Heap(&heap, 9, Insert_Min_Heap);
	Push_Heap(&heap, 8, Insert_Min_Heap);
	Push_Heap(&heap, 7, Insert_Min_Heap);
	Push_Heap(&heap, 6, Insert_Min_Heap);
	Push_Heap(&heap, 5, Insert_Min_Heap);
	Push_Heap(&heap, 4, Insert_Min_Heap);
	Push_Heap(&heap, 3, Insert_Min_Heap);
	Push_Heap(&heap, 2, Insert_Min_Heap);
	Push_Heap(&heap, 1, Insert_Min_Heap);
	Push_Heap(&heap, 0, Insert_Min_Heap);
	Print_Heap(heap.array_ptr, heap.size);
	Sort_Heap(heap.array_ptr, heap.size);
	for (int i = 0; i < heap.size; ++i)
	{
		printf("%d ", heap.array_ptr[i]);
	}
	printf("\n\n");
	Print_Heap(heap.array_ptr, heap.size);

	Destroy_Heap(&heap);
	printf("*****************************EXIT*****************************\n\n");
}

void Test_Heap_04()
{
	printf("******************************04******************************\n");
	Heap heap;
	Init_Heap(&heap);

	Push_Heap(&heap, 0, Insert_Max_Heap);
	Push_Heap(&heap, 1, Insert_Max_Heap);
	Push_Heap(&heap, 2, Insert_Max_Heap);
	Push_Heap(&heap, 3, Insert_Max_Heap);
	Push_Heap(&heap, 4, Insert_Max_Heap);
	Push_Heap(&heap, 5, Insert_Max_Heap);
	Push_Heap(&heap, 6, Insert_Max_Heap);
	Push_Heap(&heap, 7, Insert_Max_Heap);
	Push_Heap(&heap, 8, Insert_Max_Heap);
	Push_Heap(&heap, 9, Insert_Max_Heap);
	Print_Heap(heap.array_ptr, heap.size);
	Sort_Heap(heap.array_ptr, heap.size);
	for (int i = 0; i < heap.size; ++i)
	{
		printf("%d ", heap.array_ptr[i]);
	}
	printf("\n\n");
	Print_Heap(heap.array_ptr, heap.size);

	Destroy_Heap(&heap);
	printf("*****************************EXIT*****************************\n\n");
}

int main()
{
	Test_Heap_01();
	Test_Heap_02();
	Test_Heap_03();
	Test_Heap_04();
	return 0;
}