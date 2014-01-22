#include <stdio.h>
#include <math.h>
#include <stdbool.h>

#include "sudoku.h"

// 默认九宫格大小
#define SIZE 9

#define SEP_LINE "+------+------+------+"

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
 * 打印数独矩阵内容
 */
static void print( void )
{
  int r, c;

  for( r = 0; r < SIZE; r++ ) {
    if( r % 3 == 0 ) {
      printf( "%s\n", SEP_LINE );
    }
    for( c = 0; c < SIZE; c++ ) {
      if( c % 3 == 0 ) {
	printf( "|" );
      }
      int num = matrix[ r * SIZE + c ];
      if( num == 0 ) {
	printf( ". ");
      } else {
	printf( "%d ", num );
      }
    }
    printf( "|\n" );
  }

  printf( "%s\n\n", SEP_LINE );
}

/*
 * 在数独矩阵中找到第一个待解元素的序号，找不到返回-1
 */
static int find( void )
{
  int i;

  for( i = 0; i < SIZE * SIZE; i++ ) {
    if( matrix[i] == 0 ) {
      return i;
    }
  }

  return -1;
}

/*
 * 设置数独矩阵中序号为loc的值为num
 *
 *   成功返回true
 *   失败返回false
 */
static bool set( const int loc, const int num )
{
  int r = loc / SIZE;
  int c = loc % SIZE;
  int g = ( r / 3 ) * 3 + c / 3;

  bool valid = matrix[loc] == 0
    && ( cols[c] & ( 1 << num ) ) == 0
    && ( rows[r] & ( 1 << num ) ) == 0
    && ( grids[g] & ( 1 << num ) ) == 0;

  if( !valid ) {
    return false;
  }

  matrix[loc] = num;
  cols[c] |= ( 1 << num );
  rows[r] |= ( 1 << num );
  grids[g] |= ( 1 << num );

  return true;
}

/*
 * 清楚数独矩阵中序号为loc的值
 */
static void unset( const int loc )
{
  int r = loc / SIZE;
  int c = loc % SIZE;
  int g = ( r / 3 ) * 3 + c / 3;

  int num = matrix[loc];
  matrix[loc] = 0;
  cols[c] ^= ( 1 << num );
  rows[r] ^= ( 1 << num );
  grids[g] ^= ( 1 << num );
}

/*
 * 计算数独并显示结果
 */
void sudoku( void )
{
  int loc = find();
  if( loc < 0 ) {
    print();
    return;
  }

  int n;
  for( n = 1; n < 10; n++ ) {
    if( set( loc, n ) ) {
      sudoku();
      unset( loc );
    }
  }
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
  int loc, c;

  for( loc = 0; loc < SIZE * SIZE; ) {
    c = getchar();

    if( c == EOF ) {
      break;
    }

    if( c == '#' ) {
      while( ( c = getchar() ) && c >= 0 && c != '\n' && c != '\r' ) {
	;
      }
    } else if( c >= '1' && c <= '9' ) {
      set( loc, c - '0' );
      loc++;
    } else if( c == '.' || c == '0' ) {
      loc++;
    }
  }

  printf( "Sudoku Game:\n" );
  print();
}
