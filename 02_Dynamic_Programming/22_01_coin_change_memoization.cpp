#include <iostream>
#include <vector>
#include <algorithm>

long helper(int index, int target, int* denominations, vector<vector<long>>& dp)
{
    // Base case
    if (index == 0)
    {
        return (target % denominations[0] == 0);
    }

    if (dp[index][target] != -1)
    {
        return dp[index][target];
    }

    // Pick and not pick
    long notTake = helper(index - 1, target, denominations, dp);
    long take = 0;
    if (target >= denominations[index])
    {
        take = helper(index, target - denominations[index], denominations, dp);
    }

    return dp[index][target] = (take + notTake);
}

long countWaysToMakeChange(int *denominations, int n, int value)
{
    vector<vector<long>> dp(n, vector<long>(value + 1, -1));
    return helper(n - 1, value, denominations, dp);
}