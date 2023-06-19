/* Time complexity : O(n x n) [n stands for number of rows] */
/* Space complexity : O(n x n)[this O(n x n) is used in dp array] */
#include <bits/stdc++.h> 
int minimumPathSum(vector<vector<int>>& t, int n)
{
	vector<int> frontRow(n, 0), currentRow(n, 0);

    /* copy last row in dp array as it stands for base case */
    for(int j = 0; j < n; j++)
    {
        frontRow[n-1][j] = t[n-1][j];
    }

    for(int i = n-2; i >= 0; i--)
    {
        for(int j = i; j >= 0; j--)
        {
            int down = t[i][j] + frontRow[j];
            int diagonal = t[i][j] + frontRow[j+1];
            currentRow[j] = min(down, diagonal);
        }
        frontRow = currentRow;
    }

    return frontRow[0];
}