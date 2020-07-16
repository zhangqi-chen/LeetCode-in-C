/**
 * Given a collection of candidate numbers (candidates) and a target
 * number (target), find all unique combinations in candidates where
 * the candidate numbers sums to target.
 * 
 * Each number in candidates may only be used once in the combination.
 * 
 * Note:
 * 
 * All numbers (including target) will be positive integers.
 * The solution set must not contain duplicate combinations.
 */

#include <stdlib.h>

int cmp(const void* a, const void* b) {
    return (*(int*)b - *(int*)a);
}

int** combinationSum2(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes) {
    *returnSize = 0;
    *returnColumnSizes = (int*)malloc(sizeof(int));
    (*returnColumnSizes)[0] = 0;
    int** res = (int**)malloc(sizeof(int*));
    if (target == 0) {
        *returnSize = 1;
        return res;
    } else if (candidatesSize == 0)
        return res;
    qsort(candidates, candidatesSize, sizeof(int), cmp);
    int **currRes, *rSize, **rcSize;
    int i, j, k, curr, c;
    i = 0;
    while (i < candidatesSize) {
        c = candidates[i];
        if (target == c) {
            *returnColumnSizes = (int*)realloc(*returnColumnSizes, sizeof(int) * (*returnSize + 1));
            res = (int**)realloc(res, sizeof(int*) * (*returnSize + 1));
            (*returnColumnSizes)[*returnSize] = 1;
            res[*returnSize] = (int*)malloc(sizeof(int));
            res[*returnSize][0] = target;
            (*returnSize)++;
        } else if (target > c) {
            rSize = (int*)malloc(sizeof(int));
            rcSize = (int**)malloc(sizeof(int*));
            currRes = (int**)malloc(sizeof(int*));
            curr = target - c;
            currRes = combinationSum2(candidates + i + 1, candidatesSize - i - 1, curr, rSize, rcSize);
            if (*rSize > 0) {
                *returnColumnSizes = (int*)realloc(*returnColumnSizes, sizeof(int) * (*returnSize + *rSize));
                res = (int**)realloc(res, sizeof(int*) * (*returnSize + *rSize));
                for (j = 0; j < *rSize; j++) {
                    (*returnColumnSizes)[*returnSize] = (*rcSize)[j] + 1;
                    res[*returnSize] = (int*)malloc(sizeof(int) * ((*rcSize)[j] + 1));
                    res[*returnSize][0] = candidates[i];
                    for (k = 1; k <= (*rcSize)[j]; k++) {
                        res[*returnSize][k] = currRes[j][k - 1];
                    }
                    (*returnSize)++;
                }
            }
            free(rSize);
            free(rcSize);
            free(currRes);
        }
        for (; i < candidatesSize && c == candidates[i]; i++) {
        }
    }
    return res;
}
