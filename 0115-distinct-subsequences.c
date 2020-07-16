/**
 * Given a string S and a string T, count the number of distinct subsequences of S which equals T.
 * 
 * A subsequence of a string is a new string which is formed from the original string by deleting some (can be none) of
 * the characters without disturbing the relative positions of the remaining characters. (ie, "ACE" is a subsequence of
 * "ABCDE" while "AEC" is not).
 */

#include <stdlib.h>
#include <string.h>

int numDistinct(char* s, char* t) {
    int slen = strlen(s);
    int tlen = strlen(t);
    if (slen == 0 || slen < tlen) return 0;
    long long* prev = (long long*)malloc(sizeof(long long) * slen);
    long long* curr = (long long*)malloc(sizeof(long long) * slen);
    curr[0] = s[0] == t[0];
    for (int j = 1; j < slen - tlen + 1; ++j) {
        curr[j] = curr[j - 1] + (s[j] == t[0]);
    }
    for (int i = 1; i < tlen; ++i) {
        int* tmp = prev;
        prev = curr;
        curr = tmp;
        curr[i - 1] = 0;
        for (int j = i; j < slen - (tlen - 1 - i); ++j) {
            curr[j] = curr[j - 1] + (s[j] == t[i]) * prev[j - 1];
        }
    }
    return (int)curr[slen - 1];
}