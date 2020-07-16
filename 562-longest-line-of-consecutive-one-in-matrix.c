/**
 * Given a 01 matrix M, find the longest line of consecutive one in the matrix. The line could be horizontal, vertical,
 * diagonal or anti-diagonal.
 */

#include <stdlib.h>

int longestLine(int** M, int MSize, int* MColSize) {
    if (MSize == 0) return 0;
    int rows = MSize;
    int cols = MColSize[0];
    if (cols == 0) return 0;
    int** dp[4];  // 0: horizontal, 1: vertical, 2: diagonal, 3: anti-diagonal
    for (int i = 0; i < 4; ++i) {
        dp[i] = (int**)malloc(sizeof(int*) * rows);
        for (int j = 0; j < rows; ++j) {
            dp[i][j] = (int*)malloc(sizeof(int) * cols);
            for (int k = 0; k < cols; ++k) {
                dp[i][j][k] = 0;
            }
        }
    }
    int max = 0;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (M[i][j] == 0) continue;
            dp[0][i][j] = dp[1][i][j] = dp[2][i][j] = dp[3][i][j] = 1;
            if (i > 0) dp[1][i][j] = dp[1][i - 1][j] + 1;
            if (j > 0) dp[0][i][j] = dp[0][i][j - 1] + 1;
            if (i > 0 && j > 0) dp[2][i][j] = dp[2][i - 1][j - 1] + 1;
            if (i > 0 && j < cols - 1) dp[3][i][j] = dp[3][i - 1][j + 1] + 1;
            if (dp[0][i][j] > max) max = dp[0][i][j];
            if (dp[1][i][j] > max) max = dp[1][i][j];
            if (dp[2][i][j] > max) max = dp[2][i][j];
            if (dp[3][i][j] > max) max = dp[3][i][j];
        }
    }
    return max;
}