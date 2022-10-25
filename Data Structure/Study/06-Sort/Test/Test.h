#pragma once

//引用测试所需头文件
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>

//引用排序头文件
#include "../Sort.h"

//生成随机数组
SortDataType* Generate_Random_Array(size_t size);

//复制数组
SortDataType* Copy_Array(const SortDataType* arr, size_t size);

//判断两数组是否一样
bool Is_Equal(const SortDataType* arr1, const SortDataType* arr2, size_t size);

//对照函数(即库函数"qsort"，并返回排序所用时间(单位：秒))
double Contrast(SortDataType* arr, size_t size, int(* Compare)(const void*, const void*));

//测试排序算法的时间(单位：秒)
double Clock_Sort(SortDataType* arr, size_t size, void(* Sort)(SortDataType*, size_t));