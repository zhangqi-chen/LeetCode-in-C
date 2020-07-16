/**
 * Given a non-empty array of digits representing a non-negative integer, plus one to the integer.
 * 
 * The digits are stored such that the most significant digit is at the head of the list, and each
 * element in the array contain a single digit.
 * 
 * You may assume the integer does not contain any leading zero, except the number 0 itself.
 */

#include <stdlib.h>

int* plusOne(int* digits, int digitsSize, int* returnSize) {
    *returnSize = digitsSize + 1;
    int* res = (int*)malloc(sizeof(int) * (*returnSize));
    int carry = 0;
    digits[digitsSize - 1] += 1;
    for (int i = digitsSize - 1; i >= 0; i--) {
        res[i + 1] = digits[i] + carry;
        carry = res[i + 1] / 10;
        res[i + 1] %= 10;
    }
    if (carry == 1)
        res[0] = 1;
    else {
        --(*returnSize);
        res++;
    }
    return res;
}