/**
 * Given an array of meeting time intervals consisting of start and end times [[s1,e1],[s2,e2],...] (si < ei), find the
 * minimum number of conference rooms required.
 */

#include <stdlib.h>

int minMeetingRooms(int** intervals, int intervalsSize, int* intervalsColSize) {
    if (intervalsSize < 2) return intervalsSize;
    int maxtime = intervals[0][1];
    for (int i = 1; i < intervalsSize; ++i) {
        int tmp = intervals[i][1];
        if (maxtime < tmp) maxtime = tmp;
    }
    maxtime += 1;
    int* timeline = (int*)malloc(sizeof(int) * maxtime);
    for (int i = 0; i < maxtime; ++i) {
        timeline[i] = 0;
    }
    for (int i = 0; i < intervalsSize; ++i) {
        int* tmp = intervals[i];
        timeline[tmp[0]] += 1;
        timeline[tmp[1]] -= 1;
    }
    int curr = 0;
    int ret = 0;
    for (int i = 0; i < maxtime; ++i) {
        curr += timeline[i];
        if (timeline[i] > 0 && curr > ret) ret = curr;
    }
    return ret;
}