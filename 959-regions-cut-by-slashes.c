/**
 * In a N x N grid composed of 1 x 1 squares, each 1 x 1 square consists of a /, \, or blank space.  These characters
 * divide the square into contiguous regions.
 * 
 * (Note that backslash characters are escaped, so a \ is represented as "\\".)
 * 
 * Return the number of regions.
 */

#include <stdlib.h>

void initUnion(int* parent, int size) {
    for (int i = 0; i < size; ++i) {
        parent[i] = i;
    }
}

int FindUnion(int* parent, int a) {
    if (parent[a] != a) {
        parent[a] = FindUnion(parent, parent[a]);
    }
    return parent[a];
}

void AddPair(int* parent, int a, int b) {
    int pa = FindUnion(parent, a);
    int pb = FindUnion(parent, b);
    if (pa < pb)
        parent[pb] = pa;
    else if (pb < pa)
        parent[pa] = pb;
}

int regionsBySlashes(char** grid, int gridSize) {
    int n = gridSize;
    int size = n * n * 2;
    int* parent = (int*)malloc(sizeof(int) * size);
    initUnion(parent, size);
    int u, d, tmp;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            u = (i * n + j) * 2;
            d = u + 1;
            if (grid[i][j] == ' ') parent[d] = u;
            if (i > 0) AddPair(parent, u, ((i - 1) * n + j) * 2 + 1);
            if (j > 0) {
                tmp = (i * n + j - 1) * 2 + (grid[i][j - 1] == '/' ? 1 : 0);
                AddPair(parent, grid[i][j] == '\\' ? d : u, tmp);
            }
        }
    }
    int* count = (int*)malloc(sizeof(int) * size);
    int regions = 0;
    for (int i = 0; i < size; ++i) {
        count[i] = 0;
    }
    for (int i = 0; i < size; ++i) {
        int j = FindUnion(parent, i);
        if (count[j]) continue;
        ++count[j];
        ++regions;
    }
    return regions;
}