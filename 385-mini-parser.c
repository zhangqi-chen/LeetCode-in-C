/**
 * Given a nested list of integers represented as a string, implement a parser to deserialize it.
 * 
 * Each element is either an integer, or a list -- whose elements may also be integers or other lists.
 * 
 * Note: You may assume that the string is well-formed:
 * 
 * String is non-empty.
 * String does not contain white spaces.
 * String contains only digits 0-9, [, - ,, ].
 */

#include <stdbool.h>
#include <stdlib.h>

// Initializes an empty nested list and return a reference to the nested integer.
struct NestedInteger *NestedIntegerInit();

// Return true if this NestedInteger holds a single integer, rather than a nested list.
bool NestedIntegerIsInteger(struct NestedInteger *);

// Return the single integer that this NestedInteger holds, if it holds a single integer
// The result is undefined if this NestedInteger holds a nested list
int NestedIntegerGetInteger(struct NestedInteger *);

// Set this NestedInteger to hold a single integer.
void NestedIntegerSetInteger(struct NestedInteger *ni, int value);

// Set this NestedInteger to hold a nested list and adds a nested integer elem to it.
void NestedIntegerAdd(struct NestedInteger *ni, struct NestedInteger *elem);

// Return the nested list that this NestedInteger holds, if it holds a nested list
// The result is undefined if this NestedInteger holds a single integer
struct NestedInteger **NestedIntegerGetList(struct NestedInteger *);

// Return the nested list's size that this NestedInteger holds, if it holds a nested list
// The result is undefined if this NestedInteger holds a single integer
int NestedIntegerGetListSize(struct NestedInteger *);

char *GetNum(char *s, int *num) {
    *num = 0;
    int neg = 1;
    if (*s == '-') {
        neg = -1;
        ++s;
    }
    while (*s >= '0' && *s <= '9') {
        *num = *num * 10 + *s++ - '0';
    }
    *num *= neg;
    return s;
}

char *FindBracket(char *s) {
    int bracket = 1;
    ++s;
    for (int i = 1; i > 0; ++s) {
        if (*s == '[')
            ++i;
        else if (*s == ']')
            --i;
    }
    return s;
}

struct NestedInteger *deserialize(char *s) {
    if (*s != '[') {
        int n;
        GetNum(s, &n);
        struct NestedInteger *nestInt = NestedIntegerInit();
        NestedIntegerSetInteger(nestInt, n);
        return nestInt;
    }
    int bracket = 1;
    ++s;
    struct NestedInteger *ret = NestedIntegerInit();
    while (*s != ']') {
        if (*s == ',') {
            ++s;
        } else if (*s == '-' || (*s >= '0' && *s <= '9')) {
            int n;
            s = GetNum(s, &n);
            struct NestedInteger *nestInt = NestedIntegerInit();
            NestedIntegerSetInteger(nestInt, n);
            NestedIntegerAdd(ret, nestInt);
        } else {
            struct NestedInteger *nestInt = deserialize(s);
            NestedIntegerAdd(ret, nestInt);
            s = FindBracket(s);
        }
    }
    return ret;
}