#ifndef __SUDOKU_H__
#define __SUDOKU_H__

#include <stdbool.h>

#define SIZE 9

void sudoku( void );
void read( void );
void print( void );

int find( void );
bool set( const int loc, const int num );
void unset( const int loc );

#endif
