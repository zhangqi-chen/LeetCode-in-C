/**
 * Given an integer array nums, find the contiguous subarray (containing at least one number)
 * which has the largest sum and return its sum.
 */

int maxSubArray(int* nums, int numsSize) {
    int i, curr, ans;
    curr = ans = nums[0];
    for (i = 1; i < numsSize; ++i) {
        curr = curr > 0 ? curr + nums[i] : nums[i];
        ans = curr > ans ? curr : ans;
    }
    return ans;
}