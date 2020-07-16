/**
 * Given two sequences pushed and popped with distinct values, return true if and only if this could have been the result
 * of a sequence of push and pop operations on an initially empty stack.
 */

#include <stdbool.h>
#include <stdlib.h>

bool validateStackSequences(int* pushed, int pushedSize, int* popped, int poppedSize) {
    if (poppedSize > pushedSize) return false;
    int* stack = (int*)malloc(sizeof(int) * pushedSize);
    int s = -1;
    int i, j;
    i = j = 0;
    while (i < pushedSize || j < poppedSize) {
        if (j == poppedSize) return true;
        if (i == pushedSize && popped[j] != stack[s]) return false;
        if (s >= 0 && stack[s] == popped[j]) {
            ++j;
            --s;
        } else {
            stack[++s] = pushed[i++];
        }
    }
    return true;
}