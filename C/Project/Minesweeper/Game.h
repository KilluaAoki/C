#pragma once

//引用头文件
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <windows.h>

//定义标识符
#define ROW 9        //定义二维数组行数(ROW)
#define COL 9        //定义二维数组列数(COL)
#define BOMB 10      //定义炸弹个数(BOMB)
#define ROWS ROW+2   //定义棋盘行数(ROWS)
#define COLS COL+2   //定义棋盘列数(COLS)

//菜单
void Menu();

//游戏主框架
void Game();

//初始化棋盘
void InitBoard(char board[ROWS][COLS], int rows, int cols, char value);

//打印棋盘
void PrintBoard(char board[ROWS][COLS], int row, int col);

//设置炸弹
void SetBombs(char board[ROWS][COLS], int row, int col);

//获取坐标周围的炸弹数量
int GetBombsCount(char bomb_board[ROWS][COLS], int x, int y);

//排查炸弹
void CheckBombs(char bomb_board[ROWS][COLS], char show_board[ROWS][COLS], int row, int col);

//更改炸弹(防止第一次被炸死)
void ChangeBombs(char bomb_board[ROWS][COLS], int x, int y);

//自动展开棋盘
void ExpandBoard(char bomb_board[ROWS][COLS], char show_board[ROWS][COLS], int x, int y, int* ptr);