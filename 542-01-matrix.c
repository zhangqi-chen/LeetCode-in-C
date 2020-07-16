/**
 * Given a matrix consists of 0 and 1, find the distance of the nearest 0 for each cell.
 * 
 * The distance between two adjacent cells is 1.
 */

int** updateMatrix(int** matrix, int matrixSize, int* matrixColSize, int* returnSize, int** returnColumnSizes) {
    *returnSize = matrixSize;
    *returnColumnSizes = matrixColSize;
    int rows = matrixSize;
    int cols = matrixColSize[0];
    int* rqueue = (int*)malloc(sizeof(int) * rows * cols);
    int* cqueue = (int*)malloc(sizeof(int) * rows * cols);
    int qSize = 0;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (matrix[i][j])
                matrix[i][j] = -1;
            else {
                rqueue[qSize] = i;
                cqueue[qSize++] = j;
            }
        }
    }
    int idx = 0;
    int path = 0;
    int a[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    while (idx < qSize) {
        int currSize = qSize;
        ++path;
        for (int i = idx; i < currSize; ++i) {
            int r = rqueue[i];
            int c = cqueue[i];
            for (int j = 0; j < 4; ++j) {
                if (r + a[j][0] >= rows || r + a[j][0] < 0) continue;
                if (c + a[j][1] >= cols || c + a[j][1] < 0) continue;
                if (matrix[r + a[j][0]][c + a[j][1]] >= 0) continue;
                matrix[r + a[j][0]][c + a[j][1]] = path;
                rqueue[qSize] = r + a[j][0];
                cqueue[qSize++] = c + a[j][1];
            }
        }
        idx = currSize;
    }
    return matrix;
}