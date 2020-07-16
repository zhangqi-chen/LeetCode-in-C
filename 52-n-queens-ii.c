/**
 * The n-queens puzzle is the problem of placing n queens on an n×n chessboard such
 * that no two queens attack each other.
 * 
 * Given an integer n, return the number of distinct solutions to the n-queens puzzle.
 */

int oneQueen(int n, int *chess, int first) {
    int choices[n];
    int i, j, ans = 0;
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
            if (first == n - 1)
                ans += 1;
            else
                ans += oneQueen(n, chess, first + 1);
        }
    }
    return ans;
}

int totalNQueens(int n) {
    if (n == 0 || n == 2 || n == 3) return 0;
    int chess[n];
    int ans = 0;
    ans = oneQueen(n, chess, 0);
    return ans;
}