#include "Singly Linked List.h"

void Test_01()
{
	SLLNode* phead = NULL;
	Head_Insert_SinglyLinkedListNode(&phead, 2);
	Head_Insert_SinglyLinkedListNode(&phead, 1);
	Head_Insert_SinglyLinkedListNode(&phead, 0);
	Tail_Insert_SinglyLinkedListNode(&phead, 3);
	Tail_Insert_SinglyLinkedListNode(&phead, 4);
	Head_Delete_SinglyLinkedListNode(&phead);
	Tail_Delete_SinglyLinkedListNode(&phead);
	Print_SinglyLinkedList(phead);
	Destroy_SinglyLinkedListNode(&phead);
}

void Test_02()
{
	SLLNode* phead = NULL;
	Head_Insert_SinglyLinkedListNode(&phead, 2);
	SLLNode* pos = Search_SinglyLinkedListNode(phead, 2);
	Before_Insert_SinglyLinkedListNode(&phead, pos, 0);
	Before_Insert_SinglyLinkedListNode(&phead, pos, 1);
	After_Insert_SinglyLinkedListNode(pos, 3);
	pos = Search_SinglyLinkedListNode(phead, 0);
	Erase_SinglyLinkedListNode(&phead, pos);
	pos = Search_SinglyLinkedListNode(phead, 3);
	Erase_SinglyLinkedListNode(&phead, pos);
	pos = Search_SinglyLinkedListNode(phead, 2);
	Before_Erase_SinglyLinkedListNode(&phead, pos);
	After_Insert_SinglyLinkedListNode(pos, 3);
	After_Erase_SinglyLinkedListNode(pos);
	Print_SinglyLinkedList(phead);
	Destroy_SinglyLinkedListNode(&phead);
}

void Test_03()
{
	SLLNode* phead = NULL;
	Head_Insert_SinglyLinkedListNode(&phead, 2);
	Head_Insert_SinglyLinkedListNode(&phead, 1);
	Head_Insert_SinglyLinkedListNode(&phead, 0);
	Tail_Insert_SinglyLinkedListNode(&phead, 3);
	Tail_Insert_SinglyLinkedListNode(&phead, 4);
	Print_SinglyLinkedList(phead);
	printf("The length of the list is %d.\n", Length_SinglyLinkedList(phead));
	Destroy_SinglyLinkedListNode(&phead);
}

void Test_04()
{
	SLLNode* phead = NULL;
	Head_Insert_SinglyLinkedListNode(&phead, 2);
	Head_Insert_SinglyLinkedListNode(&phead, 1);
	Head_Insert_SinglyLinkedListNode(&phead, 0);
	Tail_Insert_SinglyLinkedListNode(&phead, 3);
	Tail_Insert_SinglyLinkedListNode(&phead, 4);
	Print_SinglyLinkedList(phead);
	SLLNode* pos = Search_SinglyLinkedListNode(phead, 3);
	if (pos)
	{
		pos->data *= 10;
		printf("Found it.\n");
	}
	else
	{
		printf("Could not find it.\n");
	}
	Print_SinglyLinkedList(phead);
	pos = Search_SinglyLinkedListNode(phead, 2);
	if (pos)
	{
		Before_Insert_SinglyLinkedListNode(&phead, pos, 20);
	}
	Print_SinglyLinkedList(phead);
	pos = Search_SinglyLinkedListNode(phead, 1);
	if (pos)
	{
		Before_Insert_SinglyLinkedListNode(&phead, pos, 10);
	}
	Print_SinglyLinkedList(phead);
	Destroy_SinglyLinkedListNode(&phead);
}

int main()
{
	//Test_01();

	//Test_02();

	//Test_03();

	//Test_04();

	return 0;
}