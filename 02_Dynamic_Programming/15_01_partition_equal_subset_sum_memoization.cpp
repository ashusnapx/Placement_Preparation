bool helper(int index, int target, vector<int> &arr, vector<vector<int>> &dp)
{
    /* base case */
    if(target == 0)
    {
        return true;
    }

    if(index == 0)
    {
        return arr[index] == target;
    }

    /* check if it previously existed */
    if(dp[index][target] != -1)
    {
        return dp[index][target];
    }

    /* small calculation + recursive call */
    bool notTake = helper(index - 1, target, arr, dp);

    bool take = false;

    if(target >= arr[index])
    {
        take = helper(index - 1, target - arr[index], arr, dp);
    }

    return dp[index][target] = take | notTake;
}

bool canPartition(vector<int> &arr, int n)
{
    int sum = 0;
    for(int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    if(sum % 2 != 0)
    {
        return false;
    }
    vector<vector<int>> dp(n+1, vector<int>((sum/2)+1, -1));
	return helper(n-1, sum/2, arr, dp);
}
/* every subarray is a subsequence */