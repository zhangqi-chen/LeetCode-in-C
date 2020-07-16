/**
 * There are two sorted arrays nums1 and nums2 of size m and n respectively.
 * 
 * Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).
 * 
 * You may assume nums1 and nums2 cannot be both empty.
 */

int median(int* n1, int* n2, int size, int l1, int r1) {
    int m1 = (l1 + r1) / 2;
    int m2 = size / 2 - m1;
    if (n1[m1 - 1] > n2[m2]) {
        return median(n1, n2, size, l1, m1);
    } else if (n2[m2 - 1] > n1[m1]) {
        return median(n1, n2, size, m1, r1);
    }
    return m1;
}

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int size = nums1Size + nums2Size;
    if (nums1Size > nums2Size) {
        int* temp = nums1;
        nums1 = nums2;
        nums2 = temp;
        nums1Size = nums2Size;
        nums2Size = size - nums1Size;
    }
    int m1, m2;
    if (nums1Size == 0 || nums1[0] >= nums2[size / 2 - 1]) {
        m1 = 0;
    } else if (nums1[nums1Size - 1] <= nums2[size / 2 - nums1Size]) {
        m1 = nums1Size;
    } else {
        m1 = median(nums1, nums2, size, 0, nums1Size);
    }
    m2 = size / 2 - m1;
    double l1, l2, r1, r2;
    r1 = m1 == nums1Size ? nums2[nums2Size - 1] : nums1[m1];
    r2 = m2 == nums2Size ? nums1[nums1Size - 1] : nums2[m2];
    r1 = r1 > r2 ? r2 : r1;
    if (size % 2 == 1) return r1;
    l1 = m1 == 0 ? nums2[0] : nums1[m1 - 1];
    l2 = m2 == 0 ? nums1[0] : nums2[m2 - 1];
    l1 = l1 < l2 ? l2 : l1;
    return (l1 + r1) / 2;
}