#include <bits/stdc++.h>

long countWaysToMakeChange(int *denominations, int n, int value)
{
    vector<vector<long>> dp(n, vector<long> (value+1,0));
    vector<long> prev(value+1,0), curr(value+1,0);
    
    /* base case */
    for(int target = 0; target <= value; target++)
    {
        prev[target] = (target % denominations[0] == 0);
    }

    for(int index = 1; index < n; index++)
    {
        for(int target = 0; target <= value; target++)
        {
            long notTake = prev[target];
            long take = 0;
            if(target >= denominations[index])
            {
                take = curr[target - denominations[index]];
            }
            curr[target] = (take + notTake);
        }
        prev = curr;
    }

    return prev[value];
}