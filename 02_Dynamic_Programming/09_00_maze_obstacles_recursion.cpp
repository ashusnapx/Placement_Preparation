int helper(int row, int col, vector< vector< int> > &mat)
{
    if(row >= 0 and col >= 0 and mat[row][col] == -1)
    {
        return 0;
    }
    if( row == 0 and col == 0 )
    {
        return 1;
    }
    if( row < 0 or col < 0 )
    {
        return 0;
    }

    int down = helper(row-1, col, mat);
    int left = helper(row, col-1, mat);

    return down + left;
}

int mazeObstacles(int row, int col, vector< vector< int> > &mat) {
    // Write your code here
    return helper(row-1, col-1, mat);
}