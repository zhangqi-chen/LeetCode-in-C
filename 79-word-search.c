/**
 * Given a 2D board and a word, find if the word exists in the grid.
 * 
 * The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally
 * or vertically neighboring. The same letter cell may not be used more than once.
 */

#include <stdbool.h>
#include <string.h>

bool search(char** board, bool** visited, int rows, int cols, int r, int c, char* word) {
    if (strlen(word) == 0) return true;
    bool ans;
    if (r > 0 && !visited[r - 1][c] && board[r - 1][c] == word[0]) {
        visited[r - 1][c] = true;
        ans = search(board, visited, rows, cols, r - 1, c, word + 1);
        if (ans) return true;
        visited[r - 1][c] = false;
    }
    if (r < rows - 1 && !visited[r + 1][c] && board[r + 1][c] == word[0]) {
        visited[r + 1][c] = true;
        ans = search(board, visited, rows, cols, r + 1, c, word + 1);
        if (ans) return true;
        visited[r + 1][c] = false;
    }
    if (c > 0 && !visited[r][c - 1] && board[r][c - 1] == word[0]) {
        visited[r][c - 1] = true;
        ans = search(board, visited, rows, cols, r, c - 1, word + 1);
        if (ans) return true;
        visited[r][c - 1] = false;
    }
    if (c < cols - 1 && !visited[r][c + 1] && board[r][c + 1] == word[0]) {
        visited[r][c + 1] = true;
        ans = search(board, visited, rows, cols, r, c + 1, word + 1);
        if (ans) return true;
        visited[r][c + 1] = false;
    }
    return false;
}

bool exist(char** board, int boardSize, int* boardColSize, char* word) {
    int rows = boardSize;
    int cols = boardColSize[0];
    bool** visited = (bool**)malloc(sizeof(bool*) * rows);
    for (int i = 0; i < rows; ++i) {
        visited[i] = (bool*)malloc(sizeof(bool) * cols);
        for (int j = 0; j < cols; ++j) {
            visited[i][j] = false;
        }
    }
    bool ans;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (word[0] != board[i][j]) continue;
            visited[i][j] = true;
            ans = search(board, visited, rows, cols, i, j, word + 1);
            if (ans) return true;
            visited[i][j] = false;
        }
    }
    free(visited);
    return false;
}