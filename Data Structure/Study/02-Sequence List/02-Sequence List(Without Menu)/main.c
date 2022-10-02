#include "Sequence List.h"

void Test_SequenceList_01()
{
	printf("******************************01******************************\n");
	SeqList seqList;
	Init_SequenceList(&seqList);

	Head_Insert_SequenceList(&seqList, 20);
	Head_Insert_SequenceList(&seqList, 10);
	Print_SequenceList(&seqList);

	Tail_Insert_SequenceList(&seqList, 30);
	Tail_Insert_SequenceList(&seqList, 40);
	Print_SequenceList(&seqList);

	Remove_SequenceList(&seqList);
	printf("*****************************EXIT*****************************\n\n");
}

void Test_SequenceList_02()
{
	printf("******************************02******************************\n");
	SeqList seqList;
	Init_SequenceList(&seqList);

	Tail_Insert_SequenceList(&seqList, 30);
	Tail_Insert_SequenceList(&seqList, 40);
	Print_SequenceList(&seqList);

	Head_Insert_SequenceList(&seqList, 20);
	Head_Insert_SequenceList(&seqList, 10);
	Print_SequenceList(&seqList);

	Remove_SequenceList(&seqList);
	printf("*****************************EXIT*****************************\n\n");
}

void Test_SequenceList_03()
{
	printf("******************************03******************************\n");
	SeqList seqList;
	Init_SequenceList(&seqList);

	Head_Insert_SequenceList(&seqList, 4000);
	Head_Insert_SequenceList(&seqList, 3000);
	Head_Delete_SequenceList(&seqList);
	Print_SequenceList(&seqList);

	Head_Insert_SequenceList(&seqList, 2000);
	Head_Insert_SequenceList(&seqList, 1000);
	Head_Delete_SequenceList(&seqList);
	Print_SequenceList(&seqList);

	Remove_SequenceList(&seqList);
	printf("*****************************EXIT*****************************\n\n");
}

void Test_SequenceList_04()
{
	printf("******************************04******************************\n");
	SeqList seqList;
	Init_SequenceList(&seqList);

	Head_Insert_SequenceList(&seqList, 4000);
	Head_Insert_SequenceList(&seqList, 3000);
	Tail_Delete_SequenceList(&seqList);
	Print_SequenceList(&seqList);

	Head_Insert_SequenceList(&seqList, 2000);
	Head_Insert_SequenceList(&seqList, 1000);
	Tail_Delete_SequenceList(&seqList);
	Print_SequenceList(&seqList);

	Remove_SequenceList(&seqList);
	printf("*****************************EXIT*****************************\n\n");
}

void Test_SequenceList_05()
{
	printf("******************************05******************************\n");
	SeqList seqList;
	Init_SequenceList(&seqList);

	Insert_SequenceList(&seqList, 0, 20);
	Insert_SequenceList(&seqList, 0, 10);
	Insert_SequenceList(&seqList, 1, 15);
	Insert_SequenceList(&seqList, 3, 30);
	Insert_SequenceList(&seqList, 3, 25);
	Print_SequenceList(&seqList);

	Remove_SequenceList(&seqList);
	printf("*****************************EXIT*****************************\n\n");
}

void Test_SequenceList_06()
{
	printf("******************************06******************************\n");
	SeqList seqList;
	Init_SequenceList(&seqList);

	Insert_SequenceList(&seqList, 0, 1000);
	Delete_SequenceList(&seqList, 0);

	Insert_SequenceList(&seqList, 0, 20);
	Insert_SequenceList(&seqList, 0, 10);
	Insert_SequenceList(&seqList, 1, 15);
	Delete_SequenceList(&seqList, 1);
	Print_SequenceList(&seqList);

	Insert_SequenceList(&seqList, 2, 30);
	Insert_SequenceList(&seqList, 2, 25);
	Delete_SequenceList(&seqList, 2);
	Print_SequenceList(&seqList);

	Remove_SequenceList(&seqList);
	printf("*****************************EXIT*****************************\n\n");
}

void Test_SequenceList_07()
{
	printf("******************************07******************************\n");
	SeqList seqList;
	Init_SequenceList(&seqList);

	Head_Insert_SequenceList(&seqList, 10);
	Head_Insert_SequenceList(&seqList, 5);
	Tail_Insert_SequenceList(&seqList, 15);
	Tail_Insert_SequenceList(&seqList, 20);
	Tail_Insert_SequenceList(&seqList, 40);
	Print_SequenceList(&seqList);

	size_t pos = Search_SequenceList(&seqList, 5);
	if (pos != -1)
	{
		Modify_SequenceList(&seqList, pos, 0);
	}
	pos = Search_SequenceList(&seqList, 15);
	if (pos != -1)
	{
		Delete_SequenceList(&seqList, pos);
	}
	pos = Search_SequenceList(&seqList, 40);
	if (pos != -1)
	{
		Insert_SequenceList(&seqList, pos, 30);
	}
	Print_SequenceList(&seqList);

	Remove_SequenceList(&seqList);
	printf("*****************************EXIT*****************************\n\n");
}

int main()
{
	Test_SequenceList_01();
	Test_SequenceList_02();
	Test_SequenceList_03();
	Test_SequenceList_04();
	Test_SequenceList_05();
	Test_SequenceList_06();
	Test_SequenceList_07();
	return 0;
}