/**
 * Return the length of the shortest, non-empty, contiguous subarray of A with sum at least K.
 * 
 * If there is no non-empty subarray with sum at least K, return -1.
 */

int shortestSubarray(int* A, int ASize, int K) {
    int* sum = (int*)malloc(sizeof(int) * (ASize + 1));
    sum[0] = 0;
    for (int i = 0; i < ASize; ++i) {
        sum[i + 1] = sum[i] + A[i];
    }
    int* deque = (int*)malloc(sizeof(int) * (ASize + 1));
    int ans = ASize + 1;
    int head = 0;
    int tail = -1;
    for (int i = 0; i <= ASize; ++i) {
        while (tail >= head && sum[i] <= sum[deque[tail]]) {
            --tail;
        }
        deque[++tail] = i;
        while (tail > head && sum[i] - K >= sum[deque[head]]) {
            if (deque[tail] - deque[head] < ans) ans = deque[tail] - deque[head];
            ++head;
        }
    }
    if (ans == ASize + 1) return -1;
    return ans;
}