/**
 * Given a string s, partition s such that every substring of the partition is a palindrome.
 * 
 * Return the minimum cuts needed for a palindrome partitioning of s.
 */

#include <stdlib.h>
#include <string.h>
#define N 1500

int minCut(char* s) {
    int slen = strlen(s);
    int pld[N][N];  // pld[i][j] = isPalindrome(s[i:j+1])
    for (int i = 0; i < slen - 1; ++i) {
        int min = i < slen - i - 1 ? i : slen - i - 1;
        for (int j = 0; j < min + 1; ++j) {
            if (j == 0) {
                pld[i][i] = 1;
                pld[i][i + 1] = s[i] == s[i + 1];
                continue;
            }
            pld[i - j][i + j] = pld[i - j + 1][i + j - 1] && (s[i - j] == s[i + j]);
            pld[i - j][i + j + 1] = pld[i - j + 1][i + j] && (s[i - j] == s[i + j + 1]);
        }
    }
    pld[slen - 1][slen - 1] = 1;
    if (pld[0][slen - 1]) return 0;
    int cut[N];  // cut[i] is the mincut of s[0:i+1]
    for (int i = 0; i < slen; ++i) {
        if (pld[0][i]) {
            cut[i] = 0;
            continue;
        }
        cut[i] = i;
        for (int j = 1; j <= i; ++j) {
            if (pld[j][i] && cut[i] > cut[j - 1] + 1) {
                cut[i] = cut[j - 1] + 1;
            }
        }
    }
    return cut[slen - 1];
}