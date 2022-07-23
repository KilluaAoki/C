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
void InitBoard(char board[ROW][COL], int row, int col)
{
	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < col; ++j)
		{
			board[i][j] = ' ';
		}
	}
}

//打印棋盘
void PrintBoard(char board[ROW][COL], int row, int col)
{
	printf("\n");
	if (row < 10)
	{
		for (int i = 0; i < COL; i++)
		{
			printf("   %d", i + 1);
		}
	}
	else
	{
		for (int i = 0; i < COL; i++)
		{
			printf("  %-2d", i + 1);
		}
	}
	printf("\n");
	for (int i = 0; i < row; ++i)
	{
		printf("%-2d", i + 1);
		for (int j = 0; j < col; ++j)
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
			printf("  ");
			for (int j = 0; j < col; ++j)
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

//玩家移动
char PlayerMove(char board[ROW][COL], int row, int col)
{
	printf("\nPlayer move\n");
	while (1)
	{
		int x = 0, y = 0;
		printf("Please enter the coordinate>>");
		scanf_s("%d%d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = 'O';
				char ret = JudgmentWinner(board, x - 1, y - 1);
				return ret;
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

//电脑移动
char ComputerMove(char board[ROW][COL], int row, int col)
{
	printf("\nComputer move\n");
	while (1)
	{
		int x = rand() % row, y = rand() % col;
		if (board[x][y] == ' ')
		{
			board[x][y] = 'X';
			char ret = JudgmentWinner(board, x, y);
			return ret;
		}
	}
}

//判断平局(仅由"JudgmentWinner"函数调用)
int JudgmentTie(char board[ROW][COL], int row, int col)
{
	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < col; ++j)
		{
			if (board[i][j] == ' ')
			{
				return 1;
			}
		}
	}
	return 0;
}

//判断输赢
char JudgmentWinner(char board[ROW][COL], int x, int y)
{
	int count = 1;

	//判断行
	for (int i = y + 1; i < COL; ++i)
	{
		if (board[x][i] == ' ')
		{
			break;
		}
		if (board[x][i] == board[x][y])
		{
			count++;
		}
	}
	for (int i = y - 1; i >= 0; --i)
	{
		if (board[x][i] == ' ')
		{
			break;
		}
		if (board[x][i] == board[x][y])
		{
			count++;
		}
	}
	if (count >= WIN)
	{
		return board[x][y];
	}

	//判断列
	count = 1;
	for (int i = x + 1; i < ROW; ++i)
	{
		if (board[i][y] == ' ')
		{
			break;
		}
		if (board[i][y] == board[x][y])
		{
			count++;
		}
	}
	for (int i = x - 1; i >= 0; --i)
	{
		if (board[i][y] == ' ')
		{
			break;
		}
		if (board[x][y] == board[i][y])
		{
			count++;
		}

	}
	if (count >= WIN)
	{
		return board[x][y];
	}

	//判断左上到右下对角线
	count = 1;
	for (int i = x + 1, j = y + 1; i < ROW && j < COL; ++i, ++j)
	{
		if (board[i][j] == ' ')
		{
			break;
		}
		if (board[x][y] == board[i][j])
		{
			count++;
		}
	}
	for (int i = x - 1, j = y - 1; i >= 0 && j >= 0; --i, --j)
	{
		if (board[i][j] == ' ')
		{
			break;
		}
		if (board[x][y] == board[i][j])
		{
			count++;
		}
	}
	if (count >= WIN)
	{
		return board[x][y];
	}

	//判断右上到左下对角线
	count = 1;
	for (int i = x + 1, j = y - 1; i < ROW && j >= 0; ++i, --j)
	{
		if (board[i][j] == ' ')
		{
			break;
		}
		if (board[x][y] == board[i][j])
		{
			count++;
		}
	}
	for (int i = x - 1, j = y + 1; i >= 0 && j < COL; --i, ++j)
	{
		if (board[i][j] == ' ')
		{
			break;
		}
		if (board[x][y] == board[i][j])
		{
			count++;
		}
	}
	if (count >= WIN)
	{
		return board[x][y];
	}

	//判断是否产生平局
	int ret = JudgmentTie(board, ROW, COL);
	if (ret == 0)
	{
		return '?';
	}
	return '~';
}

//游戏主框架
void Game()
{
	system("cls");
	srand((unsigned int)time(NULL));
	char ret;
	char board[ROW][COL];
	InitBoard(board, ROW, COL);
	PrintBoard(board, ROW, COL);
	while (1)
	{
		//玩家回合：玩家走"O"。
		ret = PlayerMove(board, ROW, COL);
		PrintBoard(board, ROW, COL);
		if (ret != '~')
		{
			break;
		}

		//电脑回合：电脑走"X"。
		ret = ComputerMove(board, ROW, COL);
		PrintBoard(board, ROW, COL);
		if (ret != '~')
		{
			break;
		}
	}
	system("cls");
	PrintBoard(board, ROW, COL);
	if (ret == 'O')
	{
		printf("\nPlayer Winner!\n\n");
		system("pause");
	}
	if (ret == 'X')
	{
		printf("\nComputer Winner!\n\n");
		system("pause");
	}
	if (ret == '?')
	{
		printf("\nTie!\n\n");
		system("pause");
	}
}