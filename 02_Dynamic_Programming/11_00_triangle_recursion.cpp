/* Time complexity : 2 ^ (sum from 1 to n) [n stands for number of rows] */
/* Space complexity : O(n) */
#include <bits/stdc++.h> 
int helper(int row, int col, vector<vector<int>>& t, int n)
{
    if(row == n-1)
    {
        return t[row][col];
    }

    int down = t[row][col] + helper(row+1, col, t, n);
    int diagonal = t[row][col] + helper(row+1, col+1, t, n);

    return min(down, diagonal);
}
int minimumPathSum(vector<vector<int>>& t, int n){
	// Write your code here.
	return helper(0, 0, t, n);
}