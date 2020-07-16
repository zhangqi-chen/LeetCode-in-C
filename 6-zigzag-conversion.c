/**
 * The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)
 * 
 * P   A   H   N
 * A P L S I I G
 * Y   I   R
 * And then read line by line: "PAHNAPLSIIGYIR"
 * 
 * Write the code that will take a string and make this conversion given a number of rows.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* convert(char* s, int numRows) {
    if (numRows == 1) return s;
    char* zigzag;
    int i, j, k, m, n, a;
    n = numRows;
    m = strlen(s);
    zigzag = (char*)malloc((m + 1) * sizeof(char));
    k = 0;
    for (i = 0; i < n; i++) {
        if (i == 0 || i == n - 1) {
            for (j = i; j < m; j += 2 * n - 2) {
                zigzag[k] = s[j];
                k++;
            }
        } else {
            for (j = i; j < m; j += 2 * n - 2) {
                zigzag[k] = s[j];
                k++;
                a = (2 * n - 2) * (j / (2 * n - 2));
                if (a + 2 * n - 2 - (j - a) < m) {
                    zigzag[k] = s[a + 2 * n - 2 - (j - a)];
                    k++;
                }
            }
        }
    }
    zigzag[m] = '\0';
    return zigzag;
}

int main() {
    char s[] = "PAYPALISHIRING";
    char* r;
    r = convert(s, 4);
    printf("%s", r);
    return 0;
}