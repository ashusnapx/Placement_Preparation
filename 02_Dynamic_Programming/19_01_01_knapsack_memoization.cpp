#include <bits/stdc++.h> 
int helper(int index, int maxWeight, vector<int> &weightOfObject, vector<int> &valueOfObject, vector<vector<int>> &dp)
{
	// base case
	if(index == 0)
	{
		if(weightOfObject[index] <= maxWeight)
		{
			return valueOfObject[index];
		}
		else
		{
			return 0;
		}
	}

    /* check if it previously existed */
    if(dp[index][maxWeight] != -1)
    {
        return dp[index][maxWeight];
    }

	// recursion + small calculations
	int notTake = 0 + helper(index - 1, maxWeight, weightOfObject, valueOfObject, dp);
	int take = INT_MIN;
	if(maxWeight >= weightOfObject[index])
	{
		take = valueOfObject[index] + helper(index - 1, maxWeight - weightOfObject[index], weightOfObject, valueOfObject, dp);
	}
	
	return dp[index][maxWeight] = max(notTake, take);
}
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	// Write your code here
    vector<vector<int>>dp(n, vector<int>(maxWeight+1, -1));
	return helper(n-1, maxWeight, weight, value, dp);
}