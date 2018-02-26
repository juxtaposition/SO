#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "helpers.h"
#define COL 7
#define ROW 10



int main()
{
int indice = 0;
int pivote = 0;
int size = 2; // Leer del archivo
int rowMatrix = ((size * 2) + 3);
int colMatrix = (size + 2);

int cantidad = 10;

typedef int arrelo_matrix[cantidad * colMatrix];
arrelo_matrix *matrix;

/*
  Ejemplo para pasar como argumento un arreglo bidemencional 
*/
typedef int simpleMatrix[10];
simpleMatrix *simple;
simple = malloc((10 * 10) * sizeof(int));
/*
  Ejemplo para pasar como argumento un arreglo bidemencional 
*/

int numbers[ROW][COL] = {
  {'-', '|', '|', ' ', '|', '|', '-'},  /* Number zero */
  {' ', ' ', '|', ' ', ' ', '|', ' '},  /* Number one*/
  {'-', ' ', '|', '-', '|', ' ', '-'},  /* Number one*/
  {'-', ' ', '|', '-', ' ', '|', '-'},  /* Number one*/
  {' ', '|', '|', '-', ' ', '|', ' '},  /* Number one*/
  {'-', '|', ' ', '-', ' ', '|', '-'},  /* Number one*/
  {'-', '|', ' ', '-', '|', '|', '-'},  /* Number one*/
  {'-', ' ', '|', ' ', ' ', '|', ' '},  /* Number one*/
  {'-', '|', '|', '-', '|', '|', '-'},  /* Number one*/
  {'-', '|', '|', '-', ' ', '|', ' '}  /* Number one*/
};


matrix = malloc((rowMatrix * (cantidad * colMatrix)) * sizeof(int));

for(int row = 0; row < rowMatrix; row++)
{
  for(int col = 0; col < (colMatrix * cantidad); col++)
  {
    *(*(matrix + row) + col) = ' ';
  }
}


for(int i = 0; i < cantidad; i++)
{
  for(int j = 0; j < rowMatrix; j++)
  {
   //printf("Cordenada (%d,%d) = %c\n",i,j,numbers[i][j]);
    switch(numbers[i][j])
    {
     case '-':
       if(j == 0) {
       //*(*(matrix ) + 1 + (i * colMatrix)) = '-';
       //*(*(matrix ) + 2 + (i * colMatrix)) = '-';
       drawRows(rowMatrix, cantidad * colMatrix, 0, (i * colMatrix), matrix, size);
       } else if(j == 3) {
       pivote = 3;
       //*(*(matrix + pivote) + 1 + (i * colMatrix)) = '-';
       //*(*(matrix + pivote) + 2 + (i * colMatrix)) = '-';
       drawRows(rowMatrix, cantidad * colMatrix, 3, (i * colMatrix), matrix, size);
       } else if(j == 6) {
       pivote = 6;
       //*(*(matrix + pivote) + 1 + (i * colMatrix)) = '-';
       //*(*(matrix + pivote) + 2 + (i * colMatrix)) = '-';
       drawRows(rowMatrix, cantidad * colMatrix, 6, (i * colMatrix), matrix, size);
       }
       break;
     case '|':
       if(j == 1) {
       *(*(matrix + 1) + (i * colMatrix)) = '|';
       *(*(matrix + 2) + (i * colMatrix)) = '|';
       } else if(j == 2) {
       indice = 1;
       *(*(matrix + indice) + (colMatrix-1) + (i * colMatrix)) = '|';
       *(*(matrix + indice + 1) + (colMatrix-1) + (i * colMatrix)) = '|';
       } else if(j == 4) {
       indice = colMatrix;
        *(*(matrix + indice) + (i * colMatrix)) = '|';
        *(*(matrix + indice + 1) + (i * colMatrix)) = '|';
       } else if(j == 5) {
       indice = colMatrix;
        *(*(matrix + indice) + (colMatrix-1) + (i * colMatrix)) = '|';
        *(*(matrix + indice + 1) + (colMatrix-1) + (i * colMatrix)) = '|';
       }
       break;
    }
  }
}



for(int row = 0; row < rowMatrix; row++)
{
  for(int col = 0; col < (colMatrix * cantidad); col++)
  {
    printf("%c", *(*(matrix + row) + col));
  }
  printf("\n");
}

/* 
  Ejemplo sencillo para pasar un apuntador a un arreglo
  bidemencional
*/
//sizeMatrix(simple);
//printMatrix(simple);

return 0;
}
