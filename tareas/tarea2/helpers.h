#ifndef HELPERS_H_
#define HELPERS_H_

void drawRows(int rows, int cols, int (*array)[], int size);
void drawCols(int rows, int cols, int (*array)[], int size);
void printMatrix(int (*array)[]);

// Testing
void sizeMatrix(int (*array)[10]);

#endif
