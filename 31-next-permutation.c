/**
 * Implement next permutation, which rearranges numbers into the lexicographically
 * next greater permutation of numbers.
 * 
 * If such arrangement is not possible, it must rearrange it as the lowest possible
 * order (ie, sorted in ascending order). 
 * 
 * The replacement must be in-place and use only constant extra memory.
 */

void nextPermutation(int* nums, int numsSize) {
    int i, j, temp;
    for (i = numsSize - 1; i > 0; i--) {
        if (nums[i] > nums[i - 1]) break;
    }
    if (i > 0) {
        for (j = i; j < numsSize; j++) {
            if (nums[j] <= nums[i - 1]) break;
        }
        j -= 1;
        temp = nums[i - 1];
        nums[i - 1] = nums[j];
        nums[j] = temp;
    }
    for (j = i; j <= (i + numsSize - 1) / 2; j++) {
        if (j != numsSize - 1 + i - j) {
            temp = nums[j];
            nums[j] = nums[numsSize - 1 + i - j];
            nums[numsSize - 1 + i - j] = temp;
        }
    }
}
