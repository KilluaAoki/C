#pragma once

//引用头文件
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

//定义标识符
#define ROW 3
#define COL 3

//声明函数
void Menu();
void Init_Board(char board[ROW][COL], int row, int col);
void Print_Board(char board[ROW][COL], int row, int col);
void Player_Move(char board[ROW][COL], int row, int col);
void Computer_Move(char board[ROW][COL], int row, int col);
char Winner(char board[ROW][COL], int row, int col);