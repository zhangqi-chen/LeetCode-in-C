/**
 * Given an array nums of positive integers, return the longest possible length of an array prefix of nums, such that
 * it is possible to remove exactly one element from this prefix so that every number that has appeared in it will have
 * the same number of occurrences.
 * 
 * If after removing one element there are no remaining elements, it's still considered that every appeared number has
 * the same number of ocurrences (0).
 */

#include <stdlib.h>

int check(int* freq, int* n, int size) {
    if (size == 1) return 1;
    if (size == 2) return abs(freq[n[0]] - freq[n[1]]) == 1 || freq[n[0]] == 1 || freq[n[1]] == 1;
    int eq;
    int flag = 0;
    if (freq[n[1]] == freq[n[0]]) {
        eq = freq[n[0]];
    } else if ((freq[n[0]] == 1 && freq[n[1]] == 2) || (freq[n[0]] == 2 && freq[n[1]] == 1)) {
        if (freq[n[2]] > 2) return 0;
        eq = freq[n[2]];
        flag = 1;
    } else if (freq[n[0]] + 1 == freq[n[1]] || freq[n[1]] == 1) {
        eq = freq[n[0]];
        flag = 1;
    } else if (freq[n[1]] + 1 == freq[n[0]] || freq[n[0]] == 1) {
        eq = freq[n[1]];
        flag = 1;
    }
    for (int i = 2; i < size; ++i) {
        int new = freq[n[i]];
        if (new == eq)
            continue;
        else if (new == eq + 1 || new == 1) {
            if (flag == 0)
                flag = 1;
            else
                return 0;
        } else
            return 0;
    }
    if (flag || eq == 1) return eq;
    return 0;
}

int maxEqualFreq(int* nums, int numsSize) {
    int freq[100001] = {0};
    int* numbers = (int*)malloc(sizeof(int) * numsSize);
    int nSize = 0;
    int max = 0;
    int f = 0;
    for (int i = 0; i < numsSize; ++i) {
        int n = nums[i];
        if (freq[n] == 0) numbers[nSize++] = n;
        ++freq[n];
        if (freq[n] > f) f = freq[n];
        if (nSize > 3 && f > 2 && i - max + 2 < f) continue;
        if (check(freq, numbers, nSize)) max = i + 1;
    }
    return max;
}