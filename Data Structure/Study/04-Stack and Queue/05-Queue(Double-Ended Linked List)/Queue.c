#include "Queue.h"

//初始化队列
void Init_Queue(Queue* ptr)
{
	assert(ptr);
	ptr->head = ptr->tail = NULL;
	ptr->size = 0;
}

//向队列尾部插入元素
void Push_Queue(Queue* ptr, QueueType data)
{
	assert(ptr);
	QueueNode* newNode = (QueueNode*)malloc(sizeof(QueueNode));
	if (newNode == NULL)
	{
		perror("Push_Queue");
		exit(EXIT_FAILURE);
	}
	else
	{
		newNode->data = data;
		newNode->next = NULL;
	}
	if (ptr->head == NULL && ptr->tail == NULL)
	{
		ptr->head = ptr->tail = newNode;
	}
	else
	{
		ptr->tail->next = newNode;
		ptr->tail = newNode;
	}
	++ptr->size;
}

//从首端弹出元素
void Pop_Queue(Queue* ptr)
{
	assert(ptr);
	assert(!Empty_Queue(ptr));
	if (ptr->head->next == NULL)
	{
		free(ptr->head);
		ptr->head = ptr->tail = NULL;
	}
	else
	{
		QueueNode* del = ptr->head;
		ptr->head = ptr->head->next;
		free(del);
	}
	--ptr->size;
}

//获取队列的首端元素数据
QueueType Front_Queue(Queue* ptr)
{
	assert(ptr);
	assert(!Empty_Queue(ptr));
	return ptr->head->data;
}

//获取队列的尾部元素数据
QueueType Back_Queue(Queue* ptr)
{
	assert(ptr);
	assert(!Empty_Queue(ptr));
	return ptr->tail->data;
}

//判断队列是否为空队列
bool Empty_Queue(Queue* ptr)
{
	assert(ptr);
	return ((ptr->head == NULL) && (ptr->tail == NULL));
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
	QueueNode* cur = ptr->head;
	while (cur != NULL)
	{
		QueueNode* del = cur;
		cur = cur->next;
		free(del);
	}
	ptr->head = ptr->tail = NULL;
}