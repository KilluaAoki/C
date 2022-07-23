#include "Game.h"

int main()
{
	int input = 0;
	do
	{
		system("cls");
		Menu();
		printf("Please enter>>");
		scanf_s("%d", &input);
		switch (input)
		{
		case 1:
			Game();
			break;
		case 0:
			printf("\nExit!\n");
			break;
		default:
			printf("\nError!Please try again.\n\n");
			system("pause");
			break;
		}
	} while (input);
	return 0;
}