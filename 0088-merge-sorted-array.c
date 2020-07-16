/**
 * Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.
 * 
 * Note:
 * The number of elements initialized in nums1 and nums2 are m and n respectively.
 * You may assume that nums1 has enough space (size that is greater or equal to m + n) to hold additional elements from nums2.
 */

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
    int i = --m + n--;
    while (m >= 0 && n >= 0) {
        nums1[i--] = nums1[m] > nums2[n] ? nums1[m--] : nums2[n--];
    }
    while (n >= 0) {
        nums1[i--] = nums2[n--];
    }
}