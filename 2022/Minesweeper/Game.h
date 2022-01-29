#pragma once

//引用头文件
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

//定义标识符
#define BOMB 80
#define ROW 9
#define COL 9
#define ROWS ROW+2
#define COLS COL+2

//声明函数
void Menu();
void Init_Board(char board[ROWS][COLS], int rows, int cols, char set);
void Print_Board(char board[ROWS][COLS], int row, int col);
void Set_Board(char board[ROWS][COLS], int row, int col);
void Find_Board(char mine_board[ROWS][COLS], char show_board[ROWS][COLS], int row, int col);