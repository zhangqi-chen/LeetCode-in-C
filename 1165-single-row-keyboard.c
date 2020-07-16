/**
 * There is a special keyboard with all keys in a single row.
 * 
 * Given a string keyboard of length 26 indicating the layout of the keyboard (indexed from 0 to 25), initially your
 * finger is at index 0. To type a character, you have to move your finger to the index of the desired character. The
 * time taken to move your finger from index i to index j is |i - j|.
 * 
 * You want to type a string word. Write a function to calculate how much time it takes to type it with one finger.
 */

#include <stdlib.h>

int calculateTime(char* keyboard, char* word) {
    int loc[26];
    for (int i = 0; i < 26; ++i) {
        loc[keyboard[i] - 'a'] = i;
    }
    int curr = 0;
    int ret = 0;
    while (*word) {
        int new = loc[*word++ - 'a'];
        ret += abs(new - curr);
        curr = new;
    }
    return ret;
}