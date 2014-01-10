#include <stdio.h>
#include <math.h>
#include <stdbool.h>

#include "sudoku.h"

// 数独矩阵
static int matrix[ SIZE * SIZE ];

// bit-vectors，缓存已经使用过的数字，规则如下：
//
//   - 如果第i个数字已使用，则 2^(i-1)对应的bit位为1
//   - 否则，2^(i-1)对应的bit位为0
static int cols[ SIZE ];  // 行
static int rows[ SIZE ];  // 列
static int grids[ SIZE ]; // 网格

/*
 * 打印数据矩阵内容
 */
static void print( void )
{

}

static int find( void )
{
}

static bool set( const int loc, const int num )
{
  return false;
}

static void unset( const int loc )
{
}

void sudoku( void )
{
}

/*
 * 读入用户的输入数据，并保存至数独矩阵
 *
 * 输入数据规则如下：
 *   - 0 和 . 代表空白位；
 *   - 1~9 是合法数字；
 *   - 以#开始的行是注释；
 *   - 所有非[0-9.]字符都被忽略；
 *
 * 保存至数独的规则如下：
 *   - 每次读入一个字符进行保存；
 *   - 按从左到右、从上到下的次序；
 *   - 空白用0表示；
 */
void read( void )
{

}
