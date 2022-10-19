#pragma once

//引用头文件
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

//重命名队列数据元素类型
typedef int QueueDataType;

//定义结构体类型(数组实现队列(此实现会造成空间浪费，可移动元素规避(效率低)，也可使用循环数组规避，但其限定了可用空间的大小))
typedef struct Queue
{
	QueueDataType* array_ptr;
	size_t push_index;
	size_t pop_index;
	size_t size;
	size_t capacity;
	size_t capacity_count;
} Queue;

//初始化队列
void Init_Queue(Queue* ptr);

//向队列尾部插入元素
void Push_Queue(Queue* ptr, QueueDataType data);

//从首端弹出元素
QueueDataType Pop_Queue(Queue* ptr);

//获取队列的首端元素数据
QueueDataType Front_Queue(Queue* ptr);

//获取队列的尾部元素数据
QueueDataType Back_Queue(Queue* ptr);

//判断队列是否为空队列
bool Empty_Queue(Queue* ptr);

//获取队列中的元素个数
size_t Size_Queue(Queue* ptr);

//销毁队列
void Destroy_Queue(Queue* ptr);