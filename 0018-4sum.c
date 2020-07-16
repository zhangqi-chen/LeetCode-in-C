/**
 * Given an array nums of n integers and an integer target, are there elements
 * a, b, c, and d in nums such that a + b + c + d = target? Find all unique
 * quadruplets in the array which gives the sum of target.
 */

#include <stdlib.h>

int cmp(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int** fourSum(int* nums, int numsSize, int target, int* returnSize, int** returnColumnSizes) {
    *returnColumnSizes = (int*)malloc(sizeof(int) * numsSize * 3);
    *returnSize = 0;
    int** res = (int**)malloc(sizeof(int*) * numsSize * 3);
    if (numsSize == 0) return res;
    res[*returnSize] = (int*)malloc(sizeof(int) * 4);
    int i, j, k, l, curr;
    qsort(nums, numsSize, sizeof(int), cmp);
    i = 0;
    while (i < numsSize - 3) {
        j = i + 1;
        while (j < numsSize - 2) {
            k = j + 1;
            l = numsSize - 1;
            curr = target - nums[i] - nums[j];
            while (k < l) {
                if (nums[k] + nums[l] < curr) {
                    k++;
                } else if (nums[k] + nums[l] > curr) {
                    l--;
                } else {
                    res[*returnSize][0] = nums[i];
                    res[*returnSize][1] = nums[j];
                    res[*returnSize][2] = nums[k];
                    res[*returnSize][3] = nums[l];
                    (*returnColumnSizes)[*returnSize] = 4;
                    (*returnSize)++;
                    res[*returnSize] = (int*)malloc(sizeof(int) * 4);
                    while (nums[k] == nums[++k] && k < l) {
                    }
                    while (nums[l] == nums[--l] && k < l) {
                    }
                }
            }
            while (nums[j] == nums[++j] && j < numsSize - 2) {
            }
        }
        while (nums[i] == nums[++i] && i < numsSize - 3) {
        }
    }
    return res;
}
