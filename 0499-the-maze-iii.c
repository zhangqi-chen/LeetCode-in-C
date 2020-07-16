/**
 * There is a ball in a maze with empty spaces and walls. The ball can go through empty spaces by rolling up (u),
 * down (d), left (l) or right (r), but it won't stop rolling until hitting a wall. When the ball stops, it could
 * choose the next direction. There is also a hole in this maze. The ball will drop into the hole if it rolls on
 * to the hole.
 * 
 * Given the ball position, the hole position and the maze, find out how the ball could drop into the hole by moving
 * the shortest distance. The distance is defined by the number of empty spaces traveled by the ball from the start
 * position (excluded) to the hole (included). Output the moving directions by using 'u', 'd', 'l' and 'r'. Since
 * there could be several different shortest ways, you should output the lexicographically smallest way. If the ball
 * cannot reach the hole, output "impossible".
 * 
 * The maze is represented by a binary 2D array. 1 means the wall and 0 means the empty space. You may assume that
 * the borders of the maze are all walls. The ball and the hole coordinates are represented by row and column indexes.
 */

#include <stdlib.h>
#include <string.h>

typedef struct _path {
    int length;   // Path length
    char* steps;  // Path steps
} Path;

char* findShortestWay(int** maze, int mazeSize, int* mazeColSize, int* ball, int ballSize, int* hole, int holeSize) {
    int rows = mazeSize;
    int cols = mazeColSize[0];
    maze[hole[0]][hole[1]] = 2;  // Hole marked with 2
    // Path info for every position, intialized with NULL
    Path*** mazePath = (Path***)malloc(sizeof(Path**) * rows);
    for (int i = 0; i < rows; ++i) {
        mazePath[i] = (Path**)malloc(sizeof(Path*) * cols);
        for (int j = 0; j < cols; ++j) {
            mazePath[i][j] = NULL;
        }
    }
    // BFS queue, initalized with ball position
    int* rqueue = (int*)malloc(sizeof(int*) * rows * cols);
    int* cqueue = (int*)malloc(sizeof(int*) * rows * cols);
    int qSize = 0;
    rqueue[qSize] = ball[0];
    cqueue[qSize++] = ball[1];
    // Path info at ball position
    Path* ballpath = (Path*)malloc(sizeof(Path));
    ballpath->length = 0;
    ballpath->steps = "\0";
    mazePath[ball[0]][ball[1]] = ballpath;
    // 4 directions
    int a[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    char d[4] = {'d', 'u', 'r', 'l'};
    // BFS
    int qStart = 0;
    while (qStart < qSize) {
        int currSize = qSize;
        for (int i = qStart; i < currSize; ++i) {
            int rs = rqueue[i];
            int cs = cqueue[i];
            Path* currPath = mazePath[rs][cs];
            int lenStart = currPath->length;
            int newNsteps = strlen(currPath->steps) + 1;
            for (int j = 0; j < 4; ++j) {
                // Incrementals
                int ra = a[j][0];
                int ca = a[j][1];
                // Current position
                int rc = rs;
                int cc = cs;
                int len = lenStart;  // Current length
                // Move forward incrementally if there is no wall
                while (rc + ra >= 0 && rc + ra < rows && cc + ca >= 0 && cc + ca < cols && maze[rc + ra][cc + ca] != 1) {
                    rc += ra;
                    cc += ca;
                    ++len;
                    if (rc == hole[0] && cc == hole[1]) break;  // Break if arrives hole
                }
                if (rc == rs && cc == cs) continue;                                        // Continue if the ball hasn't moved
                if (mazePath[rc][cc] != NULL && mazePath[rc][cc]->length < len) continue;  // Continue if path is longer than the exist one
                // New steps info
                char* newsteps = (char*)malloc(sizeof(char) * (newNsteps + 1));
                strcpy(newsteps, currPath->steps);
                newsteps[newNsteps] = '\0';
                newsteps[newNsteps - 1] = d[j];
                // Continue if the length is the same but steps is lexicographically bigger
                if (mazePath[rc][cc] != NULL && mazePath[rc][cc]->length == len && strcmp(newsteps, mazePath[rc][cc]->steps) >= 0) continue;
                // Replace the Path at position (rc, cc)
                Path* newPath = (Path*)malloc(sizeof(Path));
                newPath->length = len;
                newPath->steps = newsteps;
                mazePath[rc][cc] = newPath;
                if (maze[rc][cc] == 2) continue;  // Hole isn't added to queue
                rqueue[qSize] = rc;
                cqueue[qSize++] = cc;
            }
        }
        qStart = currSize;
    }
    if (mazePath[hole[0]][hole[1]] == NULL) return "impossible";  // No path if Path[hole] is NULL
    return mazePath[hole[0]][hole[1]]->steps;
}