/**
 * Given an integer n, your task is to count how many strings of length n can be formed under the following rules:
 * 
 * Each character is a lower case vowel ('a', 'e', 'i', 'o', 'u')
 * Each vowel 'a' may only be followed by an 'e'.
 * Each vowel 'e' may only be followed by an 'a' or an 'i'.
 * Each vowel 'i' may not be followed by another 'i'.
 * Each vowel 'o' may only be followed by an 'i' or a 'u'.
 * Each vowel 'u' may only be followed by an 'a'.
 * Since the answer may be too large, return it modulo 10^9 + 7.
 */

#define MODNUM 1000000007

int countVowelPermutation(int n) {
    if (n == 0) return 0;
    long long vowelsCurr[5], vowelsPrev[5];
    for (int i = 0; i < 5; ++i) {
        vowelsCurr[i] = 1;
    }
    for (int i = 1; i < n; ++i) {
        vowelsPrev[0] = vowelsCurr[0];
        vowelsPrev[1] = vowelsCurr[1];
        vowelsPrev[2] = vowelsCurr[2];
        vowelsPrev[3] = vowelsCurr[3];
        vowelsPrev[4] = vowelsCurr[4];
        vowelsCurr[0] = vowelsPrev[1] % MODNUM;
        vowelsCurr[1] = (vowelsPrev[0] + vowelsPrev[2]) % MODNUM;
        vowelsCurr[2] = (vowelsPrev[0] + vowelsPrev[1] + vowelsPrev[3] + vowelsPrev[4]) % MODNUM;
        vowelsCurr[3] = (vowelsPrev[2] + vowelsPrev[4]) % MODNUM;
        vowelsCurr[4] = vowelsPrev[0] % MODNUM;
    }
    long long res = (vowelsCurr[0] + vowelsCurr[1] + vowelsCurr[2] + vowelsCurr[3] + vowelsCurr[4]) % MODNUM;
    return (int)(res % MODNUM);
}