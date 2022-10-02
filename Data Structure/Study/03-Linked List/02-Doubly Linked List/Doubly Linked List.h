#pragma once

//引用头文件
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

//重命名双向链表数据元素类型
typedef int DLLDataType;

//定义结构体类型(带头双向循环链表)
typedef struct DoublyLinkedListNode
{
	DLLDataType data;
	struct DoublyLinkedListNode* prev;
	struct DoublyLinkedListNode* next;
} DLLNode;

//初识化双向链表
DLLNode* Init_DoublyLinkedListNode();

//创建一个双向链表节点
DLLNode* Create_DoublyLinkedListNode(DLLDataType data);

//打印双向链表
void Print_DoublyLinkedList(DLLNode* phead);

//在双向链表的首位置插入节点(头插)
void Head_Insert_DoublyLinkedListNode(DLLNode* phead, DLLDataType data);

//在双向链表的末位置插入节点(尾插)
void Tail_Insert_DoublyLinkedListNode(DLLNode* phead, DLLDataType data);

//删除双向链表的首位置节点(头删)
void Head_Delete_DoublyLinkedListNode(DLLNode* phead);

//删除双向链表的末位置节点(尾删)
void Tail_Delete_DoublyLinkedListNode(DLLNode* phead);

//查找双向链表数据元素的节点地址
DLLNode* Search_DoublyLinkedListNode(DLLNode* phead, DLLDataType data);

//在双向链表节点之前插入新节点
void Insert_DoublyLinkedListNode(DLLNode* phead, DLLNode* pos, DLLDataType data);

//删除当前双向链表节点
void Erase_DoublyLinkedList(DLLNode* pos);

//判断双向链表是否为空表
bool Empty_DoublyLinkedList(DLLNode* phead);

//获取双向链表的长度
size_t Length_DoublyLinkedList(DLLNode* phead);

//销毁双向链表
void Destroy_DoublyLinkedList(DLLNode* phead);