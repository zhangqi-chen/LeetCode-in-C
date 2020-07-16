/**
 * Given an array A, we can perform a pancake flip: We choose some positive integer k <= A.length, then reverse the 
 * rder of the first k elements of A.  We want to perform zero or more pancake flips (doing them one after another in
 * succession) to sort the array A.
 * 
 * Return the k-values corresponding to a sequence of pancake flips that sort A.  Any valid answer that sorts the array
 * within 10 * A.length flips will be judged as correct.
 * 
 * Note:
 * 1 <= A.length <= 100
 * A[i] is a permutation of [1, 2, ..., A.length]
 */

int* pancakeSort(int* A, int ASize, int* returnSize) {
    *returnSize = 0;
    int* res = (int*)malloc(sizeof(int) * 2 * ASize);
    int i, j;
    for (i = ASize; i >= 1; --i) {
        for (j = i - 1; j >= 0; --j) {
            if (A[j] == i) break;
        }
        if (j == i - 1) continue;
        int* tmp = (int*)malloc(sizeof(int) * ASize);
        int idx = 0;
        for (int k = i - 1; k > j; --k) {
            tmp[idx++] = A[k];
        }
        for (int k = 0; k < j; ++k) {
            tmp[idx++] = A[k];
        }
        tmp[idx++] = A[j];
        while (idx < ASize) {
            tmp[idx++] = A[idx];
        }
        A = tmp;
        res[(*returnSize)++] = j + 1;
        res[(*returnSize)++] = i;
    }
    return res;
}
