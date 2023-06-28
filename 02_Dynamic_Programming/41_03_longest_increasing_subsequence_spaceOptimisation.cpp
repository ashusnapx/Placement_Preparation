#include <bits/stdc++.h>

int longestIncreasingSubsequence(int arr[], int n)
{
    /* declare a 1D dp array */
    vector<int> prev(n+1, 0), ind(n+1, 0);
    /* base case */

    /* take and not take conditions */
    for(int index = n - 1; index >= 0; index--)
    {
        for(int prev_index = index - 1; prev_index >= -1; prev_index--)
        {
            /* not take */
            int len = 0 + prev[prev_index + 1]; // +1 because of paramter shift

            if(prev_index == -1 or arr[index] > arr[prev_index])
            {
                len = max(len, 1 + prev[index + 1]);
            } 
            ind[prev_index + 1] = len;
        }
        prev = ind;
    }
    return ind[0];
}
