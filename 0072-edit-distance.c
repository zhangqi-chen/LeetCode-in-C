/**
 * Given two words word1 and word2, find the minimum number of operations required to convert word1 to word2.
 * 
 * You have the following 3 operations permitted on a word:
 * 
 * Insert a character
 * Delete a character
 * Replace a character
 */
#include <string.h>

int minDistance(char* word1, char* word2) {
    int len1 = strlen(word1);
    int len2 = strlen(word2);
    if (len1 == 0) return len2;
    if (len2 == 0) return len1;
    int data[len1 + 1][len2 + 1], replace;
    for (int i = 0; i <= len1; ++i) {
        for (int j = 0; j <= len2; ++j) {
            if (i == 0)
                data[i][j] = j;
            else if (j == 0)
                data[i][j] = i;
            else {
                data[i][j] = 1 + (data[i - 1][j] > data[i][j - 1] ? data[i][j - 1] : data[i - 1][j]);
                replace = data[i - 1][j - 1] + (word1[i - 1] != word2[j - 1]);
                if (replace < data[i][j]) data[i][j] = replace;
            }
        }
    }
    return data[len1][len2];
}