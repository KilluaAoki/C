#include "Heap.h"

//初始化堆
void Init_Heap(Heap* ptr)
{
	assert(ptr);
	ptr->array_ptr = NULL;
	ptr->size = ptr->capacity = 0;
}

//检查堆容量
void Check_Heap(Heap* ptr)
{
	assert(ptr);
	if (ptr->size == ptr->capacity)
	{
		ptr->capacity = ptr->capacity == 0 ? 4 : ptr->capacity * 2;
		ElemType* tmp = (ElemType*)realloc(ptr->array_ptr, sizeof(ElemType) * ptr->capacity);
		if (tmp == NULL)
		{
			perror("Check_Heap");
			exit(EXIT_FAILURE);
		}
		ptr->array_ptr = tmp;
	}
}

//以树状打印堆：https://stackoverflow.com/questions/65140349/printing-binary-heap-in-tree-format-c-language。
int Pow_2i(int a)
{
	int r = 1;
	while (a--)
	{
		r *= 2;
	}
	return r;
}

void Print_Heap(ElemType* arr_ptr, size_t size)
{
	int longest_digits = 0;
	int tree_depth = 0;
	int pos = 0;
	int depth = 0;
	for (size_t i = 0; i < size; ++i)
	{
		if (arr_ptr[i] != -1)
		{
			const int len = snprintf(NULL, 0, "%d", arr_ptr[i]);
			if (longest_digits < len)
			{
				longest_digits = len;
			}
		}
		if (pos == 0)
		{
			tree_depth++;
			pos = Pow_2i(depth++);
		}
		pos--;
	}
	pos = 0;
	depth = 0;
	const int additional_offset = 3;
	int max_width = Pow_2i(tree_depth) * (longest_digits + additional_offset);
	for (size_t i = 0; i < size; ++i)
	{
		const bool first = pos == 0;
		if (first)
		{
			pos = Pow_2i(depth);
			depth++;
		}
		const int count_elems = Pow_2i(depth);
		const int chunk = max_width / count_elems;
		const int width = chunk + (first ? -chunk / 2 : 0);
		const int pre_spaces = width - longest_digits;
		printf("%*s", pre_spaces, "");
		if (arr_ptr[i] == -1)
		{
			printf("%*s", longest_digits, "-");
		}
		else
		{
			printf("%*d", longest_digits, arr_ptr[i]);
		}
		if (pos == 1)
		{
			printf("\n");
		}
		pos--;
	}
	printf("\n\n");
}

//交换元素
void Swap(Heap* ptr, size_t x, size_t y)
{
	assert(ptr);
	ElemType tmp = ptr->array_ptr[x];
	ptr->array_ptr[x] = ptr->array_ptr[y];
	ptr->array_ptr[y] = tmp;
}

//适用于小根堆的向上调整函数
void Insert_Min_Heap(Heap* ptr, size_t index, size_t size)
{
	assert(ptr && size != 0);
	size_t father = index == 0 ? 0 : (index - 1) / 2;
	while (ptr->array_ptr[index] < ptr->array_ptr[father])
	{
		Swap(ptr, index, father);
		index = father;
		father = index == 0 ? 0 : (index - 1) / 2;
	}
}

//适用于小根堆的向下调整函数
void Ify_Min_Heap(Heap* ptr, size_t index, size_t size)
{
	assert(ptr && size != 0);
	size_t left = index * 2 + 1;
	while (left < size)
	{
		size_t smallest = left + 1 < size && ptr->array_ptr[left + 1] < ptr->array_ptr[left] ? left + 1 : left;
		smallest = ptr->array_ptr[smallest] < ptr->array_ptr[index] ? smallest : index;
		if (smallest == index)
		{
			break;
		}
		Swap(ptr, index, smallest);
		index = smallest;
		left = index * 2 + 1;
	}
}

//适用于大根堆的向上调整函数
void Insert_Max_Heap(Heap* ptr, size_t index, size_t size)
{
	assert(ptr && size != 0);
	size_t father = index == 0 ? 0 : (index - 1) / 2;
	while (ptr->array_ptr[index] > ptr->array_ptr[father])
	{
		Swap(ptr, index, father);
		index = father;
		father = index == 0 ? 0 : (index - 1) / 2;
	}
}

//适用于大根堆的向下调整函数
void Ify_Max_Heap(Heap* ptr, size_t index, size_t size)
{
	assert(ptr && size != 0);
	size_t left = index * 2 + 1;
	while (left < size)
	{
		size_t largest = left + 1 < size && ptr->array_ptr[left + 1] > ptr->array_ptr[left] ? left + 1 : left;
		largest = ptr->array_ptr[largest] > ptr->array_ptr[index] ? largest : index;
		if (largest == index)
		{
			break;
		}
		Swap(ptr, index, largest);
		index = largest;
		left = index * 2 + 1;
	}
}

//插入元素到堆中
void Push_Heap(Heap* ptr, ElemType data, void (* Adjustment)(Heap*, size_t, size_t))
{
	assert(ptr);
	Check_Heap(ptr);
	ptr->array_ptr[ptr->size] = data;
	Adjustment(ptr, ptr->size++, ptr->size);
}

//删除堆顶元素
ElemType Pop_Heap(Heap* ptr, void (* Adjustment)(Heap*, size_t, size_t))
{
	assert(ptr);
	assert(!Empty_Heap(ptr));
	ElemType ans = ptr->array_ptr[0];
	Swap(ptr, 0, --ptr->size);
	Adjustment(ptr, 0, ptr->size);
	return ans;
}

//获取堆顶元素数据
ElemType Top_Heap(Heap* ptr)
{
	assert(ptr);
	assert(!Empty_Heap(ptr));
	return ptr->array_ptr[0];
}

//堆排序
void Sort_Heap(Heap* ptr, size_t size)
{
	assert(ptr);
	if (size < 2)
		return;
	for (int i = ((int)size) - 1; i >= 0; --i)
	{
		Ify_Max_Heap(ptr, i, size);
	}
	size_t heapSize = size;
	Swap(ptr, 0, --heapSize);
	while (heapSize > 0)
	{
		Ify_Max_Heap(ptr, 0, heapSize);
		Swap(ptr, 0, --heapSize);
	}
}

//判断堆是否为空堆
bool Empty_Heap(Heap* ptr)
{
	assert(ptr);
	return ptr->size == 0;
}

//获取堆中的元素个数
size_t Size_Heap(Heap* ptr)
{
	assert(ptr);
	return ptr->size;
}

//销毁堆
void Destroy_Heap(Heap* ptr)
{
	assert(ptr);
	free(ptr->array_ptr);
	ptr->array_ptr = NULL;
	ptr->size = ptr->capacity = 0;
}