/**
 * You are given an integer array nums and you have to return a new counts array. The counts array has the property
 * where counts[i] is the number of smaller elements to the right of nums[i].
 */

#include <stdlib.h>

int *res, *idx, *tmp;

void sort(int* nums, int left, int right) {
    if (left + 1 == right) return;
    int mid = (left + right) / 2;
    sort(nums, left, mid);
    sort(nums, mid, right);
    int i = left;
    int j = mid;
    for (int k = left; k < right; ++k) {
        if (j == right || (i < mid && nums[idx[i]] > nums[idx[j]])) {
            res[idx[i]] += right - j;
            tmp[k] = idx[i++];
        } else
            tmp[k] = idx[j++];
    }
    for (i = left; i < right; ++i) {
        idx[i] = tmp[i];
    }
}

int* countSmaller(int* nums, int numsSize, int* returnSize) {
    *returnSize = numsSize;
    if (numsSize == 0) return 0;
    res = (int*)malloc(sizeof(int) * numsSize);
    idx = (int*)malloc(sizeof(int) * numsSize);
    tmp = (int*)malloc(sizeof(int) * numsSize);
    for (int i = 0; i < numsSize; ++i) {
        res[i] = 0;
        idx[i] = i;
    }
    sort(nums, 0, numsSize);
    return res;
}