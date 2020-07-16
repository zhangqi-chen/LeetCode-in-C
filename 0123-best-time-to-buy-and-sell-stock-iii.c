/**
 * Say you have an array for which the ith element is the price of a given stock on day i.
 * 
 * Design an algorithm to find the maximum profit. You may complete at most two transactions.
 * 
 * Note: You may not engage in multiple transactions at the same time (i.e., you must sell the stock before you buy
 * again).
 */

#define max(a, b) ((a) > (b) ? (a) : (b))

#DP trick
int maxProfit(int* prices, int pricesSize) {
    if (pricesSize < 2) return 0;
    int dp1 = -prices[0];
    int dp2 = dp1 + prices[1];
    if (pricesSize < 4) {
        for (int i = 1; i < pricesSize - 1; ++i) {
            dp1 = max(dp1, -prices[i]);
            dp2 = max(dp2, dp1 + prices[i + 1]);
        }
        return max(dp2, 0);
    }
    int dp3 = dp2 - prices[2];
    int dp4 = dp3 + prices[3];
    for (int i = 1; i < pricesSize; ++i) {
        dp1 = max(dp1, -prices[i]);
        if (i < pricesSize - 1) dp2 = max(dp2, dp1 + prices[i + 1]);
        if (i < pricesSize - 3) dp3 = max(dp3, dp2 - prices[i + 2]);
        if (i < pricesSize - 3) dp4 = max(dp4, dp3 + prices[i + 3]);
    }
    if (dp2 < 0 && dp4 < 0) return 0;
    return max(dp2, dp4);
}

#DP
int maxProfit(int* prices, int pricesSize) {
    if (pricesSize < 2) return 0;
    int dp[pricesSize][4];
    dp[0][0] = -prices[0];
    for (int i = 1; i < 4; ++i) {
        dp[0][i] = INT_MIN / 2;
    }
    for (int i = 1; i < pricesSize; ++i) {
        dp[i][0] = max(dp[i - 1][0], -prices[i]);
        dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i]);
        dp[i][2] = max(dp[i - 1][2], dp[i - 1][1] - prices[i]);
        dp[i][3] = max(dp[i - 1][3], dp[i - 1][2] + prices[i]);
    }
    if (dp[pricesSize - 1][3] < 0 && dp[pricesSize - 1][1] < 0) return 0;
    return max(dp[pricesSize - 1][3], dp[pricesSize - 1][1]);
}