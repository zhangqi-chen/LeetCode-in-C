/**
 * Given a sorted array and a target value, return the index if the target
 * is found. If not, return the index where it would be if it were inserted
 * in order.
 * 
 * You may assume no duplicates in the array.
 */

int searchInsert(int* nums, int numsSize, int target) {
    if (numsSize == 0) return 0;
    if (target <= nums[0]) return 0;
    if (target == nums[numsSize - 1]) return numsSize - 1;
    if (target > nums[numsSize - 1]) return numsSize;
    int res, i = numsSize / 2;
    if (target == nums[i]) return i;
    if (target < nums[i])
        return searchInsert(nums, i, target);
    else
        return i + searchInsert(nums + i, numsSize - i, target);
}