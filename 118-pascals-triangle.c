/**
 * Given a non-negative integer numRows, generate the first numRows of Pascal's triangle.
 */

#include <stdlib.h>

int** generate(int numRows, int* returnSize, int** returnColumnSizes) {
    *returnSize = numRows;
    if (numRows == 0) return 0;
    int** res = (int**)malloc(sizeof(int*) * numRows);
    *returnColumnSizes = (int*)malloc(sizeof(int) * numRows);
    for (int i = 1; i <= numRows; ++i) {
        (*returnColumnSizes)[i - 1] = i;
        res[i - 1] = (int*)malloc(sizeof(int) * i);
        res[i - 1][0] = 1;
        res[i - 1][i - 1] = 1;
        for (int j = 1; j < i - 1; ++j) {
            res[i - 1][j] = res[i - 2][j - 1] + res[i - 2][j];
        }
    }
    return res;
}