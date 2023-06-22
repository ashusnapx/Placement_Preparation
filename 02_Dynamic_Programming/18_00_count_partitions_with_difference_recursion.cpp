#include <bits/stdc++.h> 
int mod = 1e9 + 7;
int helper(int index, int target, vector<int> &arr)
{
    /* base case */
    if(index == 0)
    {
        if(target == 0 and arr[0] == 0) return 2;
        if(target == 0 or arr[0] == target) return 1;
        return 0;
    }

    /* pick and not pick */
    int notTake = 0 + helper(index - 1, target, arr);
    int take = 0;
    if(target >= arr[index])
    {
        take = helper(index - 1, target - arr[index], arr);
    }
    return (take + notTake) % mod;
}
int countPartitions(int n, int d, vector<int> &arr) {
    int sum = 0;
    for(int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    if (sum - d < 0 || (sum - d) % 2 != 0) {
        return 0; // No valid partition exists
    }
    int updatedSum = (sum - d) / 2;
    return helper(n-1, updatedSum, arr);
}