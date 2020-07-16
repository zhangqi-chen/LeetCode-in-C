/**
 * Find the minimum length word from a given dictionary words, which has all the letters from the string licensePlate.
 * Such a word is said to complete the given string licensePlate
 * 
 * Here, for letters we ignore case. For example, "P" on the licensePlate still matches "p" on the word.
 * 
 * It is guaranteed an answer exists. If there are multiple answers, return the one that occurs first in the array.
 * 
 * The license plate might have the same letter occurring multiple times. For example, given a licensePlate of "PP",
 * the word "pair" does not complete the licensePlate, but the word "supper" does.
 */

#include <stdlib.h>
#include <string.h>

int cmp(const void* a, const void* b) {
    return strlen(*(char**)a) - strlen(*(char**)b);
}

char* shortestCompletingWord(char* licensePlate, char** words, int wordsSize) {
    qsort(words, wordsSize, sizeof(char*), cmp);
    int licenseDict[26] = {0};
    while (*licensePlate) {
        char c = *(licensePlate++);
        if (c >= 'A' && c <= 'Z') c += 'a' - 'A';
        if (c >= 'a' && c <= 'z') ++licenseDict[c - 'a'];
    }
    for (int i = 0; i < wordsSize; ++i) {
        int wDict[26] = {0};
        char* w = words[i];
        while (*w) {
            ++wDict[*(w++) - 'a'];
        }
        int flag = 0;
        for (int j = 0; j < 26; ++j) {
            if (licenseDict[j] > wDict[j]) {
                flag = 1;
                break;
            }
        }
        if (flag == 0) return words[i];
    }
    return 0;
}