#pragma once

//引用头文件
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

//定义标识符
#define LIMIT_SIZE 5

//重命名队列数据元素类型
typedef int ElemType;

//定义结构体类型(循环数组实现队列(此实现限定了可用空间的大小))
typedef struct Queue
{
	ElemType* array_ptr;
	size_t push_index;
	size_t pop_index;
	size_t size;
	size_t capacity;
} Queue;

//初始化队列
void Init_Queue(Queue* ptr);

//获取下一个位置
size_t NextIndex(size_t index);

//向队列尾部插入元素
void Push_Queue(Queue* ptr, ElemType data);

//从首端弹出元素
ElemType Pop_Queue(Queue* ptr);

//获取队列的首端元素数据
ElemType Front_Queue(Queue* ptr);

//获取队列的尾部元素数据
ElemType Back_Queue(Queue* ptr);

//判断队列是否为空队列
bool Empty_Queue(Queue* ptr);

//判断队列是否为满队列
bool Full_Queue(Queue* ptr);

//获取队列中的元素个数
size_t Size_Queue(Queue* ptr);

//销毁队列
void Destroy_Queue(Queue* ptr);