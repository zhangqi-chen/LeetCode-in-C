/**
 * Given two words (beginWord and endWord), and a dictionary's word list, find the length of shortest transformation
 * sequence from beginWord to endWord, such that:
 * 
 * Only one letter can be changed at a time.
 * Each transformed word must exist in the word list. Note that beginWord is not a transformed word.
 * 
 * Note:
 * Return 0 if there is no such transformation sequence.
 * All words have the same length.
 * All words contain only lowercase alphabetic characters.
 * You may assume no duplicates in the word list.
 * You may assume beginWord and endWord are non-empty and are not the same.
 */

#include <stdlib.h>
#include <string.h>

int ladderLength(char* beginWord, char* endWord, char** wordList, int wordListSize) {
    int size = wordListSize + 1;
    int wlen = strlen(beginWord);
    char** list = (char**)malloc(sizeof(char*) * size);
    int* visited = (int*)malloc(sizeof(int) * size);
    int** diff = (int**)malloc(sizeof(int*) * size);
    int* diffSize = (int*)malloc(sizeof(int) * size);
    int endidx = 0;
    for (int i = 0; i < size; ++i) {
        list[i] = i == 0 ? beginWord : wordList[i - 1];
        visited[i] = 0;
        diff[i] = (int*)malloc(sizeof(int) * size);
        diffSize[i] = 0;
        if (strcmp(endWord, list[i]) == 0) {
            endidx = i;
        }
    }
    if (endidx == 0) return 0;
    for (int i = 0; i < size; ++i) {
        for (int j = i + 1; j < size; ++j) {
            int tmp = 0;
            for (int k = 0; k < wlen; ++k) {
                tmp += list[i][k] != list[j][k];
                if (tmp > 1) break;
            }
            if (tmp == 1) {
                diff[i][diffSize[i]++] = j;
                diff[j][diffSize[j]++] = i;
            }
        }
    }
    int* curr = (int*)malloc(sizeof(int) * size);
    int* prev = (int*)malloc(sizeof(int) * size);
    int prevSize, currSize = 1;
    int level = 1;
    curr[0] = 0;
    visited[0] = 1;
    while (currSize > 0) {
        ++level;
        int* tmp = prev;
        prev = curr;
        curr = tmp;
        prevSize = currSize;
        currSize = 0;
        for (int i = 0; i < prevSize; ++i) {
            for (int j = 0; j < diffSize[prev[i]]; ++j) {
                int k = diff[prev[i]][j];
                if (visited[k]) continue;
                if (k == endidx) return level;
                curr[currSize++] = k;
                visited[k] = 1;
            }
        }
    }
    return 0;
}