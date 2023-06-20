#include <bits/stdc++.h> 
bool helper(int index, int target, vector<int> &arr, vector<vector<int>> &dp)
{
    /* base case */
    if(target == 0) return true; 
    /* so basically in this approach we reduce target everytime we move forward */

    if(index == 0)
    {
        if(arr[0] == target)
        {
            return true;
        }
        return false;
    }

    if(dp[index][target] != -1)
    {
        return dp[index][target];
    }

    /* condition of not including array value */
    bool notTake = helper(index - 1, target, arr, dp);

    /* condition for including new value */
    bool take = false;

    if( target >= arr[index])
    {
        take = helper(index - 1, target - arr[index], arr, dp);
    }

    return dp[index][target] = (take) or (notTake);
}
bool subsetSumToK(int array_size, int target, vector<int> &arr) {
    /* if the target is 0, then  */
    vector<vector<int>> dp(array_size + 1, vector<int>(target + 1, -1));
    return helper(array_size - 1, target, arr, dp);
}


/* Time complexity : O(n x target) */
/* Space complexity : O(n x target) + O(n) */