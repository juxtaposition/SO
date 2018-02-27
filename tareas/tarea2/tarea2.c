#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "helpers.h"
#define COL 7
#define ROW 10



int main()
{
int size = 4; // Leer del archivo
int rowMatrix = ((size * 2) + 3);
int colMatrix = (size + 2);


int cantidad = 10;


typedef int arrelo_matrix[cantidad * colMatrix];
arrelo_matrix *matrix;

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

// Llenamos de ceros la matriz
for(int row = 0; row < rowMatrix; row++)
{
  for(int col = 0; col < (colMatrix * cantidad); col++)
  { 
    *(*(matrix + row) + col) = ' ';
  }
}

// Pintamos los numeros dependiendo de la cantidad indicada
for(int i = 0; i < cantidad; i++)
{
  for(int j = 0; j < rowMatrix; j++)
  {
    switch(numbers[i][j])
    {
     case '-':
       if(j == 0) {
       drawRows(rowMatrix, cantidad * colMatrix, 0,
               (i * colMatrix), matrix, size);
       } else if(j == 3) {
       drawRows(rowMatrix, cantidad * colMatrix, size + 1,
               (i * colMatrix), matrix, size);
       } else if(j == 6) {
       drawRows(rowMatrix, cantidad * colMatrix, (size*2) + 2,
               (i * colMatrix), matrix, size);
       }
       break;
     case '|':
       if(j == 1) {
       drawCols(rowMatrix, cantidad * colMatrix, 0,
               (i * colMatrix), matrix, size);
       } else if(j == 2) {
       drawCols(rowMatrix, cantidad * colMatrix, 0,
               (colMatrix-1) + (i * colMatrix), matrix, size);
       } else if(j == 4) {
       drawCols(rowMatrix, cantidad * colMatrix, size + 1,
               (i * colMatrix), matrix, size);
       } else if(j == 5) {
       drawCols(rowMatrix, cantidad * colMatrix, size + 1,
               (colMatrix-1) + (i * colMatrix), matrix, size);
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

return 0;
}
