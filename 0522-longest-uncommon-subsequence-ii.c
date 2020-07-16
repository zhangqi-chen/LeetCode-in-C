/**
 * Given a list of strings, you need to find the longest uncommon subsequence among them. The longest uncommon
 * subsequence is defined as the longest subsequence of one of these strings and this subsequence should not be
 * any subsequence of the other strings.
 * 
 * A subsequence is a sequence that can be derived from one sequence by deleting some characters without changing
 * the order of the remaining elements. Trivially, any string is a subsequence of itself and an empty string is a
 * subsequence of any string.
 * 
 * The input will be a list of strings, and the output needs to be the length of the longest uncommon subsequence.
 * If the longest uncommon subsequence doesn't exist, return -1.
 */

#include <stdlib.h>
#include <string.h>

int substr(char* s, char* t) {
    while (*s) {
        if (*s == *t) ++t;
        if (!(*t)) return 1;
        ++s;
    }
    return 0;
}

int cmp(const void* A, const void* B) {
    char* a = *(char**)A;
    char* b = *(char**)B;
    int alen = strlen(a);
    int blen = strlen(b);
    if (alen != blen) return blen - alen;
    return strcmp(a, b);
}

int findLUSlength(char** strs, int strsSize) {
    if (strsSize == 1) return strlen(strs[0]);
    qsort(strs, strsSize, sizeof(char*), cmp);
    int maxlen = strlen(strs[0]);
    if (strcmp(strs[0], strs[1]) != 0) return maxlen;
    int* mark = (int*)malloc(sizeof(int) * strsSize);
    mark[0] = 1;
    mark[1] = 0;
    for (int i = 2; i < strsSize; ++i) {
        mark[i] = 1;
        for (int j = 0; j < i; ++j) {
            if (mark[j] && substr(strs[j], strs[i])) {
                mark[i] = 0;
                break;
            }
        }
        if (i < strsSize - 1 && strcmp(strs[i], strs[i + 1]) == 0) continue;
        if (mark[i] == 1) return strlen(strs[i]);
    }
    return -1;
}