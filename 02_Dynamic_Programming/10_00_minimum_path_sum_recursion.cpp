#include <bits/stdc++.h> 

int helper(int row, int col, vector<vector<int>>& grid, vector<vector<int>>& dp)
{
    /* base case */
    if(row == 0 && col == 0)
    {
        dp[row][col] = grid[row][col];
        return dp[row][col];
    }

    int up = INT_MAX, left = INT_MAX;
    
    if(row > 0)
    {
        up = helper(row-1, col, grid);
    }

    if(col > 0)
    {
        left = helper(row, col-1, grid);
    }

    return min(up, left) + grid[row][col];
}

int minSumPath(vector<vector<int>>& grid) 
{
    int m = grid.size();
    int n = grid[0].size();
    return helper(m-1, n-1, grid);
}
