#include <bits/stdc++.h> 
int helper(int m, int n, vector<vector<int>> &dp)
{
    for(int row = 0; row < m; row++)
    {
        for(int col = 0; col < n; col++)
        {
            if(row == 0 and col == 0)
            {
                /* base case */
                dp[0][0] = 1;
            }
            int down = dp[row-1][col];
            int left = dp[row][col-1];
            dp[row][col] = down + left;
        }
    }

    return dp[row][col];
}
int uniquePaths(int m, int n) 
{
    /* creating a dp array to store values */
    vector<vector<int>> dp(m+1, vector<int>(n+1,-1));

    return helper(m,n,dp);
}

/* Time complexity : O(n x m) */
/* space complexity : O(n x m) */