/**
 * Given an array with n objects colored red, white or blue, sort them in-place so that objects of
 * the same color are adjacent, with the colors in the order red, white and blue.
 * 
 * Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.
 * 
 * Note: You are not suppose to use the library's sort function for this problem.
 */

void sortColors(int* nums, int numsSize) {
    int head = 0;
    int curr = 0;
    int tail = numsSize - 1;
    while (curr <= tail) {
        if (nums[curr] == 0) {
            nums[curr++] = nums[head];
            nums[head++] = 0;
        } else if (nums[curr] == 2) {
            nums[curr] = nums[tail];
            nums[tail--] = 2;
        } else
            ++curr;
    }
}