#include "Contacts.h"

int main()
{
	int input = 0;
	Contacts contacts;
	Init_Contacts(&contacts);
	do
	{
		Menu();
		printf("Please enter>>");
		scanf_s("%d", &input);
		switch (input)
		{
		case ADD:
			Add_Contacts(&contacts);
			Clear();
			break;
		case DEL:
			Del_Contacts(&contacts);
			Clear();
			break;
		case SEARCH:
			Search_Contacts(&contacts);
			Clear();
			break;
		case MODIFY:
			Modify_Contacts(&contacts);
			Clear();
			break;
		case SORT:
			Sort_Contacts(&contacts);
			system("cls");
			break;
		case PRINT:
			Point_Contacts(&contacts);
			Clear();
			break;
		case EXIT:
			printf("\nExit!\n");
			break;
		default:
			printf("\nError!Please try again.\n\n");
			Clear();
			break;
		}
	} while (input);
	return 0;
}