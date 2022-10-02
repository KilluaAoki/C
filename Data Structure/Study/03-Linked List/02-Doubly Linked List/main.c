#include "Doubly Linked List.h"

void Test_DoublyLinkedList_01()
{
	printf("**************************************************01**************************************************\n");
	DLLNode* phead = Init_DoublyLinkedListNode();

	Head_Insert_DoublyLinkedListNode(phead, 4);
	Head_Insert_DoublyLinkedListNode(phead, 3);
	Head_Insert_DoublyLinkedListNode(phead, 2);
	Head_Insert_DoublyLinkedListNode(phead, 1);
	Print_DoublyLinkedList(phead);
	Tail_Insert_DoublyLinkedListNode(phead, 5);
	Tail_Insert_DoublyLinkedListNode(phead, 6);
	Tail_Insert_DoublyLinkedListNode(phead, 7);
	Tail_Insert_DoublyLinkedListNode(phead, 8);
	Print_DoublyLinkedList(phead);
	Head_Insert_DoublyLinkedListNode(phead, 0);
	Tail_Insert_DoublyLinkedListNode(phead, 9);
	Print_DoublyLinkedList(phead);
	printf("The length of the Doubly Linked List is %zu.\n", Length_DoublyLinkedList(phead));

	Destroy_DoublyLinkedList(phead);
	phead = NULL;
	printf("************************************************EXIT************************************************\n\n");
}

void Test_DoublyLinkedList_02()
{
	printf("**************************************************02**************************************************\n");
	DLLNode* phead = Init_DoublyLinkedListNode();

	Head_Insert_DoublyLinkedListNode(phead, 4);
	Head_Delete_DoublyLinkedListNode(phead);
	Head_Insert_DoublyLinkedListNode(phead, 3);
	Head_Insert_DoublyLinkedListNode(phead, 2);
	Head_Insert_DoublyLinkedListNode(phead, 1);
	Print_DoublyLinkedList(phead);
	Head_Delete_DoublyLinkedListNode(phead);
	Print_DoublyLinkedList(phead);
	Head_Delete_DoublyLinkedListNode(phead);
	Print_DoublyLinkedList(phead);
	Head_Delete_DoublyLinkedListNode(phead);
	Print_DoublyLinkedList(phead);
	Head_Insert_DoublyLinkedListNode(phead, 0);
	Tail_Insert_DoublyLinkedListNode(phead, 1);
	Tail_Insert_DoublyLinkedListNode(phead, 2);
	Tail_Insert_DoublyLinkedListNode(phead, 3);
	Print_DoublyLinkedList(phead);
	Head_Delete_DoublyLinkedListNode(phead);
	Print_DoublyLinkedList(phead);
	printf("The length of the Doubly Linked List is %zu.\n", Length_DoublyLinkedList(phead));

	Destroy_DoublyLinkedList(phead);
	phead = NULL;
	printf("************************************************EXIT************************************************\n\n");
}

void Test_DoublyLinkedList_03()
{
	printf("**************************************************03**************************************************\n");
	DLLNode* phead = Init_DoublyLinkedListNode();

	Head_Insert_DoublyLinkedListNode(phead, 0);
	Tail_Delete_DoublyLinkedListNode(phead);
	Tail_Insert_DoublyLinkedListNode(phead, 2);
	Tail_Insert_DoublyLinkedListNode(phead, 3);
	Tail_Insert_DoublyLinkedListNode(phead, 4);
	Tail_Insert_DoublyLinkedListNode(phead, 5);
	Head_Insert_DoublyLinkedListNode(phead, 1);
	Head_Insert_DoublyLinkedListNode(phead, 0);
	Print_DoublyLinkedList(phead);
	Head_Delete_DoublyLinkedListNode(phead);
	Print_DoublyLinkedList(phead);
	Tail_Delete_DoublyLinkedListNode(phead);
	Print_DoublyLinkedList(phead);
	Tail_Delete_DoublyLinkedListNode(phead);
	Print_DoublyLinkedList(phead);
	Tail_Delete_DoublyLinkedListNode(phead);
	Print_DoublyLinkedList(phead);
	Tail_Delete_DoublyLinkedListNode(phead);
	Print_DoublyLinkedList(phead);
	Tail_Delete_DoublyLinkedListNode(phead);
	Print_DoublyLinkedList(phead);
	printf("The length of the Doubly Linked List is %zu.\n", Length_DoublyLinkedList(phead));

	Destroy_DoublyLinkedList(phead);
	phead = NULL;
	printf("************************************************EXIT************************************************\n\n");
}

void Test_DoublyLinkedList_04()
{
	printf("**************************************************04**************************************************\n");
	DLLNode* phead = Init_DoublyLinkedListNode();

	Insert_DoublyLinkedListNode(phead, phead, 4);
	DLLNode* pos = Search_DoublyLinkedListNode(phead, 4);
	if (pos != NULL)
	{
		Insert_DoublyLinkedListNode(phead, pos, 3);
	}
	pos = Search_DoublyLinkedListNode(phead, 3);
	if (pos != NULL)
	{
		Insert_DoublyLinkedListNode(phead, pos, 2);
	}
	pos = Search_DoublyLinkedListNode(phead, 2);
	if (pos != NULL)
	{
		Insert_DoublyLinkedListNode(phead, pos, 1);
	}
	Print_DoublyLinkedList(phead);
	Head_Insert_DoublyLinkedListNode(phead, 0);
	Tail_Delete_DoublyLinkedListNode(phead);
	Print_DoublyLinkedList(phead);
	Head_Delete_DoublyLinkedListNode(phead);
	Print_DoublyLinkedList(phead);
	Insert_DoublyLinkedListNode(phead, phead, 4);
	Print_DoublyLinkedList(phead);
	Tail_Insert_DoublyLinkedListNode(phead, 5);
	Print_DoublyLinkedList(phead);
	printf("The length of the Doubly Linked List is %zu.\n", Length_DoublyLinkedList(phead));

	Destroy_DoublyLinkedList(phead);
	phead = NULL;
	printf("************************************************EXIT************************************************\n\n");
}

void Test_DoublyLinkedList_05()
{
	printf("**************************************************05**************************************************\n");
	DLLNode* phead = Init_DoublyLinkedListNode();

	Insert_DoublyLinkedListNode(phead, phead, 4);
	DLLNode* pos = Search_DoublyLinkedListNode(phead, 4);
	if (pos != NULL)
	{
		Insert_DoublyLinkedListNode(phead, pos, 3);
	}
	pos = Search_DoublyLinkedListNode(phead, 3);
	if (pos != NULL)
	{
		Insert_DoublyLinkedListNode(phead, pos, 2);
	}
	pos = Search_DoublyLinkedListNode(phead, 2);
	if (pos != NULL)
	{
		Insert_DoublyLinkedListNode(phead, pos, 1);
	}
	Print_DoublyLinkedList(phead);
	Head_Insert_DoublyLinkedListNode(phead, 0);
	Tail_Delete_DoublyLinkedListNode(phead);
	Print_DoublyLinkedList(phead);
	Head_Delete_DoublyLinkedListNode(phead);
	Print_DoublyLinkedList(phead);
	Insert_DoublyLinkedListNode(phead, phead, 4);
	Print_DoublyLinkedList(phead);
	Tail_Insert_DoublyLinkedListNode(phead, 5);
	Print_DoublyLinkedList(phead);
	printf("The length of the Doubly Linked List is %zu.\n", Length_DoublyLinkedList(phead));

	Destroy_DoublyLinkedList(phead);
	phead = NULL;
	printf("************************************************EXIT************************************************\n\n");
}

void Test_DoublyLinkedList_06()
{
	printf("**************************************************06**************************************************\n");
	DLLNode* phead = Init_DoublyLinkedListNode();

	Insert_DoublyLinkedListNode(phead, phead, 4);
	Tail_Insert_DoublyLinkedListNode(phead, 5);
	Tail_Insert_DoublyLinkedListNode(phead, 7);
	Tail_Insert_DoublyLinkedListNode(phead, 8);
	Tail_Insert_DoublyLinkedListNode(phead, 9);
	Head_Insert_DoublyLinkedListNode(phead, 3);
	Head_Insert_DoublyLinkedListNode(phead, 1);
	Head_Insert_DoublyLinkedListNode(phead, 2);
	Head_Insert_DoublyLinkedListNode(phead, 0);
	Print_DoublyLinkedList(phead);
	DLLNode* pos = Search_DoublyLinkedListNode(phead, 1);
	if (pos != NULL)
	{
		Erase_DoublyLinkedList(pos);
	}
	Print_DoublyLinkedList(phead);
	pos = Search_DoublyLinkedListNode(phead, 8);
	if (pos != NULL)
	{
		pos->data = 6;
	}
	pos = Search_DoublyLinkedListNode(phead, 7);
	if (pos != NULL)
	{
		Erase_DoublyLinkedList(pos);
	}
	pos = Search_DoublyLinkedListNode(phead, 9);
	if (pos != NULL)
	{
		Erase_DoublyLinkedList(pos);
	}
	pos = Search_DoublyLinkedListNode(phead, 2);
	if (pos != NULL)
	{
		Insert_DoublyLinkedListNode(phead, pos, 1);
	}
	Print_DoublyLinkedList(phead);
	printf("The length of the Doubly Linked List is %zu.\n", Length_DoublyLinkedList(phead));

	Destroy_DoublyLinkedList(phead);
	phead = NULL;
	printf("************************************************EXIT************************************************\n\n");
}

int main()
{
	Test_DoublyLinkedList_01();
	Test_DoublyLinkedList_02();
	Test_DoublyLinkedList_03();
	Test_DoublyLinkedList_04();
	Test_DoublyLinkedList_05();
	Test_DoublyLinkedList_06();
	return 0;
}