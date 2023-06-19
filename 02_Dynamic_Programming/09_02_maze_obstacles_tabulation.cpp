int mod = int(1e9 + 7);

int mazeObstacles(int row, int col, vector< vector< int> > &mat) 
{
    int dp[row][col];
    int up, left;
   for(int i = 0; i < row; i++)
   {
        for(int j = 0; j < col; j++)
        {
            if(i == 0 and j == 0)
            {
                dp[i][j] = 1;
            }
            else if(mat[i][j] == -1)
            {
                dp[i][j] = 0;
            }
            else
            {
                if(i > 0)
                {
                    up = dp[i-1][j];
                }
                if(j > 0)
                {
                    left = dp[i][j-1];
                }
                dp[i][j] = (up + left) % mod;
            }
        }
   }

   return dp[row-1][col-1];
}