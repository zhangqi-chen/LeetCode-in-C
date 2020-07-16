/**
 * Given an array of words and a width maxWidth, format the text such that each line has exactly 
 * maxWidth characters and is fully (left and right) justified.
 * 
 * You should pack your words in a greedy approach; that is, pack as many words as you can in each
 * line. Pad extra spaces ' ' when necessary so that each line has exactly maxWidth characters.
 * 
 * Extra spaces between words should be distributed as evenly as possible. If the number of spaces
 * on a line do not divide evenly between words, the empty slots on the left will be assigned more
 * spaces than the slots on the right.
 * 
 * For the last line of text, it should be left justified and no extra space is inserted between words.
 * 
 * Note:
 * A word is defined as a character sequence consisting of non-space characters only.
 * Each word's length is guaranteed to be greater than 0 and not exceed maxWidth.
 * The input array words contains at least one word.
 */

#include <stdlib.h>
#include <string.h>

char** fullJustify(char** words, int wordsSize, int maxWidth, int* returnSize) {
    *returnSize = 0;
    char** res = (char**)malloc(sizeof(char*) * wordsSize);
    int i, n, spaces, spacenum, extraspace;
    int curr = 0;   // current width
    int start = 0;  // starting words index of current line
    for (i = 0; i < wordsSize; ++i) {
        if (curr + strlen(words[i]) <= maxWidth) {
            curr += strlen(words[i]) + 1;
        } else {
            n = i - start;                 // number of words at current line
            spaces = maxWidth - curr + n;  // space count
            if (n > 1) {
                spacenum = spaces / (n - 1);    // least spaces between words
                extraspace = spaces % (n - 1);  // extra space count
            } else {
                spacenum = spaces;
                extraspace = 0;
            }
            res[*returnSize] = (char*)malloc(sizeof(char) * (maxWidth + 1));
            res[*returnSize][0] = '\0';
            for (int j = 0; j < n; ++j) {
                strcat(res[*returnSize], words[j + start]);
                if (n == 1 || j < n - 1) {
                    for (int k = 0; k < spacenum; ++k) {
                        strcat(res[*returnSize], " ");
                    }
                    if (j < extraspace) strcat(res[*returnSize], " ");
                }
            }
            ++(*returnSize);
            start = i;
            curr = strlen(words[i]) + 1;
        }
    }
    // last line
    n = i - start;
    res[*returnSize] = (char*)malloc(sizeof(char) * (maxWidth + 1));
    res[*returnSize][0] = '\0';
    strcat(res[*returnSize], words[start]);
    for (i = start + 1; i < wordsSize; ++i) {
        strcat(res[*returnSize], " ");
        strcat(res[*returnSize], words[i]);
    }
    for (i = strlen(res[*returnSize]); i < maxWidth; ++i) {
        res[*returnSize][i] = ' ';
    }
    res[(*returnSize)++][maxWidth] = '\0';
    return res;
}