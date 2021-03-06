/**
 * Given an array nums and a value val, remove all instances of that value
 * in-place and return the new length.
 * 
 * Do not allocate extra space for another array, you must do this by
 * modifying the input array in-place with O(1) extra memory.
 * 
 * The order of elements can be changed. It doesn't matter what you leave
 * beyond the new length.
 */

int removeElement(int* nums, int numsSize, int val) {
    int i, j=0;
    for (i = 0; i < numsSize; i++){
        if (nums[i]!=val)
            nums[j++] = nums[i];
    }
    return j;
}
