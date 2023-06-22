#include <bits/stdc++.h>

long countWaysToMakeChange(int *denominations, int n, int value)
{
    vector<vector<long>> dp(n, vector<long> (value+1,0));
    
    /* base case */
    for(int target = 0; target <= value; target++)
    {
        dp[0][target] = (target % denominations[0] == 0);
    }

    for(int index = 1; index < n; index++)
    {
        for(int target = 0; target <= value; target++)
        {
            long notTake = dp[index-1][target];
            long take = 0;
            if(target >= denominations[index])
            {
                take = dp[index][target - denominations[index]];
            }
            dp[index][target] = (take + notTake);
        }
    }

    return dp[n-1][value];
}