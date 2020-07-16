/**
 * Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
 * (i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).
 * 
 * You are given a target value to search. If found in the array return its index, otherwise return -1.
 * 
 * You may assume no duplicate exists in the array.
 * 
 * Your algorithm's runtime complexity must be in the order of O(log n).
 */

int search(int* nums, int numsSize, int target) {
    if (numsSize == 0) return -1;
    int left, right, idx = numsSize / 2;
    if (nums[0] == target)
        return 0;
    else if (nums[numsSize - 1] == target)
        return numsSize - 1;
    else if (nums[idx] == target)
        return idx;
    if (numsSize < 4) return -1;
    if (nums[numsSize - 1] > nums[0] && (target < nums[0] || target > nums[numsSize - 1]))
        return -1;
    else {
        left = search(nums + 1, idx - 1, target);
        if (left > -1) return 1 + left;
        right = search(nums + 1 + idx, numsSize - idx - 2, target);
        if (right > -1) return idx + right + 1;
        return -1;
    }
}