/**
 * Implement strStr().
 * 
 * Return the index of the first occurrence of needle in haystack,
 * or -1 if needle is not part of haystack.
 */

#include <string.h>

int strStr(char* haystack, char* needle) {
    int i, j, hlen, nlen, flag;
    hlen = strlen(haystack);
    nlen = strlen(needle);
    if (nlen == 0)
        return 0;
    else if (hlen == 0)
        return -1;
    for (i = 0; i <= hlen - nlen; i++) {
        flag = 0;
        for (j = 0; j < nlen; j++) {
            if (haystack[i + j] != needle[j]) {
                flag = 0;
                break;
            } else {
                flag = 1;
            }
        }
        if (flag) return i;
    }
    return -1;
}