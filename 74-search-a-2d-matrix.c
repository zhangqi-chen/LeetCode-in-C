/**
 * Write an efficient algorithm that searches for a value in an m x n matrix. This matrix
 * has the following properties:
 * 
 * Integers in each row are sorted from left to right.
 * The first integer of each row is greater than the last integer of the previous row.
 */

#include <stdbool.h>

int searchRows(int** matrix, int r1, int r2, int target) {
    if (target < matrix[r1][0]) return -1;
    if (r1 == r2) return r1;
    if (target >= matrix[r2][0]) return r2;
    int newr = (r1 + r2) / 2;
    if (target >= matrix[newr][0])
        return searchRows(matrix, newr, r2 - 1, target);
    else
        return searchRows(matrix, r1, newr - 1, target);
}

bool searchCols(int** matrix, int r, int c1, int c2, int target) {
    if (target < matrix[r][c1] || target > matrix[r][c2]) return false;
    if (target == matrix[r][c1] || target == matrix[r][c2]) return true;
    if (c1 + 1 >= c2) return false;
    int newc = (c1 + c2) / 2;
    if (target >= matrix[r][newc])
        return searchCols(matrix, r, newc, c2 - 1, target);
    else
        return searchCols(matrix, r, c1 + 1, newc - 1, target);
}
bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target) {
    if (matrixSize == 0 || matrixColSize[0] == 0) return false;
    int rows = matrixSize;
    int cols = matrixColSize[0];
    int r = searchRows(matrix, 0, rows - 1, target);
    if (r < 0) return false;
    return searchCols(matrix, r, 0, cols - 1, target);
}