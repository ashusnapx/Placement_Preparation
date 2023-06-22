#include <bits/stdc++.h> 
int helper(int index, int maxWeight, vector<int> &profit, vector<int> &weightOfEachItem, vector<vector<int>> &dp)
{
    /* base case */
    if(index == 0)
	{
		if(weightOfEachItem[index] <= maxWeight)
		{
			return profit[index] * (maxWeight / weightOfEachItem[index]);
		}
		else
		{
			return 0;
		}
	}

    if(dp[index][maxWeight] != -1)
    {
        return dp[index][maxWeight];
    }

    /* pick and not pick */
    int notTake = 0 + helper(index-1, maxWeight, profit, weightOfEachItem, dp);
    int take = INT_MIN;
    if(maxWeight >= weightOfEachItem[index])
    {
        take = profit[index] + helper(index, maxWeight - weightOfEachItem[index], profit, weightOfEachItem, dp);
    }

    return dp[index][maxWeight] = max(take, notTake);
}
int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
{
    vector<vector<int>> dp(n, vector<int> (w+1, -1));
    return helper(n-1, w, profit, weight, dp);
}
