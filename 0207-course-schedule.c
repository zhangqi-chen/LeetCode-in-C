/**
 * There are a total of numCourses courses you have to take, labeled from 0 to numCourses-1.
 * 
 * Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is 
 * expressed as a pair: [0,1]
 * 
 * Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses?
 */

#include <stdbool.h>
#include <stdlib.h>

int** graph;
int *gSize, *visited, *looped;

bool loop(int s) {
    for (int i = 0; i < gSize[s]; ++i) {
        int n = graph[s][i];
        if (visited[n]) return true;
        visited[n] = 1;
        if (looped[n] == -1) looped[n] = loop(n);
        if (looped[n]) return true;
        visited[n] = 0;
    }
    looped[s] = 0;
    return false;
}

bool canFinish(int numCourses, int** prerequisites, int prerequisitesSize, int* prerequisitesColSize) {
    graph = (int**)malloc(sizeof(int*) * numCourses);
    gSize = (int*)malloc(sizeof(int) * numCourses);
    visited = (int*)malloc(sizeof(int) * numCourses);
    looped = (int*)malloc(sizeof(int) * numCourses);
    for (int i = 0; i < numCourses; ++i) {
        visited[i] = 0;
        gSize[i] = 0;
        looped[i] = -1;
        graph[i] = (int*)malloc(sizeof(int) * (numCourses - 1));
    }
    for (int i = 0; i < prerequisitesSize; ++i) {
        int* tmp = prerequisites[i];
        graph[tmp[1]][gSize[tmp[1]]++] = tmp[0];
    }
    for (int i = 0; i < numCourses; ++i) {
        if (loop(i)) return false;
    }
    return true;
}