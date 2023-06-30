void bfs(int row, int col, vector<vector<int>> &visited, vector<vector<char>>& grid)
{
    visited[row][col] = 1;
    queue<pair<int,int>> q;
    q.push({row, col});
    int n = grid.size();
    int m = grid[0].size();

    while(!q.empty())
    {
        int row = q.front().first;
        int col = q.front().second;
        q.pop();

        /* traverse to all neighbours and mark them visited in visited array */
        for(int delta_row = -1; delta_row <= 1; delta_row++)
        {
            for(int delta_col = -1; delta_col <= 1; delta_col++)
            {
                int new_row = row + delta_row;
                int new_col = col + delta_col;

                if(new_col >= 0 and new_col < m and new_row >= 0 and new_row < n and grid[new_row][new_col] == '1' and visited[new_row][new_col] == 0)
                {
                    visited[new_row][new_col] = 1;
                    q.push({new_row, new_col});
                }
            }
        }
    }
}
int numIslands(vector<vector<char>>& grid) 
{
    int n = grid.size();
    int m = grid[0].size();
    int islandCounter = 0;

    /* create a same size 2D array to check which vertex is visited and vice-versa */
    vector<vector<int>> visited(n, vector<int> (m, 0));

    /* traverse the grid */
    for(int row = 0; row < n; row++)
    {
        for(int col = 0; col < m; col++)
        {
            if(visited[row][col] == 0 and grid[row][col] == '1')
            {
                islandCounter++;
                bfs(row, col, visited, grid);
            }
        }
    }
    return islandCounter;
}