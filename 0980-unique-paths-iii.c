/**
 * On a 2-dimensional grid, there are 4 types of squares:
 * 
 * 1 represents the starting square.  There is exactly one starting square.
 * 2 represents the ending square.  There is exactly one ending square.
 * 0 represents empty squares we can walk over.
 * -1 represents obstacles that we cannot walk over.
 * 
 * Return the number of 4-directional walks from the starting square to the ending square, that walk over every
 * non-obstacle square exactly once.
 */

int rows, cols, pathNum;

void path(int** grid, int r, int c, int steps, int dest) {
    if (grid[r][c] == 2) {
        if (steps == dest) ++pathNum;
        return;
    }
    if (grid[r][c] != 0) return;
    grid[r][c] = 1;
    if (r > 0) path(grid, r - 1, c, steps + 1, dest);
    if (r < rows - 1) path(grid, r + 1, c, steps + 1, dest);
    if (c > 0) path(grid, r, c - 1, steps + 1, dest);
    if (c < cols - 1) path(grid, r, c + 1, steps + 1, dest);
    grid[r][c] = 0;
}

int uniquePathsIII(int** grid, int gridSize, int* gridColSize) {
    pathNum = 0;
    rows = gridSize;
    cols = gridColSize[0];
    int r, c;
    int dest = 0;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (grid[i][j] == -1)
                continue;
            else if (grid[i][j] == 1) {
                r = i;
                c = j;
                grid[i][j] = 0;
            }
            ++dest;
        }
    }
    path(grid, r, c, 1, dest);
    return pathNum;
}