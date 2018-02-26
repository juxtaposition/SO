#include "helpers.h"
#include <stdio.h>

void drawRows(int rows, int cols, int (*array)[], int size)
{
}

void drawCols(int rows, int cols, int (*array)[], int size)
{
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
