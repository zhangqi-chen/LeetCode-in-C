/**
 * Write a program to solve a Sudoku puzzle by filling the empty cells.
 * 
 * A sudoku solution must satisfy all of the following rules:
 * 
 * Each of the digits 1-9 must occur exactly once in each row.
 * Each of the digits 1-9 must occur exactly once in each column.
 * Each of the the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.
 * 
 * Empty cells are indicated by the character '.'.
 */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

bool dfs(char** board, bool** rows, bool** cols, bool** squares, int r, int c) {
    bool choices[9];
    int s = (r / 3) * 3 + c / 3;
    int i, j, nr, nc;

    // List choices of (r, c)
    for (i = 0; i < 9; i++) {
        choices[i] = false;
        if (rows[r][i] || cols[c][i] || squares[s][i])
            choices[i] = true;
    }

    // Find next blank (nr, nc)
    nr = r;
    nc = c;
    while (nr < 9) {
        nc = nc + 1;
        if (nc == 9) {
            nc = 0;
            nr = nr + 1;
        }
        if (nr < 9 && board[nr][nc] == '.') break;
    }

    // Fill the blank with number i ('1'+i)
    bool ans;
    for (i = 0; i < 9; i++) {
        if (choices[i]) continue;
        board[r][c] = '1' + i;
        rows[r][i] = cols[c][i] = squares[s][i] = true;
        if (nr == 9) return true;  // no blank left
        ans = dfs(board, rows, cols, squares, nr, nc);
        if (ans == false) {  // erase number i
            board[r][c] = '.';
            rows[r][i] = cols[c][i] = squares[s][i] = false;
        } else
            return true;
    }
    return false;  // no choices
}

void solveSudoku(char** board, int boardSize, int* boardColSize) {
    // initialize
    bool **rows, **cols, **squares;
    rows = (bool**)malloc(sizeof(bool*) * boardSize);
    cols = (bool**)malloc(sizeof(bool*) * boardSize);
    squares = (bool**)malloc(sizeof(bool*) * boardSize);
    int i, j, s;
    for (i = 0; i < boardSize; i++) {
        rows[i] = (bool*)malloc(sizeof(bool) * boardSize);
        cols[i] = (bool*)malloc(sizeof(bool) * boardSize);
        squares[i] = (bool*)malloc(sizeof(bool) * boardSize);
        for (j = 0; j < boardSize; j++) {
            rows[i][j] = cols[i][j] = squares[i][j] = false;
        }
    }
    // input existing data
    char num;
    int r, c;
    r = c = -1;
    for (i = 0; i < boardSize; i++) {
        for (j = 0; j < boardSize; j++) {
            num = board[i][j];
            if (num == '.' && r == -1) {
                r = i;
                c = j;
                continue;
            } else if (num == '.')
                continue;
            else {
                s = 3 * (i / 3) + j / 3;
                rows[i][num - '1'] = true;
                cols[j][num - '1'] = true;
                squares[s][num - '1'] = true;
            }
        }
    }
    // solve sudoku
    if (r > -1) dfs(board, rows, cols, squares, r, c);
    free(rows);
    free(cols);
    free(squares);
}

int main() {
    int i, j;
    char sdk[9][9] = {{"53..7...."},
                      {"6..195..."},
                      {".98....6."},
                      {"8...6...3"},
                      {"4..8.3..1"},
                      {"7...2...6"},
                      {".6....28."},
                      {"...419..5"},
                      {"....8..79"}};
    char* bo[9];
    for (i = 0; i < 9; i++) {
        bo[i] = sdk[i];
    }
    int csize[9] = {9, 9, 9, 9, 9, 9, 9, 9, 9};
    for (i = 0; i < 9; i++) {
        for (j = 0; j < 9; j++) {
            printf("%c ", bo[i][j]);
        }
        printf("\n");
    }
    solveSudoku(bo, 9, csize);
    printf("Solved:\n");
    for (i = 0; i < 9; i++) {
        for (j = 0; j < 9; j++) {
            printf("%c ", bo[i][j]);
        }
        printf("\n");
    }
    return 0;
}