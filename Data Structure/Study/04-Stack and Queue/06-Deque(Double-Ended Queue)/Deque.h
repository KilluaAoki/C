#pragma once

//引用头文件
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

//重命名双端队列数据元素类型
typedef int DequeDataType;

//定义结构体类型(双端队列节点(双向链表节点))
typedef struct DequeNode
{
	DequeDataType data;
	struct DequeNode* prev;
	struct DequeNode* next;
} DequeNode;

//定义结构体类型(双端链表实现双端队列)
typedef struct Deque
{
	size_t size;
	DequeNode* head;
	DequeNode* tail;
} Deque;

//初始化双端队列
void Init_Deque(Deque* ptr);

//创建一个双端队列节点
DequeNode* Create_DequeNode(DequeDataType data);

//向双端队列的首端插入元素
void Push_Front_Deque(Deque* ptr, DequeDataType data);

//向双端队列的尾部插入元素
void Push_Back_Deque(Deque* ptr, DequeDataType data);

//从双端队列首端弹出元素
DequeDataType Pop_Front_Deque(Deque* ptr);

//从双端队列尾部弹出元素
DequeDataType Pop_Back_Deque(Deque* ptr);

//获取双端队列的首端元素数据
DequeDataType Front_Deque(Deque* ptr);

//获取双端队列的尾部元素数据
DequeDataType Back_Deque(Deque* ptr);

//检查双端队列是否为空
bool Empty_Deque(Deque* ptr);

//获取双端队列中的元素个数
size_t Size_Deque(Deque* ptr);

//销毁双端队列
void Destroy_Queue(Deque* ptr);