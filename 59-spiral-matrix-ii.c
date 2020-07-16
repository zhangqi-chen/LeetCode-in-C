/**
 * Given a positive integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.
 */

#include <stdlib.h>

int** generateMatrix(int n, int* returnSize, int** returnColumnSizes) {
    *returnSize = n;
    (*returnColumnSizes) = (int*)malloc(sizeof(int) * n);
    if (n == 0) return 0;
    int** res = (int**)malloc(sizeof(int*) * n);
    int i, j, k = 0;
    for (i = 0; i < n; ++i) {
        (*returnColumnSizes)[i] = n;
        res[i] = (int*)malloc(sizeof(int) * n);
    }
    for (i = 0; i < n / 2; ++i) {
        for (j = i; j < n - 1 - i; ++j) {
            res[i][j] = ++k;
        }
        for (j = i; j < n - 1 - i; ++j) {
            res[j][n - 1 - i] = ++k;
        }
        for (j = n - 1 - i; j > i; --j) {
            res[n - 1 - i][j] = ++k;
        }
        for (j = n - 1 - i; j > i; --j) {
            res[j][i] = ++k;
        }
    }
    if (i * 2 + 1 == n) res[i][i] = ++k;
    return res;
}