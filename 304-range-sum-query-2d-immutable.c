/**
 * Given a 2D matrix matrix, find the sum of the elements inside the rectangle defined by its upper left corner
 * (row1, col1) and lower right corner (row2, col2).
 */

#include <stdlib.h>

typedef struct {
    int** matrix;
    int** dict;
} NumMatrix;

NumMatrix* numMatrixCreate(int** matrix, int matrixSize, int* matrixColSize) {
    NumMatrix mtx;
    mtx.matrix = matrix;
    if (matrixSize == 0 || matrixColSize[0] == 0) return &mtx;
    mtx.dict = (int**)malloc(sizeof(int*) * matrixSize);
    for (int i = 0; i < matrixSize;++i){
        mtx.dict[i] = (int*)malloc(sizeof(int) * matrixColSize[0]);
        for (int j = 0; j < matrixColSize[0];++j){
            mtx.dict[i][j] = -1;
        }
    }
    return &mtx;
}

int sumMatrix(NumMatrix* obj, int row, int col){
    if (row < 0 || col < 0) return 0;
    int** mtx = obj->matrix;
    int** dict = obj->dict;
    if (dict[row][col] >= 0) return dict[row][col];
}

int numMatrixSumRegion(NumMatrix* obj, int row1, int col1, int row2, int col2) {

}

void numMatrixFree(NumMatrix* obj) {
    free(obj->matrix);
    free(obj->dict);
    free(obj);
}