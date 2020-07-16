/**
 * For an undirected graph with tree characteristics, we can choose any node as the root. The result graph is then a
 * rooted tree. Among all possible rooted trees, those with minimum height are called minimum height trees (MHTs).
 * Given such a graph, write a function to find all the MHTs and return a list of their root labels.
 * 
 * Format
 * The graph contains n nodes which are labeled from 0 to n - 1. You will be given the number n and a list of
 * undirected edges (each edge is a pair of labels).
 * 
 * You can assume that no duplicate edges will appear in edges. Since all edges are undirected, [0, 1] is the same as
 * [1, 0] and thus will not appear together in edges.
 */

#include <stdlib.h>
#include <string.h>

// DFS, time too long
int minHeight;
int* nodes;
int** graph;
int* graphSize;

int findHeight(int first) {
    int leaves = 0;
    int nextHeight = 0;
    for (int i = 0; i < graphSize[first]; ++i) {
        int n = graph[first][i];
        if (nodes[n]) continue;
        ++leaves;
        nodes[n] = 1;
        int nHeight = findHeight(n);
        if (nHeight >= minHeight) {
            nodes[n] = 0;
            return minHeight + 1;
        }
        if (nHeight > nextHeight) nextHeight = nHeight;
        nodes[n] = 0;
    }
    if (leaves == 0) return 0;
    return 1 + nextHeight;
}

int* findMinHeightTrees(int n, int** edges, int edgesSize, int* edgesColSize, int* returnSize) {
    graph = (int**)malloc(sizeof(int*) * n);
    graphSize = (int*)malloc(sizeof(int) * n);
    nodes = (int*)malloc(sizeof(int) * n);
    for (int i = 0; i < n; ++i) {
        nodes[i] = 0;
        graphSize[i] = 0;
        graph[i] = (int*)malloc(sizeof(int) * (n - 1));
    }
    for (int i = 0; i < edgesSize; ++i) {
        int a = edges[i][0];
        int b = edges[i][1];
        graph[a][graphSize[a]++] = b;
        graph[b][graphSize[b]++] = a;
    }
    minHeight = edgesSize;
    int* ret = (int*)malloc(sizeof(int) * n);
    *returnSize = 0;
    for (int i = 0; i < n; ++i) {
        nodes[i] = 1;
        int currHeight = findHeight(i);
        nodes[i] = 0;
        if (currHeight < minHeight) {
            *returnSize = 0;
            minHeight = currHeight;
        }
        if (currHeight == minHeight) ret[(*returnSize)++] = i;
    }
    return ret;
}

// Delete degree=1 node everytime
int* findMinHeightTrees(int n, int** edges, int edgesSize, int* edgesColSize, int* returnSize) {
    int** graph = (int**)malloc(sizeof(int*) * n);
    int* graphSize = (int*)malloc(sizeof(int) * n);
    int* nodes = (int*)malloc(sizeof(int) * n);
    for (int i = 0; i < n; ++i) {
        nodes[i] = 0;
        graphSize[i] = 0;
        graph[i] = (int*)malloc(sizeof(int) * (n - 1));
    }
    for (int i = 0; i < edgesSize; ++i) {
        int a = edges[i][0];
        int b = edges[i][1];
        graph[a][graphSize[a]++] = b;
        graph[b][graphSize[b]++] = a;
    }
    int* degree = (int*)malloc(sizeof(int) * n);
    memcpy(degree, graphSize, sizeof(int) * n);
    int num = n;
    int* delete = (int*)malloc(sizeof(int) * n);
    while (num > 2) {
        int dSize = 0;
        for (int i = 0; i < n; ++i) {
            if (degree[i] == 1) {
                degree[i] = -1;
                delete[dSize++] = i;
            }
        }
        for (int i = 0; i < dSize; ++i) {
            int d = delete[i];
            for (int j = 0; j < graphSize[d]; ++j) {
                --degree[graph[d][j]];
            }
        }
        num -= dSize;
    }
    *returnSize = 0;
    int* ret = (int*)malloc(sizeof(int) * num);
    for (int i = 0; i < n; ++i) {
        if (degree[i] >= 0) ret[(*returnSize)++] = i;
    }
    return ret;
}