/**
 * Given a collection of distinct integers, return all possible permutations.
 */
#include <stdlib.h>
#include <string.h>

void backtrack(int** res, int* nums, int numsSize, int* returnSize, int** returnColumnSizes, int first) {
    if (first == numsSize - 1) {
        (*returnColumnSizes)[*returnSize] = numsSize;
        res[*returnSize] = (int*)malloc(sizeof(int) * numsSize);
        memcpy(res[*returnSize], nums, sizeof(int) * numsSize);
        ++(*returnSize);
    } else {
        int i, temp;
        for (i = first; i < numsSize; i++) {
            temp = nums[i];
            nums[i] = nums[first];
            nums[first] = temp;
            backtrack(res, nums, numsSize, returnSize, returnColumnSizes, first + 1);
            temp = nums[i];
            nums[i] = nums[first];
            nums[first] = temp;
        }
    }
}

int** permute(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    *returnSize = 0;
    if (numsSize == 0) return 0;
    *returnColumnSizes = (int*)malloc(sizeof(int) * 1000);
    int** res = (int**)malloc(sizeof(int*) * 1000);
    backtrack(res, nums, numsSize, returnSize, returnColumnSizes, 0);
    return res;
}