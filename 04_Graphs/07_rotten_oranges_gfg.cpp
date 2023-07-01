#include <bits/stdc++.h>
int minTimeToRot(vector<vector<int>>& grid, int n, int m)
{
    /* sabse pehle mai ek queue create krunga, 
    usmei do cheezen hongi,
    ek toh rotten fruits ka coordinate
    aur dusra time ya maxTime bol lo
    */
     queue<pair<pair<int, int>, int>> q;

     /* ab ek visited array create krunga */
       vector<vector<int>> visited(n, vector<int>(m, 0)); // Use vector instead of dynamic allocation

     /* now i'll traverse the grid and push rotten fruits in queue */
     for(int i = 0; i < n; i++)
     {
        for(int j = 0; j < m; j++)
        {
            if(grid[i][j] == 2) // check if its rotten fruit or not
            {
                q.push({{i, j}, 0});
                visited[i][j] = 2;
            }
            else
            {
                visited[i][j] = 0;
            }
        }
     }

     /* time will increase, so create a counter */
     int timeCounter = 0;
     int delRow[] = {-1, 0, 1, 0};
     int delCol[] = {0, 1, 0, -1};

     while(!q.empty())
     {
        int row = q.front().first.first;
        int col = q.front().first.second;
        int time = q.front().second;
        q.pop();
        timeCounter = max(timeCounter, time);
        for(int i = 0; i < 4; i++)
        {
            int neigbouringRow = row + delRow[i];
            int neigbouringCol = col + delCol[i];

            if(neigbouringRow >= 0 and neigbouringRow < n and neigbouringCol >= 0 and neigbouringCol < m and visited[neigbouringRow][neigbouringCol] != 2 and grid[neigbouringRow][neigbouringCol] == 1)
            {
                q.push({{neigbouringRow, neigbouringCol}, time+1});
                visited[neigbouringRow][neigbouringCol] = 1;
            }
        }
     }

     /* check if all oranges are not rotten or not? */
     for(int i = 0; i < n; i++)
     {
        for(int j = 0; j < m; j++)
        {
            if(grid[i][j] == 1 and visited[i][j] != 2)
            {
                return -1;
            }
        }
     }

     return timeCounter;
}