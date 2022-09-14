#pragma once

//引用头文件
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//重命名单链表数据元素类型
typedef int SLLDataType;

//定义结构体类型(无头单向非循环链表)
typedef struct SinglyLinkedListNode
{
	SLLDataType data;
	struct SinglyLinkedListNode* next;
} SLLNode;

//创建一个单链表节点
SLLNode* Create_SinglyLinkedListNode(SLLDataType data);

//打印单链表
void Print_SinglyLinkedList(SLLNode* phead);

//在单链表的首位置插入节点(头插)
void Head_Insert_SinglyLinkedListNode(SLLNode** pphead, SLLDataType data);

//在单链表的末位置插入节点(尾插)
void Tail_Insert_SinglyLinkedListNode(SLLNode** pphead, SLLDataType data);

//删除单链表的首位置节点(头删)
void Head_Delete_SinglyLinkedListNode(SLLNode** pphead);

//删除单链表的末位置节点(尾删)
void Tail_Delete_SinglyLinkedListNode(SLLNode** pphead);

//查找单链表数据元素的节点地址
SLLNode* Search_SinglyLinkedListNode(SLLNode* phead, SLLDataType data);

//在单链表节点之前插入新节点
void Before_Insert_SinglyLinkedListNode(SLLNode** pphead, SLLNode* pos, SLLDataType data);

//在单链表节点之后插入新节点
void After_Insert_SinglyLinkedListNode(SLLNode* pos, SLLDataType data);

//删除当前单链表节点
void Erase_SinglyLinkedListNode(SLLNode** pphead, SLLNode* pos);

//删除当前单链表节点的前一个节点
void Before_Erase_SinglyLinkedListNode(SLLNode** pphead, SLLNode* pos);

//删除当前单链表节点的后一个节点
void After_Erase_SinglyLinkedListNode(SLLNode* pos);

//获取单链表的长度
size_t Length_SinglyLinkedList(SLLNode* phead);

//销毁单链表
void Destroy_SinglyLinkedList(SLLNode** pphead);