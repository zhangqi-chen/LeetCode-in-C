/**
 * The gray code is a binary numeral system where two successive values differ in only one bit.
 * 
 * Given a non-negative integer n representing the total number of bits in the code, print the sequence of gray code.
 * A gray code sequence must begin with 0.
 */

int* grayCode(int n, int* returnSize) {
    *returnSize = 1 << n;
    int* res = (int*)malloc(sizeof(int) * (*returnSize));
    res[0] = 0;
    int cnt = 1;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < cnt; ++j) {
            res[cnt + j] = res[cnt - 1 - j] + cnt;
        }
        cnt <<= 1;
    }
    return res;
}