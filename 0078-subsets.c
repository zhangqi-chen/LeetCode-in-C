/**
 * Given a set of distinct integers, nums, return all possible subsets (the power set).
 * 
 * Note: The solution set must not contain duplicate subsets.
 */

#include <math.h>
#include <stdlib.h>

void dfs(int** res, int* nums, int numsSize, int* curr, int idx, int start, int* returnSize, int** returnColumnSizes) {
    res[*returnSize] = (int*)malloc(sizeof(int) * idx);
    for (int i = 0; i < idx; ++i) {
        res[*returnSize][i] = curr[i];
    }
    (*returnColumnSizes)[(*returnSize)++] = idx;
    if (start < numsSize) {
        for (int i = start; i < numsSize; ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            curr[idx] = nums[i];
            dfs(res, nums, numsSize, curr, idx + 1, i + 1, returnSize, returnColumnSizes);
        }
    }
}

int** subsets(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    *returnSize = 0;
    int n = pow(2, numsSize);
    *returnColumnSizes = (int*)malloc(sizeof(int) * n);
    int** res = (int**)malloc(sizeof(int*) * n);
    int curr[numsSize];
    dfs(res, nums, numsSize, curr, 0, 0, returnSize, returnColumnSizes);
    return res;
}