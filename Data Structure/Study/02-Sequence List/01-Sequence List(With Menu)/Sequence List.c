#include "Sequence List.h"

//总菜单
void Menu()
{
	printf("********************************************************\n");
	printf("**********        1. 单顺序表操作菜单         **********\n");
	printf("**********        2. 多顺序表操作菜单         **********\n");
	printf("**********           0. 退出程序              **********\n");
	printf("********************************************************\n");
}

//单顺序表操作菜单
void Menu_Single_SequenceList()
{
	printf("************************************************************\n");
	printf("**********        1. 头插         2. 尾插         **********\n");
	printf("**********        3. 头删         4. 尾删         **********\n");
	printf("**********        5. 指定位置插入数据元素         **********\n");
	printf("**********        6. 指定位置删除数据元素         **********\n");
	printf("**********        7.   重置顺序表为空表           **********\n");
	printf("**********        8.  修改顺序表数据元素          **********\n");
	printf("**********        9.  查找顺序表数据元素          **********\n");
	printf("**********       10. 判断顺序表是否为空表         **********\n");
	printf("**********       11. 获取指定位置数据元素         **********\n");
	printf("**********       12.      打印顺序表              **********\n");
	printf("**********            0. 返回上级菜单             **********\n");
	printf("************************************************************\n");
}

//多顺序表操作菜单
void Menu_Multiple_SequenceList()
{
	printf("******************************************************************\n");
	printf("**********        1. 于表一指定位置插入数据元素         **********\n");
	printf("**********        2. 于表二指定位置插入数据元素         **********\n");
	printf("**********        3. 于表一指定位置删除数据元素         **********\n");
	printf("**********        4. 于表二指定位置删除数据元素         **********\n");
	printf("**********        5.       重置表一为空表               **********\n");
	printf("**********        6.       重置表二为空表               **********\n");
	printf("**********        7.      修改表一数据元素              **********\n");
	printf("**********        8.      修改表二数据元素              **********\n");
	printf("**********        9.          打印表一                  **********\n");
	printf("**********       10.          打印表二                  **********\n");
	printf("**********       11.  求两个顺序表的并集至表一          **********\n");
	printf("**********               0. 返回上级菜单                **********\n");
	printf("******************************************************************\n");
}

//清屏
void Clear_Screen()
{
	system("pause");
	system("cls");
}

//初始化顺序表
void Init_SequenceList(SeqList* ptr)
{
	assert(ptr != NULL);
	ptr->array_ptr = NULL;
	ptr->size = 0;
	ptr->capacity = 0;
}

//打印顺序表
void Print_SequenceList(SeqList* ptr)
{
	assert(ptr != NULL);
	if (ptr->size == 0)
	{
		printf("当前顺序表无数据元素。\n");
		return;
	}
	printf("\n%-s\t%-s\n", "数据元素序号", "数据元素值");
	for (size_t i = 0; i < ptr->size; i++)
	{
		printf("%-zu\t\t%-d\n", i + 1, ptr->array_ptr[i]);//若顺序表中的数据元素类型不是整型类型则需要手动修改"printf"函数的格式指定符。
	}
	printf("\n");
}

//清除顺序表
void Remove_SequenceList(SeqList* ptr)
{
	assert(ptr != NULL);
	free(ptr->array_ptr);
	ptr->array_ptr = NULL;
	ptr->capacity = ptr->size = 0;
}

//检查容量
void Check_SequenceList(SeqList* ptr)
{
	assert(ptr != NULL);
	if (ptr->capacity == ptr->size)
	{
		size_t newCapacity = ptr->capacity == 0 ? DEFAULT_SIZE : ptr->capacity + EXPAND_SIZE;
		SeqListType* tmp = (SeqListType*)realloc(ptr->array_ptr, newCapacity * sizeof(SeqListType));
		if (tmp == NULL)
		{
			perror("realloc fail");
			return;
		}
		ptr->array_ptr = tmp;
		ptr->capacity = newCapacity;
	}
}

//查找顺序表数据元素的位置
size_t Search_SequenceList_Printf(SeqList* ptr, SeqListType data)
{
	assert(ptr != NULL);
	if (ptr->size == 0)
	{
		printf("当前顺序表无数据元素。\n");
		return 0;
	}
	for (size_t i = 0; i < ptr->size; i++)
	{
		if (ptr->array_ptr[i] == data)
		{
			return i + 1;//返回位置，即下标加一。
		}
	}
	printf("当前顺序表数据元素中无给定值。\n");
	return 0;
}

//查找顺序表数据元素的位置(无输出)
size_t Search_SequenceList_NoPrintf(SeqList* ptr, SeqListType data)
{
	assert(ptr != NULL);
	if (ptr->size == 0)
	{
		return 0;
	}
	for (size_t i = 0; i < ptr->size; i++)
	{
		if (ptr->array_ptr[i] == data)
		{
			return i + 1;//返回位置，即下标加一。
		}
	}
	return 0;
}

//修改顺序表数据元素
void Modify_SequenceList(SeqList* ptr, size_t Location, SeqListType data)
{
	assert(ptr != NULL);
	if (Location > ptr->size)
	{
		printf("输入错误，顺序表中无此位置数据元素。\n");
		return;
	}
	ptr->array_ptr[Location - 1] = data;
}

//在顺序表的首位置插入数据元素(头插)
void Head_Insert_SequenceList(SeqList* ptr, SeqListType data)
{
	assert(ptr != NULL);
	Check_SequenceList(ptr);
	for (int i = (int)ptr->size - 1; i >= 0; i--)
	{
		ptr->array_ptr[i + 1] = ptr->array_ptr[i];
	}
	ptr->array_ptr[0] = data;
	ptr->size++;
}

//在顺序表的末位置插入数据元素(尾插)
void Tail_Insert_SequenceList(SeqList* ptr, SeqListType data)
{
	assert(ptr != NULL);
	Check_SequenceList(ptr);
	ptr->array_ptr[ptr->size] = data;
	ptr->size++;
}

//在顺序表的首位置删除数据元素(头删)
void Head_Delete_SequenceList(SeqList* ptr)
{
	assert(ptr != NULL);
	if (ptr->size == 0)
	{
		printf("当前顺序表无数据元素。\n");
		return;
	}
	for (size_t i = 1; i < ptr->size; i++)
	{
		ptr->array_ptr[i - 1] = ptr->array_ptr[i];
	}
	ptr->size--;
}

//在顺序表的末位置删除数据元素(尾删)
void Tail_Delete_SequenceList(SeqList* ptr)
{
	assert(ptr != NULL);
	if (ptr->size == 0)
	{
		printf("当前顺序表无数据元素。\n");
		return;
	}
	ptr->size--;
}

//在顺序表的任意位置插入数据元素
void Insert_SequenceList(SeqList* ptr, size_t Location, SeqListType data)
{
	assert(ptr != NULL);
	if (Location > ptr->size + 1)
	{
		printf("输入位置无效。\n");
		return;
	}
	Check_SequenceList(ptr);
	for (int i = (int)(ptr->size - 1); i >= ((int)Location - 1); i--)
	{
		ptr->array_ptr[i + 1] = ptr->array_ptr[i];
	}
	ptr->array_ptr[Location - 1] = data;
	ptr->size++;
}

//在顺序表的任意位置删除数据元素
void Delete_SequenceList(SeqList* ptr, size_t Location)
{
	assert(ptr != NULL);
	if (ptr->size == 0)
	{
		printf("当前顺序表无数据元素。\n");
		return;
	}
	if (Location > ptr->size)
	{
		printf("输入位置无效。\n");
		return;
	}
	for (size_t i = Location - 1; i < ptr->size - 1; i++)
	{
		ptr->array_ptr[i] = ptr->array_ptr[i + 1];
	}
	ptr->size--;
}

//判断顺序表是否为空表
void Judge_Empty_SequenceList(SeqList* ptr)
{
	assert(ptr != NULL);
	if (ptr->size == 0)
	{
		printf("此顺序表为空表。\n");
		return;
	}
	printf("此顺序表不是空表。\n");
}

//重置顺序表为空表
void Clear_SequenceList(SeqList* ptr)
{
	assert(ptr != NULL);
	ptr->size = 0;
	ptr->capacity = 0;
	ptr->array_ptr = NULL;
}

//获取顺序表任意位置的数据元素
size_t Get_Data_SequenceList(SeqList* ptr, size_t Location, SeqListType* data)
{
	assert(ptr != NULL);
	if (ptr->size == 0)
	{
		printf("当前顺序表无数据元素。\n");
		return 0;
	}
	if (Location > ptr->size)
	{
		printf("输入位置无效。\n");
		return 0;
	}
	*data = ptr->array_ptr[Location - 1];
	return 1;
}

//求两个顺序表的并集，即将所有在第二个顺序表中但不在第一个顺序表中的数据元素插入到第一个顺序表中。
void Union_SequenceList(SeqList* ptr1, SeqList* ptr2)
{
	assert(ptr1 != NULL && ptr2 != NULL);
	SeqListType tmp;
	for (size_t i = 1; i <= ptr2->size; i++)
	{
		Get_Data_SequenceList(ptr2, i, &tmp);
		if (Search_SequenceList_NoPrintf(ptr1, tmp) == 0)
		{
			Tail_Insert_SequenceList(ptr1, tmp);
		}
	}
}