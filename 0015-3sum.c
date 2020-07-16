/**
 * Given an array nums of n integers, are there elements a, b, c in nums such that
 * a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.
 */

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

#include <stdio.h>
#include <stdlib.h>

int cmp(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    *returnColumnSizes = (int*)malloc(sizeof(int) * numsSize * 6);
    *returnSize = 0;
    int** res = (int**)malloc(sizeof(int*) * numsSize * 6);
    if (numsSize == 0) return res;
    res[*returnSize] = (int*)malloc(sizeof(int) * 3);
    int i, j, k;
    qsort(nums, numsSize, sizeof(int), cmp);
    i = 0;
    while (i < numsSize - 2) {
        j = i + 1;
        k = numsSize - 1;
        while (k > j) {
            if (nums[i] + nums[j] + nums[k] < 0)
                j++;
            else if (nums[i] + nums[j] + nums[k] > 0)
                k--;
            else {
                res[*returnSize][0] = nums[i];
                res[*returnSize][1] = nums[j];
                res[*returnSize][2] = nums[k];
                (*returnColumnSizes)[*returnSize] = 3;
                (*returnSize)++;
                res[*returnSize] = (int*)malloc(sizeof(int) * 3);
                while (nums[j] == nums[++j] && j < k) {
                }
                while (nums[k] == nums[--k] && j < k) {
                }
            }
        }
        while (nums[i] == nums[++i] && i < numsSize - 2) {
        }
    }
    return res;
}

int main() {
    int nums[] = {-1, 0, 1, 2, -1, -4};
    int nsize = 6, rsizet;
    int *rsize = &rsizet, *rcsizet;
    int** rcsize = &rcsizet;
    int** ans;
    ans = threeSum(nums, nsize, rsize, rcsize);
    for (int i = 0; i < *rsize; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", ans[i][j]);
        }
        printf(":%d\n", (*rcsize)[i]);
    }
    return 0;
}