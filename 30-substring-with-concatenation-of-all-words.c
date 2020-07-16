/**
 * You are given a string, s, and a list of words, words, that are all of the same length. 
 * Find all starting indices of substring(s) in s that is a concatenation of each word in 
 * words exactly once and without any intervening characters.
 */

#include <string.h>

int oneWord(char* s, char** words, int wordsSize, int* flags, int start) {
    int wlen = strlen(words[0]);
    for (int i = 0; i < wordsSize; ++i) {
        if (flags[i] == 0) {
            int found = 1;
            for (int j = 0; j < wlen; ++j) {
                if (words[i][j] != s[start + j]) {
                    found = 0;
                    break;
                }
            }
            if (found) {
                flags[i] = 1;
                return i + 1;
            }
        }
    }
    return 0;
}

int* findSubstring(char* s, char** words, int wordsSize, int* returnSize) {
    *returnSize = 0;
    int slen = strlen(s);
    int* res = (int*)malloc(sizeof(int) * (slen + 1));
    if (wordsSize == 0) return res;
    int wlen = strlen(words[0]);
    if (wlen * wordsSize > slen) return res;
    if (wlen == 0) {
        for (int i = 0; i <= slen; ++i) {
            res[i] = i;
        }
        *returnSize = slen + 1;
        return res;
    }
    int flags[wordsSize];
    int i, start;
    for (i = 0; i < wordsSize; ++i) {
        flags[i] = 0;
    }
    for (start = 0; start <= slen - wlen * wordsSize; ++start) {
        if (oneWord(s, words, wordsSize, flags, start)) {
            int found = 1;
            for (int i = 1; i < wordsSize; ++i) {
                if (0 == oneWord(s, words, wordsSize, flags, start + i * wlen)) {
                    found = 0;
                    break;
                }
            }
            if (found) {
                res[(*returnSize)++] = start;
            }
            for (i = 0; i < wordsSize; ++i) {
                flags[i] = 0;
            }
        }
    }
    return res;
}