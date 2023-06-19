#include <bits/stdc++.h> 
int helper(int m, int n, vector<vector<int>> &dp)
{
    /* base case */
    if(m == 1 or n == 1)
    {
        return 1;
    }

    /* checking if value previously visited or not? */
    if(dp[m][n] != -1)
    {
        return dp[m][n];
    }

    /* make recursive calls */
    int down = helper(m - 1, n, dp);
    int left = helper(m, n - 1, dp);

    return dp[m][n] = down + left;
}
int uniquePaths(int m, int n) 
{
    /* creating a dp array to store values */
    vector<vector<int>> dp(m+1, vector<int>(n+1,-1));

    return helper(m,n,dp);
}

/* time complexity : O(n x m) */
/* space complexity : O((n-1) x (m-1)) + O(n x m) */
/* O((n-1) x (m-1)) is the recursion stack space and somewhere we can optimise it. so lets move to tabular form */