/**
 * Given a 32-bit signed integer, reverse digits of an integer.
 */

int reverse(int x) {
    long res = 0;
    while (x != 0) {
        res = res * 10 + x % 10;
        x /= 10;
    }
    if ((int)res != res)
        return 0;
    return res;
}