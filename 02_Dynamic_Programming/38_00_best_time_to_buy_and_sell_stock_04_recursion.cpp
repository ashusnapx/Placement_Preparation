#include <bits/stdc++.h> 

int helper(int index, int buy, int limit, vector<int> &prices, int n)
{
    /* base case */
    if(index == n or limit == 0) return 0;

    /* now i'll buy and sell */
    int profit = 0;

    /* buy */
    if(buy == 1)
    {
        profit = max(-prices[index] + helper(index + 1, 0, limit, prices, n), 0 + helper(index + 1, 1, limit, prices, n));
    }
    else
    {
        profit = max(prices[index] + helper(index + 1, 1, limit - 1, prices, n), 0 + helper(index + 1, 0, limit, prices, n));
    }
    return profit;
}
int maximumProfit(vector<int> &prices, int n, int k)
{
    return helper(0, 1, k, prices, n);
}
