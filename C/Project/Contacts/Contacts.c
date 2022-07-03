#include "Contacts.h"

//菜单
void Menu()
{
	printf("******************************************\n");
	printf("**********  1.Add     2.Del     **********\n");
	printf("**********  3.Search  4.Modify  **********\n");
	printf("**********  5.Sort    6.Print   **********\n");
	printf("**********        0.Exit        **********\n");
	printf("******************************************\n");
}

//清屏
void Clear()
{
	system("pause");
	system("cls");
}

////初始化通讯录(静态)
//void Init_Contacts(Contacts* contacts)
//{
//	memset(contacts->people, 0, sizeof(contacts->people));
//	contacts->number = 0;
//}

//初始化通讯录(动态)
void Init_Contacts(Contacts* contacts)
{
	contacts->people = (Information*)malloc(DEFAULT_SIZE * sizeof(Information));
	if (contacts->people == NULL)
	{
		perror("Init_Contacts");
		return;
	}
	contacts->number = 0;
	contacts->capacity = DEFAULT_SIZE;
	Read_Contacts(contacts);
}

////添加联系人的信息(静态)
//void Add_Contacts(Contacts* contacts)
//{
//	if (contacts->number == MAX)
//	{
//		printf("联系人已满！添加失败！\n");
//		return;
//	}
//	printf("请输入姓名>>");
//	scanf_s("%s", contacts->people[contacts->number].name, MAX_NAME);
//	printf("请输入年龄>>");
//	scanf_s("%d", &(contacts->people[contacts->number].age));
//	printf("请输入性别>>");
//	scanf_s("%s", contacts->people[contacts->number].sex, MAX_SEX);
//	printf("请输入电话>>");
//	scanf_s("%s", contacts->people[contacts->number].phone, MAX_PHONE);
//	printf("请输入地址>>");
//	scanf_s("%s", contacts->people[contacts->number].address, MAX_ADDRESS);
//	contacts->number++;
//	printf("添加成功！\n");
//}

//添加联系人的信息(动态)
void Add_Contacts(Contacts* contacts)
{
	Check_Capacity(contacts);
	printf("请输入姓名>>");
	scanf_s("%s", contacts->people[contacts->number].name, MAX_NAME);
	printf("请输入年龄>>");
	scanf_s("%d", &(contacts->people[contacts->number].age));
	printf("请输入性别>>");
	scanf_s("%s", contacts->people[contacts->number].sex, MAX_SEX);
	printf("请输入电话>>");
	scanf_s("%s", contacts->people[contacts->number].phone, MAX_PHONE);
	printf("请输入地址>>");
	scanf_s("%s", contacts->people[contacts->number].address, MAX_ADDRESS);
	contacts->number++;
	printf("添加成功！\n");
}

//删除联系人的信息
void Del_Contacts(Contacts* contacts)
{
	if (contacts->number == 0)
	{
		printf("联系人为空！请添加联系人！\n");
		return;
	}
	Point_Contacts(contacts);
	int input = 0;
	printf("请输入需要删除的联系人的序号>>");
	scanf_s("%d", &input);
	if (input > contacts->number || input <= 0)
	{
		printf("联系人不存在\n");
		return;
	}
	for (int i = input; i < contacts->number; i++)
	{
		contacts->people[i - 1] = contacts->people[i];
	}
	printf("删除联系人成功！\n");
	contacts->number--;
}

//查找联系人
void Search_Contacts(Contacts* contacts)
{
	if (contacts->number == 0)
	{
		printf("联系人为空！请添加联系人！\n");
		return;
	}
	char name[MAX_NAME] = { 0 };
	printf("请输入要搜索的联系人的姓名>>");
	scanf_s("%s", name, MAX_NAME);
	for (int i = 0; i < contacts->number; i++)
	{
		if (strcmp(name, contacts->people[i].name) == 0)
		{
			printf("%-s\t%-10s\t%-5s\t%-5s\t%-20s\t%-30s\n", "序号", "姓名", "年龄", "性别", "电话", "地址");
			printf("%-d\t%-10s\t%-5d\t%-5s\t%-20s\t%-30s\n",
				i + 1,
				contacts->people[i].name,
				contacts->people[i].age,
				contacts->people[i].sex,
				contacts->people[i].phone,
				contacts->people[i].address
			);
			return;
		}
	}
	printf("查无此人！\n");
}

//更改联系人的信息
void Modify_Contacts(Contacts* contacts)
{
	if (contacts->number == 0)
	{
		printf("联系人为空！请添加联系人！\n");
		return;
	}
	char name[MAX_NAME] = { 0 };
	printf("请输入要更改的联系人的姓名>>");
	scanf_s("%s", name, MAX_NAME);
	for (int i = 0; i < contacts->number; i++)
	{
		if (strcmp(name, contacts->people[i].name) == 0)
		{
			printf("请输入姓名>>");
			scanf_s("%s", contacts->people[i].name, MAX_NAME);
			printf("请输入年龄>>");
			scanf_s("%d", &(contacts->people[i].age));
			printf("请输入性别>>");
			scanf_s("%s", contacts->people[i].sex, MAX_SEX);
			printf("请输入电话>>");
			scanf_s("%s", contacts->people[i].phone, MAX_PHONE);
			printf("请输入地址>>");
			scanf_s("%s", contacts->people[i].address, MAX_ADDRESS);
			printf("更改成功！\n");
			return;
		}
	}
	printf("更改失败！\n");
}

//排序联系人
void Sort_Menu()
{
	printf("***************************************\n");
	printf("**********  1. Sort By Name  **********\n");
	printf("**********  2. Sort By Age   **********\n");
	printf("**********  0.  Exit Sort    **********\n");
	printf("***************************************\n");
}
int Compar_Name(const void* p1, const void* p2)
{
	return strcmp(((Information*)p1)->name, ((Information*)p2)->name);
}
int Compar_Age(const void* p1, const void* p2)
{
	return ((Information*)p1)->age - ((Information*)p2)->age;
}
void Swap(char* p1, char* p2, size_t size)
{
	for (int i = 0; i < size; i++)
	{
		char tmp = *p1;
		*p1 = *p2;
		*p2 = tmp;
		p1++, p2++;
	}
}
void Insert_Sort(void* base, size_t num, size_t size, int (*compar)(const void*, const void*))
{
	for (int i = 1; i < num; i++)
	{
		for (int j = i - 1; j >= 0 && compar((char*)base + j * size, (char*)base + (j + 1) * size) > 0; j--)
		{
			Swap((char*)base + j * size, (char*)base + (j + 1) * size, size);
		}
	}
}
void Sort(Contacts* contacts, int (*ptr)(const void*, const void*))
{
	system("cls");
	printf("排序前>");
	Point_Contacts(contacts);
	Insert_Sort(contacts->people, contacts->number, sizeof(Information), ptr);
	printf("排序后>");
	Point_Contacts(contacts);
	system("pause");
}
void Sort_Contacts(Contacts* contacts)
{
	if (contacts->number == 0)
	{
		printf("联系人为空！请添加联系人！\n");
		Clear();
		return;
	}
	else if (contacts->number == 1)
	{
		printf("通讯录中仅有一位联系人！无需排序！\n");
		Clear();
		return;
	}
	int input = 0;
	do
	{
		system("cls");
		Sort_Menu();
		printf("Please enter>>");
		scanf_s("%d", &input);
		switch (input)
		{
		case 1:
			Sort(contacts, Compar_Name);
			break;
		case 2:
			Sort(contacts, Compar_Age);
			break;
		case 0:
			printf("\nExit Sort!\n\n");
			Clear();
			break;
		default:
			printf("\nError!Please try again.\n\n");
			Clear();
			break;
		}
	} while (input);
}

//打印联系人的信息
void Point_Contacts(Contacts* contacts)
{
	if (contacts->number == 0)
	{
		printf("联系人为空！请添加联系人！\n");
		return;
	}
	printf("\n%-s\t%-10s\t%-5s\t%-5s\t%-20s\t%-30s\n", "序号", "姓名", "年龄", "性别", "电话", "地址");
	for (int i = 0; i < contacts->number; i++)
	{
		printf("%-d\t%-10s\t%-5d\t%-5s\t%-20s\t%-30s\n",
			i+1,
			contacts->people[i].name,
			contacts->people[i].age,
			contacts->people[i].sex,
			contacts->people[i].phone,
			contacts->people[i].address
		);
	}
	printf("\n");
}

//检查容量
void Check_Capacity(Contacts* contacts)
{
	if (contacts->number == contacts->capacity)
	{
		Information* tmp = (Information*)realloc(contacts->people, (EXPAND_SIZE + contacts->capacity) * sizeof(Information));
		if (tmp != NULL)
		{
			contacts->people = tmp;
			contacts->capacity += EXPAND_SIZE;
		}
		else
		{
			perror("Add_Contacts");
			return;
		}
	}
}

//清除通讯录
void Remove_Contacts(Contacts* contacts)
{
	free(contacts->people);
	contacts->people = NULL;
	contacts->number = 0;
	contacts->capacity = 0;
}

//从文件中读取通讯录信息
void Read_Contacts(Contacts* contacts)
{
	FILE* ptr;
	fopen_s(&ptr, "Contacts.dat", "r+");
	if (ptr == NULL)
	{
		perror("Read_Contacts");
		return;
	}
	Information tmp;
	while (fread(&tmp, sizeof(Information), 1, ptr))
	{
		Check_Capacity(contacts);
		contacts->people[contacts->number] = tmp;
		contacts->number++;
	}
	fclose(ptr);
	ptr = NULL;
}

//保存通讯录至文件
void Save_Contacts(Contacts* contacts)
{
	FILE* ptr;
	fopen_s(&ptr, "Contacts.dat", "w+");
	if (ptr == NULL)
	{
		perror("Save_Contacts");
		return;
	}
	for (int i = 0; i < contacts->number; i++)
	{
		fwrite(contacts->people + i, sizeof(Information), 1, ptr);
	}
	fclose(ptr);
	ptr = NULL;
}