/**
 * Given a collection of numbers that might contain duplicates, return all possible unique permutations.
 */

#include <stdlib.h>
#include <string.h>

void backtrack(int** res, int* nums, int numsSize, int* returnSize, int** returnColumnSizes, int min, int max, int first) {
    if (first == numsSize - 1) {
        (*returnColumnSizes)[*returnSize] = numsSize;
        res[*returnSize] = (int*)malloc(sizeof(int) * numsSize);
        memcpy(res[*returnSize], nums, sizeof(int) * numsSize);
        ++(*returnSize);
    } else {
        int i, j, temp;
        int* repeat = (int*)malloc(sizeof(int) * (max - min + 1));
        memset(repeat, 0, sizeof(int) * (max - min + 1));
        for (i = first; i < numsSize; i++) {
            if (repeat[nums[i] - min] == 1) continue;
            repeat[nums[i] - min] = 1;
            temp = nums[i];
            nums[i] = nums[first];
            nums[first] = temp;
            backtrack(res, nums, numsSize, returnSize, returnColumnSizes, min, max, first + 1);
            temp = nums[i];
            nums[i] = nums[first];
            nums[first] = temp;
        }
        free(repeat);
    }
}

int** permuteUnique(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    *returnSize = 0;
    if (numsSize == 0) return 0;
    *returnColumnSizes = (int*)malloc(sizeof(int) * 1000);
    int** res = (int**)malloc(sizeof(int*) * 1000);
    int min = nums[0], max = nums[0];
    for (int i = 1; i < numsSize; ++i) {
        min = nums[i] < min ? nums[i] : min;
        max = nums[i] > max ? nums[i] : max;
    }
    backtrack(res, nums, numsSize, returnSize, returnColumnSizes, min, max, 0);
    return res;
}