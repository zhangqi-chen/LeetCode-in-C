/**
 * Given an array nums of n integers and an integer target, find three integers
 * in nums such that the sum is closest to target. Return the sum of the three
 * integers. You may assume that each input would have exactly one solution.
 */
#include <stdio.h>
#include <stdlib.h>

int cmp(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int threeSumClosest(int* nums, int numsSize, int target) {
    qsort(nums, numsSize, sizeof(int), cmp);
    int i, j, k, curr, ans;
    ans = nums[0] + nums[1] + nums[2];
    for (i = 0; i < numsSize - 2; i++) {
        j = i + 1;
        k = numsSize - 1;
        while (j < k) {
            curr = nums[i] + nums[j] + nums[k];
            if (abs(ans - target) > abs(curr - target)) ans = curr;
            if (curr < target)
                j++;
            else if (curr > target)
                k--;
            else
                return target;
        }
    }
    return ans;
}