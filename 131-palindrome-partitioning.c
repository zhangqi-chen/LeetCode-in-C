/**
 * Given a string s, partition s such that every substring of the partition is a palindrome.
 * 
 * Return all possible palindrome partitioning of s.
 */

#include <stdlib.h>
#include <string.h>
#define N 1000

int pld[N][N];     // pld[i][j] = idPalindrome(s[i:j+1], j+1-i)
char plds[N][N][N];   // plds[i][j] = s[i:j+1]
int curr[N];

int isPalindrome(char* s, int slen) {
    if (slen == 1) return 1;
    for (int i = 0; i < slen / 2; ++i) {
        if (s[i] == s[slen - 1 - i]) continue;
        return 0;
    }
    return 1;
}

void dfs(char*** res, int currSize, int idx, int slen, int* rSize, int** rCSize) {
    if (idx == slen) {
        curr[currSize] = idx;
        res[*rSize] = (char**)malloc(sizeof(char*) * currSize);
        (*rCSize)[*rSize] = currSize;
        for (int i = 0; i < currSize; ++i) {
            res[*rSize][i] = plds[curr[i]][curr[i + 1] - 1];
        }
        ++(*rSize);
        return;
    }
    for (int i = idx; i < slen; ++i) {
        if (pld[idx][i] == 0) continue;
        curr[currSize] = idx;
        dfs(res, currSize + 1, i + 1, slen, rSize, rCSize);
    }
}

char*** partition(char* s, int* returnSize, int** returnColumnSizes) {
    int slen = strlen(s);
    for (int i = 0; i < slen; ++i) {
        for (int j = i; j < slen; ++j) {
            pld[i][j] = isPalindrome(s + i, j - i + 1);
            if (pld[i][j] == 0) continue;
            memcpy(plds[i][j], s + i, j - i + 1);
            plds[i][j][j - i + 1] = '\0';
        }
    }
    int n = slen * slen;
    *returnSize = 0;
    (*returnColumnSizes) = (int*)malloc(sizeof(int) * n);
    char*** res = (char***)malloc(sizeof(char**) * n);
    dfs(res, 0, 0, slen, returnSize, returnColumnSizes);
    return res;
}