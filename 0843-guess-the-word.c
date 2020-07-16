/**
 * This problem is an interactive problem new to the LeetCode platform.
 * 
 * We are given a word list of unique words, each word is 6 letters long, and one word in this list is chosen as
 * secret.
 * 
 * You may call master.guess(word) to guess a word.  The guessed word should have type string and must be from the
 * original list with 6 lowercase letters.
 * 
 * This function returns an integer type, representing the number of exact matches (value and position) of your guess
 * to the secret word.  Also, if your guess is not in the given wordlist, it will return -1 instead.
 * 
 * For each test case, you have 10 guesses to guess the word. At the end of any number of calls, if you have made 10 or
 * less calls to master.guess and at least one of these guesses was the secret, you pass the testcase.
 * 
 * Besides the example test case below, there will be 5 additional test cases, each with 100 words in the word list.
 * The letters of each word in those testcases were chosen independently at random from 'a' to 'z', such that every
 * word in the given word lists is unique.
 */

#include <stdlib.h>
#include <time.h>
#define GNUM 10

int guess(Master*, char* word);

int match(char* a, char* b) {
    int n = 0;
    for (int i = 0; i < 6; ++i) {
        n += (a[i] == b[i]);
    }
    return n;
}

void findSecretWord(char** wordlist, int wordlistSize, Master* master) {
    srand(time(NULL));
    int history[GNUM], result[GNUM];
    int gidx = rand() % wordlistSize;  // random initialization, 0/END didn't pass
    for (int i = 0; i < GNUM; ++i) {
        history[i] = gidx;
        char* word = wordlist[gidx];
        result[i] = guess(master, word);
        if (result[i] == 6) return;
        gidx = (gidx + 1) % wordlistSize;
        int j = 0;
        while (j <= i) {
            char* gword = wordlist[gidx];
            int curr = match(wordlist[history[j]], gword);
            if (curr == result[j]) {
                ++j;
            } else {
                j = 0;
                gidx = (gidx + 1) % wordlistSize;
            }
        }
    }
}