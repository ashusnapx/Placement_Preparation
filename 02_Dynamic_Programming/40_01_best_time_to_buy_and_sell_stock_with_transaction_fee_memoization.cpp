#include <bits/stdc++.h> 
int helper(int index, int buy, vector<int> &prices, int n, vector<vector<int>> &dp, int fee)
{
    // base case
    if(index == n)
    {
        return 0;
    }

    if(dp[index][buy] != -1)
    {
        return dp[index][buy];
    }

    int profit = 0;

    if(buy)
    {
        profit = max(-prices[index] + helper(index + 1, 0, prices, n, dp, fee), 
        0 + helper(index + 1, 1, prices, n, dp, fee));
    }
    else
    {
        profit = max(prices[index] - fee + helper(index + 1, 1, prices, n, dp, fee), 
        0 + helper(index + 1, 0, prices, n, dp, fee));
    }

    return dp[index][buy] = profit;
} 
int maximumProfit(int n, int fee, vector<int> &prices) {
    vector<vector<int>> dp(n+1, vector<int>(3, -1));
    return helper(0, 1, prices, n, dp, fee);
}
