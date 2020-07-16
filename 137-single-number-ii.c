/**
 * Given a non-empty array of integers, every element appears three times except for one, which appears exactly once.
 * Find that single one.
 * 
 * Note:
 * Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
 */

int singleNumber(int* nums, int numsSize) {
    int once = 0;
    int twice = 0;
    for (int i = 0; i < numsSize; ++i) {
        once = ~twice & (once ^ nums[i]);
        twice = ~once & (twice ^ nums[i]);
    }
    return once;
}

int singleNumber(int* nums, int numsSize) {
    int bits[32] = {0};
    unsigned int n;
    for (int i = 0; i < numsSize; ++i) {
        n = nums[i];
        for (int j = 0; j < 32; ++j) {
            bits[j] += 1 & (n >> j);
        }
    }
    n = 0;
    for (int i = 31; i >= 0; --i) {
        n = (n << 1) + bits[i] % 3;
    }
    return n;
}