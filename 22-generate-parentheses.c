/**
 * Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
 */

#include <stdlib.h>
#include <string.h>

char **generateParenthesis(int n, int *returnSize) {
    char **res = (char **)malloc(sizeof(char *));
    if (n == 0) {
        *returnSize = 1;
        res[0] = (char *)malloc(sizeof(char) * 1);
        res[0][0] = '\0';
        return res;
    } else {
        *returnSize = 0;
        char **left, **right;
        int *leftSize, *rightSize;
        leftSize = (int *)malloc(sizeof(int));
        rightSize = (int *)malloc(sizeof(int));
        int i, k, p, q;
        k = 0;
        for (i = 0; i <= n - i - 1; i++) {
            left = generateParenthesis(i, leftSize);
            right = generateParenthesis(n - i - 1, rightSize);
            *returnSize += (*leftSize) * (*rightSize);
            res = (char **)realloc(res, sizeof(char *) * (*returnSize));
            for (p = 0; p < *leftSize; p++) {
                for (q = 0; q < *rightSize; q++) {
                    res[k] = (char *)malloc(sizeof(char) * (2 * n + 1));
                    strcpy(res[k], "(");
                    strcat(res[k], left[p]);
                    strcat(res[k], ")");
                    strcat(res[k], right[q]);
                    res[k][2 * n] = '\0';
                    k++;
                }
            }
            // Speed up
            if (i < n - i - 1) {
                *returnSize += (*leftSize) * (*rightSize);
                res = (char **)realloc(res, sizeof(char *) * (*returnSize));
                for (p = 0; p < *rightSize; p++) {
                    for (q = 0; q < *leftSize; q++) {
                        res[k] = (char *)malloc(sizeof(char) * (2 * n + 1));
                        strcpy(res[k], "(");
                        strcat(res[k], right[p]);
                        strcat(res[k], ")");
                        strcat(res[k], left[q]);
                        res[k][2 * n] = '\0';
                        k++;
                    }
                }
            }
        }
    }
    return res;
}