/**
 * Implement pow(x, n), which calculates x raised to the power n (xn).
 */

double myPow(double x, int n) {
    if (n == 0) return 1;
    if (n == 1) return x;
    if (n == -1) return 1 / x;
    double temp = myPow(x, n / 2);
    return temp * temp * myPow(x, n % 2);
}