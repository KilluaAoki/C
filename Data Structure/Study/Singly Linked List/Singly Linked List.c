#include "Singly Linked List.h"

//创建一个单链表节点
SLLNode* Create_SinglyLinkedListNode(SLLDataType data)
{
	SLLNode* newNode = (SLLNode*)malloc(sizeof(SLLNode));
	if (newNode == NULL)
	{
		perror("Create_SinglyLinkedListNode");
		exit(EXIT_FAILURE);
	}
	newNode->data = data;
	newNode->next = NULL;
	return newNode;
}

//打印单链表
void Print_SinglyLinkedList(SLLNode* phead)
{
	SLLNode* cur = phead;
	while (cur != NULL)
	{
		printf("%d -> ", cur->data);
		cur = cur->next;
	}
	printf("NULL\n");
}

//在单链表的首位置插入节点(头插)
void Head_Insert_SinglyLinkedListNode(SLLNode** pphead, SLLDataType data)
{
	assert(pphead);
	SLLNode* newNode = Create_SinglyLinkedListNode(data);
	newNode->next = *pphead;
	*pphead = newNode;
}

//在单链表的末位置插入节点(尾插)
void Tail_Insert_SinglyLinkedListNode(SLLNode** pphead, SLLDataType data)
{
	assert(pphead);
	SLLNode* newNode = Create_SinglyLinkedListNode(data);
	if (*pphead == NULL)
	{
		*pphead = newNode;
	}
	else
	{
		SLLNode* cur = *pphead;
		while (cur->next != NULL)
		{
			cur = cur->next;
		}
		cur->next = newNode;
	}
}

//删除单链表的首位置节点(头删)
void Head_Delete_SinglyLinkedListNode(SLLNode** pphead)
{
	assert(pphead);
	assert(*pphead);
	SLLNode* next = (*pphead)->next;
	free(*pphead);
	*pphead = next;
}

//删除单链表的末位置节点(尾删)
void Tail_Delete_SinglyLinkedListNode(SLLNode** pphead)
{
	assert(pphead);
	assert(*pphead);
	if ((*pphead)->next == NULL)
	{
		free(*pphead);
		*pphead = NULL;
	}
	else
	{
		SLLNode* cur = *pphead;
		while (cur->next->next != NULL)
		{
			cur = cur->next;
		}
		free(cur->next);
		cur->next = NULL;
	}
}

//查找单链表数据元素的节点地址
SLLNode* Search_SinglyLinkedListNode(SLLNode* phead, SLLDataType data)
{
	SLLNode* cur = phead;
	while (cur != NULL)
	{
		if (cur->data == data)
		{
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}

//在单链表节点之前插入新节点
void Before_Insert_SinglyLinkedListNode(SLLNode** pphead, SLLNode* pos, SLLDataType data)
{
	assert(pphead);
	assert(pos);
	SLLNode* newNode = Create_SinglyLinkedListNode(data);
	if (pos == *pphead)
	{
		newNode->next = *pphead;
		*pphead = newNode;
	}
	else
	{
		SLLNode* cur = *pphead;
		while (cur->next != pos)
		{
			cur = cur->next;
			assert(cur);
		}
		newNode->next = pos;
		cur->next = newNode;
	}
}

//在单链表节点之后插入新节点
void After_Insert_SinglyLinkedListNode(SLLNode* pos, SLLDataType data)
{
	assert(pos);
	SLLNode* newNode = Create_SinglyLinkedListNode(data);
	newNode->next = pos->next;
	pos->next = newNode;
}

//删除当前单链表节点
void Erase_SinglyLinkedListNode(SLLNode** pphead, SLLNode* pos)
{
	assert(pphead);
	assert(pos);
	if (pos == *pphead)
	{
		SLLNode* next = pos->next;
		free(pos);
		*pphead = next;
	}
	else
	{
		SLLNode* cur = *pphead;
		while (cur->next != pos)
		{
			cur = cur->next;
		}
		cur->next = pos->next;
		free(pos);
	}
}

//删除当前单链表节点的前一个节点
void Before_Erase_SinglyLinkedListNode(SLLNode** pphead, SLLNode* pos)
{
	assert(pphead);
	assert(pos);
	assert(*pphead && pos != *pphead);
	if (pos == (*pphead)->next)
	{
		free(*pphead);
		*pphead = pos;
	}
	else
	{
		SLLNode* cur = *pphead;
		while (cur->next->next != pos)
		{
			cur = cur->next;
			assert(cur->next);
		}
		free(cur->next);
		cur->next = pos;
	}
}

//删除当前单链表节点的后一个节点
void After_Erase_SinglyLinkedListNode(SLLNode* pos)
{
	assert(pos);
	assert(pos->next);
	SLLNode* next = pos->next->next;
	free(pos->next);
	pos->next = next;
}

//获取单链表长度
size_t Length_SinglyLinkedList(SLLNode* phead)
{
	size_t count = 0;
	SLLNode* cur = phead;
	while (cur != NULL)
	{
		++count;
		cur = cur->next;
	}
	return count;
}

//销毁单链表
void Destroy_SinglyLinkedList(SLLNode** pphead)
{
	assert(pphead);
	SLLNode* cur = *pphead;
	while (cur != NULL)
	{
		SLLNode* next = cur->next;
		free(cur);
		cur = next;
	}
	*pphead = NULL;
}