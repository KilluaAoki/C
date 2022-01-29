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
void Init_Board(char board[ROW][COL], int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			board[i][j] = ' ';
		}
	}
}

//打印棋盘
void Print_Board(char board[ROW][COL], int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			printf(" %c ", board[i][j]);
			if (j < col - 1)
			{
				printf("|");
			}
		}
		printf("\n");
		if (i < row - 1)
		{
			for (int j = 0; j < col; j++)
			{
				printf("---");
				if (j < col - 1)
				{
					printf("|");
				}

			}
			printf("\n");
		}
	}
}

//玩家回合
void Player_Move(char board[ROW][COL], int row, int col)
{
	int x = 0, y = 0;
	printf("\nPlayer move\n");
	while (1)
	{
		printf("Please enter the coordinate>>");
		scanf_s("%d %d", &x, &y);
		//判断坐标合法性
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			//判断坐标是否被占用
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = 'O';
				break;
			}
			else
			{
				printf("Error!Coordinate is occupied,Please try again.\n");
			}
		}
		else
		{
			printf("Error!Coordinate is not legal,Please try again.\n");
		}
	}
}

//电脑回合
void Computer_Move(char board[ROW][COL], int row, int col)
{
	
	printf("\nComputer move\n");
	while (1)
	{
		//随机
		int x = rand() % row, y = rand() % col;
		if (board[x][y] == ' ')
		{
			board[x][y] = 'X';
			break;
		}
	}
}

//判断输赢
int Is_Full(char board[ROW][COL], int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (board[i][j] == ' ')
			{
				return 1;
			}
		}
	}
	return 0;
}
char Winner(char board[ROW][COL], int row, int col)
{
	//行
	for (int i = 0; i < row; i++)
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ')
		{
			return board[i][0];
		}
	}
	
	//列
	for (int i = 0; i < col; i++)
	{
		if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ')
		{
			return board[0][i];
		}
	}
	
	//对角
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ')
	{
		return board[0][0];
	}
	if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ')
	{
		return board[0][2];
	}

	//平局
	int ret = Is_Full(board, ROW, COL);
	if (ret == 0)
	{
		return '?';
	}
	return '~';
}