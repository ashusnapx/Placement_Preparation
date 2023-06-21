#include <bits/stdc++.h> 
int helper(int index, int maxWeight, vector<int> &weightOfObject, vector<int> &valueOfObject)
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

	// recursion + small calculations
	int notTake = 0 + helper(index - 1, maxWeight, weightOfObject, valueOfObject);
	int take = INT_MIN;
	if(maxWeight >= weightOfObject[index])
	{
		take = valueOfObject[index] + helper(index - 1, maxWeight - weightOfObject[index], weightOfObject, valueOfObject);
	}
	
	return max(notTake, take);
}
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	// Write your code here
	return helper(n-1, maxWeight, weight, value);
}