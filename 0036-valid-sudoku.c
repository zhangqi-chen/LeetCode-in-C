/**
 * Determine if a 9x9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:
 * 
 * Each row must contain the digits 1-9 without repetition.
 * Each column must contain the digits 1-9 without repetition.
 * Each of the 9 3x3 sub-boxes of the grid must contain the digits 1-9 without repetition.
 * 
 * The Sudoku board could be partially filled, where empty cells are filled with the character '.'.
 */

#include <stdbool.h>
#include <stdlib.h>

bool isValidSudoku(char** board, int boardSize, int* boardColSize) {
    char **rows, **cols, **squares;
    rows = (int**)malloc(sizeof(int*) * boardSize);
    cols = (int**)malloc(sizeof(int*) * boardSize);
    squares = (int**)malloc(sizeof(int*) * boardSize);
    int i, j, s;
    char c;
    for (i = 0; i < boardSize; i++) {
        rows[i] = (int*)malloc(sizeof(int) * boardSize);
        cols[i] = (int*)malloc(sizeof(int) * boardSize);
        squares[i] = (int*)malloc(sizeof(int) * boardSize);
        for (j = 0; j < boardSize; j++) {
            rows[i][j] = 0;
            cols[i][j] = 0;
            squares[i][j] = 0;
        }
    }
    for (i = 0; i < boardSize; i++) {
        for (j = 0; j < boardSize; j++) {
            c = board[i][j];
            if (c == '.') continue;
            s = 3 * (i / 3) + j / 3;
            if (rows[i][c - '1'] > 0 || cols[j][c - '1'] > 0 || squares[s][c - '1'] > 0)
                return false;
            else {
                rows[i][c - '1'] = 1;
                cols[j][c - '1'] = 1;
                squares[s][c - '1'] = 1;
            }
        }
    }
    free(rows);
    free(cols);
    free(squares);
    return true;
}
