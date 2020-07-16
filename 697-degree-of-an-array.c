/**
 * Given a non-empty array of non-negative integers nums, the degree of this array is defined as the maximum frequency
 * of any one of its elements.
 * 
 * Your task is to find the smallest possible length of a (contiguous) subarray of nums, that has the same degree as
 * nums.
 */

#define MAXLEN 50000

int findShortestSubArray(int* nums, int numsSize) {
    if (numsSize < 2) return numsSize;
    int minloc[MAXLEN];
    int cnt[MAXLEN] = {0};
    for (int i = 0; i < MAXLEN; ++i) {
        minloc[i] = -1;
    }
    int maxcnt = 1;
    int minlen = 1;
    for (int i = 0; i < numsSize; ++i) {
        int n = nums[i];
        if (minloc[n] < 0) minloc[n] = i;
        ++cnt[n];
        if (cnt[n] > maxcnt) {
            maxcnt = cnt[n];
            minlen = i - minloc[n] + 1;
        } else if (cnt[n] == maxcnt && i - minloc[n] + 1 < minlen)
            minlen = i - minloc[n] + 1;
    }
    return minlen;
}