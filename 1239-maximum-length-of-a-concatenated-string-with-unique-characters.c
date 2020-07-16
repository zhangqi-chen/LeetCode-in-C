/**
 * Given an array of strings arr. String s is a concatenation of a sub-sequence of arr which have unique characters.
 * 
 * Return the maximum possible length of s.
 */
#include <stdlib.h>
#include <string.h>

int** dict;
int* arrlen;
int* curr;
int currlen, maxlen;

int unique(int* a, int* b) {
    for (int i = 0; i < 26; ++i) {
        if (a[i] + b[i] > 1) return 0;
    }
    return 1;
}

void backtrack(int start, int arrSize) {
    for (int i = start; i < arrSize; ++i) {
        if (unique(curr, dict[i]) == 0) continue;
        for (int j = 0; j < 26; ++j) {
            if (dict[i][j] == 1) curr[j] = 1;
        }
        currlen += arrlen[i];
        if (currlen > maxlen) maxlen = currlen;
        backtrack(i + 1, arrSize);
        for (int j = 0; j < 26; ++j) {
            if (dict[i][j] == 1) curr[j] = 0;
        }
        currlen -= arrlen[i];
    }
}

int maxLength(char** arr, int arrSize) {
    maxlen = 0;
    dict = (int**)malloc(sizeof(int*) * arrSize);
    arrlen = (int*)malloc(sizeof(int) * arrSize);
    for (int i = 0; i < arrSize; ++i) {
        dict[i] = (int*)malloc(sizeof(int) * 26);
        for (int j = 0; j < 26; ++j) {
            dict[i][j] = 0;
        }
        arrlen[i] = strlen(arr[i]);
        for (int j = 0; j < arrlen[i]; ++j) {
            ++dict[i][arr[i][j] - 'a'];
        }
    }
    curr = (int*)malloc(sizeof(int) * 26);
    for (int i = 0; i < 26; ++i) {
        curr[i] = 0;
    }
    currlen = 0;
    backtrack(0, arrSize);
    return maxlen;
}