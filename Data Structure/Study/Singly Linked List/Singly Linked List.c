#include "Singly Linked List.h"

//创建一个单链表节点
SLLNode* Create_SinglyLinkedListNode(SLLDataType data)
{
	SLLNode* ptr = (SLLNode*)malloc(sizeof(SLLDataType));
	if (ptr == NULL)
	{
		perror("malloc");
		exit(errno);
	}
	ptr->data = data;
	ptr->next = NULL;
	return ptr;
}

//打印单链表
void Print_SinglyLinkedList(SLLNode* phead)
{
	SLLNode* cur = phead;
	while (cur != NULL)
	{
		printf("%d->", cur->data);
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
	if (*pphead == NULL)
	{
		printf("当前单链表无数据元素。\n");
		return;
	}
	else
	{
		SLLNode* cur = (*pphead)->next;
		free(*pphead);
		*pphead = cur;
	}
}

//删除单链表的末位置节点(尾删)
void Tail_Delete_SinglyLinkedListNode(SLLNode** pphead)
{
	assert(pphead);
	if (*pphead == NULL)
	{
		printf("当前单链表无数据元素。\n");
		return;
	}
	if ((*pphead)->next == NULL)
	{
		free((*pphead));
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
	while (cur)
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
	if (*pphead == pos)
	{
		newNode->next = pos;
		*pphead = newNode;
	}
	else
	{
		SLLNode* prev = *pphead;
		while (prev->next != pos)
		{
			prev = prev->next;
		}
		newNode->next = pos;
		prev->next = newNode;
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
	if ((*pphead) == pos)
	{
		SLLNode* cur = (*pphead)->next;
		free(*pphead);
		*pphead = cur;
	}
	else
	{
		SLLNode* prev = *pphead;
		while (prev->next != pos)
		{
			prev = prev->next;
		}
		prev->next = pos->next;
		free(pos);
	}
}

//删除当前单链表节点的前一个节点
void Before_Erase_SinglyLinkedListNode(SLLNode** pphead, SLLNode* pos)
{
	assert(pphead);
	assert(pos);
	if (*pphead == pos)
	{
		return;
	}
	SLLNode* del = *pphead;
	while (del->next != pos)
	{
		del = del->next;
	}
	*pphead = pos;
	free(del);
}

//删除当前单链表节点的后一个节点
void After_Erase_SinglyLinkedListNode(SLLNode* pos)
{
	assert(pos);
	if (pos->next == NULL)
	{
		return;
	}
	SLLNode* del = pos->next;
	pos->next = pos->next->next;
	free(del);
}

//获取单链表的长度
int Length_SinglyLinkedList(SLLNode* phead)
{
	int len = 0;
	SLLNode* cur = phead;
	while (cur)
	{
		len++;
		cur = cur->next;
	}
	return len;
}

//销毁单链表
void Destroy_SinglyLinkedListNode(SLLNode** pphead)
{
	assert(pphead);
	SLLNode* cur = *pphead;
	while (cur)
	{
		SLLNode* next = cur->next;
		free(cur);
		cur = next;
	}
	*pphead = NULL;
}