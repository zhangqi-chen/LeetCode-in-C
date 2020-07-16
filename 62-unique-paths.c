/**
 * A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).
 * 
 * The robot can only move either down or right at any point in time. The robot is trying to reach
 * the bottom-right corner of the grid (marked 'Finish' in the diagram below).
 * 
 * How many possible unique paths are there?
 */

int uniquePaths(int m, int n) {
    int data[m];
    for (int i = 0; i < m; ++i) {
        data[i] = 0;
    }
    data[0] = 1;
    for (int i = 0; i < n; ++i) {
        for (int j = 1; j < m; ++j) {
            data[j] += data[j - 1];
        }
    }
    return data[m - 1];
}