/**
 * Given a string containing digits from 2-9 inclusive, return all possible
 * letter combinations that the number could represent.
 */

#include <stdlib.h>
#include <string.h>

char** letterCombinations(char* digits, int* returnSize) {
    int length = strlen(digits);
    int i, j, interval, n;
    *returnSize = 0;
    if (length == 0) return 0;
    char dict[10][4] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    *returnSize = 1;
    for (i = 0; i < length; i++) {
        n = digits[i] == '9' || digits[i] == '7' ? 4 : 3;
        (*returnSize) *= n;
    }
    char** res = (char**)malloc(sizeof(char*) * (*returnSize));
    for (i = 0; i < *returnSize; i++) {
        res[i] = (char*)malloc(sizeof(char) * (length + 1));
        res[i][length] = '\0';
    }
    interval = *returnSize;
    for (i = 0; i < length; i++) {
        n = digits[i] == '9' || digits[i] == '7' ? 4 : 3;
        interval /= n;
        int m = digits[i] - '0';
        for (j = 0; j < *returnSize; j++) {
            res[j][i] = dict[m][(j / interval) % n];
        }
    }
    return res;
}