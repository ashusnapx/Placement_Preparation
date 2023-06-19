int mod = int(1e9 + 7);

int helper(int row, int col, vector< vector< int> > &mat, vector< vector< int> > &dp)
{
    /* edge case + base case */
    if(row >= 0 and col >= 0 and mat[row][col] == -1)
    {
        return 0;
    }
    if(row < 0 or col < 0)
    {
        return 0;
    }
    if(row == 0 and col == 0)
    {
        return 1;
    }

    /* check if value exists from before or not */
    if(dp[row][col] != -1)
    {
        return dp[row][col];
    }

    /* small calculation + recursive call */
    int down = helper(row-1, col, mat, dp);
    int left = helper(row, col-1, mat, dp);

    /* return the values */
    return dp[row][col] = (down + left) % mod;
}

int mazeObstacles(int row, int col, vector< vector< int> > &mat) {
   vector< vector< int> > dp(row, vector<int>(col,-1));
   return helper(row-1, col-1, mat, dp);
}