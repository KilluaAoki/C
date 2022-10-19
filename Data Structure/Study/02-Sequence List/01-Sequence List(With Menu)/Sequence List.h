#pragma once

//引用头文件
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <Windows.h>

//定义标识符
#define EXPAND_SIZE 5
#define DEFAULT_SIZE 5

//重命名顺序表数据元素类型
typedef int SeqListDataType;

//定义结构体类型(顺序表)
typedef struct SequenceList
{
	SeqListDataType* array_ptr;
	size_t size;
	size_t capacity;
} SeqList;

//总菜单
void Menu();

//单顺序表操作菜单
void Menu_Single_SequenceList();

//多顺序表操作菜单
void Menu_Multiple_SequenceList();

//清屏
void Clear_Screen();

//初始化顺序表
void Init_SequenceList(SeqList* ptr);

//打印顺序表
void Print_SequenceList(SeqList* ptr);

//清除顺序表
void Remove_SequenceList(SeqList* ptr);

//检查容量
void Check_SequenceList(SeqList* ptr);

//查找顺序表数据元素的位置(具有输出)
size_t Search_SequenceList_Printf(SeqList* ptr, SeqListDataType data);

//查找顺序表数据元素的位置(无输出)
size_t Search_SequenceList_NoPrintf(SeqList* ptr, SeqListDataType data);

//修改顺序表数据元素
void Modify_SequenceList(SeqList* ptr, size_t Location, SeqListDataType data);

//在顺序表的首位置插入数据元素(头插)
void Head_Insert_SequenceList(SeqList* ptr, SeqListDataType data);

//在顺序表的末位置插入数据元素(尾插)
void Tail_Insert_SequenceList(SeqList* ptr, SeqListDataType data);

//在顺序表的首位置删除数据元素(头删)
void Head_Delete_SequenceList(SeqList* ptr);

//在顺序表的末位置删除数据元素(尾删)
void Tail_Delete_SequenceList(SeqList* ptr);

//在顺序表的任意位置插入数据元素
void Insert_SequenceList(SeqList* ptr, size_t Location, SeqListDataType data);

//在顺序表的任意位置删除数据元素
void Delete_SequenceList(SeqList* ptr, size_t Location);

//判断顺序表是否为空表
void Judge_Empty_SequenceList(SeqList* ptr);

//重置顺序表为空表
void Clear_SequenceList(SeqList* ptr);

//获取顺序表任意位置的数据元素
size_t Get_Data_SequenceList(SeqList* ptr, size_t Location, SeqListDataType* data);

//求两个顺序表的并集，即将所有在第二个顺序表中但不在第一个顺序表中的数据元素插入到第一个顺序表中。
void Union_SequenceList(SeqList* ptr1, SeqList* ptr2);