/*
 * Copyright (c) david, all rights reserved.
 *
 * filename    : main.c
 * author      : david
 *
 * description : 计算数独的C语言代码
 */
#include <stdio.h>
#include "sudoku.h"

int main( void )
{
  read();

  printf( "Result(s):\n" );
  sudoku();

  return 0;
}
