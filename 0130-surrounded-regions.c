/**
 * Given a 2D board containing 'X' and 'O' (the letter O), capture all regions surrounded by 'X'.
 * 
 * A region is captured by flipping all 'O's into 'X's in that surrounded region.
 * 
 * Example:
 * 
 * X X X X
 * X O O X
 * X X O X
 * X O X X
 * 
 * After running your function, the board should be:
 * 
 * X X X X
 * X X X X
 * X X X X
 * X O X X
 * 
 * Explanation:
 * 
 * Surrounded regions shouldn’t be on the border, which means that any 'O' on the border of the board are not flipped
 * to 'X'. Any 'O' that is not on the border and it is not connected to an 'O' on the border will be flipped to 'X'.
 * Two cells are connected if they are adjacent cells connected horizontally or vertically.
 */

void searchbound(char** board, int** visited, int rsize, int csize, int r, int c) {
    if (c < csize - 1 && board[r][c + 1] == 'O' && visited[r][c + 1] == 0) {
        visited[r][c + 1] = 1;
        searchbound(board, visited, rsize, csize, r, c + 1);
    }
    if (c > 0 && board[r][c - 1] == 'O' && visited[r][c - 1] == 0) {
        visited[r][c - 1] = 1;
        searchbound(board, visited, rsize, csize, r, c - 1);
    }
    if (r < rsize - 1 && board[r + 1][c] == 'O' && visited[r + 1][c] == 0) {
        visited[r + 1][c] = 1;
        searchbound(board, visited, rsize, csize, r + 1, c);
    }
    if (r > 0 && board[r - 1][c] == 'O' && visited[r - 1][c] == 0) {
        visited[r - 1][c] = 1;
        searchbound(board, visited, rsize, csize, r - 1, c);
    }
}

void solve(char** board, int boardSize, int* boardColSize) {
    if (boardSize < 3 || boardColSize[0] < 3) return;
    int rsize = boardSize;
    int csize = boardColSize[0];
    int** visited = (int**)malloc(sizeof(int*) * rsize);
    for (int i = 0; i < rsize; ++i) {
        visited[i] = (int*)malloc(sizeof(int) * csize);
        for (int j = 0; j < csize; ++j) {
            visited[i][j] = 0;
        }
    }
    for (int i = 0; i < csize; ++i) {
        if (board[0][i] == 'O' && visited[0][i] == 0) {
            visited[0][i] = 1;
            searchbound(board, visited, rsize, csize, 0, i);
        }
        if (board[rsize - 1][i] == 'O' && visited[rsize - 1][i] == 0) {
            visited[rsize - 1][i] = 1;
            searchbound(board, visited, rsize, csize, rsize - 1, i);
        }
    }
    for (int i = 1; i < rsize - 1; ++i) {
        if (board[i][0] == 'O' && visited[i][0] == 0) {
            visited[i][0] = 1;
            searchbound(board, visited, rsize, csize, i, 0);
        }
        if (board[i][csize - 1] == 'O' && visited[i][csize - 1] == 0) {
            visited[i][csize - 1] = 1;
            searchbound(board, visited, rsize, csize, i, csize - 1);
        }
    }
    for (int i = 0; i < rsize; ++i) {
        for (int j = 0; j < csize; ++j) {
            if (board[i][j] == 'O' && visited[i][j] == 0) {
                board[i][j] = 'X';
            }
        }
    }
}