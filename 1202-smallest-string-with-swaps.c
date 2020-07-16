/**
 * You are given a string s, and an array of pairs of indices in the string pairs where pairs[i] = [a, b] indicates
 * 2 indices(0-indexed) of the string.
 * 
 * You can swap the characters at any pair of indices in the given pairs any number of times.
 * 
 * Return the lexicographically smallest string that s can be changed to after using the swaps.
 */

#include <stdlib.h>
#include <string.h>

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
    else
        parent[pa] = pb;
}

void compressUnion(int* parent, int size) {
    for (int i = 0; i < size; ++i) {
        FindUnion(parent, i);
    }
}

int** compressUnionData(int* parent, int size, int* unionSize) {
    unionSize = (int*)malloc(sizeof(int) * size);
    int** unionIdx = (int**)malloc(sizeof(int*) * size);
    for (int i = 0; i < size; ++i) {
        ++unionSize[FindUnion(parent, i)];
    }
    for (int i = 0; i < size; ++i) {
        if (unionSize[i] == 0) continue;
        unionIdx[i] = (int*)malloc(sizeof(int) * unionSize[i]);
        unionSize[i] = 0;
    }
    for (int i = 0; i < size; ++i) {
        int p = parent[i];
        unionIdx[p][unionSize[p]] = i;
    }
    return unionIdx;
}

int cmp(const void* a, const void* b) {
    return (*(char*)a - *(char*)b);
}

char* smallestStringWithSwaps(char* s, int** pairs, int pairsSize, int* pairsColSize) {
    int slen = strlen(s);
    if (pairsSize == 0 || slen <= 1) return s;
    int* parent = (int*)malloc(sizeof(int) * slen);
    initUnion(parent, slen);
    for (int i = 0; i < pairsSize; ++i) {
        AddPair(parent, pairs[i][0], pairs[i][1]);
    }
    int* unionSize = (int*)malloc(sizeof(int) * slen);
    int** unionIdx = (int**)malloc(sizeof(int*) * slen);
    char** data = (char**)malloc(sizeof(char*) * slen);
    memset(unionSize, 0, sizeof(int) * slen);
    for (int i = 0; i < slen; ++i) {
        ++unionSize[FindUnion(parent, i)];
    }
    for (int i = 0; i < slen; ++i) {
        if (unionSize[i] == 0) continue;
        unionIdx[i] = (int*)malloc(sizeof(int) * unionSize[i]);
        data[i] = (char*)malloc(sizeof(char) * unionSize[i]);
        unionSize[i] = 0;
    }
    for (int i = 0; i < slen; ++i) {
        int p = parent[i];
        unionIdx[p][unionSize[p]] = i;
        data[p][unionSize[p]++] = s[i];
    }
    for (int i = 0; i < slen; ++i) {
        if (unionSize[i] == 0) continue;
        qsort(data[i], unionSize[i], sizeof(char), cmp);
        for (int j = 0; j < unionSize[i]; ++j) {
            s[unionIdx[i][j]] = data[i][j];
        }
    }
    return s;
}