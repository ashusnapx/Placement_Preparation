int mod = int(1e9 + 7);

int mazeObstacles(int row, int col, vector< vector< int> > &mat) 
{
    vector<int> prev(col, 0);
    
   for(int i = 0; i < row; i++)
   {
        vector<int> curr(col, 0);
        for(int j = 0; j < col; j++)
        {
            if(i == 0 and j == 0)
            {
                curr[j] = 1;
            }
            else if(mat[i][j] == -1)
            {
                curr[j] = 0;
            }
            else
            {
                int up = 0, left = 0;
                if(i > 0)
                {
                    up = prev[j];
                }
                if(j > 0)
                {
                    left = curr[j-1];
                }
                curr[j] = (up + left) % mod;
            }
        }

        prev = curr;
   }

   return prev[col-1];
}