#include <bits/stdc++.h> 
int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
{
    vector<vector<int>> dp(n, vector<int> (w+1, 0));

    /* base case */
    for(int target = 0; target <= w; target++)
    {
        dp[0][target] = ((int)(target / weight[0])) * profit[0] ;
    }

    /* take or not take condition */
    for(int index = 1; index < n; index++)
    {
        for(int target = 0; target <= w; target++)
        {
            int notTake = 0 + dp[index - 1][target];
            int take = 0;
            if(weight[index] <= target)
            {
                take = profit[index] + dp[index][target - weight[index]];
            }
            dp[index][target] = max(take, notTake);
        }
    }

    return dp[n-1][w];
}
