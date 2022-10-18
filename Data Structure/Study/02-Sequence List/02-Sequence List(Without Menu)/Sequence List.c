#include "Sequence List.h"

//初始化顺序表
void Init_SequenceList(SeqList* ptr)
{
	assert(ptr);
	ptr->array_ptr = NULL;
	ptr->capacity = ptr->size = 0;
}

//打印顺序表
void Print_SequenceList(SeqList* ptr)
{
	assert(ptr);
	assert(ptr->size);
	for (size_t i = 0; i < ptr->size; ++i)
	{
		printf("%d ", ptr->array_ptr[i]);
	}
	printf("\n");
}

//清除顺序表
void Remove_SequenceList(SeqList* ptr)
{
	assert(ptr);
	free(ptr->array_ptr);
	ptr->array_ptr = NULL;
	ptr->capacity = ptr->size = 0;
}

//检查容量
void Check_SequenceList(SeqList* ptr)
{
	assert(ptr);
	if (ptr->size == ptr->capacity)
	{
		size_t newCapacity = ptr->capacity == 0 ? DEFAULT_SIZE : ptr->capacity + EXPAND_SIZE;
		SeqListType* tmp = (SeqListType*)realloc(ptr->array_ptr, sizeof(SeqListType) * newCapacity);
		if (tmp == NULL)
		{
			perror("Check_SequenceList");
			exit(EXIT_FAILURE);
		}
		ptr->array_ptr = tmp;
		ptr->capacity = newCapacity;
	}
}

//查找顺序表数据元素的位置
size_t Search_SequenceList(SeqList* ptr, SeqListType data)
{
	assert(ptr);
	assert(ptr->size);
	for (size_t i = 0; i < ptr->size; ++i)
	{
		if (ptr->array_ptr[i] == data)
			return i;
	}
	return -1;
}

//修改顺序表数据元素
void Modify_SequenceList(SeqList* ptr, size_t pos, SeqListType data)
{
	assert(ptr);
	assert(pos < ptr->size);
	ptr->array_ptr[pos] = data;
}

//在顺序表的首位置插入数据元素(头插)
void Head_Insert_SequenceList(SeqList* ptr, SeqListType data)
{
	assert(ptr);
	Check_SequenceList(ptr);
	for (size_t i = ptr->size; i > 0; --i)
	{
		ptr->array_ptr[i] = ptr->array_ptr[i - 1];
	}
	ptr->array_ptr[0] = data;
	++ptr->size;
}

//在顺序表的末位置插入数据元素(尾插)
void Tail_Insert_SequenceList(SeqList* ptr, SeqListType data)
{
	assert(ptr);
	Check_SequenceList(ptr);
	ptr->array_ptr[ptr->size] = data;
	++ptr->size;
}

//在顺序表的首位置删除数据元素(头删)
void Head_Delete_SequenceList(SeqList* ptr)
{
	assert(ptr);
	assert(ptr->size);
	for (size_t i = 0; i < ptr->size - 1; ++i)
	{
		ptr->array_ptr[i] = ptr->array_ptr[i + 1];
	}
	--ptr->size;
}

//在顺序表的末位置删除数据元素(尾删)
void Tail_Delete_SequenceList(SeqList* ptr)
{
	assert(ptr);
	assert(ptr->size);
	--ptr->size;
}

//在顺序表的任意位置插入数据元素
void Insert_SequenceList(SeqList* ptr, size_t pos, SeqListType data)
{
	assert(ptr);
	assert(pos <= ptr->size);
	Check_SequenceList(ptr);
	for (size_t i = ptr->size; i > pos; --i)
	{
		ptr->array_ptr[i] = ptr->array_ptr[i - 1];
	}
	ptr->array_ptr[pos] = data;
	++ptr->size;
}

//在顺序表的任意位置删除数据元素
void Delete_SequenceList(SeqList* ptr, size_t pos)
{
	assert(ptr);
	assert(pos < ptr->size);
	for (size_t i = pos; i < ptr->size - 1; ++i)
	{
		ptr->array_ptr[i] = ptr->array_ptr[i + 1];
	}
	--ptr->size;
}