/**
 * Given two strings A and B of lowercase letters, return true if and only if we can swap two 
 * letters in A so that the result equals B.
 */

#include <stdbool.h>
#include <string.h>

bool buddyStrings(char* A, char* B) {
    int lenA = strlen(A);
    int lenB = strlen(B);
    if (lenA != lenB) return false;
    if (lenA == 0 || lenA == 1) return false;
    int rep[26] = {0};
    int diff = -1;
    for (int i = 0; i < lenA; ++i) {
        ++rep[A[i] - 'a'];
        if (A[i] == B[i]) continue;
        if (diff == -2) {
            return false;
        } else if (diff == -1) {
            diff = i;
        } else {
            if (A[i] == B[diff] && A[diff] == B[i])
                diff = -2;
            else
                return false;
        }
    }
    if (diff == -2)
        return true;
    else if (diff >= 0)
        return false;
    else {
        for (int i = 0; i < 26; ++i) {
            if (rep[i] > 1) return true;
        }
        return false;
    }
}