#ifndef HELPERS_H_
#define HELPERS_H_

void drawRows(int m, int n, int OffsetRows, int OffsetCols, int array[m][n], int size);
void drawCols(int rows, int cols, int (*array)[], int size);
void printMatrix(int (*array)[]);

// Testing
void sizeMatrix(int (*array)[10]);

#endif
