/**
 * Given a list of words, we may encode it by writing a reference string S and a list of indexes A.
 * 
 * For example, if the list of words is ["time", "me", "bell"], we can write it as S = "time#bell#" and indexes =
 * [0, 2, 5].
 * 
 * Then for each index, we will recover the word by reading from the reference string from that index until we reach
 * a "#" character.
 * 
 * What is the length of the shortest reference string S possible that encodes the given words?
 */

#include <stdlib.h>

int *wlen;

int cmp(const void *a, const void *b) {
    return wlen[*(int *)b] - wlen[*(int *)a];
}

int endswith(char *w1, char *w2, int wlen1, int wlen2) {
    w1 += (wlen1 - wlen2);
    while (*w2) {
        if (*w2 != *w1)
            return 0;
        ++w2;
        ++w1;
    }
    return 1;
}

int minimumLengthEncoding(char **words, int wordsSize) {
    wlen = (int *)malloc(sizeof(int) * wordsSize);
    int *sWords = (int *)malloc(sizeof(int) * wordsSize);
    for (int i = 0; i < wordsSize; ++i) {
        sWords[i] = i;
        wlen[i] = strlen(words[i]);
    }
    qsort(sWords, wordsSize, sizeof(int), cmp);
    for (int i = 1; i < wordsSize; ++i) {
        int wleni = wlen[sWords[i]];
        char *wordi = words[sWords[i]];
        for (int j = 0; j < i; ++j) {
            if (sWords[j] < 0) continue;
            if (endswith(words[sWords[j]], wordi, wlen[sWords[j]], wleni)) {
                sWords[i] = -1;
                break;
            }
        }
    }
    int ret = 0;
    for (int i = 0; i < wordsSize; ++i) {
        if (sWords[i] >= 0) ret += wlen[sWords[i]] + 1;
    }
    return ret;
}