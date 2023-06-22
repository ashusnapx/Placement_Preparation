#include <iostream>
#include <vector>

using namespace std;

int helper(int index, int target, vector<int> &num, vector<vector<int>> &dp)
{
    /* base case */
    if (index == 0)
    {
        return num[0] == target;
    }

    if(target == 0)
    {
        return 1;
    }

    if (dp[index][target] != -1)
    {
        return dp[index][target];
    }

    /* subsets pick and not pick */
    int notTake = helper(index - 1, target, num, dp);
    int take = 0;
    if (target >= num[index])
    {
        take = helper(index - 1, target - num[index], num, dp);
    }

    return dp[index][target] = take + notTake;
}

int findWays(vector<int> &num, int tar)
{
    int n = num.size();
    vector<vector<int>> dp(n, vector<int>(tar + 1, -1));
    return helper(n - 1, tar, num, dp);
}