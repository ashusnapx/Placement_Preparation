/* dekho question kya bol rha hai, mere pas ek matrix hai, 
usmien kuch bhi numbers filled hn, aur mujhe 
sr(starting row mtlb x coordinate) aur saath mei sc(starting column) 
aur ek initial color diya hua (color basically ek number hai), 
ab dekho, 4 directions mei jo uske jaise rang honge unko change krna hai ek given color 
(yaani ki ek number se) aur jo naya matrix hoga usey return krna hai*/

#include <iostream>
#include <vector>

using namespace std;

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

vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) 
{
    int initialColor = image[sr][sc];
    vector<vector<int>> ans = image; // creating a copy of image matrix

    /* up means row - 1, col */
    /* right means row, col + 1 */
    /* down means row + 1, col */
    /* left means row, col - 1 */
    /* Δ change in row is -1, 0, 1 */
    /* Δ change in col is -1, 0, 1 */
    int delRow[] = {-1, 0, 1, 0};
    int delCol[] = {0, 1, 0, -1};
    dfs(sr, sc, ans, image, newColor, delRow, delCol, initialColor);
    return ans;
}

int main()
{
    // Test Case 1
    vector<vector<int>> image1 = {{1, 1, 1}, {1, 1, 0}, {1, 0, 1}};
    int sr1 = 1, sc1 = 1, newColor1 = 2;
    vector<vector<int>> result1 = floodFill(image1, sr1, sc1, newColor1);
    cout << "Test Case 1:\n";
    cout << "Original Image:\n";
    for (const auto& row : image1) {
        for (const auto& pixel : row) {
            cout << pixel << " ";
        }
        cout << endl;
    }
    cout << "Modified Image:\n";
    for (const auto& row : result1) {
        for (const auto& pixel : row) {
            cout << pixel << " ";
        }
        cout << endl;
    }
    cout << endl;

    // Test Case 2
    vector<vector<int>> image2 = {{0, 0, 0}, {0, 1, 1}};
    int sr2 = 1, sc2 = 1, newColor2 = 1;
    vector<vector<int>> result2 = floodFill(image2, sr2, sc2, newColor2);
    cout << "Test Case 2:\n";
    cout << "Original Image:\n";
    for (const auto& row : image2) {
        for (const auto& pixel : row) {
            cout << pixel << " ";
        }
        cout << endl;
    }
    cout << "Modified Image:\n";
    for (const auto& row : result2) {
        for (const auto& pixel : row) {
            cout << pixel << " ";
        }
        cout << endl;
    }
    cout << endl;

    // Test Case 3
    vector<vector<int>> image3 = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int sr3 = 0, sc3 = 1, newColor3 = 0;
    vector<vector<int>> result3 = floodFill(image3, sr3, sc3, newColor3);
    cout << "Test Case 3:\n";
    cout << "Original Image:\n";
    for (const auto& row : image3) {
        for (const auto& pixel : row) {
            cout << pixel << " ";
        }
        cout << endl;
    }
    cout << "Modified Image:\n";
    for (const auto& row : result3) {
        for (const auto& pixel : row) {
            cout << pixel << " ";
        }
        cout << endl;
    }
    cout << endl;

    return 0;
}
