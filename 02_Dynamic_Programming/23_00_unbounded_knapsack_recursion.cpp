#include <bits/stdc++.h> 
int helper(int index, int maxWeight, vector<int> &profit, vector<int> &weightOfEachItem)
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

    /* pick and not pick */
    int notTake = helper(index-1, maxWeight, profit, weightOfEachItem);
    int take = INT_MIN;
    if(maxWeight >= weightOfEachItem[index])
    {
        take = profit[index] + helper(index, maxWeight - weightOfEachItem[index], profit, weightOfEachItem);
    }

    return max(take, notTake);
}
int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
{
   return helper(n-1, w, profit, weight);
}
