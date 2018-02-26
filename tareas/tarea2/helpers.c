#include "helpers.h"
#include <stdio.h>

void drawRows(int OffsetRows, int OffsetCols, int (*array)[], int size)
{
  for(int i = 1; i <= size; i++)
  {
    (*array + OffsetRows)[OffsetCols + i] = '-';
    //*(*(matrix + offsetRows) + i + (offSetCols)) = '-';
  }
}

void drawCols(int rows, int cols, int (*array)[], int size)
{
  for(int i = 0; i < size; i++)
  {
    (*array + rows + (size))[cols] = '|';
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
