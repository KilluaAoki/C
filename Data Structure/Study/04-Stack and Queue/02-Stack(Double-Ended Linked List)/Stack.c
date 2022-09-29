#include "Stack.h"

//初始化栈
void Init_Stack(Stack* ptr)
{
	assert(ptr);
	ptr->size = 0;
	ptr->head = ptr->tail = NULL;
}

//将一个元素压入栈中
void Push_Stack(Stack* ptr, ElemType data)
{
	assert(ptr);
	StackNode* newNode = (StackNode*)malloc(sizeof(StackNode));
	if (newNode == NULL)
	{
		perror("Push_Stack");
		exit(EXIT_FAILURE);
	}
	newNode->data = data;
	newNode->prev = newNode->next = NULL;
	if (ptr->head == NULL)
	{
		ptr->head = ptr->tail = newNode;
	}
	else
	{
		ptr->head->prev = newNode;
		newNode->next = ptr->head;
		ptr->head = newNode;
	}
	++ptr->size;
}

//将一个元素从栈中弹出
ElemType Pop_Stack(Stack* ptr)
{
	assert(ptr);
	assert(!Empty_Stack(ptr));
	ElemType ans = ptr->head->data;
	if (ptr->head == ptr->tail)
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

//获取栈的栈顶元素数据
ElemType Top_Stack(Stack* ptr)
{
	assert(ptr);
	return ptr->head->data;
}

//判断栈是否为空栈
bool Empty_Stack(Stack* ptr)
{
	assert(ptr);
	return ptr->size == 0;
}

//获取栈中的元素个数
size_t Size_Stack(Stack* ptr)
{
	assert(ptr);
	return ptr->size;
}

//销毁栈
void Destroy_Stack(Stack* ptr)
{
	assert(ptr);
	while (ptr->head)
	{
		if (ptr->head->next == NULL)
		{
			free(ptr->head);
			break;
		}
		ptr->head = ptr->head->next;
		free(ptr->head->prev);
	}
	ptr->head = ptr->tail = NULL;
}