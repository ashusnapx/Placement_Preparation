#include <bits/stdc++.h> 
int helper(int index, int buy, vector<int> &prices, int n, vector<vector<int>> &dp)
{
    // base case
    if(index >= n)
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
        profit = max(-prices[index] + helper(index + 1, 0, prices, n, dp), 
        0 + helper(index + 1, 1, prices, n, dp));
    }
    else
    {
        profit = max(prices[index] + helper(index + 2, 1, prices, n, dp), 
        0 + helper(index + 1, 0, prices, n, dp));
    }

    return dp[index][buy] = profit;
}

int stockProfit(vector<int> &prices){
    int n = prices.size();
    vector<vector<int>> dp(n+1, vector<int>(3, -1));
    return helper(0, 1, prices, n, dp);
}