/**
 * The set [1,2,3,...,n] contains a total of n! unique permutations.
 * 
 * Given n and k, return the kth permutation sequence.
 */

#include <stdlib.h>

char* getPermutation(int n, int k) {
    int nums[9] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320};
    int choice[9] = {0};
    char* res = (char*)malloc(sizeof(char) * (n + 1));
    res[n] = '\0';
    int next;
    for (int i = 0; i < n; ++i) {
        if (k == 1) {
            next = 0;
        } else if (k % nums[n - i - 1] == 0) {
            next = k / nums[n - i - 1] - 1;
            k = nums[n - i - 1];
        } else {
            next = k / nums[n - i - 1];
            k %= nums[n - i - 1];
        }
        int count = 0;
        for (int j = 0; j < n; ++j) {
            if (choice[j] == 0 && count == next) {
                choice[j] = 1;
                res[i] = '1' + j;
                break;
            } else if (choice[j] == 0)
                ++count;
        }
    }
    return res;
}