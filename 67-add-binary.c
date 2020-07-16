/**
 * Given two binary strings, return their sum (also a binary string).
 * 
 * The input strings are both non-empty and contains only characters 1 or 0.
 */

#include <stdlib.h>
#include <string.h>

char* addBinary(char* a, char* b) {
    if (strlen(a) < strlen(b)) {
        char* temp = a;
        a = b;
        b = temp;
    }
    int lena = strlen(a);
    int lenb = strlen(b);
    char* res = (char*)malloc(sizeof(char) * (lena + 2));
    res[lena + 1] = '\0';
    int n, carry = 0;
    for (int i = 0; i < lena; ++i) {
        n = a[lena - 1 - i] - '0' + carry;
        if (i < lenb)
            n += b[lenb - 1 - i] - '0';
        carry = n / 2;
        res[lena - i] = (n % 2) + '0';
    }
    if (carry)
        res[0] = '1';
    else
        ++res;
    return res;
}