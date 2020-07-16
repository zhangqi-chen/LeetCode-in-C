/**
 * Given an array of strings, group anagrams together.
 * 
 * Note:
 * All inputs will be in lowercase.
 * The order of your output does not matter.
 */

#include <stdlib.h>
#include <string.h>

int cmp(const void* A, const void* B) {
    char** a = (char**)A;
    char** b = (char**)B;
    int lena = strlen(*a);
    int lenb = strlen(*b);
    if (lena < lenb)
        return -1;
    else if (lena > lenb)
        return 1;
    else {
        int dict[26] = {0};
        for (int i = 0; i < lena; ++i) {
            ++dict[(*a)[i] - 'a'];
            --dict[(*b)[i] - 'a'];
        }
        int res = 0;
        for (int i = 0; i < 26; ++i) {
            if (dict[i] != 0) {
                res = dict[i];
                break;
            }
        }
        return res;
    }
}

char*** groupAnagrams(char** strs, int strsSize, int* returnSize, int** returnColumnSizes) {
    *returnSize = 0;
    if (strsSize == 0) return 0;
    *returnColumnSizes = (int*)malloc(sizeof(int) * strsSize);
    char*** res = (char***)malloc(sizeof(char**) * strsSize);
    qsort(strs, strsSize, sizeof(char*), cmp);
    int i, j, prev = 0;
    for (i = 1; i <= strsSize; ++i) {
        if (i == strsSize || cmp(strs + i - 1, strs + i) != 0) {
            res[*returnSize] = (char**)malloc(sizeof(char*) * (i - prev));
            for (j = 0; j < (i - prev); ++j) {
                res[*returnSize][j] = strs[prev + j];
            }
            (*returnColumnSizes)[(*returnSize)++] = i - prev;
            prev = i;
        }
    }
    return res;
}

// First coding, slower
int cmp1(const void* a, const void* b) {
    return (*(char*)a - *(char*)b);
}

char*** groupAnagrams(char** strs, int strsSize, int* returnSize, int** returnColumnSizes) {
    *returnSize = 0;
    if (strsSize == 0) return 0;
    *returnColumnSizes = (int*)malloc(sizeof(int) * strsSize);
    char*** res = (char***)malloc(sizeof(char**) * strsSize);
    char dict[strsSize][30], temp[30];
    int i, j, len, flag;
    for (i = 0; i < strsSize; ++i) {
        len = strlen(strs[i]);
        strcpy(temp, strs[i]);
        qsort(temp, len, sizeof(char), cmp1);
        flag = 0;
        for (j = 0; j < *returnSize; ++j) {
            if (strcmp(temp, dict[j]) == 0) {
                res[j][(*returnColumnSizes)[j]] = (char*)malloc(sizeof(char) * (len + 1));
                strcpy(res[j][(*returnColumnSizes)[j]], strs[i]);
                ++(*returnColumnSizes)[j];
                flag = 1;
                break;
            }
        }
        if (flag == 0) {
            strcpy(dict[*returnSize], temp);
            res[*returnSize] = (char**)malloc(sizeof(char*) * strsSize);
            res[*returnSize][0] = (char*)malloc(sizeof(char) * (len + 1));
            strcpy(res[*returnSize][0], strs[i]);
            (*returnColumnSizes)[*returnSize] = 1;
            ++(*returnSize);
        }
    }
    return res;
}