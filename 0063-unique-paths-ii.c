/**
 * A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).
 * 
 * The robot can only move either down or right at any point in time. The robot is trying to reach
 * the bottom-right corner of the grid (marked 'Finish' in the diagram below).
 * 
 * Now consider if some obstacles are added to the grids. How many unique paths would there be?
 */

int uniquePathsWithObstacles(int** obstacleGrid, int obstacleGridSize, int* obstacleGridColSize) {
    int rows = obstacleGridSize;
    int cols = obstacleGridColSize[0];
    long data[cols];
    for (int i = 0; i < cols; ++i) {
        data[i] = 0;
    }
    data[0] = 1;
    for (int i = 0; i < rows; ++i) {
        data[0] = obstacleGrid[i][0] == 0 && data[0];
        for (int j = 1; j < cols; ++j) {
            if (obstacleGrid[i][j] == 1)
                data[j] = 0;
            else
                data[j] += data[j - 1];
        }
    }
    return data[cols - 1];
}