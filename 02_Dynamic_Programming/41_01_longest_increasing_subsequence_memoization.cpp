#include <bits/stdc++.h>
int helper(int curr_index, int prev_index, int *arr, int n, vector<vector<int>> &dp)
{
    /* base case */
    if(curr_index == n) return 0;

    if(dp[curr_index][prev_index + 1] != -1) return dp[curr_index][prev_index + 1];

    /* not take */
    int len = 0 + helper(curr_index + 1, prev_index, arr, n, dp);

    /* take */
    
    if(prev_index == -1 or arr[curr_index] > arr[prev_index])
    {
        len = max(len, 1 + helper(curr_index + 1, curr_index, arr, n, dp));
    }
    return dp[curr_index][prev_index + 1] = len;
}
int longestIncreasingSubsequence(int arr[], int n)
{
    vector<vector<int>> dp(n, vector<int> (n+1, -1));
    return helper(0, -1, arr, n, dp);
}
