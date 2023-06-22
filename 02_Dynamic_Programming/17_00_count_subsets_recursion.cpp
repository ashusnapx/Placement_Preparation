#include <bits/stdc++.h> 
int helper(int index, int target, vector<int> &num)
{
    /* base case */
    if(index == 0)
    {
        return num[0] == target;
    }
    if(target == 0)
    {
        return 1;
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