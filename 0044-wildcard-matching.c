/**
 * Given an input string (s) and a pattern (p), implement wildcard pattern
 * matching with support for '?' and '*'.
 * 
 * '?' Matches any single character.
 * '*' Matches any sequence of characters (including the empty sequence).
 * The matching should cover the entire input string (not partial).
 * 
 * Note:
 * s could be empty and contains only lowercase letters a-z.
 * p could be empty and contains only lowercase letters a-z, and characters like ? or *.
 */

#include <bool.h>
#include <string.h>

bool isMatch(char* s, char* p) {
    int i = 0, j = 0;
    int istar = -1, jstar = -1;
    int lens = strlen(s), lenp = strlen(p);
    while (i < lens) {
        if (j < lenp && (s[i] == p[j] || p[j] == '?')) {
            ++i;
            ++j;
        } else if (j < lenp && p[j] == '*') {
            istar = i;
            jstar = j++;
        } else if (istar >= 0) {
            i = ++istar;
            j = jstar + 1;
        } else
            return false;
    }
    while (j < lenp && p[j] == '*') ++j;
    return j == lenp;
}

// DP
bool isMatch(char* s, char* p) {
    int lens = strlen(s);
    int lenp = strlen(p);
    int i, j;
    bool** data = (bool**)malloc(sizeof(bool*) * (lenp + 1));
    data[0] = (bool*)malloc(sizeof(bool) * (lens + 1));
    memset(data[0], false, sizeof(bool) * (lens + 1));
    data[0][0] = true;
    for (i = 1; i <= lenp; i++) {
        data[i] = (bool*)malloc(sizeof(bool) * (lens + 1));
        data[i][0] = p[i - 1] == '*' ? data[i - 1][0] : false;
        for (j = 1; j <= lens; j++) {
            if (p[i - 1] == '?') {
                data[i][j] = data[i - 1][j - 1];
            } else if (p[i - 1] != '*') {
                data[i][j] = data[i - 1][j - 1] && p[i - 1] == s[j - 1];
            } else {
                data[i][j] = data[i][j - 1] || data[i - 1][j];
            }
        }
    }
    bool ans = data[lenp][lens];
    free(data);
    return ans;
}

// Recurse
bool isMatch(char* s, char* p) {
    int lens = strlen(s);
    int lenp = strlen(p);
    if (lenp == 1 && p[0] == '*') return true;
    if (lens == 0 && lenp == 0) return true;
    if (lenp == 0 && lens != 0) return false;
    int i, j;
    if (p[0] != '*') {
        for (i = 0; i < lens && i < lenp && (p[i] == s[i] || p[i] == '?'); i++) {
        }
        if (i < lenp && p[i] != '*')
            return false;
        else if (i == lens && i == lenp)
            return true;
        else
            return isMatch(s + i, p + i);
    } else {
        for (j = 1; j < lenp && p[j] == '*'; j++) {
        }
        if (j == lenp) return true;
        i = 0;
        while (i < lens) {
            if (p[j] != '?') {
                for (; i < lens && s[i] != p[j]; i++) {
                }
            }
            if (i < lens) {
                if (isMatch(s + i + 1, p + j + 1))
                    return true;
                else
                    i++;
            }
        }
        return false;
    }
}
