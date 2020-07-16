/**
 * A subarray A[i], A[i+1], ..., A[j] of A is said to be turbulent if and only if:
 * 
 * For i <= k < j, A[k] > A[k+1] when k is odd, and A[k] < A[k+1] when k is even;
 * OR, for i <= k < j, A[k] > A[k+1] when k is even, and A[k] < A[k+1] when k is odd.
 * That is, the subarray is turbulent if the comparison sign flips between each adjacent pair of elements in the subarray.
 * 
 * Return the length of a maximum size turbulent subarray of A.
 */

int maxTurbulenceSize(int* A, int ASize) {
    if (ASize < 2) return ASize;
    int maxSize = 1;
    int curr = 1;
    int ascend = 0;
    for (int i = 1; i < ASize; ++i) {
        if (A[i] > A[i - 1]) {
            if (ascend < 0)
                ++curr;
            else
                curr = 2;
            ascend = 1;
        } else if (A[i] < A[i - 1]) {
            if (ascend > 0)
                ++curr;
            else
                curr = 2;
            ascend = -1;
        } else {
            curr = 1;
            ascend = 0;
        }
        if (curr > maxSize) maxSize = curr;
    }
    return maxSize;
}