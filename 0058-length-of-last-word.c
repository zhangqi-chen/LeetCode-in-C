/**
 * Given a string s consists of upper/lower-case alphabets and empty space characters ' ',
 * return the length of last word (last word means the last appearing word if we loop from
 * left to right) in the string.
 */

#include <string.h>

int lengthOfLastWord(char* s) {
    int start = -1;
    int end = -1;
    for (int i = strlen(s) - 1; i >= 0; --i) {
        if (start < 0 && s[i] != ' ') {
            start = i;
        } else if (start >= 0 && s[i] == ' ') {
            end = i;
            break;
        }
    }
    return start - end;
}