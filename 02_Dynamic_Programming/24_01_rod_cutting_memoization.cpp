int helper(int index,int length, vector<int> lengthOfWood, vector<int> &price, vector<vector<int>> &dp)
{
    /* base case */
    if(index == 0)
    {
        return length * price[0];
    }
	if(dp[index][length] != -1)
	{
		return dp[index][length];
	}

    int notTake = 0 + helper(index - 1, length, lengthOfWood, price, dp);
    int take = INT_MIN;
    if(length >= lengthOfWood[index])
    {
        take = price[index] + helper(index,length-lengthOfWood[index],lengthOfWood, price, dp);
    }

    return dp[index][length] = max(take, notTake);
}
int cutRod(vector<int> &price, int n)
{
	vector<int> lengthOfWood;
    for(int i = 0; i < n; i++)
    {
        lengthOfWood.push_back(i + 1);
    }
	vector<vector<int>> dp(n, vector<int> (n+1, -1));
    return helper(n-1, n, lengthOfWood, price, dp);
}
