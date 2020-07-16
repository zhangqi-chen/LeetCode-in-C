/**
 * Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.
 */

#include <stdlib.h>

void dfs(int** res, int* curr, int n, int k, int idx, int start, int* returnSize, int** returnColumnSizes) {
    if (idx == k) {
        res[*returnSize] = (int*)malloc(sizeof(int) * k);
        for (int i = 0; i < k; ++i) {
            res[*returnSize][i] = curr[i];
        }
        (*returnColumnSizes)[(*returnSize)++] = k;
    } else {
        for (int i = start; i < n - k + idx + 1; ++i) {
            curr[idx] = i + 1;
            dfs(res, curr, n, k, idx + 1, i + 1, returnSize, returnColumnSizes);
        }
    }
}

int** combine(int n, int k, int* returnSize, int** returnColumnSizes) {
    *returnSize = 0;
    if (k > n) return 0;
    int num = 1;
    for (int i = 0; i < k; ++i) {
        num = num * (n - i) / (i + 1);
    }
    *returnColumnSizes = (int*)malloc(sizeof(int) * num);
    int** res = (int**)malloc(sizeof(int*) * num);
    int curr[k];
    dfs(res, curr, n, k, 0, 0, returnSize, returnColumnSizes);
    return res;
}