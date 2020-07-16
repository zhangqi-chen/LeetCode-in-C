/**
 * You are given two integer arrays nums1 and nums2 sorted in ascending order and an integer k.
 * 
 * Define a pair (u,v) which consists of one element from the first array and one element from the second array.
 * 
 * Find the k pairs (u1,v1),(u2,v2) ...(uk,vk) with the smallest sums.
 */

#include <stdlib.h>

int cmp(const void* a, const void* b) {
    return (*(int**)a)[0] + (*(int**)a)[1] - (*(int**)b)[0] - (*(int**)b)[1];
}

int** kSmallestPairs(int* nums1, int nums1Size, int* nums2, int nums2Size, int k, int* returnSize, int** returnColumnSizes) {
    if (k > nums1Size * nums2Size) k = nums1Size * nums2Size;
    *returnSize = k;
    if (k == 0) return 0;
    *returnColumnSizes = (int*)malloc(sizeof(int) * nums1Size * nums2Size);
    int** res = (int**)malloc(sizeof(int*) * nums1Size * nums2Size);
    int n = 0;
    for (int i = 0; i < nums1Size;++i){
        for (int j = 0; j < nums2Size;++j){
            res[n] = (int*)malloc(sizeof(int) * 2);
            res[n][0] = nums1[i];
            res[n][1] = nums2[j];
            (*returnColumnSizes)[n++] = 2;
        }
    }
    qsort(res, nums1Size * nums2Size, sizeof(int*), cmp);
    return res;
}