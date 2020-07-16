/**
 * There are a total of n courses you have to take, labeled from 0 to n-1.
 * 
 * Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is
 * expressed as a pair: [0,1]
 * 
 * Given the total number of courses and a list of prerequisite pairs, return the ordering of courses you should
 * take to finish all courses.
 * 
 * There may be multiple correct orders, you just need to return one of them. If it is impossible to finish all
 * courses, return an empty array.
 */

#include <stdlib.h>

int** graph;
int* graphSize;
int* status;

int dfs(int* ret, int numCourses, int* returnSize, int s) {
    status[s] = 1;
    int ans = 1;
    for (int i = 0; i < graphSize[s]; ++i) {
        int n = graph[s][i];
        if (status[n] == 2) continue;
        if (status[n] == 1) return -1;
        ans = dfs(ret, numCourses, returnSize, n);
        if (ans == -1) return -1;
    }
    status[s] = 2;
    ret[numCourses - 1 - (*returnSize)++] = s;
    return 1;
}

int* findOrder(int numCourses, int** prerequisites, int prerequisitesSize, int* prerequisitesColSize, int* returnSize) {
    graph = (int**)malloc(sizeof(int*) * numCourses);
    graphSize = (int*)malloc(sizeof(int) * numCourses);
    status = (int*)malloc(sizeof(int) * numCourses);
    for (int i = 0; i < numCourses; ++i) {
        status[i] = 0;
        graphSize[i] = 0;
        graph[i] = (int*)malloc(sizeof(int) * (numCourses - 1));
    }
    for (int i = 0; i < prerequisitesSize; ++i) {
        int* tmp = prerequisites[i];
        graph[tmp[1]][graphSize[tmp[1]]++] = tmp[0];
    }
    int ans;
    int* ret = (int*)malloc(sizeof(int) * numCourses);
    *returnSize = 0;
    for (int i = 0; i < numCourses; ++i) {
        if (status[i] == 0) ans = dfs(ret, numCourses, returnSize, i);
        if (ans == -1) {
            *returnSize = 0;
            return 0;
        }
    }
    return ret;
}