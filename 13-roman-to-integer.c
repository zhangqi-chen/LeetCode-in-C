/**
 * Given a roman numeral, convert it to an integer. Input is guaranteed to be within the range from 1 to 3999.
 */
#include <stdlib.h>
#include <string.h>

int romanToInt(char* s) {
    char roman[] = "IVXLCDM";
    int nums[] = {1, 5, 10, 50, 100, 500, 1000};
    int dict[26] = {0};
    int i, prev, curr, res = 0;
    for (i = 0; i < strlen(roman); i++) dict[roman[i] - 'A'] = nums[i];
    curr = 10000;
    for (i = 0; i < strlen(s); i++) {
        prev = curr;
        curr = dict[s[i] - 'A'];
        res += curr;
        if (curr > prev) res = res - 2 * prev;
    }
    return res;
}