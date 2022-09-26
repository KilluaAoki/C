#pragma once

//引用头文件
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

//定义标识符
#define EXPAND_SIZE 5
#define DEFAULT_SIZE 5

//重命名顺序表数据元素类型
typedef int ElemType;

//定义结构体类型(顺序表)
typedef struct SequenceList
{
	ElemType* array_ptr;
	size_t size;
	size_t capacity;
} SeqList;

//初始化顺序表
void Init_SequenceList(SeqList* ptr);

//打印顺序表
void Print_SequenceList(SeqList* ptr);

//清除顺序表
void Remove_SequenceList(SeqList* ptr);

//检查容量
void Check_SequenceList(SeqList* ptr);

//查找顺序表数据元素的位置
size_t Search_SequenceList(SeqList* ptr, ElemType data);

//修改顺序表数据元素
void Modify_SequenceList(SeqList* ptr, size_t pos, ElemType data);

//在顺序表的首位置插入数据元素(头插)
void Head_Insert_SequenceList(SeqList* ptr, ElemType data);

//在顺序表的末位置插入数据元素(尾插)
void Tail_Insert_SequenceList(SeqList* ptr, ElemType data);

//在顺序表的首位置删除数据元素(头删)
void Head_Delete_SequenceList(SeqList* ptr);

//在顺序表的末位置删除数据元素(尾删)
void Tail_Delete_SequenceList(SeqList* ptr);

//在顺序表的任意位置插入数据元素
void Insert_SequenceList(SeqList* ptr, size_t pos, ElemType data);

//在顺序表的任意位置删除数据元素
void Delete_SequenceList(SeqList* ptr, size_t pos);