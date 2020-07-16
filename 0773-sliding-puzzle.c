/**
 * On a 2x3 board, there are 5 tiles represented by the integers 1 through 5, and an empty square represented by 0.
 * 
 * A move consists of choosing 0 and a 4-directionally adjacent number and swapping it.
 * 
 * The state of the board is solved if and only if the board is [[1,2,3],[4,5,0]].
 * 
 * Given a puzzle board, return the least number of moves required so that the state of the board is solved. If it is
 * impossible for the state of the board to be solved, return -1.
 */

#include <stdlib.h>

#define N 50

int hash[543211];

int toNum(int* puzzle) {
    int n = 0;
    for (int i = 0; i < 6; ++i) {
        n = (n * 10) + puzzle[i];
    }
    return n;
}

void cpy(int* board, int* new) {
    for (int i = 0; i < 6; ++i) {
        new[i] = board[i];
    }
}

int findzero(int* board) {
    int i;
    for (i = 0; i < 6 && board[i] > 0; ++i) {
    }
    return i;
}

int solve(int* puzzle, int** curr, int* currSize, int j, int d, int step) {
    puzzle[j] = puzzle[j + d];
    puzzle[j + d] = 0;
    int n = toNum(puzzle);
    if (n == 123450) return step;
    if (hash[n] == -1) return -1;
    if (hash[n] == 0) {
        hash[n] = 1;
        cpy(puzzle, curr[(*currSize)++]);
    }
    puzzle[j + d] = puzzle[j];
    puzzle[j] = 0;
    return 0;
}

int slidingPuzzle(int** board, int boardSize, int* boardColSize) {
    for (int i = 0; i < 543211; ++i) {
        hash[i] = 0;
    }
    hash[123450] = 2;
    hash[123540] = hash[123504] = hash[123054] = -1;
    int** curr = (int**)malloc(sizeof(int*) * N);
    int** prev = (int**)malloc(sizeof(int*) * N);
    for (int i = 0; i < N; ++i) {
        curr[i] = (int*)malloc(sizeof(int) * 6);
        prev[i] = (int*)malloc(sizeof(int) * 6);
    }
    int currSize = 1;
    int prevSize = 0;
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 3; ++j) {
            curr[0][i * 3 + j] = board[i][j];
        }
    }
    if (toNum(curr[0]) == 123450) return 0;
    hash[toNum(curr[0])] = 1;
    int step = 0;
    int* puzzle = (int*)malloc(sizeof(int) * 6);
    int ans;
    while (currSize > 0) {
        ++step;
        int** tmp = prev;
        prev = curr;
        curr = tmp;
        prevSize = currSize;
        currSize = 0;
        for (int i = 0; i < prevSize; ++i) {
            cpy(prev[i], puzzle);
            int j = findzero(puzzle);
            if (j < 3) {
                ans = solve(puzzle, curr, &currSize, j, 3, step);
                if (ans != 0) return ans;
            } else {
                ans = solve(puzzle, curr, &currSize, j, -3, step);
                if (ans != 0) return ans;
            }
            if (j % 3 > 0) {
                ans = solve(puzzle, curr, &currSize, j, -1, step);
                if (ans != 0) return ans;
            }
            if (j % 3 < 2) {
                ans = solve(puzzle, curr, &currSize, j, 1, step);
                if (ans != 0) return ans;
            }
        }
    }
    return -1;
}