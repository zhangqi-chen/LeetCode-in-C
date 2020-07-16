/**
 * Given an array of integers nums sorted in ascending order, find the starting 
 * and ending position of a given target value.
 * 
 * Your algorithm's runtime complexity must be in the order of O(log n).
 * 
 * If the target is not found in the array, return [-1, -1].
 */

#include <stdlib.h>

int* searchRange(int* nums, int numsSize, int target, int* returnSize) {
    *returnSize = 2;
    int* res = (int*)malloc(sizeof(int) * 2);
    res[0] = res[1] = -1;
    if (numsSize == 0) return res;
    if (target < nums[0] || target > nums[numsSize - 1]) return res;
    if (nums[0] == target && nums[numsSize - 1] == target) {
        res[0] = 0;
        res[1] = numsSize - 1;
        return res;
    }
    free(res);
    int* right;
    int idx = numsSize / 2;
    res = searchRange(nums, idx, target, returnSize);
    right = searchRange(nums + idx, numsSize - idx, target, returnSize);
    if (res[0] == -1) res[0] = right[0] + (right[0] > -1 ? idx : 0);
    if (right[1] > -1) res[1] = right[1] + idx;
    free(right);
    return res;
}