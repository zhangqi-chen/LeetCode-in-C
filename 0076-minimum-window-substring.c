/**
 * Given a string S and a string T, find the minimum window in S which will contain all the characters in T in 
 * complexity O(n).
 * 
 * Note:
 * If there is no such window in S that covers all characters in T, return the empty string "".
 * If there is such window, you are guaranteed that there will always be only one unique minimum window in S.
 */

#include <string.h>

char* minWindow(char* s, char* t) {
    int lens = strlen(s);
    int lent = strlen(t);
    if (lens < lent || lens == 0) return s + lens;
    int map[128] = {0};
    for (int i = 0; i < lent; ++i) {
        ++map[t[i]];
    }
    int idx, len = INT_MAX;
    int cnt = 0;
    int left = 0, right;
    int flag = 0;
    for (right = 0; right < lens; ++right) {
        --map[s[right]];
        if (map[s[right]] >= 0) ++cnt;
        while (cnt == lent) {
            ++map[s[left]];
            if (map[s[left]] > 0) --cnt;
            ++left;
            flag = 1;
        }
        if (flag && len > right - left + 2) {
            len = right - left + 2;
            idx = left - 1;
            flag = 0;
        }
    }
    if (len == INT_MAX) return s + lens;
    s[idx + len] = '\0';
    return s + idx;
}