/**
 * Write a function to find the longest common prefix string amongst an array of strings.
 * If there is no common prefix, return an empty string "".
 */
#include <string.h>

char* longestCommonPrefix(char** strs, int strsSize) {
    char* prefix = (char*)malloc(105 * sizeof(char));
    prefix[0] = '\0';
    if (strsSize == 0)
        return prefix;
    else if (strsSize == 1) {
        strcpy(prefix, strs[0]);
        return prefix;
    }
    int i, j, flag;
    char c;
    i = 0;
    while (1) {
        c = strs[0][i];
        if (!c) break;
        flag = 0;
        for (j = 1; j < strsSize; j++) {
            if (!strs[j][i]) {
                flag = 1;
                break;
            } else if (strs[j][i] != c) {
                flag = 1;
                break;
            }
        }
        if (flag == 1)
            break;
        else {
            prefix[i] = c;
            i++;
        }
    }
    prefix[i] = '\0';
    return prefix;
}