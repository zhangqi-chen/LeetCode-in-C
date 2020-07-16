/**
 * Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.
 */

#include <stdbool.h>
#include <string.h>

bool isPalindrome(char* s) {
    int i = 0;
    int j = strlen(s) - 1;
    while (i < j) {
        while (i < j) {
            if (s[i] >= 'a' && s[i] <= 'z') break;
            if (s[i] >= '0' && s[i] <= '9') break;
            if (s[i] >= 'A' && s[i] <= 'Z') {
                s[i] += 'a' - 'A';
                break;
            }
            ++i;
        }
        while (i < j) {
            if (s[j] >= 'a' && s[j] <= 'z') break;
            if (s[j] >= '0' && s[j] <= '9') break;
            if (s[j] >= 'A' && s[j] <= 'Z') {
                s[j] += 'a' - 'A';
                break;
            }
            --j;
        }
        if (i == j) break;
        if (s[i] != s[j]) return false;
        ++i;
        --j;
    }
    return true;
}