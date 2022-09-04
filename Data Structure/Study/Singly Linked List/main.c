#include "Singly Linked List.h"

void Test_SinglyLinkedList_01()
{
	printf("******************************01******************************\n");
	SLLNode* phead = NULL;

	Head_Insert_SinglyLinkedListNode(&phead, 2);
	Print_SinglyLinkedList(phead);
	Head_Insert_SinglyLinkedListNode(&phead, 1);
	Print_SinglyLinkedList(phead);
	Head_Insert_SinglyLinkedListNode(&phead, 0);
	Print_SinglyLinkedList(phead);
	Head_Insert_SinglyLinkedListNode(&phead, -1);
	Print_SinglyLinkedList(phead);
	Head_Insert_SinglyLinkedListNode(&phead, -2);
	Print_SinglyLinkedList(phead);

	Destroy_SinglyLinkedListNode(&phead);
	printf("*****************************EXIT*****************************\n\n");
}

void Test_SinglyLinkedList_02()
{
	printf("******************************02******************************\n");
	SLLNode* phead = NULL;

	Tail_Insert_SinglyLinkedListNode(&phead, 0);
	Print_SinglyLinkedList(phead);
	Head_Insert_SinglyLinkedListNode(&phead, -1);
	Print_SinglyLinkedList(phead);
	Tail_Insert_SinglyLinkedListNode(&phead, 1);
	Print_SinglyLinkedList(phead);
	Head_Insert_SinglyLinkedListNode(&phead, -2);
	Print_SinglyLinkedList(phead);
	Tail_Insert_SinglyLinkedListNode(&phead, 2);
	Print_SinglyLinkedList(phead);

	Destroy_SinglyLinkedListNode(&phead);
	printf("*****************************EXIT*****************************\n\n");
}

void Test_SinglyLinkedList_03()
{
	printf("******************************03******************************\n");
	SLLNode* phead = NULL;

	Tail_Insert_SinglyLinkedListNode(&phead, 0);
	Head_Delete_SinglyLinkedListNode(&phead);
	Print_SinglyLinkedList(phead);
	Head_Insert_SinglyLinkedListNode(&phead, -1);
	Print_SinglyLinkedList(phead);
	Tail_Insert_SinglyLinkedListNode(&phead, 1);
	Head_Delete_SinglyLinkedListNode(&phead);
	Print_SinglyLinkedList(phead);
	Head_Insert_SinglyLinkedListNode(&phead, -2);
	Print_SinglyLinkedList(phead);
	Tail_Insert_SinglyLinkedListNode(&phead, 2);
	Head_Delete_SinglyLinkedListNode(&phead);
	Print_SinglyLinkedList(phead);
	Head_Insert_SinglyLinkedListNode(&phead, 0);
	Tail_Insert_SinglyLinkedListNode(&phead, 3);
	Head_Delete_SinglyLinkedListNode(&phead);
	Print_SinglyLinkedList(phead);

	Destroy_SinglyLinkedListNode(&phead);
	printf("*****************************EXIT*****************************\n\n");
}

void Test_SinglyLinkedList_04()
{
	printf("******************************04******************************\n");
	SLLNode* phead = NULL;

	Tail_Insert_SinglyLinkedListNode(&phead, 0);
	Tail_Delete_SinglyLinkedListNode(&phead);
	Print_SinglyLinkedList(phead);
	Tail_Insert_SinglyLinkedListNode(&phead, 1);
	Tail_Insert_SinglyLinkedListNode(&phead, 2);
	Tail_Delete_SinglyLinkedListNode(&phead);
	Print_SinglyLinkedList(phead);
	Tail_Insert_SinglyLinkedListNode(&phead, 2);
	Tail_Insert_SinglyLinkedListNode(&phead, 3);
	Tail_Insert_SinglyLinkedListNode(&phead, 4);
	Tail_Insert_SinglyLinkedListNode(&phead, 5);
	Tail_Delete_SinglyLinkedListNode(&phead);
	Print_SinglyLinkedList(phead);
	Head_Insert_SinglyLinkedListNode(&phead, 0);
	Print_SinglyLinkedList(phead);

	Destroy_SinglyLinkedListNode(&phead);
	printf("*****************************EXIT*****************************\n\n");
}

void Test_SinglyLinkedList_05()
{
	printf("******************************05******************************\n");
	SLLNode* phead = NULL;

	Tail_Insert_SinglyLinkedListNode(&phead, 0);
	SLLNode* pos = Search_SinglyLinkedListNode(phead, 0);
	if (pos != NULL)
	{
		Before_Insert_SinglyLinkedListNode(&phead, pos, -1);
	}
	Print_SinglyLinkedList(phead);
	Head_Delete_SinglyLinkedListNode(&phead);
	Tail_Insert_SinglyLinkedListNode(&phead, 2);
	pos = Search_SinglyLinkedListNode(phead, 2);
	if (pos != NULL)
	{
		Before_Insert_SinglyLinkedListNode(&phead, pos, 1);
	}
	Print_SinglyLinkedList(phead);
	Tail_Insert_SinglyLinkedListNode(&phead, 3);
	pos = Search_SinglyLinkedListNode(phead, 0);
	if (pos != NULL)
	{
		Before_Insert_SinglyLinkedListNode(&phead, pos, -1);
	}
	Print_SinglyLinkedList(phead);

	pos = Search_SinglyLinkedListNode(phead, 3);
	if (pos != NULL)
	{
		After_Insert_SinglyLinkedListNode(pos, 4);
	}
	pos = Search_SinglyLinkedListNode(phead, 4);
	if (pos != NULL)
	{
		After_Insert_SinglyLinkedListNode(pos, 7);
	}
	Head_Insert_SinglyLinkedListNode(&phead, -3);
	pos = Search_SinglyLinkedListNode(phead, -3);
	if (pos != NULL)
	{
		After_Insert_SinglyLinkedListNode(pos, -2);
	}
	Print_SinglyLinkedList(phead);
	pos = Search_SinglyLinkedListNode(phead, 7);
	if (pos != NULL)
	{
		pos->data = 5;
	}
	Print_SinglyLinkedList(phead);
	Tail_Insert_SinglyLinkedListNode(&phead, 6);
	Print_SinglyLinkedList(phead);
	pos = NULL;

	Destroy_SinglyLinkedListNode(&phead);
	printf("*****************************EXIT*****************************\n\n");
}

void Test_SinglyLinkedList_06()
{
	printf("******************************06******************************\n");
	SLLNode* phead = NULL;

	Tail_Insert_SinglyLinkedListNode(&phead, 0);
	SLLNode* pos = Search_SinglyLinkedListNode(phead, 0);
	if (pos != NULL)
	{
		Erase_SinglyLinkedListNode(&phead, pos);
	}
	Print_SinglyLinkedList(phead);
	Tail_Insert_SinglyLinkedListNode(&phead, 1);
	Tail_Insert_SinglyLinkedListNode(&phead, 3);
	Print_SinglyLinkedList(phead);
	pos = Search_SinglyLinkedListNode(phead, 3);
	if (pos != NULL)
	{
		Erase_SinglyLinkedListNode(&phead, pos);
	}
	Print_SinglyLinkedList(phead);
	Tail_Insert_SinglyLinkedListNode(&phead, 2);
	Tail_Insert_SinglyLinkedListNode(&phead, 3);
	Tail_Insert_SinglyLinkedListNode(&phead, 9);
	Tail_Insert_SinglyLinkedListNode(&phead, 4);
	Print_SinglyLinkedList(phead);
	pos = Search_SinglyLinkedListNode(phead, 9);
	if (pos != NULL)
	{
		Erase_SinglyLinkedListNode(&phead, pos);
	}
	Print_SinglyLinkedList(phead);
	Head_Insert_SinglyLinkedListNode(&phead, 0);
	Print_SinglyLinkedList(phead);
	pos = Search_SinglyLinkedListNode(phead, 0);
	if (pos != NULL)
	{
		Erase_SinglyLinkedListNode(&phead, pos);
	}
	Print_SinglyLinkedList(phead);
	pos = NULL;

	Destroy_SinglyLinkedListNode(&phead);
	printf("*****************************EXIT*****************************\n\n");
}

void Test_SinglyLinkedList_07()
{
	printf("******************************07******************************\n");
	SLLNode* phead = NULL;

	Tail_Insert_SinglyLinkedListNode(&phead, 0);
	Tail_Insert_SinglyLinkedListNode(&phead, 1);
	Print_SinglyLinkedList(phead);
	SLLNode* pos = Search_SinglyLinkedListNode(phead, 1);
	if (pos != NULL)
	{
		Before_Erase_SinglyLinkedListNode(&phead, pos);
	}
	Print_SinglyLinkedList(phead);
	Tail_Insert_SinglyLinkedListNode(&phead, 2);
	Tail_Insert_SinglyLinkedListNode(&phead, 5);
	Tail_Insert_SinglyLinkedListNode(&phead, 6);
	Tail_Insert_SinglyLinkedListNode(&phead, 3);
	Print_SinglyLinkedList(phead);
	pos = Search_SinglyLinkedListNode(phead, 3);
	if (pos != NULL)
	{
		Before_Erase_SinglyLinkedListNode(&phead, pos);
	}
	Print_SinglyLinkedList(phead);
	pos = Search_SinglyLinkedListNode(phead, 2);
	if (pos != NULL)
	{
		After_Erase_SinglyLinkedListNode(pos);
	}
	Print_SinglyLinkedList(phead);
	pos = NULL;

	Destroy_SinglyLinkedListNode(&phead);
	printf("*****************************EXIT*****************************\n\n");
}

void Test_SinglyLinkedList_08()
{
	printf("******************************08******************************\n");
	SLLNode* phead = NULL;

	Print_SinglyLinkedList(phead);
	printf("Singly Linked List Length = %zu\n", Length_SinglyLinkedList(phead));
	Tail_Insert_SinglyLinkedListNode(&phead, 5);
	Tail_Insert_SinglyLinkedListNode(&phead, 6);
	Tail_Insert_SinglyLinkedListNode(&phead, 7);
	Head_Insert_SinglyLinkedListNode(&phead, 4);
	Print_SinglyLinkedList(phead);
	printf("Singly Linked List Length = %zu\n", Length_SinglyLinkedList(phead));
	Head_Insert_SinglyLinkedListNode(&phead, 3);
	Head_Insert_SinglyLinkedListNode(&phead, 2);
	Head_Insert_SinglyLinkedListNode(&phead, 1);
	Head_Insert_SinglyLinkedListNode(&phead, 0);
	Print_SinglyLinkedList(phead);
	printf("Singly Linked List Length = %zu\n", Length_SinglyLinkedList(phead));

	Destroy_SinglyLinkedListNode(&phead);
	printf("*****************************EXIT*****************************\n\n");
}

int main()
{
	Test_SinglyLinkedList_01();
	Test_SinglyLinkedList_02();
	Test_SinglyLinkedList_03();
	Test_SinglyLinkedList_04();
	Test_SinglyLinkedList_05();
	Test_SinglyLinkedList_06();
	Test_SinglyLinkedList_07();
	Test_SinglyLinkedList_08();
	return 0;
}