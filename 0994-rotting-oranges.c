/**
 * In a given grid, each cell can have one of three values:
 * 
 * the value 0 representing an empty cell;
 * the value 1 representing a fresh orange;
 * the value 2 representing a rotten orange.
 * 
 * Every minute, any fresh orange that is adjacent (4-directionally) to a rotten orange becomes rotten.
 * 
 * Return the minimum number of minutes that must elapse until no cell has a fresh orange.  If this is impossible, return -1 instead.
 */

#include <stdlib.h>

int orangesRotting(int **grid, int gridSize, int *gridColSize) {
    int rows = gridSize;
    int cols = gridColSize[0];
    int *rqueue = (int *)malloc(sizeof(int) * rows * cols);
    int *cqueue = (int *)malloc(sizeof(int) * rows * cols);
    int qSize = 0;
    int a[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (grid[i][j] < 2) continue;
            rqueue[qSize] = i;
            cqueue[qSize++] = j;
        }
    }
    int idx = 0;
    int time = 0 < qSize ? -1 : 0;
    while (idx < qSize) {
        ++time;
        int curr = qSize;
        for (int i = idx; i < curr; ++i) {
            int r = rqueue[i];
            int c = cqueue[i];
            for (int j = 0; j < 4; ++j) {
                int rr = r + a[j][0];
                int cc = c + a[j][1];
                if (rr >= rows || rr < 0 || cc >= cols || cc < 0) continue;
                if (grid[rr][cc] != 1) continue;
                grid[rr][cc] = 2;
                rqueue[qSize] = rr;
                cqueue[qSize++] = cc;
            }
        }
        idx = curr;
    }
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (grid[i][j] == 1) return -1;
        }
    }
    return time;
}