/**
 * Given an unsorted integer array, find the smallest missing positive integer.
 */
#include <stdlib.h>

int firstMissingPositive(int* nums, int numsSize) {
    int i, temp;
    for (i = 0; i < numsSize; i++) {
        if (nums[i] <= 0) nums[i] = numsSize + 1;  // numsSize+1 won't be scanned.
    }
    for (i = 0; i < numsSize; i++) {
        temp = abs(nums[i]);
        if (temp <= numsSize && temp > 0 && nums[temp - 1] > 0)
            nums[temp - 1] = -nums[temp - 1];  // mark with negative sign.
    }
    for (i = 0; i < numsSize; i++) {
        if (nums[i] >= 0) return i + 1;  // first positive number is the answer.
    }
    return i + 1;
}
