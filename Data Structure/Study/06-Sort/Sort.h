#pragma once

//引用头文件
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

//引用栈头文件(以实现快速排序的非递归实现)
#include "./Stack/Stack.h"

//重命名需要排序的数组的数据元素类型
typedef int SortDataType;

/*
 * 工具函数
 * 1.此处比较器适用于"qsort"库函数，本项目中所实现的排序算法都为升序，并未改造成库函数的形式，故本项目实现的排序算法无需比较器。
 * 2.交换元素为异或交换，无需临时变量，并且解决了相同位置交换为"0"的问题。
 */

//整型比较器
int Compare_Int(const void* p1, const void* p2);

//交换元素
void Swap(SortDataType* ptr1, SortDataType* ptr2);

/*
 * 三大基本排序(升序)
 * 1. 时间复杂度均为：O(N ^ 2)，空间复杂度均为：O(1)。(其中"^"符号表示次方)
 * 2. 包含了冒泡排序、选择排序、插入排序。
 * 3. 稳定性：选择排序为不稳定排序，冒泡排序和插入排序为稳定排序。
 */

//冒泡排序
void Bubble_Sort(SortDataType* arr, size_t size);

//选择排序
void Selection_Sort(SortDataType* arr, size_t size);

//插入排序
void Insertion_Sort(SortDataType* arr, size_t size);

/*
 * 希尔排序(升序)
 * 1. 本项目中时间复杂度为：O(N ^ 1.5)，空间复杂度为：O(1)。(其中"^"符号表示次方)
 * 2. 希尔排序的时间复杂度与增量序列的选取有关，本项目中使用的增量序列为：{ ((3 ^ K) - 1) / 2 }，其中"K"为正整数。
 * 3. 本项目使用的增量序列源自于Donald Knuth和Vaughan Pratt，详细：https://oeis.org/A003462。
 * 4. 稳定性：不稳定排序。
 */

//希尔排序
void Shell_Sort(SortDataType* arr, size_t size);

/*
 * 堆排序(升序)
 * 1. 时间复杂度为：O(N * logN)，空间复杂度为：O(1)。("log"符号表示以"2"为底的对数)
 * 2. 利用适用于大根堆的向下调整函数，将数组调整为升序。
 * 3. 稳定性：不稳定排序。
 */

//适用于大根堆的向下调整函数
void Ify_Max_Heap(SortDataType* arr, size_t index, size_t size);

//堆排序
void Heap_Sort(SortDataType* arr, size_t size);

/*
 * 归并排序(升序)
 * 1. 时间复杂度为：O(N * logN)，空间复杂度为：递归实现O(N + logN)、非递归实现O(N)。("log"符号表示以"2"为底的对数)
 * 2. 包含递归与非递归实现归并排序。
 * 3. 递归与非递归实现共用"Merge"核心函数。
 * 4. 稳定性：稳定排序。
 */

//归并排序核心函数
void Merge(SortDataType* arr, size_t left, size_t middle, size_t right);

//归并排序递归过程函数
void Merge_Sort_Recursive_Process(SortDataType* arr, size_t left, size_t right);

//归并排序(递归实现)
void Merge_Sort_Recursive(SortDataType* arr, size_t size);

//归并排序(非递归实现)
void Merge_Sort_UnRecursive(SortDataType* arr, size_t size);

/*
 * 快速排序(升序)
 * 1. 快速排序的时间复杂度和空间复杂度是在概率上求得一个长期期望，故时间复杂度可以认为是：O(N * logN)，空间复杂度为：O(logN)。("log"符号表示以"2"为底的对数)
 * 2. 包含递归与非递归实现快速排序。
 * 3. 递归与非递归实现共用"Partition"核心函数。
 * 4. 快速排序的非递归实现使用栈来模拟递归过程。
 * 5. 稳定性：不稳定排序。
 */

//快速排序核心函数
void Partition(SortDataType* arr, int left, int right, int* pkeyLight, int* pkeyRight);

//快速排序递归过程函数
void Quick_Sort_Recursive_Process(SortDataType* arr, int left, int right);

//快速排序(递归实现)
void Quick_Sort_Recursive(SortDataType* arr, size_t size);

//快速排序(非递归实现)
void Quick_Sort_UnRecursive(SortDataType* arr, size_t size);

/*
 * 计数排序(升序)
 * 1. 时间复杂度为：O(N + K)，空间复杂度为：O(K)，其中"K"为数值范围的最大值。
 * 2. 稳定性：稳定排序。
 */

void Count_Sort(SortDataType* arr, size_t size);

/*
 * 基数排序(升序)
 * 1. 时间复杂度为：O(N * K)，空间复杂度为：O(N + K)，其中"K"为数值范围的最大值。
 * 2. 稳定性：稳定排序。
 */

//获取数组中最大值的十进制位数
size_t Get_Max_Decimal_Bits_Digit(const SortDataType* arr, size_t size);

//获取当前位数上的值(数字)
SortDataType Get_Digit_Value(SortDataType num, size_t digit);

//基数排序核心函数
void Radix(SortDataType* arr, int left, int right, size_t digit);

//基数排序
void Radix_Sort(SortDataType* arr, size_t size);