#include <bits/stdc++.h> 
int minSumPath(vector<vector<int>> &grid) {
    int row = grid.size();
    int col = grid[0].size();
    int dp[row][col];

    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            if(i == 0 and j == 0) {
                dp[i][j] = grid[i][j];
            } else {
                int up = INT_MAX;
                int left = INT_MAX;
                
                if(i > 0) {
                    up = dp[i-1][j];
                }
                if(j > 0) {
                    left = dp[i][j-1];
                }

                dp[i][j] = min(up, left) + grid[i][j];
            }
        }
    }

    return dp[row-1][col-1];
}
