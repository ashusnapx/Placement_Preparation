#include <bits/stdc++.h> 
int helper(int index, int target, vector<int> &num)
{
    /* base case */
    if(index == 0)
    {
        if(target == 0 and num[0] == 0) return 2;
        if(target == 0 or num[0] == 0) return 1;
        return 0;
    }

    /* subsets pick and not pick */
    int notTake = helper(index - 1, target, num);
    int take = 0;
    if(target >= num[index])
    {
        take = 1 + helper(index - 1, target - num[index], num);
    }

    return take + notTake;
}
int findWays(vector<int> &num, int tar)
{
    return helper(num.size()-1, tar, num);
}