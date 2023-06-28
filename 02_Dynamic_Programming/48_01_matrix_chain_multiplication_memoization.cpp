/* 
Steps to master matrix chain multiplication : 
1. start with entire block/ array. f(i, j), where i is start and j is the end
2. try all partitions
3. return the best possible 2 partitions
 */

#include <bits/stdc++.h> 
int helper(int first_index, int last_index, vector<int> &arr, vector<vector<int>> &dp)
{
    /* base case */
    if(first_index == last_index) return 0;

    int mini = 1e9;

    if(dp[first_index][last_index] != -1)
    {
        return dp[first_index][last_index];
    }

    /* try all partitions */
    for(int k = first_index; k < last_index; k++)
    {
        int steps = arr[first_index - 1] * arr[k] * arr[last_index] + helper(first_index, k, arr, dp) + helper(k + 1, last_index, arr, dp);

        if(steps < mini)
        {
            mini = steps;
        }
    }

    return dp[first_index][last_index] = mini;
}

int matrixMultiplication(vector<int> &arr, int N)
{
    vector<vector<int>> dp(N, vector<int> (N, -1));
   return helper(1, N-1, arr, dp);
}