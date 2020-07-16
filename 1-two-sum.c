/**
 * Given an array of integers, return indices of the two numbers such that they add up to a specific target.
 * You may assume that each input would have exactly one solution, and you may not use the same element twice.
 */

#include <stdio.h>
#include <stdlib.h>

int *twoSum(int *nums, int numsSize, int target, int *returnSize) {
    int i, j;
    int *res = (int *)malloc(sizeof(int) * 2);
    for (i = 0; i < numsSize; i++) {
        for (j = i + 1; j < numsSize; j++) {
            if (nums[i] + nums[j] == target) {
                *returnSize = 2;
                res[0] = i;
                res[1] = j;
                return res;
            }
        }
    }
    *returnSize = 0;
    return res;
}

int main() {
    int nums[] = {2, 7, 11, 15};
    int rsize;
    int *returnSize = &rsize;
    int *res = twoSum(nums, 4, 18, returnSize);
    printf("Target=18, answer 1=%d, answer 2=%d", nums[res[0]], nums[res[1]]);
    free(res);
    return 0;
}