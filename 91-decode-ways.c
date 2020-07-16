/**
 * A message containing letters from A-Z is being encoded to numbers using the following mapping:
 * 
 * 'A' -> 1
 * 'B' -> 2
 * ...
 * 'Z' -> 26
 * 
 * Given a non-empty string containing only digits, determine the total number of ways to decode it.
 */

#include <string.h>

int numDecodings(char* s) {
    int slen = strlen(s);
    if (s[0] == '0') return 0;
    if (slen == 1) return 1;
    int n[slen];
    int prev = s[0] - '0';
    int curr = s[1] - '0';
    n[0] = 1;
    n[1] = curr > 0 ? 1 : 0;
    if (prev * 10 + curr < 27) n[1] += 1;
    prev = curr;
    for (int i = 2; i < slen; ++i) {
        curr = s[i] - '0';
        n[i] = curr > 0 ? n[i - 1] : 0;
        if (prev > 0 && prev * 10 + curr < 27) n[i] += n[i - 2];
        if (n[i] == 0 && n[i - 1] == 0) return 0;
        prev = curr;
    }
    return n[slen - 1];
}