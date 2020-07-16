/**
 * Given a string s1, we may represent it as a binary tree by partitioning it to two non-empty substrings recursively.
 * 
 * Given two strings s1 and s2 of the same length, determine if s2 is a scrambled string of s1.
 */

#include <stdlib.h>

bool isScramble(char *s1, char *s2) {
    int len = strlen(s1);
    if (len != strlen(s2)) return false;
    if (len == 1) return s1[0] == s2[0];
    int d1[26] = {0};
    int d2[26] = {0};
    for (int i = 0; i < len; ++i) {
        ++d1[*(s1 + i) - 'a'];
        ++d2[*(s2 + i) - 'a'];
    }
    for (int i = 0; i < 26; ++i) {
        if (d1[i] != d2[i]) return false;
    }
    char *t1 = (char *)malloc(sizeof(char) * (len + 1));
    char *t2 = (char *)malloc(sizeof(char) * (len + 1));
    for (int i = 1; i < len; ++i) {
        strcpy(t1, s1);
        strcpy(t2, s2);
        t1[i] = t2[i] = '\0';
        if (isScramble(t1, t2) && isScramble(s1 + i, s2 + i)) return true;
        strcpy(t2, s2);
        t2[len - i] = '\0';
        if (isScramble(t1, s2 + len - i) && isScramble(s1 + i, t2)) return true;
    }
    return false;
}