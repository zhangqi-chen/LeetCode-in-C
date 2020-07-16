/**
 * Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *longestPalindrome(char *s) {
    int i, j, length, plength, limit, start;
    length = strlen(s);
    if (length < 2) return s;
    plength = 1;
    start = 0;
    for (i = 0; i < length; i++) {
        limit = i < length - 1 - i ? i : length - 1 - i;
        for (j = 0; j <= limit; j++) {
            if (s[i - j] != s[i + j]) break;
        }
        if (2 * j - 1 > plength) {
            plength = 2 * j - 1;
            start = i - j + 1;
        }
        limit = i < length - 2 - i ? i : length - 2 - i;
        for (j = 0; j <= limit; j++) {
            if (s[i - j] != s[i + j + 1]) break;
        }
        if (2 * j > plength) {
            plength = 2 * j;
            start = i - j + 1;
        }
    }
    char *ans = (char *)malloc((plength + 1) * sizeof(char));
    strncpy(ans, s + start, plength);
    ans[plength] = '\0';
    return ans;
}

int main() {
    char s[] = "bb";
    char *ps = longestPalindrome(s);
    printf("%s", ps);
    return 0;
}