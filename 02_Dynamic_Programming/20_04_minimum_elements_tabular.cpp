#include <bits/stdc++.h> 
int minimumElements(vector<int> &num, int x)
{
    int n = num.size();
    vector<vector<int>> dp(n, vector<int> (x+1, 0));
    for(int target = 0; target <= x; target++)
    {
        if(target % num[0] == 0)
        {
            dp[0][target] = target / num[0];
        }
        else{
            dp[0][target] = 1e9;
        }
    }
    for(int index = 1; index < n; index++)
    {
        for(int target = 1; target <= x; target++)
        {
            int notTake = 0 + dp[index - 1][target];
            int take = INT_MAX;
            if(target >= num[index])
            {
                take = 1 + dp[index][target - num[index]];
            }
            dp[index][target] = min(take, notTake);
        }
    }
    int ans = dp[n-1][x];
    if(ans >= 1e9)
    {
        return -1;
    }
    return ans;
}