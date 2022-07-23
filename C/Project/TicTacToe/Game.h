#pragma once

//引用头文件
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

//定义标识符
#define ROW 3 //行数(ROW)
#define COL 3 //列数(COL)
#define WIN 3 //获胜连棋数(WIN)

//菜单
void Menu();

//游戏主框架
void Game();

//初始化棋盘
void InitBoard(char board[ROW][COL], int row, int col);

//打印棋盘
void PrintBoard(char board[ROW][COL], int row, int col);

//玩家移动
char PlayerMove(char board[ROW][COL], int row, int col);

//电脑移动
char ComputerMove(char board[ROW][COL], int row, int col);

//判断输赢
char JudgmentWinner(char board[ROW][COL], int x, int y);