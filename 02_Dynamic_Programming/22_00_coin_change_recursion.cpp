long long helper(int index, int target, int *denominations)
{
    /* base case */
    if(index == 0)
    {
        return (target % denominations[0] == 0);
    }

    /* pick and not pick */
    long notTake = helper(index - 1, target, denominations);
    long take = 0;
    if(target >= denominations[index])
    {
        take = helper(index, target - denominations[index], denominations);
    }

    return (take + notTake);
}

long countWaysToMakeChange(int *denominations, int n, int value)
{
    long ans = helper(n-1, value, denominations);
    if(ans >= 1e9)
    {
        return 0;
    }
    return ans;
}