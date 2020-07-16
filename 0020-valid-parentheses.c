/**
 * Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
 * 
 * An input string is valid if:
 * 
 * Open brackets must be closed by the same type of brackets
 * Open brackets must be closed in the correct order.
 * Note that an empty string is also considered valid.
 */

#include <stdbool.h>
#include <string.h>

bool isValid(char* s) {
    int length = strlen(s);
    if (length == 0)
        return true;
    else if (length == 1)
        return false;
    char queue[length + 1];
    queue[0] = s[0];
    int dict[128];
    dict[')'] = '(';
    dict[']'] = '[';
    dict['}'] = '{';
    int i, k = 1;
    for (i = 1; i < length; i++) {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
            queue[k] = s[i];
            k++;
        } else if (k == 0)
            return false;
        else if (dict[s[i]] == queue[k - 1])
            k--;
        else
            return false;
    }
    if (k == 0)
        return true;
    else
        return false;
}