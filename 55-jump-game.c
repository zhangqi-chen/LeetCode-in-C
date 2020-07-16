/**
 * Given an array of non-negative integers, you are initially positioned at the first index of the array.
 * 
 * Each element in the array represents your maximum jump length at that position.
 * 
 * Determine if you are able to reach the last index.
 */

#include <stdbool.h>

bool canJump(int* nums, int numsSize) {
    if (numsSize == 1) return true;
    if (nums[0] == 0) return false;
    int i, j, max = nums[0];
    for (i = 1; i < numsSize; ++i) {
        if (i > max) {
            return false;
        } else if (max < i + nums[i])
            max = i + nums[i];
        if (max >= numsSize - 1) return true;
    }
    return true;
}