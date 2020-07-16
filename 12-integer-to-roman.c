/**
 * Given an integer, convert it to a roman numeral. Input is guaranteed to be within the range from 1 to 3999.
 */

#include <stdio.h>
#include <stdlib.h>

char* intToRoman(int num) {
    char roman[4][3] = {"MMM", "CDM", "XLC", "IVX"};
    int dict[3] = {1, 5, 10};
    char* res = (char*)malloc(30 * sizeof(char));
    int i, j, curr, k = 0;
    for (i = 0; i < 4; i++) {
        curr = num;
        for (j = 0; j < 3 - i; j++) curr /= 10;
        if (curr == 0) continue;
        curr %= 10;
        if (curr == 4 || curr == 9) {
            curr += 1;
            res[k] = roman[i][0];
            k++;
        }
        j = 2;
        while (curr > 0) {
            if (curr >= dict[j]) {
                curr -= dict[j];
                res[k] = roman[i][j];
                k++;
                j = 0;
            }else
                j--;
        }
    }
    res[k] = '\0';
    return res;
}

int main() {
    int num = 1994;
    char* roman = intToRoman(num);
    printf("%s", roman);
    return 0;
}