/**
 * Determine whether an integer is a palindrome. An integer is a palindrome when it reads the same backward as forward.
 */

#include <stdbool.h>

bool isPalindrome(int x) {
    if (x < 0) return false;
    if (x < 10) return true;
    long res = 0, y = x;
    while (x > 0) {
        res = res * 10 + x % 10;
        x = x / 10;
    }
    if (y == res)
        return true;
    else
        return false;
}