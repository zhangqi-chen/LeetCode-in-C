/**
 * Given a sorted array nums, remove the duplicates in-place such that duplicates appeared at most twice and return
 * the new length.
 * 
 * Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) 
 * extra memory.
 */

int removeDuplicates(int* nums, int numsSize) {
    if (numsSize < 3) return numsSize;
    int slow = 0;
    int fast = 1;
    int cnt = 1;
    for (; fast < numsSize; ++fast) {
        if (cnt == 1) {
            if (nums[fast] == nums[slow]) ++cnt;
            nums[++slow] = nums[fast];
        } else {
            if (nums[fast] != nums[slow]) {
                nums[++slow] = nums[fast];
                cnt = 1;
            }
        }
    }
    return slow + 1;
}