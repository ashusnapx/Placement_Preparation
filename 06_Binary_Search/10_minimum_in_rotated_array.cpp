#include <bits/stdc++.h>
int findMin(vector<int>& arr)
{
	int n = arr.size();
    int start = 0, end = n - 1, ans = INT_MAX, mid;

    while(start <= end)
    {
        mid = (start + end) / 2;

        // sorted
        if(arr[start] <= arr[mid])
        {
            /* [5, 6, 1, 2, 3, 4] */
            /*  l     m        h  */
            ans = min(ans, arr[start]);
            low = mid + 1;
        }
        // not sorted
        else
        {
            ans = min(ans, arr[mid]);
            high = mid - 1;
        }
    }

    return ans;
}