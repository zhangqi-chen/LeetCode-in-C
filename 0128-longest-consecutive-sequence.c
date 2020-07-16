/**
 * Given an unsorted array of integers, find the length of the longest consecutive elements sequence.
 * 
 * Your algorithm should run in O(n) complexity.
 */

int cmp(const void *a, const void *b) {
    if (*(int *)a < *(int *)b)
        return -1;
    else if (*(int *)a > *(int *)b)
        return 1;
    return 0;
}

int longestConsecutive(int *nums, int numsSize) {
    if (numsSize < 2)
        return numsSize;
    qsort(nums, numsSize, sizeof(int), cmp);
    int maxlen = 1;
    int len = 1;
    for (int i = 1; i < numsSize; ++i) {
        if (nums[i] > nums[i - 1] + 1) {
            if (len > maxlen) maxlen = len;
            len = 1;
        } else if (nums[i] == nums[i - 1])
            continue;
        else {
            ++len;
        }
    }
    if (len > maxlen) maxlen = len;
    return maxlen;
}

// HashSet
#define N 134217728

typedef unsigned int uint;

void hashAdd(uint *hash, uint n) {
    hash[n >> 5] |= (1u << (n & 31));
}

int hashCheck(uint *hash, uint n) {
    return hash[n >> 5] & (1u << (n & 31));
}

int longestConsecutive(int *nums, int numsSize) {
    if (numsSize < 2)
        return numsSize;
    uint *hashset = (uint *)malloc(sizeof(uint) * N);
    for (int i = 0; i < N; ++i) {
        hashset[i] = 0u;
    }
    for (int i = 0; i < numsSize; ++i) {
        uint n = (uint)nums[i];
        hashAdd(hashset, n);
    }
    int maxlen = 1;
    int len;
    for (int i = 0; i < numsSize; ++i) {
        uint n = (uint)nums[i];
        if (hashCheck(hashset, n - 1))
            continue;
        for (len = 1; hashCheck(hashset, n + len); ++len) {
        }
        if (len > maxlen)
            maxlen = len;
    }
    return maxlen;
}