/**
 * Given an array of non-negative integers, you are initially positioned at the first
 * index of the array.
 * 
 * Each element in the array represents your maximum jump length at that position.
 * 
 * Your goal is to reach the last index in the minimum number of jumps.
 */
#include <stdlib.h>
#include <string.h>

int jump(int* nums, int numsSize) {
    if (numsSize == 1) return 0;
    int* data = (int*)malloc(sizeof(int) * numsSize);
    memset(data, 0, sizeof(int) * numsSize);
    int i, j, start = 1;
    for (i = 0; i < numsSize; ++i) {
        if (i + nums[i] >= numsSize - 1) return data[i] + 1;
        for (j = start; j <= i + nums[i]; ++j) {
            if (data[j] == 0 || data[j] > data[i] + 1)
                data[j] = data[i] + 1;
        }
        start = i + nums[i] + 1;
    }
    return data[numsSize - 1];
}