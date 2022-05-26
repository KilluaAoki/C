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

//初始化通讯录(静态)
void Init_Contacts(Contacts* contacts)
{
	memset(contacts->people, 0, sizeof(contacts->people));
	contacts->number = 0;
}

//添加联系人的信息(静态)
void Add_Contacts(Contacts* contacts)
{
	if (contacts->number == MAX)
	{
		printf("联系人已满！添加失败！\n");
		return;
	}
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
	return strcmp(((Contacts*)p1)->people->name, ((Contacts*)p2)->people->name);
}
int Compar_Age(const void* p1, const void* p2)
{
	return ((Contacts*)p1)->people->age - ((Contacts*)p2)->people->age;
}
void Sort_Contacts(Contacts* contacts)
{
	if (contacts->number == 0)
	{
		printf("联系人为空！请添加联系人！\n");
		return;
	}
	int input = 0;
	do
	{
		system("cls");
		Sort_Menu();
		printf("Please enter>>");
		scanf_s("%d", &input);
		if (input == 1)
		{
			system("cls");
			printf("排序前>\n");
			Point_Contacts(contacts);
			qsort(contacts->people, contacts->number, sizeof(contacts->people[0]), Compar_Name);
			printf("\n排序后>\n");
			Point_Contacts(contacts);
			printf("\n");
			system("pause");
		}
		else if (input == 2)
		{
			system("cls");
			printf("排序前>\n");
			Point_Contacts(contacts);
			qsort(contacts->people, contacts->number, sizeof(contacts->people[0]), Compar_Age);
			printf("\n排序后>\n");
			Point_Contacts(contacts);
			printf("\n");
			system("pause");
		}
		else if (input)
		{
			printf("\nError!Please try again.\n\n");
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
	printf("%-s\t%-10s\t%-5s\t%-5s\t%-20s\t%-30s\n", "序号", "姓名", "年龄", "性别", "电话", "地址");
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
}