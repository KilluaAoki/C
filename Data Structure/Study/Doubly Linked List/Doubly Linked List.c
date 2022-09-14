#include "Doubly Linked List.h"

//初识化双向链表
DLLNode* Init_DoublyLinkedListNode()
{
	DLLNode* guard = (DLLNode*)malloc(sizeof(DLLNode));
	guard->prev = guard;
	guard->next = guard;
	return guard;
}

//创建一个双向链表节点
DLLNode* Create_DoublyLinkedListNode(DLLDataType data)
{
	DLLNode* newNode = (DLLNode*)malloc(sizeof(DLLNode));
	newNode->data = data;
	newNode->prev = newNode;
	newNode->next = newNode;
	return newNode;
}

//打印双向链表
void Print_DoublyLinkedList(DLLNode* phead)
{
	assert(phead);
	if (Empty_DoublyLinkedList(phead))
	{
		printf("-->guard<--\n");
		return;
	}
	DLLNode* cur = phead->next;
	printf("guard-->( ");
	while (cur != phead)
	{
		if (cur->next == phead)
		{
			printf("%d", cur->data);
			break;
		}
		printf("%d < = > ", cur->data);
		cur = cur->next;
	}
	printf(" )-->guard\n");
	cur = phead->prev;
	printf("guard<--( ");
	while (cur != phead)
	{
		if (cur->prev == phead)
		{
			printf("%d", cur->data);
			break;
		}
		printf("%d < = > ", cur->data);
		cur = cur->prev;
	}
	printf(" )<--guard\n");
}

//在双向链表的首位置插入节点(头插)
void Head_Insert_DoublyLinkedListNode(DLLNode* phead, DLLDataType data)
{
	assert(phead);
	DLLNode* newNode = Create_DoublyLinkedListNode(data);
	newNode->prev = phead;
	newNode->next = phead->next;
	phead->next->prev = newNode;
	phead->next = newNode;
}

//在双向链表的末位置插入节点(尾插)
void Tail_Insert_DoublyLinkedListNode(DLLNode* phead, DLLDataType data)
{
	assert(phead);
	DLLNode* newNode = Create_DoublyLinkedListNode(data);
	newNode->next = phead;
	newNode->prev = phead->prev;
	phead->prev->next = newNode;
	phead->prev = newNode;
}

//删除双向链表的首位置节点(头删)
void Head_Delete_DoublyLinkedListNode(DLLNode* phead)
{
	assert(phead);
	assert(!Empty_DoublyLinkedList(phead));
	DLLNode* del = phead->next;
	phead->next->next->prev = phead;
	phead->next = phead->next->next;
	free(del);
}

//删除双向链表的末位置节点(尾删)
void Tail_Delete_DoublyLinkedListNode(DLLNode* phead)
{
	assert(phead);
	assert(!Empty_DoublyLinkedList(phead));
	DLLNode* del = phead->prev;
	phead->prev->prev->next = phead;
	phead->prev = phead->prev->prev;
	free(del);
}

//查找双向链表数据元素的节点地址
DLLNode* Search_DoublyLinkedListNode(DLLNode* phead, DLLDataType data)
{
	assert(phead);
	DLLNode* cur = phead->next;
	while (cur != phead)
	{
		if (cur->data == data)
		{
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}

//在双向链表节点之前插入新节点
void Insert_DoublyLinkedListNode(DLLNode* phead, DLLNode* pos, DLLDataType data)
{
	assert(phead);
	assert(pos);
	DLLNode* newNode = Create_DoublyLinkedListNode(data);
	newNode->next = pos;
	newNode->prev = pos->prev;
	pos->prev->next = newNode;
	pos->prev = newNode;
}

//删除当前双向链表节点
void Erase_DoublyLinkedList(DLLNode* pos)
{
	assert(pos);
	pos->prev->next = pos->next;
	pos->next->prev = pos->prev;
	free(pos);
}

//判断双向链表是否为空表
bool Empty_DoublyLinkedList(DLLNode* phead)
{
	assert(phead);
	return phead->next == phead;
}

//获取双向链表的长度
size_t Length_DoublyLinkedList(DLLNode* phead)
{
	assert(phead);
	size_t count = 0;
	DLLNode* cur = phead->next;
	while (cur != phead)
	{
		++count;
		cur = cur->next;
	}
	return count;
}

//销毁双向链表
void Destroy_DoublyLinkedList(DLLNode* phead)
{
	assert(phead);
	DLLNode* cur = phead->next;
	while (cur != phead)
	{
		DLLNode* next = cur->next;
		free(cur);
		cur = next;
	}
	free(phead);
}