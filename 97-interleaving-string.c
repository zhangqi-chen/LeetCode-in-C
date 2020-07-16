/**
 * Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and s2.
 */

#include <stdbool.h>
#include <string.h>

bool isInterleave(char* s1, char* s2, char* s3) {
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    if (len1 + len2 != strlen(s3)) return false;
    bool data[len1 + 1];
    data[0] = true;
    for (int i = 1; i <= len1; ++i) {
        data[i] = data[i - 1] && s1[i - 1] == s3[i - 1];
    }
    for (int i = 1; i <= len2; ++i) {
        data[0] = data[0] && s2[i - 1] == s3[i - 1];
        for (int j = 1; j <= len1; ++j) {
            data[j] = (data[j - 1] && s1[j - 1] == s3[i + j - 1]) || (data[j] && s2[i - 1] == s3[i + j - 1]);
        }
    }
    return data[len1];
}