#include "Game.h"

//菜单
void Menu()
{
	printf("******************************\n");
	printf("**********  1.Play  **********\n");
	printf("**********  0.Exit  **********\n");
	printf("******************************\n");
}

//初始化棋盘
void Init_Board(char board[ROWS][COLS], int rows, int cols, char set)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			board[i][j] = set;
		}
	}
}

//打印棋盘
void Print_Board(char board[ROWS][COLS], int row, int col)
{
	//打印列数
	for (int i = 0; i <= col; i++)
	{
		printf("%d ", i);
	}
	printf("\n");
	//打印行
	for (int i = 1; i <= row; i++)
	{
		//打印行数
		printf("%d ", i);
		//打印列
		for (int j = 1; j <= col; j++)
		{
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
}

//布置雷
void Set_Board(char board[ROWS][COLS], int row, int col)
{
	int count = BOMB;
	while (count)
	{
		int x = rand() % row + 1;
		int y = rand() % col + 1;
		if (board[x][y] == '0')
		{
			board[x][y] = '1';
			count--;
		}
	}
}

//判断坐标周围炸弹的个数
int Get_Mine_Count(char mine_board[ROWS][COLS], int x, int y)
{
	int count = 0;
	for (int i = -1; i <= 1; i++)
	{
		for (int j = -1; j <= 1; j++)
		{
			if (mine_board[x + i][y + j] == '1')
			{
				count++;
			}
		}
	}
	return count;
}

//排查雷
void Find_Board(char mine_board[ROWS][COLS], char show_board[ROWS][COLS], int row, int col)
{
	int x = 0, y = 0, win = 0;
	while (win < row * col - BOMB)
	{
		printf("\nPlease enter the coordinate>>");
		scanf_s("%d%d", &x, &y);
		//判断坐标合法性
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (mine_board[x][y] == '1')
			{
				system("cls");
				printf("\nGame over!You were blown up!\n\n");
				Print_Board(mine_board, ROW, COL);
				printf("\n");
				system("pause");
				break;
			}
			else
			{
				int count = Get_Mine_Count(mine_board, x, y);
				show_board[x][y] = '0' + count;
				system("cls");
				Print_Board(show_board, ROW, COL);
				win++;
			}
		}
		else
		{
			printf("Error!Coordinate is not legal,Please try again.\n");
		}
	}
	if (win == row * col - BOMB)
	{
		system("cls");
		printf("\nYou're winner!\n\n");
		Print_Board(mine_board, ROW, COL);
		printf("\n");
		system("pause");
	}
}