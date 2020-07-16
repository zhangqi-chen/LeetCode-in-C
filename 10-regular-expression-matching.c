/**
 * Given an input string (s) and a pattern (p), implement regular expression matching with support for '.' and '*'.
 * 
 * '.' Matches any single character.
 * '*' Matches zero or more of the preceding element.
 * The matching should cover the entire input string (not partial).
 * 
 * Note:
 * s could be empty and contains only lowercase letters a-z.
 * p could be empty and contains only lowercase letters a-z, and characters like . or *.
 */

#include <bool.h>
#include <string.h>

bool isMatch(char* s, char* p) {
    int slen = strlen(s);
    int plen = strlen(p);
    bool dp[slen + 1][plen + 1];
    bool first;
    // start from end of strings
    for (int i = slen; i >= 0; --i) {
        for (int j = plen; j >= 0; --j) {
            // initialize: dp[slen][plen]=true, dp[][plen]=false
            dp[i][j] = (i == slen && j == plen) ? true : false;
            if (j == plen) continue;
            first = i < slen && (p[j] == s[i] || p[j] == '.');  // p[j] match with s[i]
            if (j + 1 < plen && p[j + 1] == '*') {
                dp[i][j] = dp[i][j + 2] || first && dp[i + 1][j];  // IMPORTANT! (ignore x*) || first && s[i+1:]=p[j:]
            } else {
                dp[i][j] = first && dp[i + 1][j + 1];  // first match && next one
            }
        }
    }
    return dp[0][0];
}

// slower method
bool isMatch(char* s, char* p) {
    int slen = strlen(s);
    int plen = strlen(p);
    if (plen == 0) return slen == 0;

    bool first = slen > 0 && (p[0] == s[0] || p[0] == '.');

    if (plen > 1 && p[1] == '*') {
        return isMatch(s, p + 2) || (first && isMatch(s + 1, p));
    }
    return first && isMatch(s + 1, p + 1);
}
