#include "Game.h"

void Game()
{
	system("cls");
	char ret;
	char board[ROW][COL];
	Init_Board(board, ROW, COL);
	Print_Board(board, ROW, COL);
	while (1)
	{
		//玩家走：“O”
		Player_Move(board, ROW, COL);
		Print_Board(board, ROW, COL);
		//判断输赢
		ret = Winner(board, ROW, COL);
		if (ret != '~')
		{
			break;
		}
		
		//电脑走：“X”
		Computer_Move(board, ROW, COL);
		Print_Board(board, ROW, COL);
		//判断输赢
		ret = Winner(board, ROW, COL);
		if (ret != '~')
		{
			break;
		}
	}
	system("cls");
	Print_Board(board, ROW, COL);
	if (ret == 'O')
	{
		printf("\nPlayer Winner\n\n");
		system("pause");
	}
	if (ret == 'X')
	{
		printf("\nComputer Winner\n\n");
		system("pause");
	}
	if (ret == '?')
	{
		printf("\nFlat\n\n");
		system("pause");
	}
}

int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));
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