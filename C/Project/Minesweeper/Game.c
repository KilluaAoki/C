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
void InitBoard(char board[ROWS][COLS], int rows, int cols, char value)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			board[i][j] = value;
		}
	}
}

//打印棋盘
void PrintBoard(char board[ROWS][COLS], int row, int col)
{
	printf("\n\t\t\t\t\t\t----Minesweeper----\n\n\t\t\t\t\t\t");
	for (int i = 0; i <= col; i++)
	{
		printf("%d ", i);
	}
	printf("\n");
	for (int i = 1; i <= row; i++)
	{
		printf("\t\t\t\t\t\t%d ", i);
		for (int j = 1; j <= col; j++)
		{
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
}

//设置炸弹
void SetBombs(char bomb_board[ROWS][COLS], int row, int col)
{
	int bombs = BOMB;
	while (bombs)
	{
		int x = rand() % row + 1, y = rand() % col + 1;
		if (bomb_board[x][y] == '0')
		{
			bomb_board[x][y] = '1';
			bombs--;
		}
	}
}

//更改炸弹
void ChangeBombs(char bomb_board[ROWS][COLS], int x, int y)
{
	do
	{
		int rand_x = rand() % ROW + 1, rand_y = rand() % COL + 1;
		if (bomb_board[rand_x][rand_y] == '0')
		{
			bomb_board[rand_x][rand_y] = '1';
			bomb_board[x][y] = '0';
			break;
		}
	} while (1);
}

//获取坐标周围的炸弹数量
int GetBombsCount(char bomb_board[ROWS][COLS], int x, int y)
{
	int count = 0;
	for (int i = x - 1; i <= x + 1; ++i)
	{
		for (int j = y - 1; j <= y + 1; ++j)
		{
			if (bomb_board[i][j] == '1')
			{
				count++;
			}
		}
	}
	return count;
}

//自动展开棋盘
void ExpandBoard(char bomb_board[ROWS][COLS], char show_board[ROWS][COLS], int x, int y, int* ptr)
{
	if (x == 0 || y == 0 || x == ROWS - 1 || y == COLS - 1 || show_board[x][y] != '*')
	{
		return;
	}
	int ret = GetBombsCount(bomb_board, x, y);
	if (ret > 0)
	{
		(*ptr)++;
		show_board[x][y] = (char)(48 + ret);
		return;
	}
	else
	{
		show_board[x][y] = ' ';
		for (int i = x - 1; i <= x + 1; ++i)
		{
			for (int j = y - 1; j <= y + 1; ++j)
			{
				if (i == x && j == y)
				{
					continue;
				}
				ExpandBoard(bomb_board, show_board, i, j, ptr);
			}
		}
	}
	(*ptr)++;
}

//排查炸弹
void CheckBombs(char bomb_board[ROWS][COLS], char show_board[ROWS][COLS], int row, int col)
{
	int x, y, win = 0;
	while (win < row * col - BOMB)
	{
		printf("\nPlease enter the coordinate>>");
		scanf_s("%d%d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (show_board[x][y] == '*')
			{
				if (win == 0 && bomb_board[x][y] == '1')
				{
					ChangeBombs(bomb_board, x, y);
				}
				if (bomb_board[x][y] == '1')
				{
					system("cls");
					printf("\nGame over!You were blown up!\n\n");
					PrintBoard(bomb_board, ROW, COL);
					printf("\n");
					system("pause");
					break;
				}
				else
				{
					ExpandBoard(bomb_board, show_board, x, y, &win);
					system("cls");
					PrintBoard(show_board, ROW, COL);
				}
			}
			else
			{
				printf("Error!Repeatedly entering coordinates,Please try again.");
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
		PrintBoard(bomb_board, ROW, COL);
		printf("\n");
		system("pause");
	}
}

//游戏主框架
void Game()
{
	system("cls");
	srand((unsigned)time(NULL));
	char bomb_board[ROWS][COLS];
	char show_board[ROWS][COLS];
	InitBoard(bomb_board, ROWS, COLS, '0');
	InitBoard(show_board, ROWS, COLS, '*');
	PrintBoard(show_board, ROW, COL);
	SetBombs(bomb_board, ROW, COL);
	CheckBombs(bomb_board, show_board, ROW, COL);
}