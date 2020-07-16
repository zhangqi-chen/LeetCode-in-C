/**
 * Say you have an array for which the ith element is the price of a given stock on day i.
 * 
 * If you were only permitted to complete at most one transaction (i.e., buy one and sell one share of the stock),
 * design an algorithm to find the maximum profit.
 * 
 * Note that you cannot sell a stock before you buy one.
 */

int maxProfit(int* prices, int pricesSize) {
    if (pricesSize < 2) return 0;
    int profit = 0;
    int cheapest = prices[0];
    for (int i = 1; i < pricesSize; ++i) {
        if (profit < prices[i] - cheapest) profit = prices[i] - cheapest;
        if (prices[i] < cheapest) cheapest = prices[i];
    }
    return profit;
}