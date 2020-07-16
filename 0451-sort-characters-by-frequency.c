/**
 * Given a string, sort it in decreasing order based on the frequency of characters.
 */

#include <stdlib.h>
#include <string.h>

int freq[256];

int cmp(const void* a, const void* b) {
    int A = freq[*(char*)a];
    int B = freq[*(char*)b];
    if (A == B) return *(char*)b - *(char*)a;
    return B - A;
}

char* frequencySort(char* s) {
    int slen = strlen(s);
    if (slen <= 1) return s;
    for (int i = 0; i < 256; ++i) {
        freq[i] = 0;
    }
    for (int i = 0; i < slen; ++i) {
        ++freq[s[i]];
    }
    qsort(s, slen, sizeof(char), cmp);
    return s;
}