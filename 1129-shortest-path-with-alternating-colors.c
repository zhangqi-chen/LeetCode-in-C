/**
 * Consider a directed graph, with nodes labelled 0, 1, ..., n-1.  In this graph, each edge is either red or blue, and
 * there could be self-edges or parallel edges.
 * 
 * Each [i, j] in red_edges denotes a red directed edge from node i to node j.  Similarly, each [i, j] in blue_edges
 * denotes a blue directed edge from node i to node j.
 * 
 * Return an array answer of length n, where each answer[X] is the length of the shortest path from node 0 to node X such
 * that the edge colors alternate along the path (or -1 if such a path doesn't exist).
 */

#include <stdlib.h>

int* shortestAlternatingPaths(int n, int** red_edges, int red_edgesSize, int* red_edgesColSize, int** blue_edges, int blue_edgesSize, int* blue_edgesColSize, int* returnSize) {
    // Graph Info
    int** redGraph = (int**)malloc(sizeof(int*) * n);
    int** blueGraph = (int**)malloc(sizeof(int*) * n);
    int* redGraphSize = (int*)malloc(sizeof(int) * n);
    int* blueGraphSize = (int*)malloc(sizeof(int) * n);
    for (int i = 0; i < n; ++i) {
        redGraphSize[i] = 0;
        blueGraphSize[i] = 0;
        redGraph[i] = (int*)malloc(sizeof(int) * n);
        blueGraph[i] = (int*)malloc(sizeof(int) * n);
    }
    for (int i = 0; i < red_edgesSize; ++i) {
        int* tmp = red_edges[i];
        redGraph[tmp[0]][redGraphSize[tmp[0]]++] = tmp[1];
    }
    for (int i = 0; i < blue_edgesSize; ++i) {
        int* tmp = blue_edges[i];
        blueGraph[tmp[0]][blueGraphSize[tmp[0]]++] = tmp[1];
    }
    // Shortest path for vertex end with red/blue edge
    int* redPath = (int*)malloc(sizeof(int) * n);
    int* bluePath = (int*)malloc(sizeof(int) * n);
    for (int i = 0; i < n; ++i) {
        redPath[i] = -1;
        bluePath[i] = -1;
    }
    redPath[0] = bluePath[0] = 0;
    // Queue for BFS
    int** redQueue = (int**)malloc(sizeof(int*) * 2);
    int** blueQueue = (int**)malloc(sizeof(int*) * 2);
    for (int i = 0; i < 2; ++i) {
        redQueue[i] = (int*)malloc(sizeof(int) * n);
        blueQueue[i] = (int*)malloc(sizeof(int) * n);
    }
    int redQueueSize[2] = {0, 1};
    int blueQueueSize[2] = {0, 1};
    redQueue[1][0] = 0;
    blueQueue[1][0] = 0;
    int path = 0;
    // BFS
    while (redQueueSize[1] || blueQueueSize[1]) {
        ++path;
        // Switch two queues
        redQueueSize[0] = redQueueSize[1];
        redQueueSize[1] = 0;
        blueQueueSize[0] = blueQueueSize[1];
        blueQueueSize[1] = 0;
        int* tmp = redQueue[0];
        redQueue[0] = redQueue[1];
        redQueue[1] = tmp;
        tmp = blueQueue[0];
        blueQueue[0] = blueQueue[1];
        blueQueue[1] = tmp;
        // BFS add to queue
        for (int i = 0; i < redQueueSize[0]; ++i) {
            int red = redQueue[0][i];
            for (int j = 0; j < blueGraphSize[red]; ++j) {
                int nextBlue = blueGraph[red][j];
                if (bluePath[nextBlue] >= 0) continue;
                bluePath[nextBlue] = path;
                blueQueue[1][blueQueueSize[1]++] = nextBlue;
            }
        }
        for (int i = 0; i < blueQueueSize[0]; ++i) {
            int blue = blueQueue[0][i];
            for (int j = 0; j < redGraphSize[blue]; ++j) {
                int nextRed = redGraph[blue][j];
                if (redPath[nextRed] >= 0) continue;
                redPath[nextRed] = path;
                redQueue[1][redQueueSize[1]++] = nextRed;
            }
        }
    }
    // return shortest path in two paths
    for (int i = 0; i < n; ++i) {
        if (redPath[i] == -1 && bluePath[i] >= 0)
            redPath[i] = bluePath[i];
        else if (redPath[i] * bluePath[i] >= 0 && redPath[i] > bluePath[i])
            redPath[i] = bluePath[i];
    }
    *returnSize = n;
    return redPath;
}