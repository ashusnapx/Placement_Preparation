#include <bits/stdc++.h>

long getMaximumProfit(long *value, int n)
{
    vector<vector < long>> dp(n + 1, vector<long> (2, 0));
    
    /* base case */
    dp[n][0] = dp[n][1] = 0;

    /* now the main code starts, where we'll calculate buy and sell */
    

    /* if the user will buy */
    for(long i = n-1; i >= 0; i--)
    {
        for(long buy = 0; buy <= 1; buy++)
        {
            long profit = 0;
            /* if the user will buy and if they not */
            if(buy)
            {
               profit = max(-value[i] + dp[i+1][0], 0 + dp[i+1][1]);
            }
            else
            {
                profit = max(value[i] + dp[i+1][1], 0 + dp[i+1][0]);
            }
            dp[i][buy] = profit;
        }
    }
    return dp[0][1];
}