bool helper(int index, int target, vector<int> &arr)
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

    /* small calculation + recursive call */
    bool notTake = helper(index - 1, target, arr);

    bool take = false;

    if(target >= arr[index])
    {
        take = helper(index - 1, target - arr[index], arr);
    }

    return take | notTake;
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
	return helper(n-1, sum/2, arr);
}
/* every subarray is a subsequence */