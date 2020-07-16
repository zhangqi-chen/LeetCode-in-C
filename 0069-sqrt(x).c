/**
 * Implement int sqrt(int x).
 * 
 * Compute and return the square root of x, where x is guaranteed to be a non-negative integer.
 * 
 * Since the return type is an integer, the decimal digits are truncated and only the integer 
 * part of the result is returned.
 */
#include <stdlib.h>

int mySqrt(int x) {
    if (x <= 1)
        return x;
    double r = x;
    double p = 0;
    while (abs(p - r) > 1e-1) {
        p = r;
        r = (r + x / r) / 2;
    }
    return (int)r;
}