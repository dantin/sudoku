#ifndef __SUDOKU_H__
#define __SUDOKU_H__

#include <stdbool.h>

// 默认九宫格大小
#define SIZE 9

/*
 * 读用户输入数据
 */
void read( void );

/*
 * 计算数独并显示结果
 */
void sudoku( void );

#endif
