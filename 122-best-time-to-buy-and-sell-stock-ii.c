/**
 * Say you have an array for which the ith element is the price of a given stock on day i.
 * 
 * Design an algorithm to find the maximum profit. You may complete as many transactions as you like (i.e., buy one
 * and sell one share of the stock multiple times).
 * 
 * Note: You may not engage in multiple transactions at the same time (i.e., you must sell the stock before you buy
 * again).
 */

int maxProfit(int* prices, int pricesSize) {
    if (pricesSize < 2) return 0;
    int profit = 0;
    for (int i = 0; i < pricesSize - 1; ++i) {
        if (prices[i + 1] > prices[i]) profit += prices[i + 1] - prices[i];
    }
    return profit;
}