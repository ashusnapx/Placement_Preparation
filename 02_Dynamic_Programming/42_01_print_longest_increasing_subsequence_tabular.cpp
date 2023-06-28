int longestIncreasingSubsequence(int *arr, int n)
{
    vector<int> dp(n+1, 1);

    int maximum = 1;

    for(int curr_index = 0; curr_index < n; curr_index++)
    {
        for(int prev_index = 0; prev_index < curr_index; prev_index++)
        {
            if(arr[prev_index] < arr[curr_index])
            {
                dp[curr_index] = max(dp[i], 1 + dp[prev]);
            }
        }
        maximum = max(maximum, dp[curr_index]);
    }

    return maximum;
}