/**
 * Your task is to design the basic function of Excel and implement the function of sum formula. Specifically, you need
 * to implement the following functions:
 * 
 * Excel(int H, char W): This is the constructor. The inputs represents the height and width of the Excel form. H is a 
 * positive integer, range from 1 to 26. It represents the height. W is a character range from 'A' to 'Z'. It represents
 * that the width is the number of characters from 'A' to W. The Excel form content is represented by a height * width
 * 2D integer array C, it should be initialized to zero. You should assume that the first row of C starts from 1, and
 * the first column of C starts from 'A'.
 * 
 * void Set(int row, char column, int val): Change the value at C(row, column) to be val.
 * 
 * int Get(int row, char column): Return the value at C(row, column).
 * 
 * int Sum(int row, char column, List of Strings : numbers): This function calculate and set the value at C(row, column),
 * where the value should be the sum of cells represented by numbers. This function return the sum result at C(row, column).
 * This sum formula should exist until this cell is overlapped by another value or another sum formula.
 * 
 * numbers is a list of strings that each string represent a cell or a range of cells. If the string represent a single
 * cell, then it has the following format : ColRow. For example, "F7" represents the cell at (7, F).
 * 
 * If the string represent a range of cells, then it has the following format : ColRow1:ColRow2. The range will always
 * be a rectangle, and ColRow1 represent the position of the top-left cell, and ColRow2 represents the position of the
 * bottom-right cell.
 */

#include <stdlib.h>
#include <string.h>

typedef struct _CellLink {
    int r;
    int c;
    struct _CellLink* next;
} CellLink;

typedef struct {
    int** data;
    CellLink*** updateTo;
    CellLink*** updateFrom;
} Excel;

Excel* excelCreate(int H, char W) {
    Excel* newExcel = (Excel*)malloc(sizeof(Excel));
    int rows = H;
    int cols = W - 'A' + 1;
    int** data = (int**)malloc(sizeof(int*) * rows);
    CellLink*** updateTo = (CellLink***)malloc(sizeof(CellLink**) * rows);
    CellLink*** updateFrom = (CellLink***)malloc(sizeof(CellLink**) * rows);
    for (int i = 0; i < rows; ++i) {
        data[i] = (int*)malloc(sizeof(int) * cols);
        updateTo[i] = (CellLink**)malloc(sizeof(CellLink*) * cols);
        updateFrom[i] = (CellLink**)malloc(sizeof(CellLink*) * cols);
        for (int j = 0; j < cols; ++j) {
            data[i][j] = 0;
            updateTo[i][j] = NULL;
            updateFrom[i][j] = NULL;
        }
    }
    newExcel->data = data;
    newExcel->updateTo = updateTo;
    newExcel->updateFrom = updateFrom;
    return newExcel;
}

void excelUpdate(Excel* obj, int r, int c, int diff) {
    obj->data[r][c] += diff;
    CellLink* curr = obj->updateTo[r][c];
    while (curr) {
        excelUpdate(obj, curr->r, curr->c, diff);
        curr = curr->next;
    }
}

CellLink* deleteLink(CellLink* link, int r, int c) {
    if (link == NULL) return NULL;
    if (link->r == r && link->c == c) return deleteLink(link->next, r, c);
    link->next = deleteLink(link->next, r, c);
    return link;
}

void excelSet(Excel* obj, int r, char c, int v) {
    int rr = r - 1;
    int cc = c - 'A';
    int diff = v - obj->data[rr][cc];
    excelUpdate(obj, rr, cc, diff);
    CellLink* fromlink = obj->updateFrom[rr][cc];
    while (fromlink) {
        CellLink* curr = obj->updateTo[fromlink->r][fromlink->c];
        obj->updateTo[fromlink->r][fromlink->c] = deleteLink(curr, rr, cc);
        fromlink = fromlink->next;
    }
    obj->updateFrom[rr][cc] = NULL;
}

int excelGet(Excel* obj, int r, char c) {
    return obj->data[r - 1][c - 'A'];
}

void addExcelLink(Excel* obj, int rf, int cf, int rt, int ct) {
    CellLink* newTo = (CellLink*)malloc(sizeof(CellLink));
    newTo->r = rt;
    newTo->c = ct;
    newTo->next = obj->updateTo[rf][cf];
    obj->updateTo[rf][cf] = newTo;
    CellLink* newFrom = (CellLink*)malloc(sizeof(CellLink));
    newFrom->r = rf;
    newFrom->c = cf;
    newFrom->next = obj->updateFrom[rt][ct];
    obj->updateFrom[rt][ct] = newFrom;
}

int excelSum(Excel* obj, int r, char c, char** strs, int strsSize) {
    int rt = r - 1;
    int ct = c - 'A';
    int currsum = 0;
    for (int i = 0; i < strsSize; ++i) {
        char* s = strs[i];
        int cStart = *s++ - 'A';
        int n = 0;
        while (*s && *s != ':') {
            n = n * 10 + *s++ - '0';
        }
        int rStart = n - 1;
        int cEnd = cStart;
        int rEnd = rStart;
        if (*s == ':') {
            ++s;
            cEnd = *s++ - 'A';
            n = 0;
            while (*s) {
                n = n * 10 + *s++ - '0';
            }
            rEnd = n - 1;
        }
        for (int rf = rStart; rf <= rEnd; ++rf) {
            for (int cf = cStart; cf <= cEnd; ++cf) {
                addExcelLink(obj, rf, cf, rt, ct);
                currsum += obj->data[rf][cf];
            }
        }
    }
    obj->data[rt][ct] = currsum;
    return currsum;
}

void excelFree(Excel* obj) {
}