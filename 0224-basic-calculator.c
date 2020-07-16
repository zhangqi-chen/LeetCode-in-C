/**
 * Implement a basic calculator to evaluate a simple expression string.
 * 
 * The expression string may contain open ( and closing parentheses ), the plus + or minus sign -, non-negative
 * integers and empty spaces .
 */

#include <stdlib.h>
#include <string.h>

int calculate(char* s) {
    int* stack = (char*)malloc(sizeof(int) * strlen(s));
    int size = 0;
    while (*s) {
        if (*s == ' ') {
            ++s;
            continue;
        }
        if (*s == ')') {
            --size;
            stack[size - 1] = stack[size];
        } else if (*s >= '0' && *s <= '9') {
            int n = *s++ - '0';
            while (*s >= '0' && *s <= '9') {
                n = n * 10 + (*s++ - '0');
            }
            --s;
            stack[size++] = n;
        } else {
            stack[size++] = *s++;
            continue;
        }
        if (size > 2 && stack[size - 2] != '(') {
            stack[size - 3] += stack[size - 2] == '+' ? stack[size - 1] : -stack[size - 1];
            size -= 2;
        }
        ++s;
    }
    return stack[0];
}