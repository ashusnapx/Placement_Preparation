#include <bits/stdc++.h> 
int mod = (int)(1e9+7);
int helper(int index, int target, vector<int> &arr, vector<vector<int>> &dp)
{
    // base case
    if(index == 0)
    {
        if(target == 0 and arr[0] == 0) return 2;
        if(target == 0 or arr[0] == target) return 1;
        return 0;
    }

    if(dp[index][target] != -1)
    {
        return dp[index][target];
    }

    int notTake = helper(index - 1, target, arr, dp);
    int take = 0;
    if(target >= arr[index])
    {
        take = helper(index - 1, target - arr[index], arr, dp);
    }
    return dp[index][target] = (take + notTake) % mod ;
}
int targetSum(int n, int d, vector<int>& arr) {
    int sum = 0;
    for(int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    if (sum - d < 0 || (sum - d) % 2 != 0) {
        return 0; // No valid partition exists
    }
    int updatedSum = (sum - d) / 2;
    vector<vector<int>> dp(n, vector<int>(updatedSum+1, -1));
    return helper(n-1, updatedSum, arr, dp);
}
