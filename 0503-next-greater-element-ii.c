/**
 * Given a circular array (the next element of the last element is the first element of the array), print the Next
 * Greater Number for every element. The Next Greater Number of a number x is the first greater number to its
 * traversing-order next in the array, which means you could search circularly to find its next greater number. If
 * it doesn't exist, output -1 for this number.
 */

#include <stdlib.h>

int* nextGreaterElements(int* nums, int numsSize, int* returnSize) {
    *returnSize = numsSize;
    int* ret = (int*)malloc(sizeof(int) * numsSize);
    for (int i = 0; i < numsSize; ++i) {
        ret[i] = -1;
    }
    int* stack = (int*)malloc(sizeof(int) * numsSize * 2);
    int top = -1;
    for (int i = 0; i < numsSize * 2 - 1; ++i) {
        int j = i % numsSize;
        while (top >= 0 && nums[j] > nums[stack[top]]) {
            ret[stack[top--]] = nums[j];
        }
        stack[++top] = j;
    }
    return ret;
}