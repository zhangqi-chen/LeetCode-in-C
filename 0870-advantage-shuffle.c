/**
 * Given two arrays A and B of equal size, the advantage of A with respect to B is the number of indices i for which
 * A[i] > B[i].
 * 
 * Return any permutation of A that maximizes its advantage with respect to B.
 */
int Bcpy[10000];

int cmp(const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}

int cmpidx(const void* a, const void* b) {
    return Bcpy[*(int*)a] - Bcpy[*(int*)b];
}

int* advantageCount(int* A, int ASize, int* B, int BSize, int* returnSize) {
    *returnSize = ASize;
    int* Bidx = (int*)malloc(sizeof(int) * BSize);
    for (int i = 0; i < BSize; ++i) {
        Bcpy[i] = B[i];
        Bidx[i] = i;
    }
    qsort(A, ASize, sizeof(int), cmp);
    qsort(Bidx, BSize, sizeof(int), cmpidx);
    int* sA = (int*)malloc(sizeof(int) * ASize);
    int i = 0;
    int j = 0;
    int k = ASize - 1;
    while (i < ASize) {
        if (A[i] > B[Bidx[j]])
            sA[j++] = A[i++];
        else
            sA[k--] = A[i++];
    }
    int* res = (int*)malloc(sizeof(int) * ASize);
    for (i = 0; i < ASize; ++i) {
        res[Bidx[i]] = sA[i];
    }
    return res;
}