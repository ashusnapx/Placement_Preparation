/* Time complexity : 3 to the power n [n means number of rows] */
/* Space complexity : O(n) */

#include <bits/stdc++.h> 
int helper(int row, int col, vector<vector<int>> &m)
{
    /* out of bound cases */
    if(col < 0 or col >= m[row].size() or row >= m.size())
    {
        return -1e9;
    }

    /* base cases */
    if(row == 0) return m[0][col];

    /* recursive call */
    int up = m[row][col] + helper(row - 1, col, m);
    int left = m[row][col] + helper(row - 1, col - 1, m);
    int right = m[row][col] + helper(row - 1, col + 1, m);

    return max(down, max(left, right));
}

int getMaxPathSum(vector<vector<int>> &matrix)
{
    //  Write your code here.
    return helper(0, 0, matrix);
}