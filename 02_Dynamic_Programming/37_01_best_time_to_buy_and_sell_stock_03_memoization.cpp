#include <bits/stdc++.h> 
int helper(int index, int buy, int limit, vector<int>& prices, int n, vector<vector<vector<int>>> &dp)
{
    /* base case */
    if(index == n or limit == 0) return 0;
    if(dp[index][buy][limit] != -1)
    {
        return dp[index][buy][limit];
    }
    int profit = 0;
    if(buy)
    {
        profit = max(-prices[index] + helper(index + 1, 0, limit, prices, n, dp), 0+ helper(index + 1, 1, limit, prices, n, dp));
    }
    else
    {
        profit = max(prices[index] + helper(index + 1, 1, limit - 1, prices, n, dp), 0 + helper(index + 1, 0, limit, prices, n, dp));
    }

    return dp[index][buy][limit] = profit;
}
int maxProfit(vector<int>& prices, int n)
{
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(3, -1)));
    return helper(0, 1, 2, prices, n, dp);
}