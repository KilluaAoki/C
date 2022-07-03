#include "Game.h"

void Game()
{
	system("cls");
	char mine_board[ROWS][COLS];
	char show_board[ROWS][COLS];
	//初始化变量
	Init_Board(mine_board, ROWS, COLS, '0');
	Init_Board(show_board, ROWS, COLS, '*');
	//打印棋盘
	Print_Board(show_board, ROW, COL);
	//布置雷
	Set_Board(mine_board, ROW, COL);
	//排查雷
	Find_Board(mine_board, show_board, ROW, COL);
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