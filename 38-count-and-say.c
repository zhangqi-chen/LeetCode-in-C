/**
 * The count-and-say sequence is the sequence of integers with the first five terms as following:
 * 
 * 1. 1
 * 2. 11
 * 3. 21
 * 4. 1211
 * 5. 111221
 * 
 * 1 is read off as "one 1" or 11.
 * 11 is read off as "two 1s" or 21.
 * 21 is read off as "one 2, then one 1" or 1211.
 * 
 * Given an integer n where 1 ≤ n ≤ 30, generate the nth term of the count-and-say sequence. You
 * can do so recursively, in other words from the previous member read off the digits, counting the number of digits in groups of the same digit.
 * 
 * Note: Each term of the sequence of integers will be represented as a string.
 */

#include <stdlib.h>

char* countAndSay(int n) {
    int i, j, k, count;
    char c;
    char* res = (char*)malloc(sizeof(char) * n * 2);
    char* prev = (char*)malloc(sizeof(char) * n * 2);
    char* temp;
    res[0] = '1';
    res[1] = '\0';
    if (n == 1) return res;
    for (i = 1; i < n; i++) {
        temp = prev;
        prev = res;
        res = temp;
        j = 0;
        k = 0;
        c = '\0';
        while (prev[j]) {
            if (prev[j] == c) {
                count++;
            } else {
                if (c) {
                    res[k++] = '0' + count;
                    res[k++] = c;
                }
                c = prev[j];
                count = 1;
            }
            j++;
        }
        res[k++] = '0' + count;
        res[k++] = c;
        res[k] = '\0';
    }
    free(prev);
    return res;
}