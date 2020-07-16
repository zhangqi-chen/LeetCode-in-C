/**
 * The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that
 * no two queens attack each other.
 * 
 * Given an integer n, return all distinct solutions to the n-queens puzzle.
 * 
 * Each solution contains a distinct board configuration of the n-queens' placement, where
 * 'Q' and '.' both indicate a queen and an empty space respectively.
 */

#include <stdlib.h>

void oneQueen(char ***res, int n, int *chess, int first, int *returnSize, int **returnColumnSizes) {
    int choices[n];
    int i, j;
    memset(choices, 0, sizeof(int) * n);
    for (i = 0; i < first; ++i) {
        choices[chess[i]] = 1;
        j = first - i;
        if (chess[i] - j >= 0 && chess[i] - j < n) choices[chess[i] - j] = 1;
        if (chess[i] + j >= 0 && chess[i] + j < n) choices[chess[i] + j] = 1;
    }
    for (i = 0; i < n; ++i) {
        if (choices[i] == 0) {
            chess[first] = i;
            if (first == n - 1) {
                (*returnColumnSizes)[*returnSize] = n;
                res[*returnSize] = (char **)malloc(sizeof(char *) * n);
                for (j = 0; j < n; ++j) {
                    res[*returnSize][j] = (char *)malloc(sizeof(char) * (n + 1));
                    memset(res[*returnSize][j], '.', sizeof(char) * (n));
                    res[*returnSize][j][chess[j]] = 'Q';
                    res[*returnSize][j][n] = '\0';
                }
                ++(*returnSize);
            } else
                oneQueen(res, n, chess, first + 1, returnSize, returnColumnSizes);
        }
    }
}

char ***solveNQueens(int n, int *returnSize, int **returnColumnSizes) {
    (*returnSize) = 0;
    (*returnColumnSizes) = (char *)malloc(sizeof(char *) * 1000);
    char ***res = (char ***)malloc(sizeof(char **) * 1000);
    if (n == 0) {
        (*returnColumnSizes)[(*returnSize)++] = 0;
        return res;
    }
    int chess[n];
    oneQueen(res, n, chess, 0, returnSize, returnColumnSizes);
    return res;
}