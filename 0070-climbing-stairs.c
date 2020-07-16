/**
 * You are climbing a stair case. It takes n steps to reach to the top.
 * 
 * Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
 * 
 * Note: Given n will be a positive integer.
 */

int climbStairs(int n) {
    if (n < 4) return n;
    int data[n + 1];
    data[0] = data[1] = 1;
    for (int i = 2; i <= n; ++i) {
        data[i] = data[i - 1] + data[i - 2];
    }
    return data[n];
}