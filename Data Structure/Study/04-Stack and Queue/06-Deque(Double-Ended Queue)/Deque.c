#include "Deque.h"

//初始化双端队列
void Init_Deque(Deque* ptr)
{
	assert(ptr);
	ptr->size = 0;
	ptr->head = ptr->tail = NULL;
}

//创建一个双端队列节点
DequeNode* Create_DequeNode(DequeDataType data)
{
	DequeNode* newNode = (DequeNode*)malloc(sizeof(DequeNode));
	if (newNode == NULL)
	{
		perror("Create_DequeNode");
		exit(EXIT_FAILURE);
	}
	newNode->data = data;
	newNode->prev = newNode->next = NULL;
	return newNode;
}

//向双端队列的首端插入元素
void Push_Front_Deque(Deque* ptr, DequeDataType data)
{
	assert(ptr);
	DequeNode* newNode = Create_DequeNode(data);
	if (ptr->head == NULL)
	{
		ptr->head = ptr->tail = newNode;
	}
	else
	{
		newNode->next = ptr->head;
		ptr->head->prev = newNode;
		ptr->head = newNode;
	}
	++ptr->size;
}

//向双端队列的尾部插入元素
void Push_Back_Deque(Deque* ptr, DequeDataType data)
{
	assert(ptr);
	DequeNode* newNode = Create_DequeNode(data);
	if (ptr->head == NULL)
	{
		ptr->head = ptr->tail = newNode;
	}
	else
	{
		ptr->tail->next = newNode;
		newNode->prev = ptr->tail;
		ptr->tail = ptr->tail->next;
	}
	++ptr->size;
}

//从双端队列首端弹出元素
DequeDataType Pop_Front_Deque(Deque* ptr)
{
	assert(ptr);
	assert(!Empty_Deque(ptr));
	DequeDataType ans = ptr->head->data;
	if (ptr->head->next == NULL)
	{
		free(ptr->head);
		ptr->head = ptr->tail = NULL;
	}
	else
	{
		ptr->head = ptr->head->next;
		free(ptr->head->prev);
		ptr->head->prev = NULL;
	}
	--ptr->size;
	return ans;
}

//从双端队列尾部弹出元素
DequeDataType Pop_Back_Deque(Deque* ptr)
{
	assert(ptr);
	assert(!Empty_Deque(ptr));
	DequeDataType ans = ptr->tail->data;
	if (ptr->tail->prev == NULL)
	{
		free(ptr->tail);
		ptr->head = ptr->tail = NULL;
	}
	else
	{
		ptr->tail = ptr->tail->prev;
		free(ptr->tail->next);
		ptr->tail->next = NULL;
	}
	--ptr->size;
	return ans;
}

//获取双端队列的首端元素数据
DequeDataType Front_Deque(Deque* ptr)
{
	assert(ptr);
	assert(!Empty_Deque(ptr));
	return ptr->head->data;
}

//获取双端队列的尾部元素数据
DequeDataType Back_Deque(Deque* ptr)
{
	assert(ptr);
	assert(!Empty_Deque(ptr));
	return ptr->tail->data;
}

//检查双端队列是否为空
bool Empty_Deque(Deque* ptr)
{
	assert(ptr);
	return ptr->size == 0;
}

//获取双端队列中的元素个数
size_t Size_Deque(Deque* ptr)
{
	assert(ptr);
	return ptr->size;
}

//销毁双端队列
void Destroy_Queue(Deque* ptr)
{
	assert(ptr);
	DequeNode* cur = ptr->head;
	while (cur != NULL)
	{
		DequeNode* next = cur->next;
		free(cur);
		cur = next;
	}
}