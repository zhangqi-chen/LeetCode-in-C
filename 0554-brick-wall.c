/**
 * There is a brick wall in front of you. The wall is rectangular and has several rows of bricks. The bricks have the
 * same height but different width. You want to draw a vertical line from the top to the bottom and cross the least
 * bricks.
 * 
 * The brick wall is represented by a list of rows. Each row is a list of integers representing the width of each brick
 * in this row from left to right.
 * 
 * If your line go through the edge of a brick, then the brick is not considered as crossed. You need to find out how
 * to draw the line to cross the least bricks and return the number of crossed bricks.
 * 
 * You cannot draw a line just along one of the two vertical edges of the wall, in which case the line will obviously
 * cross no bricks.
 */

#define CNT_NUM 100000
#define LOC_NUM 10000

int leastBricks(int **wall, int wallSize, int *wallColSize) {
    if (wallSize == 0 || wallColSize[0] == 0) return 0;
    int cnt[CNT_NUM] = {0};
    int loc[LOC_NUM];
    int locSize = 0;
    int max = 0;
    for (int i = 0; i < wallSize; ++i) {
        int curr = 0;
        for (int j = 0; j < wallColSize[i] - 1; ++j) {
            curr += wall[i][j];
            cnt[curr]++;
            if (cnt[curr] == 1) loc[locSize++] = curr;
            if (cnt[curr] > max) max = cnt[curr];
        }
    }
    return wallSize - max;
}