#pragma once

//引用头文件
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>

//定义标识符
#define MAX 10
#define MAX_SEX 10
#define MAX_NAME 20
#define MAX_PHONE 20
#define MAX_ADDRESS 50

//定义枚举类型(选项)
enum Option
{
	EXIT,
	ADD,
	DEL,
	SEARCH,
	MODIFY,
	SORT,
	PRINT
};

//定义结构体类型(信息)
typedef struct Information
{
	char name[MAX_NAME];
	char sex[MAX_SEX];
	char phone[MAX_PHONE];
	char address[MAX_ADDRESS];
	int age;
}Information;

//定义结构体类型(通讯录)(静态)
typedef struct Contacts
{
	Information people[MAX];
	int number;
}Contacts;

//菜单
void Menu();

//清屏
void Clear();

//初始化通讯录
void Init_Contacts(Contacts* contacts);

//添加联系人的信息
void Add_Contacts(Contacts* contacts);

//删除联系人的信息
void Del_Contacts(Contacts* contacts);

//查找联系人
void Search_Contacts(Contacts* contacts);

//更改联系人的信息
void Modify_Contacts(Contacts* contacts);

//排序联系人
void Sort_Contacts(Contacts* contacts);

//打印联系人的信息
void Point_Contacts(Contacts* contacts);