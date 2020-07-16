/**
 * Given a collection of intervals, merge all overlapping intervals.
 */

#include <stdlib.h>

int cmp(const void* A, const void* B) {
    int** a = (int**)A;
    int** b = (int**)B;
    return (*a)[0] - (*b)[0];
}

int** merge(int** intervals, int intervalsSize, int* intervalsColSize, int* returnSize, int** returnColumnSizes) {
    *returnSize = 0;
    if (intervalsSize == 0) return 0;
    *returnColumnSizes = (int*)malloc(sizeof(int) * intervalsSize);
    int** res = (int**)malloc(sizeof(int*) * intervalsSize);
    qsort(intervals, intervalsSize, sizeof(int*), cmp);
    int start = intervals[0][0];
    int end = intervals[0][1];
    for (int i = 1; i < intervalsSize; ++i) {
        if (intervals[i][0] > end) {
            (*returnColumnSizes)[*returnSize] = 2;
            res[*returnSize] = (int*)malloc(sizeof(int) * 2);
            res[*returnSize][0] = start;
            res[*returnSize][1] = end;
            ++(*returnSize);
            start = intervals[i][0];
            end = intervals[i][1];
        } else if (intervals[i][1] > end) {
            end = intervals[i][1];
        }
    }
    (*returnColumnSizes)[*returnSize] = 2;
    res[*returnSize] = (int*)malloc(sizeof(int) * 2);
    res[*returnSize][0] = start;
    res[*returnSize][1] = end;
    ++(*returnSize);
    return res;
}