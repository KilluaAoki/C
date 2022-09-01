#include "SequenceList.h"

void Single_SequenceList()
{
	system("cls");
	int input = 0;
	SeqList List;
	Init_SequenceList(&List);
	do
	{
		Menu_Single_SequenceList();
		printf("Please enter>>");
		scanf_s("%d", &input);
		switch (input)
		{
		case 1:
		{
			ElemType val;
			printf("请输入数据>>");
			scanf_s("%d", &val);
			Head_Insert_SequenceList(&List, val);
			Clear_Screen();
			break;
		}
		case 2:
		{
			ElemType val;
			printf("请输入数据>>");
			scanf_s("%d", &val);
			Tail_Insert_SequenceList(&List, val);
			Clear_Screen();
			break;
		}
		case 3:
			Head_Delete_SequenceList(&List);
			Clear_Screen();
			break;
		case 4:
			Tail_Delete_SequenceList(&List);
			Clear_Screen();
			break;
		case 5:
		{
			ElemType val;
			size_t location;
			Print_SequenceList(&List);
			printf("请输入数据>>");
			scanf_s("%d", &val);
			printf("请输入位置>>");
			scanf_s("%zu", &location);
			Insert_SequenceList(&List, location, val);
			Clear_Screen();
			break;
		}
		case 6:
		{
			if (List.size == 0)
			{
				printf("当前顺序表无数据元素。\n");
				Clear_Screen();
				break;
			}
			size_t location;
			Print_SequenceList(&List);
			printf("请输入位置>>");
			scanf_s("%zu", &location);
			Delete_SequenceList(&List, location);
			Clear_Screen();
			break;
		}
		case 7:
			Clear_SequenceList(&List);
			Clear_Screen();
			break;
		case 8:
		{
			if (List.size == 0)
			{
				printf("当前顺序表无数据元素。\n");
				Clear_Screen();
				break;
			}
			ElemType val;
			size_t location;
			Print_SequenceList(&List);
			printf("请输入数据>>");
			scanf_s("%d", &val);
			printf("请输入位置>>");
			scanf_s("%zu", &location);
			Modify_SequenceList(&List, location, val);
			Clear_Screen();
			break;
		}
		case 9:
		{
			if (List.size == 0)
			{
				printf("当前顺序表无数据元素。\n");
				Clear_Screen();
				break;
			}
			ElemType val;
			printf("请输入数据>>");
			scanf_s("%d", &val);
			size_t location = Search_SequenceList_Printf(&List, val);
			if (location != 0)
			{
				printf("\n%-s\t%-s\n", "数据元素序号", "数据元素值");
				printf("%-zu\t\t%-d\n\n", location, List.array_ptr[location - 1]);
			}
			Clear_Screen();
			break;
		}
		case 10:
			Judge_Empty_SequenceList(&List);
			Clear_Screen();
			break;
		case 11:
		{
			if (List.size == 0)
			{
				printf("当前顺序表无数据元素。\n");
				Clear_Screen();
				break;
			}
			ElemType data;
			size_t location;
			printf("请输入位置>>");
			scanf_s("%zu", &location);
			if (Get_Data_SequenceList(&List, location, &data))
			{
				printf("\n%-s\t%-s\n", "数据元素序号", "数据元素值");
				printf("%-zu\t\t%-d\n\n", location, data);
			}
			Clear_Screen();
			break;
		}
		case 12:
			Print_SequenceList(&List);
			Clear_Screen();
			break;
		case 0:
			Remove_SequenceList(&List);
			break;
		default:
			printf("\nError!Please try again.\n\n");
			Clear_Screen();
			break;
		}
	} while (input);
}

void Multiple_SequenceList()
{
	system("cls");
	int input = 0;
	SeqList List_01;
	SeqList List_02;
	Init_SequenceList(&List_01);
	Init_SequenceList(&List_02);
	do
	{
		Menu_Multiple_SequenceList();
		printf("Please enter>>");
		scanf_s("%d", &input);
		switch (input)
		{
		case 1:
		{
			ElemType val;
			size_t location;
			Print_SequenceList(&List_01);
			printf("请输入数据>>");
			scanf_s("%d", &val);
			printf("请输入位置>>");
			scanf_s("%zu", &location);
			Insert_SequenceList(&List_01, location, val);
			Clear_Screen();
			break;
		}
		case 2:
		{
			ElemType val;
			size_t location;
			Print_SequenceList(&List_02);
			printf("请输入数据>>");
			scanf_s("%d", &val);
			printf("请输入位置>>");
			scanf_s("%zu", &location);
			Insert_SequenceList(&List_02, location, val);
			Clear_Screen();
			break;
		}
		case 3:
		{
			if (List_01.size == 0)
			{
				printf("当前顺序表无数据元素。\n");
				Clear_Screen();
				break;
			}
			size_t location;
			Print_SequenceList(&List_01);
			printf("请输入位置>>");
			scanf_s("%zu", &location);
			Delete_SequenceList(&List_01, location);
			Clear_Screen();
			break;
		}
		case 4:
		{
			if (List_02.size == 0)
			{
				printf("当前顺序表无数据元素。\n");
				Clear_Screen();
				break;
			}
			size_t location;
			Print_SequenceList(&List_02);
			printf("请输入位置>>");
			scanf_s("%zu", &location);
			Delete_SequenceList(&List_02, location);
			Clear_Screen();
			break;
		}
		case 5:
			Clear_SequenceList(&List_01);
			Clear_Screen();
			break;
		case 6:
			Clear_SequenceList(&List_02);
			Clear_Screen();
			break;
		case 7:
		{
			if (List_01.size == 0)
			{
				printf("当前顺序表无数据元素。\n");
				Clear_Screen();
				break;
			}
			ElemType val;
			size_t location;
			Print_SequenceList(&List_01);
			printf("请输入数据>>");
			scanf_s("%d", &val);
			printf("请输入位置>>");
			scanf_s("%zu", &location);
			Modify_SequenceList(&List_01, location, val);
			Clear_Screen();
			break;
		}
		case 8:
		{
			if (List_02.size == 0)
			{
				printf("当前顺序表无数据元素。\n");
				Clear_Screen();
				break;
			}
			ElemType val;
			size_t location;
			Print_SequenceList(&List_02);
			printf("请输入数据>>");
			scanf_s("%d", &val);
			printf("请输入位置>>");
			scanf_s("%zu", &location);
			Modify_SequenceList(&List_02, location, val);
			Clear_Screen();
			break;
		}
		case 9:
			Print_SequenceList(&List_01);
			Clear_Screen();
			break;
		case 10:
			Print_SequenceList(&List_02);
			Clear_Screen();
			break;
		case 11:
			Union_SequenceList(&List_01, &List_02);
			Clear_Screen();
			break;
		case 0:
			Remove_SequenceList(&List_01);
			Remove_SequenceList(&List_02);
			break;
		default:
			printf("\nError!Please try again.\n\n");
			Clear_Screen();
			break;
		}
	} while (input);
}

int main()
{
	int input = 0;
	do
	{
		Menu();
		printf("Please enter>>");
		scanf_s("%d", &input);
		switch (input)
		{
		case 1:
			Single_SequenceList();
			Clear_Screen();
			break;
		case 2:
			Multiple_SequenceList();
			Clear_Screen();
			break;
		case 0:
			printf("\nExit!\n");
			break;
		default:
			printf("\nError!Please try again.\n\n");
			Clear_Screen();
			break;
		}
	} while (input);
	return 0;
}