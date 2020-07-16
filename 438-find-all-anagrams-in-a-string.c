/**
 * Given a string s and a non-empty string p, find all the start indices of p's anagrams in s.
 * 
 * Strings consists of lowercase English letters only and the length of both strings s and p will not be larger than 20100.
 * 
 * The order of output does not matter.
 */

#include <stdlib.h>
#include <string.h>

int* findAnagrams(char* s, char* p, int* returnSize) {
    int dict[26] = {0};
    *returnSize = 0;
    if (!p[0]) return 0;
    int slen = strlen(s);
    int plen = strlen(p);
    for (int i = 0; i < plen; ++i) {
        ++dict[p[i] - 'a'];
    }
    int fast = 0;
    int slow = 0;
    int* res = (int*)malloc(sizeof(int) * slen);
    while (fast < slen) {
        if (dict[s[fast] - 'a'] == 0) {
            if (fast - slow == plen) res[(*returnSize)++] = slow;
            while (s[slow] != s[fast]) {
                ++dict[s[slow++] - 'a'];
            }
            if (slow < fast)
                ++dict[s[slow++] - 'a'];
            else {
                ++slow;
                ++fast;
            }
        } else
            --dict[s[fast++] - 'a'];
    }
    if (fast - slow == plen) res[(*returnSize)++] = slow;
    return res;
}