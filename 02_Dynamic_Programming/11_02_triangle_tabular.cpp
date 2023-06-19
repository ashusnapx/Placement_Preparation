/* Time complexity : O(n x n) [n stands for number of rows] */
/* Space complexity : O(n x n)[this O(n x n) is used in dp array] */
/* Time complexity : O(n x n) [n stands for number of rows] */
/* Space complexity : O(n x n)[this O(n x n) is used in dp array] */
#include <bits/stdc++.h> 
int helper(int row, int col, vector<vector<int>>& t, int n, vector<vector<int>>& dp)
{

}
int minimumPathSum(vector<vector<int>>& t, int n)
{
	vector<vector<int>>dp(n, vector<int>(n, -1));

    /* copy last row in dp array as it stands for base case */
    for(int j = 0; j < n; j++)
    {
        dp[n-1][j] = t[n-1][j];
    }

    for(int i = n-2; i >= 0; i--)
    {
        for(int j = i; j >= 0; j--)
        {
            int down = t[i][j] + dp[i+1][j];
            int diagonal = t[i][j] + dp[i+1][j+1];
            dp[i][j] = min(down, diagonal);
        }
    }

    return dp[0][0];
}