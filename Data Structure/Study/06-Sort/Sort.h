#pragma once

//引用头文件
#include <stdio.h>
#include <stdlib.h>

//重命名需要排序的数组的数据元素类型
typedef int SortDataType;

/*
 * 工具函数
 */

//整型比较器
int Compare_Int(const void* p1, const void* p2);

//交换元素
void Swap(SortDataType* ptr1, SortDataType* ptr2);

/*
 * 三大基本排序(升序)
 * 1. 时间复杂度均为：O(N ^ 2)，空间复杂度均为：O(1)。(其中"^"符号表示次方)
 * 2. 包含了冒泡排序、选择排序、插入排序。
 */

//冒泡排序
void Bubble_Sort(SortDataType* arr, size_t size);

//选择排序
void Selection_Sort(SortDataType* arr, size_t size);

//插入排序
void Insertion_Sort(SortDataType* arr, size_t size);

/*
 * 堆排序(升序)
 * 1. 时间复杂度为：O(N * logN)，空间复杂度为：O(1)。
 * 2. 利用适用于大根堆的向下调整函数，将数组调整为升序。
 */

//适用于大根堆的向下调整函数
void Ify_Max_Heap(SortDataType* arr, size_t index, size_t size);

//堆排序
void Heap_Sort(SortDataType* arr, size_t size);

/*
 * 归并排序(升序)
 * 1. 时间复杂度为：O(N * logN)，空间复杂度为：递归实现O(N + logN)、非递归实现O(N)。
 * 2. 包含递归与非递归实现归并排序。
 * 3. 递归与非递归实现共用"Merge"核心函数。
 */

//归并排序核心函数
void Merge(SortDataType* arr, size_t left, size_t middle, size_t right);

//归并排序递归过程函数
void Merge_Sort_Recursive_Process(SortDataType* arr, size_t left, size_t right);

//归并排序(递归实现)
void Merge_Sort_Recursive(SortDataType* arr, size_t size);

//归并排序(非递归实现)
void Merge_Sort_UnRecursive(SortDataType* arr, size_t size);