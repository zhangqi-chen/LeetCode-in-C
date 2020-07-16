/**
 * Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).
 * 
 * You may assume that the intervals were initially sorted according to their start times.
 */

#include <stdlib.h>

int** insert(int** intervals, int intervalsSize, int* intervalsColSize, int* newInterval, int newIntervalSize, int* ok, int** returnColumnSizes) {
    *ok = 0;
    *returnColumnSizes = (int*)malloc(sizeof(int) * (intervalsSize + 1));
    int** res = (int**)malloc(sizeof(int*) * (intervalsSize + 1));
    int start, stage = 0;
    for (int i = 0; i < intervalsSize; ++i) {
        if (stage == 0) {
            if (intervals[i][0] > newInterval[1]) {
                (*returnColumnSizes)[*ok] = 2;
                res[(*ok)++] = newInterval;
                stage = 2;
                --i;
            } else if (intervals[i][1] < newInterval[0]) {
                (*returnColumnSizes)[*ok] = 2;
                res[(*ok)++] = intervals[i];
            } else {
                start = intervals[i][0] < newInterval[0] ? intervals[i][0] : newInterval[0];
                --i;
                stage = 1;
            }
        } else if (stage == 1) {
            if (newInterval[1] < intervals[i][0]) {
                (*returnColumnSizes)[*ok] = 2;
                res[*ok] = (int*)malloc(sizeof(int) * 2);
                res[*ok][0] = start;
                res[*ok][1] = newInterval[1];
                ++(*ok);
                --i;
                stage = 2;
            } else if (newInterval[1] <= intervals[i][1]) {
                (*returnColumnSizes)[*ok] = 2;
                res[*ok] = (int*)malloc(sizeof(int) * 2);
                res[*ok][0] = start;
                res[*ok][1] = intervals[i][1];
                ++(*ok);
                stage = 2;
            }
        } else {
            (*returnColumnSizes)[*ok] = 2;
            res[(*ok)++] = intervals[i];
        }
    }
    if (stage == 0) {
        (*returnColumnSizes)[*ok] = 2;
        res[(*ok)++] = newInterval;
    } else if (stage == 1) {
        (*returnColumnSizes)[*ok] = 2;
        res[*ok] = (int*)malloc(sizeof(int) * 2);
        res[*ok][0] = start;
        res[*ok][1] = newInterval[1];
        ++(*ok);
    }
    return res;
}