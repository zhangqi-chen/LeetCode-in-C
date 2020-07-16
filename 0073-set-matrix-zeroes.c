/**
 * Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in-place.
 */

#define SETVAL -100000

void setZeroes(int** matrix, int matrixSize, int* matrixColSize) {
    for (int i = 0; i < matrixSize; ++i) {
        for (int j = 0; j < matrixColSize[0]; ++j) {
            if (matrix[i][j] == 0) {
                matrix[i][j] = SETVAL;
                for (int k = 0; k < matrixColSize[0]; ++k) {
                    if (matrix[i][k] != 0 && matrix[i][k] != SETVAL) matrix[i][k] = SETVAL;
                }
                for (int k = 0; k < matrixSize; ++k) {
                    if (matrix[k][j] != 0 && matrix[k][j] != SETVAL) matrix[k][j] = SETVAL;
                }
            }
        }
    }
    for (int i = 0; i < matrixSize; ++i) {
        for (int j = 0; j < matrixColSize[0]; ++j) {
            if (matrix[i][j] == SETVAL)
                matrix[i][j] = 0;
        }
    }
}