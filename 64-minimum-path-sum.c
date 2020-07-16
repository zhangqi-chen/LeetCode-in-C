/**
 * Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right
 * which minimizes the sum of all numbers along its path.
 * 
 * Note: You can only move either down or right at any point in time.
 */

int minPathSum(int** grid, int gridSize, int* gridColSize) {
    int rows = gridSize;
    int cols = gridColSize[0];
    int path[cols];
    path[0] = grid[0][0];
    for (int i = 1; i < cols; ++i) {
        path[i] = path[i - 1] + grid[0][i];
    }
    for (int i = 1; i < rows; ++i) {
        path[0] += grid[i][0];
        for (int j = 1; j < cols; ++j) {
            path[j] = grid[i][j] + (path[j - 1] > path[j] ? path[j] : path[j - 1]);
        }
    }
    return path[cols - 1];
}