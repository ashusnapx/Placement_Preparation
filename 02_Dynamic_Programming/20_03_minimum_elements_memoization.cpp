#include <bits/stdc++.h> 
int helper(int index, int target, vector<int> &num, vector<vector<int>> &dp)
{
    if(index == 0)
    {
        if(target % num[index] == 0)
        {
            return target / num[index];
        }
        return 1e9;
    }

    if(dp[index][target] != -1)
    {
        return dp[index][target];
    }

    int notTake = 0 + helper(index - 1, target, num, dp);
    int take = INT_MAX;
    if(target >= num[index])
    {
        take = 1 + helper(index, target - num[index], num, dp);
    }

    return dp[index][target] = min(take, notTake);
}
int minimumElements(vector<int> &num, int x)
{
    int n = num.size();
    vector<vector<int>> dp(n, vector<int> (x+1, -1));
    int ans = helper(n - 1, x, num, dp);
    if(ans >= 1e9)
    {
        return -1;
    }
    return ans;
}