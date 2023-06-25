#include <bits/stdc++.h>
long helper(int index, int buy, long *values, int n, vector<vector < long>> &dp)
{
    if (index == n)
    {
        return 0;
    }
    if (dp[index][buy] != -1)
    {
        return dp[index][buy];
    }
    long profit = 0;
    if (buy)
    {
        profit = max(-values[index] + helper(index + 1, 0, values, n, dp),
            0 + helper(index + 1, 1, values, n, dp));
    }
    else
    {
       profit = max(values[index] + helper(index + 1, 1, values, n, dp),
            0 + helper(index + 1, 0, values, n, dp));
    }
    return dp[index][buy] = profit;
}

long getMaximumProfit(long *values, int n)
{
    vector<vector < long>> dp(n, vector<long> (2, -1));
    return helper(0, 1, values, n, dp);
}