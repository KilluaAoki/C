#include "Queue.h"

//初始化队列
void Init_Queue(Queue* ptr)
{
	assert(ptr);
	ptr->array_ptr = NULL;
	ptr->push_index = ptr->pop_index = ptr->size = ptr->capacity = ptr->capacity_count = 0;
}

//向队列尾部插入元素
void Push_Queue(Queue* ptr, ElemType data)
{
	assert(ptr);
	if (ptr->capacity_count == ptr->capacity)
	{
		ptr->capacity = ptr->capacity == 0 ? 4 : ptr->capacity * 2;
		ElemType* tmp = (ElemType*)realloc(ptr->array_ptr, sizeof(ElemType) * ptr->capacity);
		if (tmp == NULL)
		{
			perror("Push_Queue");
			exit(EXIT_FAILURE);
		}
		ptr->array_ptr = tmp;
	}
	ptr->array_ptr[ptr->push_index++] = data;
	++ptr->size;
	++ptr->capacity_count;
}

//从首端弹出元素
ElemType Pop_Queue(Queue* ptr)
{
	assert(ptr);
	assert(!Empty_Queue(ptr));
	--ptr->size;
	return ptr->array_ptr[ptr->pop_index++];
}

//获取队列的首端元素数据
ElemType Front_Queue(Queue* ptr)
{
	assert(ptr);
	assert(!Empty_Queue(ptr));
	return ptr->array_ptr[ptr->pop_index];
}

//获取队列的尾部元素数据
ElemType Back_Queue(Queue* ptr)
{
	assert(ptr);
	assert(!Empty_Queue(ptr));
	return ptr->array_ptr[ptr->push_index - 1];
}

//判断队列是否为空队列
bool Empty_Queue(Queue* ptr)
{
	assert(ptr);
	return ptr->size == 0;
}

//获取队列中的元素个数
size_t Size_Queue(Queue* ptr)
{
	assert(ptr);
	return ptr->size;
}

//销毁队列
void Destroy_Queue(Queue* ptr)
{
	assert(ptr);
	free(ptr->array_ptr);
	ptr->push_index = ptr->pop_index = ptr->size = ptr->capacity = ptr->capacity_count = 0;
}