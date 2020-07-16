/**
 * Given a string containing only digits, restore it by returning all possible valid IP address combinations.
 */

#include <stdlib.h>
#include <string.h>

void oneIp(char** res, char* s, int len, char* curr, int first, int* returnSize) {
    if (first == 4) {
        res[*returnSize] = (char*)malloc(sizeof(char) * (len + 4));
        strcpy(res[(*returnSize)++], curr);
        return;
    }
    int slen = strlen(s);
    int min = slen - (3 - first) * 3;
    int max = slen - (3 - first);
    min = min < 1 ? 1 : min;
    max = max > 3 ? 3 : max;
    int add = 0;
    int clen = len - slen + first;
    for (int i = 0; i < min - 1; ++i) {
        add = add * 10 + s[i] - '0';
    }
    for (int i = min - 1; i < max; ++i) {
        add = add * 10 + s[i] - '0';
        if ((i == 1 && add < 10) || (i == 2 && add < 100) || (add > 255)) return;
        memcpy(curr + clen, s, i + 1);
        curr[clen + i + 1] = first < 3 ? '.' : '\0';
        oneIp(res, s + i + 1, len, curr, first + 1, returnSize);
    }
}

char** restoreIpAddresses(char* s, int* returnSize) {
    *returnSize = 0;
    int len = strlen(s);
    if (len > 12 || len < 4) return 0;
    char** res = (char*)malloc(sizeof(char*) * 81);
    char curr[len + 4];
    oneIp(res, s, len, curr, 0, returnSize);
    return res;
}