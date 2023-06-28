#include <bits/stdc++.h>

int longestIncreasingSubsequence(int arr[], int n)
{
    /* declare a 2D dp array */
    vector<vector<int>> dp(n + 1, vector<int> (n + 1, 0));

    /* take and not take conditions */
    for(int index = n - 1; index >= 0; index--)
    {
        for(int prev_index = index - 1; prev_index >= -1; prev_index--)
        {
            /* not take */
            int len = 0 + dp[index + 1][prev_index + 1]; // +1 because of paramter shift

            if(prev_index == -1 or arr[index] > arr[prev_index])
            {
                len = max(len, 1 + dp[index + 1][index + 1]);
            } 
            dp[index][prev_index + 1] = len;
        }
    }
    return dp[0][0];
}
