/* 
Steps to master matrix chain multiplication : 
1. start with entire block/ array. f(i, j), where i is start and j is the end
2. try all partitions
3. return the best possible 2 partitions
 */

#include <bits/stdc++.h> 
int helper(int first_index, int last_index, vector<int> &arr)
{
    /* base case */
    if(first_index == last_index) return 0;

    int mini = 1e9;

    /* try all partitions */
    for(int k = first_index; k < last_index; k++)
    {
        int steps = arr[first_index - 1] * arr[k] * arr[last_index] + helper(first_index, k, arr) + helper(k + 1, last_index, arr);

        if(steps < mini)
        {
            mini = steps;
        }
    }

    return mini;
}

int matrixMultiplication(vector<int> &arr, int N)
{
   return helper(1, N-1, arr);
}