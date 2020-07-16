/**
 * Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.
 */

int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize) {
    int rows = matrixSize;
    int cols = matrixColSize[0];
    *returnSize = rows * cols;
    int* ans = (int*)malloc(sizeof(int) * (*returnSize));
    if (*returnSize == 0) return ans;
    int min = rows < cols ? rows : cols;
    int i, j, k = 0;
    for (i = 0; i < (min - 1) / 2 + 1; ++i) {
        if (i * 2 + 1 == rows) {
            for (j = i; j <= cols - 1 - i; ++j) {
                ans[k++] = matrix[i][j];
            }
            break;
        } else if (i * 2 + 1 == cols) {
            for (j = i; j <= rows - 1 - i; ++j) {
                ans[k++] = matrix[j][i];
            }
            break;
        }
        for (j = i; j < cols - 1 - i; ++j) {
            ans[k++] = matrix[i][j];
        }
        for (j = i; j < rows - 1 - i; ++j) {
            ans[k++] = matrix[j][cols - 1 - i];
        }
        for (j = cols - 1 - i; j > i; --j) {
            ans[k++] = matrix[rows - 1 - i][j];
        }
        for (j = rows - 1 - i; j > i; --j) {
            ans[k++] = matrix[j][i];
        }
    }
    return ans;
}