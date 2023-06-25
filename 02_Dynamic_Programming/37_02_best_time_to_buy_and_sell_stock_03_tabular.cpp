#include <bits/stdc++.h> 

int maxProfit(vector<int>& prices, int n)
{
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(3, 0)));
    
    /* base cases */
    /* 1. if limit == 0, index and buy can be anything */
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j <= 1; j++)
        {
            dp[i][j][0] = 0; // dp[index][buy][limit] = 0;
        }
    }
    /* 2. if index == n, buy and cap can be anything */
    for(int i = 0; i <= 1; i++)
    {
        for(int j = 0; j <= 2; j++)
        {
            dp[n][i][j] = 0; // dp[index][buy][limit] = 0;
        }
    }
    /* base cases ended */

    /* copy recurrence and modify it for dp vector */
    for(int index = n - 1; index >= 0; index--)
    {
        for(int buy = 0; buy <= 1; buy++)
        {
            for(int limit = 1; limit <= 2; limit++)
            {
                /* if the user will buy */
                if(buy == 1)
                {
                    dp[index][buy][limit] = max(-prices[index] + dp[index + 1][0][limit], 0 + dp[index + 1][1][limit]);
                }
                else
                {
                    dp[index][buy][limit] = max(prices[index] + dp[index + 1][1][limit - 1], 0 + dp[index + 1][0][limit]);
                }
            }
        }
    }
    return dp[0][1][2];
}