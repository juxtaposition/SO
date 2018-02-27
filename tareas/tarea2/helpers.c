#include "helpers.h"
#include <stdio.h>

void drawRows(int m, int n, int OffsetRows, int OffsetCols, int array[m][n], int size)
{
  for(int i = 1; i <= size; i++)
  {
     array[OffsetRows][OffsetCols + i] = '-';
  }
}

void drawCols(int m, int n, int OffsetRows, int OffsetCols, int array[m][n], int size)
{
  for(int i = 1; i <= size; i++)
  {
    array[OffsetRows + i][OffsetCols] = '|';
  }
}

void printMatrix(int (*array)[])
{
 for(int i = 0; i < 10; i++)
  {
    for(int j = 0; j < 10; j++)
    {
    printf("%d", (*array)[j]);
    }
   printf("\n");
  }
}

/* 
  Ejemplo sencillo para pasar un apuntador a un arreglo
  bidemencional
*/
void sizeMatrix(int (*array)[])
{
  for(int i = 0; i < 10; i++)
  {
    for(int j = 0; j < 10; j++)
    {
    (*array)[j] = 0;
    }
  }
}
