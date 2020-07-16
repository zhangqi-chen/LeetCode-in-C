/**
 * Given a list of scores of different students, return the average score of each student's top five scores in the
 * order of each student's id.
 * Each entry items[i] has items[i][0] the student's id, and items[i][1] the student's score.  The average score is
 * calculated using integer division.
 */

#include <stdlib.h>

#define NUM 1000

int cmp(const void* a, const void* b) {
    return (*(int*)b - *(int*)a);
}

int** highFive(int** items, int itemsSize, int* itemsColSize, int* returnSize, int** returnColumnSizes) {
    int* grades[NUM] = {NULL};
    int gradeSize[NUM] = {0};
    for (int i = 0; i < itemsSize; ++i) {
        int id = items[i][0];
        if (grades[id] == NULL) grades[id] = (int*)malloc(sizeof(int) * NUM);
        grades[id][gradeSize[id]++] = items[i][1];
    }
    int** ret = (int**)malloc(sizeof(int*) * NUM);
    *returnSize = 0;
    *returnColumnSizes = (int*)malloc(sizeof(int*) * NUM);
    for (int i = 0; i < NUM; ++i) {
        if (grades[i] == NULL) continue;
        qsort(grades[i], gradeSize[i], sizeof(int), cmp);
        ret[*returnSize] = (int*)malloc(sizeof(int) * 2);
        (*returnColumnSizes)[*returnSize] = 2;
        ret[*returnSize][0] = i;
        ret[(*returnSize)++][1] = (grades[i][0] + grades[i][1] + grades[i][2] + grades[i][3] + grades[i][4]) / 5;
    }
    return ret;
}