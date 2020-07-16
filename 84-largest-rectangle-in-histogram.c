/** Given n non-negative integers representing the histogram's bar height where the width of each bar is 1,
 * find the area of largest rectangle in the histogram.
 */

// stack
int largestRectangleArea(int* heights, int heightsSize) {
    if (heightsSize == 0) return 0;
    int area, maxarea = 0;
    int stack[heightsSize + 1];
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
    return maxarea;
}

// divide & conquer
int largestRectangleArea(int* heights, int heightsSize) {
    if (heightsSize == 0) return 0;
    int i, idx;
    idx = 0;
    for (i = 1; i < heightsSize; ++i) {
        if (heights[i] < heights[idx]) idx = i;
    }
    int area = heights[idx] * heightsSize;
    int left = largestRectangleArea(heights, idx);
    int right = largestRectangleArea(heights + idx + 1, heightsSize - idx - 1);
    if (left > area) area = left;
    if (right > area) area = right;
    return area;
}
