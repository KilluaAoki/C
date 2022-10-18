#include "Queue.h"

//初始化队列
void Init_Queue(Queue* ptr)
{
	assert(ptr);
	ptr->capacity = LIMIT_SIZE;
	ptr->array_ptr = (QueueType*)malloc(sizeof(QueueType) * ptr->capacity);
	if (ptr->array_ptr == NULL)
	{
		perror("Init_Queue");
		exit(EXIT_FAILURE);
	}
	ptr->push_index = ptr->pop_index = ptr->size = 0;
}

//获取下一个位置
size_t NextIndex(size_t index)
{
	return index < LIMIT_SIZE - 1 ? index + 1 : 0;
}

//向队列尾部插入元素
void Push_Queue(Queue* ptr, QueueType data)
{
	assert(ptr);
	assert(!Full_Queue(ptr));
	++ptr->size;
	ptr->array_ptr[ptr->push_index] = data;
	ptr->push_index = NextIndex(ptr->push_index);
}

//从首端弹出元素
QueueType Pop_Queue(Queue* ptr)
{
	assert(ptr);
	assert(!Empty_Queue(ptr));
	--ptr->size;
	QueueType ans = ptr->array_ptr[ptr->pop_index];
	ptr->pop_index = NextIndex(ptr->pop_index);
	return ans;
}

//获取队列的首端元素数据
QueueType Front_Queue(Queue* ptr)
{
	assert(ptr);
	assert(!Empty_Queue(ptr));
	return ptr->array_ptr[ptr->pop_index];
}

//获取队列的尾部元素数据
QueueType Back_Queue(Queue* ptr)
{
	assert(ptr);
	assert(!Empty_Queue(ptr));
	if (ptr->push_index == 0)
	{
		return ptr->array_ptr[ptr->capacity - 1];
	}
	return ptr->array_ptr[ptr->push_index - 1];
}

//判断队列是否为空队列
bool Empty_Queue(Queue* ptr)
{
	assert(ptr);
	return ptr->size == 0;
}

//判断队列是否为满队列
bool Full_Queue(Queue* ptr)
{
	assert(ptr);
	return ptr->size == ptr->capacity;
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
	ptr->array_ptr = NULL;
	ptr->capacity = LIMIT_SIZE;
	ptr->push_index = ptr->pop_index = ptr->size = 0;
}