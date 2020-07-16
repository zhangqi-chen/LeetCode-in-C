/**
 * Implement atoi which converts a string to an integer.
 * 
 * The function first discards as many whitespace characters as necessary until the first
 * non-whitespace character is found. Then, starting from this character, takes an optional
 * initial plus or minus sign followed by as many numerical digits as possible, and interprets
 * them as a numerical value.
 * 
 * The string can contain additional characters after those that form the integral number,
 * which are ignored and have no effect on the behavior of this function.
 * 
 * If the first sequence of non-whitespace characters in str is not a valid integral number,
 * or if no such sequence exists because either str is empty or it contains only whitespace
 * characters, no conversion is performed.
 * 
 * If no valid conversion could be performed, a zero value is returned.
 * 
 * Note:
 * Only the space character ' ' is considered as whitespace character.
 * Assume we are dealing with an environment which could only store integers within the 32-bit
 * signed integer range: [−231,  231 − 1]. If the numerical value is out of the range of
 * representable values, INT_MAX (231 − 1) or INT_MIN (−231) is returned.
 */

#include <stdlib.h>
#include <string.h>

int myAtoi(char* str) {
    int len = strlen(str);
    if (len == 0) return 0;
    long long ans = 0;
    int neg = 0;
    int start = 0;
    for (int i = 0; i < len; ++i) {
        if (str[i] == ' ' && start == 0) {
            continue;
        } else if (str[i] == '-' && start == 0) {
            neg = 1;
            start = 1;
        } else if (str[i] == '+' && start == 0) {
            neg = 2;
            start = 1;
        } else if (str[i] >= '0' && str[i] <= '9') {
            if (ans > INT_MAX) break;
            ans = ans * 10 + str[i] - '0';
            start = 1;
        } else {
            break;
        }
    }
    if (neg == 1) ans = -ans;
    if (ans > INT_MAX) ans = INT_MAX;
    if (ans < INT_MIN) ans = INT_MIN;
    return (int)ans;
}