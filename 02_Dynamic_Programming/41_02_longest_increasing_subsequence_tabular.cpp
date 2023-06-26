#include <bits/stdc++.h>

int longestIncreasingSubsequence(int arr[], int n)
{
    vector<vector<int>> dp(n, vector<int> (n+1, 0));

    /* base case */
    int curr_index = 0, prev_index = -1;
    if(curr_index == n) dp[curr_index][prev_index] = 0;
    int len = 0;
    for(int index = 0; index < n; index++)
    {
        for(int prev = 0; prev < index; prev++)
        {
             if(prev_index == 0 or arr[index] > arr[prev])
             {
                len = max(len, 1 + dp[index+1][index]);
             }
             else
             {
                len = 0 + dp[index+1][prev];
             }
             dp[index][prev + 1] = len;
        }
    }


    return dp[0][-1];
}
