#include <bits/stdc++.h> 
bool subsetSumToK(int array_size, int target, vector<int> &arr) {
    /* if the target is 0, then  */
    vector<vector<bool>> dp(array_size + 1, vector<bool>(target + 1, 0));
    
    /* base case */
    for(int i = 0; i < array_size; i++)
    {
        dp[i][0] = true; // dp[index][target]
    }

    /* base case */
    dp[0][arr[0]] = true; // this means that we're on index 0 and if we get the target equivalent to first element of array, then its true.

    for(int index = 1; index < array_size; index++)
    {
        for(int jo_chahiye = 1; jo_chahiye <= target; jo_chahiye++)
        {
            bool notTake = dp[index - 1][jo_chahiye];
            bool take = false;
            if(jo_chahiye >= arr[index])
            {
                take = dp[index - 1][jo_chahiye - arr[index]];
            }
            dp[index][jo_chahiye] = take | notTake;
        }
    }
    return dp[array_size - 1][target];
}


/* Time complexity : O(n x target) */
/* Space complexity : O(n x target) */