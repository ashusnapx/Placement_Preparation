/* Time complexity : O(n x n) [n stands for number of rows] */
/* Space complexity : O(n) + O(n x n)[this O(n x n) is used in dp array] */

/* Time complexity : 2 ^ (sum from 1 to n) [n stands for number of rows] */
/* Space complexity : O(n) */
#include <bits/stdc++.h> 
int helper(int row, int col, vector<vector<int>>& t, int n, vector<vector<int>>& dp)
{
    if(row == n-1)
    {
        return t[row][col];
    }

    if(dp[row][col] != -1)
    {
        return dp[row][col];
    }

    int down = t[row][col] + helper(row+1, col, t, n, dp);
    int diagonal = t[row][col] + helper(row+1, col+1, t, n, dp);

    return dp[row][col] = min(down, diagonal);
}
int minimumPathSum(vector<vector<int>>& t, int n){
	// Write your code here.
    vector<vector<int>> dp(n, vector<int> (n,-1));
	return helper(0, 0, t, n, dp);
}