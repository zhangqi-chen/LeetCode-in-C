/**
 * Given a non-negative index k where k ≤ 33, return the kth index row of the Pascal's triangle.
 */

#include <stdlib.h>

int* getRow(int rowIndex, int* returnSize) {
    *returnSize = rowIndex + 1;
    int* res = (int*)malloc(sizeof(int) * (rowIndex + 1));
    for (int i = 0; i <= rowIndex; ++i) {
        res[i] = 1;
    }
    for (int i = 2; i <= rowIndex; ++i) {
        for (int j = i - 1; j > 0; --j) {
            res[j] = res[j] + res[j - 1];
        }
    }
    return res;
}