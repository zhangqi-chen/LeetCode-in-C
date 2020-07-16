/**
 * Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
 * (i.e., [0,0,1,2,2,5,6] might become [2,5,6,0,0,1,2]).
 * 
 * You are given a target value to search. If found in the array return true, otherwise return false.
 * 
 * (This is a follow up problem to Search in Rotated Sorted Array, where nums may contain duplicates.)
 */

#include <stdbool.h>

bool search(int* nums, int numsSize, int target) {
    if (numsSize == 0) return false;
    int idx = (numsSize - 1) / 2;
    if (nums[0] == target || nums[numsSize - 1] == target || nums[idx] == target) return true;
    if (numsSize < 4) return false;
    if (nums[numsSize - 1] > nums[0]) {
        if (target < nums[0] || target > nums[numsSize - 1]) return false;
        if (target < nums[idx])
            return search(nums + 1, idx - 1, target);
        else
            return search(nums + 1 + idx, numsSize - idx - 2, target);
    } else if (nums[numsSize - 1] < nums[0] && target < nums[0] && target > nums[numsSize - 1])
        return false;
    if (nums[0] < nums[idx]) {
        if (search(nums + 1, idx - 1, target)) return true;
        if (search(nums + 1 + idx, numsSize - idx - 2, target)) return true;
    } else {
        if (search(nums + 1 + idx, numsSize - idx - 2, target)) return true;
        if (search(nums + 1, idx - 1, target)) return true;
    }
    return false;
}