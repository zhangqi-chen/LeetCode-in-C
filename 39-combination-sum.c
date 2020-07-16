/**
 * Given a set of candidate numbers (candidates) (without duplicates) and a target
 * number (target), find all unique combinations in candidates where the candidate
 * numbers sums to target.
 * 
 * The same repeated number may be chosen from candidates unlimited number of times.
 * 
 * Note:
 * All numbers (including target) will be positive integers.
 * The solution set must not contain duplicate combinations.
 */

#include <stdlib.h>

int** combinationSum(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes) {
    *returnSize = 0;
    *returnColumnSizes = (int*)malloc(sizeof(int));
    (*returnColumnSizes)[0] = 0;
    int** res = (int**)malloc(sizeof(int*));
    if (target == 0) {
        *returnSize = 1;
        return res;
    } else if (candidatesSize == 0)
        return res;
    int **currRes, *rSize, **rcSize;
    int i, j, k, curr;
    for (i = 0; i < candidatesSize; i++) {
        if (target == candidates[i]) {
            *returnColumnSizes = (int*)realloc(*returnColumnSizes, sizeof(int) * (*returnSize + 1));
            res = (int**)realloc(res, sizeof(int*) * (*returnSize + 1));
            (*returnColumnSizes)[*returnSize] = 1;
            res[*returnSize] = (int*)malloc(sizeof(int));
            res[*returnSize][0] = target;
            (*returnSize)++;
        } else if (target > candidates[i]) {
            rSize = (int*)malloc(sizeof(int));
            rcSize = (int**)malloc(sizeof(int*));
            currRes = (int**)malloc(sizeof(int*));
            curr = target - candidates[i];
            currRes = combinationSum(candidates + i, candidatesSize - i, curr, rSize, rcSize);
            if (*rSize == 0) {
                continue;
            } else {
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
            free(currRes);
            free(rSize);
            free(rcSize);
        }
    }
    return res;
}