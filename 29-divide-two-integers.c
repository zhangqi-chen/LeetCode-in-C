/**
 * Given two integers dividend and divisor, divide two integers
 * without using multiplication, division and mod operator.
 * 
 * Return the quotient after dividing dividend by divisor.
 * 
 * The integer division should truncate toward zero.
 */

int divide(int dividend, int divisor) {
    if (dividend == 0)
        return 0;
    int neg, i, div, d;
    neg = (dividend > 0 && divisor < 0) || (dividend < 0 && divisor > 0) ? -1 : 1;
    if (dividend > 0)
        div = -dividend;
    else
        div = dividend;
    if (divisor > 0)
        d = -divisor;
    else
        d = divisor;
    if (d == -1) {
        if (div == INT_MIN && neg > 0)
            return INT_MAX;
        else
            return neg * d * div;
    }
    if (div > d) return 0;
    for (i = 1; i * d >= div; i *= 2) {
        if (i * d <= -1073741824)
            return neg * (i + divide(div - d * i, d));
    }
    return neg * (i / 2 + divide(div - d * i / 2, d));
}