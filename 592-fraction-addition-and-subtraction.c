/**
 * Given a string representing an expression of fraction addition and subtraction, you need to return the calculation
 * result in string format. The final result should be irreducible fraction. If your final result is an integer, say
 * 2, you need to change it to the format of fraction that has denominator 1. So in this case, 2 should be converted 
 * to 2/1.
 */

#include <stdlib.h>
#include <string.h>

int gcd(int a, int b) {
    if (a < 0) a = -a;
    while (b > 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

char* fractionAddition(char* expression) {
    int numerator = 0;
    int denominator = 1;
    int p = 1;
    int n, d;
    while (*expression) {
        p = 1;
        if (*expression == '-') {
            p = -1;
            ++expression;
        } else if (*expression == '+') {
            ++expression;
        }
        n = 0;
        while (*expression >= '0' && *expression <= '9') {
            n = n * 10 + *expression - '0';
            ++expression;
        }
        ++expression;
        d = 0;
        while (*expression >= '0' && *expression <= '9') {
            d = d * 10 + *expression - '0';
            ++expression;
        }
        numerator = numerator * d + p * denominator * n;
        denominator *= d;
        if (numerator == 0)
            denominator = 1;
        else {
            int tmp = gcd(numerator, denominator);
            denominator /= tmp;
            numerator /= tmp;
        }
    }
    char* ret = (char*)malloc(sizeof(char) * 20);
    sprintf(ret, "%d/%d", numerator, denominator);
    return ret;
}