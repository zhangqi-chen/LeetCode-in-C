/**
 * Given a list accounts, each element accounts[i] is a list of strings, where the first
 * element accounts[i][0] is a name, and the rest of the elements are emails representing
 * emails of the account.
 * 
 * Now, we would like to merge these accounts. Two accounts definitely belong to the same
 * person if there is some email that is common to both accounts. Note that even if two
 * accounts have the same name, they may belong to different people as people could have
 * the same name. A person can have any number of accounts initially, but all of their
 * accounts definitely have the same name.
 * 
 * After merging the accounts, return the accounts in the following format: the first
 * element of each account is the name, and the rest of the elements are emails in sorted
 * order. The accounts themselves can be returned in any order.
 */

#include <stdlib.h>
#include <string.h>

void InitUnion(int* parent, int size) {
    for (int i = 0; i < size; ++i) {
        parent[i] = i;
    }
}

int FindUnion(int* parent, int a) {
    if (parent[a] != a) {
        parent[a] = FindUnion(parent, parent[a]);
    }
    return parent[a];
}

void AddPair(int* parent, int a, int b) {
    int pa = FindUnion(parent, a);
    int pb = FindUnion(parent, b);
    if (pa < pb)
        parent[pb] = pa;
    else
        parent[pa] = pb;
}

int** CompressUnionData(int* parent, int size, int** unionSize, int* unionNum) {
    *unionSize = (int*)malloc(sizeof(int) * size);
    memset(*unionSize, 0, sizeof(int) * size);
    int** unionIdx = (int**)malloc(sizeof(int*) * size);
    for (int i = 0; i < size; ++i) {
        unionIdx[i] = (int*)malloc(sizeof(int) * size);
        FindUnion(parent, i);
    }
    *unionNum = 0;
    for (int i = 0; i < size; ++i) {
        int p = parent[i];
        if ((*unionSize)[p] == 0) ++(*unionNum);
        unionIdx[p][(*unionSize)[p]++] = i;
    }
    return unionIdx;
}

int cmp(const void* a, const void* b) {
    return strcmp(*(char**)a, *(char**)b);
}

char*** accountsMerge(char*** accounts, int accountsSize, int* accountsColSize, int* returnSize, int** returnColumnSizes) {
    int eSize = 0;
    for (int i = 0; i < accountsSize; ++i) {
        eSize += accountsColSize[i] - 1;
    }
    char** emails = (char**)malloc(sizeof(char*) * eSize);
    char** names = (char**)malloc(sizeof(char*) * eSize);
    int* pemails = (int*)malloc(sizeof(int) * eSize);
    int* nemails = (int*)malloc(sizeof(int) * eSize);
    InitUnion(pemails, eSize);
    eSize = 0;
    int nSize = 0;
    for (int i = 0; i < accountsSize; ++i) {
        int currLead = -1;
        names[nSize++] = accounts[i][0];
        for (int j = 1; j < accountsColSize[i]; ++j) {
            int found = 0;
            int k = 0;
            for (; k < eSize; ++k) {
                if (strcmp(emails[k], accounts[i][j]) != 0) continue;
                found = 1;
                break;
            }
            if (found == 0) {
                k = eSize;
                nemails[eSize] = nSize - 1;
                emails[eSize++] = accounts[i][j];
            }
            if (j == 1) currLead = k;
            AddPair(pemails, k, currLead);
        }
    }

    int* unionSize;
    int** unionIdx = CompressUnionData(pemails, eSize, &unionSize, returnSize);
    (*returnColumnSizes) = (int*)malloc(sizeof(int) * (*returnSize));
    char*** ret = (char***)malloc(sizeof(char**) * (*returnSize));
    int ri = 0;
    for (int i = 0; i < eSize; ++i) {
        if (unionSize[i] == 0) continue;
        (*returnColumnSizes)[ri] = 1 + unionSize[i];
        ret[ri] = (char**)malloc(sizeof(char*) * (1 + unionSize[i]));
        for (int j = 0; j < unionSize[i]; ++j) {
            ret[ri][j + 1] = emails[unionIdx[i][j]];
        }
        qsort(ret[ri] + 1, unionSize[i], sizeof(char*), cmp);
        ret[ri++][0] = names[nemails[i]];
    }
    return ret;
}