/**
 * Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.
 */

int largestRectangleArea(char* heights, int heightsSize) {
    if (heightsSize == 0) return 0;
    int area, maxarea = 0;
    int* stack = (int*)malloc(sizeof(int) * (heightsSize + 1));
    stack[0] = -1;  // important
    int top = 0;
    for (int i = 0; i < heightsSize; ++i) {
        while (top > 0 && heights[i] < heights[stack[top]]) {
            area = heights[stack[top]] * (i - stack[top - 1] - 1);  // starts with stack[top-1]+1, ends with i-1
            if (maxarea < area) maxarea = area;
            --top;
        }
        stack[++top] = i;
    }
    while (top > 0) {
        area = heights[stack[top]] * (heightsSize - stack[top - 1] - 1);
        if (maxarea < area) maxarea = area;
        --top;
    }
    free(stack);
    return maxarea;
}

int maximalRectangle(char** matrix, int matrixSize, int* matrixColSize) {
    int rows = matrixSize;
    if (rows == 0) return 0;
    int cols = matrixColSize[0];

    for (int i = 0; i < cols; ++i) {
        if (matrix[0][i] == '1')
            matrix[0][i] = 1;
        else
            matrix[0][i] = 0;
    }
    int max = largestRectangleArea(matrix[0], cols);
    for (int i = 1; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (matrix[i][j] == '1')
                matrix[i][j] = 1 + matrix[i - 1][j];
            else
                matrix[i][j] = 0;
        }
        int curr = largestRectangleArea(matrix[i], cols);
        if (curr > max) max = curr;
    }
    return max;
}