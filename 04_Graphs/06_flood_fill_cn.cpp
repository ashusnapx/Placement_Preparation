#include <bits/stdc++.h>
void dfs(int startingRow, int startingColumn, vector<vector<int>> &ans, vector<vector<int>> &image, int newColor, int *delRow, int *delCol, int initialColor)
{
    ans[startingRow][startingColumn] = newColor;
    int n = image.size();
    int m = image[0].size();
    /* check for neighbors in all 4 directions ie. up, down, left & right */
    /* i also know that we've only 4 neighbors */
    for(int i = 0; i < 4; i++)
    {
        int updatedRow = startingRow + delRow[i];
        int updatedCol = startingColumn + delCol[i];

        if(updatedRow >= 0 and updatedRow < n and updatedCol >= 0 and updatedCol < m and image[updatedRow][updatedCol] == initialColor and ans[updatedRow][updatedCol] != newColor)
        {
            dfs(updatedRow, updatedCol, ans, image, newColor, delRow, delCol, initialColor);
        }
    }
}
vector<vector<int>> floodFill(vector<vector<int>> &image, int x, int y, int newColor)
{
   vector<vector<int>> ans = image;
   int initialColor = image[x][y];
    /* up means row - 1, col */
    /* right means row, col + 1 */
    /* down means row + 1, col */
    /* left means row, col - 1 */
    /* Δ change in row is -1, 0, 1 */
    /* Δ change in col is -1, 0, 1 */
    int delRow[] = {-1, 0, 1, 0};
    int delCol[] = {0, 1, 0, -1};
   dfs(x, y, ans, image, newColor, delRow, delCol, initialColor);
   return ans;
}