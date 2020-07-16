/**
 * Given a collection of integers that might contain duplicates, nums, return all possible subsets (the power set).
 * 
 * Note: The solution set must not contain duplicate subsets.
 */

#include <stdlib.h>

int cmp(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

void backtrack(int** res, int* nums, int numsSize, int* curr, int currSize, int first, int* returnSize, int** returnColumnsSizes) {
    res[*returnSize] = (int*)malloc(sizeof(int) * currSize);
    for (int i = 0; i < currSize; ++i) {
        res[*returnSize][i] = curr[i];
    }
    (*returnColumnsSizes)[(*returnSize)++] = currSize;
    if (first == numsSize) return;
    for (int i = first; i < numsSize; ++i) {
        if (i > first && nums[i] == nums[i - 1]) continue;
        curr[currSize] = nums[i];
        backtrack(res, nums, numsSize, curr, currSize + 1, i + 1, returnSize, returnColumnsSizes);
    }
}

int** subsetsWithDup(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    qsort(nums, numsSize, sizeof(int), cmp);
    int** res = (int**)malloc(sizeof(int*) * (1 << numsSize));
    (*returnColumnSizes) = (int*)malloc(sizeof(int) * (1 << numsSize));
    *returnSize = 0;
    int curr[numsSize];
    backtrack(res, nums, numsSize, curr, 0, 0, returnSize, returnColumnSizes);
    return res;
}