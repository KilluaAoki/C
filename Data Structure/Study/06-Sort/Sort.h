#pragma once

//引用头文件
#include <stdio.h>

//重命名需要排序的数组的数据元素类型
typedef int SortDataType;

//整型比较器
int Compare_Int(const void* p1, const void* p2);

//交换元素
void Swap(SortDataType* ptr1, SortDataType* ptr2);

//冒泡排序
void Bubble_Sort(SortDataType* arr, size_t size);

//选择排序
void Selection_Sort(SortDataType* arr, size_t size);

//插入排序
void Insertion_Sort(SortDataType* arr, size_t size);

//堆排序
void Heap_Sort(SortDataType* arr, size_t size);