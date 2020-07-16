/**
 * Given a string containing just the characters '(' and ')', find the
 * length of the longest valid (well-formed) parentheses substring.
 */

#include <string.h>

int longestValidParentheses(char* s) {
    int len = strlen(s);
    if (len < 2) return 0;
    int *data, *dict;
    data = (int*)malloc(sizeof(int) * (len + 1));
    dict = (int*)malloc(sizeof(int) * (len * 2 + 2));
    int i, ans = 0;
    for (i = 0; i < len * 2 + 1; i++) dict[i] = 0;
    data[0] = len;
    dict[data[0]] = 1;
    for (i = 1; i < len + 1; i++) {
        data[i] = data[i - 1] + (s[i - 1] == '(' ? 1 : -1);
        dict[data[i] + 1] = 0;
        if (dict[data[i]] == 0)
            dict[data[i]] = i + 1;
        else if (i + 1 - dict[data[i]] > ans)
            ans = i + 1 - dict[data[i]];
    }
    free(data);
    free(dict);
    return ans;
}
