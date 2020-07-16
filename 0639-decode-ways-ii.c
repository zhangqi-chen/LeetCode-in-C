/**
 * A message containing letters from A-Z is being encoded to numbers using the following mapping way:
 * 
 * 'A' -> 1
 * 'B' -> 2
 * ...
 * 'Z' -> 26
 * 
 * Beyond that, now the encoded string can also contain the character '*', which can be treated as one of the numbers from 1 to 9.
 * 
 * Given the encoded message containing digits and the character '*', return the total number of ways to decode it.
 * 
 * Also, since the answer may be very large, you should return the output mod 10E9 + 7.
 */

#include <string.h>
#define N 1000000007

int calcOne(char* s) {
    if (s[0] == '0') return 0;
    if (s[0] == '*') return 9;
    return 1;
}

int calcTwo(char* s) {
    if (s[0] == '0') return 0;
    if (s[0] == '*') {
        if (s[1] == '*') return 15;
        if (s[1] >= '0' && s[1] <= '6') return 2;
        return 1;
    } else if (s[0] == '1') {
        if (s[1] == '*') return 9;
        return 1;
    } else if (s[0] == '2') {
        if (s[1] == '*') return 6;
        if (s[1] >= '0' && s[1] <= '6') return 1;
    }
    return 0;
}

int numDecodings(char* s) {
    int slen = strlen(s);
    long long dp[slen];
    dp[0] = calcOne(s);
    if (slen == 1) return dp[0];
    dp[1] = calcTwo(s) + dp[0] * calcOne(s + 1);
    for (int i = 2; i < slen; ++i) {
        dp[i] = (dp[i - 1] * calcOne(s + i)) % N;
        dp[i] = (dp[i] + dp[i - 2] * calcTwo(s + i - 1)) % N;
    }
    return dp[slen - 1];
}

// slow
int calc(int n0, int n1, char c1, char c) {
    int res = c - '0' > 0 ? n1 : 0;
    if (c1 > '0' && (c1 - '0') * 10 + c - '0' < 27) res = (res + n0) % N;
    return res;
}

int numDecodings(char* s) {
    int slen = strlen(s);
    if (s[0] == '0') return 0;
    int n[slen][10];
    for (int i = 0; i < 10; ++i) {
        n[0][i] = 1;
    }
    for (int m = 1; m < slen; ++m) {
        int n0 = 0;
        if (m == 1)
            n0 = 1;
        else if (s[m - 2] != '*')
            n0 = n[m - 2][s[m - 2] - '0'];
        else {
            for (int i = 1; i < 10; ++i) {
                n0 = (n0 + n[m - 2][i]) % N;
            }
        }
        for (int i = 0; i < 10; ++i) {
            n[m][i] = 0;
            if (i > 0 && s[m] == '*' || s[m] == i + '0') {
                for (int j = 0; j < 10; ++j) {
                    if (j > 0 && s[m - 1] == '*' || s[m - 1] == j + '0') {
                        n[m][i] = (n[m][i] + calc(n0, n[m - 1][j], '0' + j, '0' + i)) % N;
                    }
                }
            }
        }
    }
    if (s[slen - 1] != '*') return n[slen - 1][s[slen - 1] - '0'];
    int res = 0;
    for (int i = 1; i < 10; ++i) {
        res = (res + n[slen - 1][i]) % N;
    }
    return res;
}
