/**
 * Given two non-negative integers num1 and num2 represented as strings,
 * return the product of num1 and num2, also represented as a string.
 */
#include <stdlib.h>
#include <string.h>

char* multiply(char* num1, char* num2) {
    int len1 = strlen(num1);
    int len2 = strlen(num2);
    int* temp = (int*)malloc(sizeof(int) * (len1 + len2));
    char* res = (char*)malloc(sizeof(char) * (len1 + len2 + 1));
    memset(temp, 0, sizeof(int) * (len1 + len2));
    int i, j;
    for (i = len1 - 1; i >= 0; i--) {
        for (j = len2 - 1; j >= 0; j--) {
            temp[i + j + 1] += (num1[i] - '0') * (num2[j] - '0');
        }
    }
    for (i = len1 + len2 - 1; i > 0; i--) {
        temp[i - 1] += temp[i] / 10;
        temp[i] %= 10;
    }
    for (i = 0; i < len1 + len2 && temp[i] == 0; i++) {
    }
    if (i == len1 + len2) {
        res[0] = '0';
        res[1] = '\0';
    } else {
        for (j = i; j < len1 + len2; j++) {
            res[j - i] = temp[j] + '0';
        }
        res[j - i] = '\0';
    }
    return res;
}