#include <bits/stdc++.h>

int cutRod(vector<int> &price, int n)
{
	vector<int> lengthOfWood;
    for(int i = 0; i < n; i++)
    {
        lengthOfWood.push_back(i + 1);
    }
	vector<vector<int>> dp(n, vector<int> (n+1, 0));

    /* base case */
    /* dp[index][length] */
    for(int length = 0; length <= n; length++)
    {
        dp[0][length] = length * price[0];
    }

    for(int index = 1; index < n; index++)
    {
        for(int length = 1; length <= n; length++)
        {
            int notTake = 0 + dp[index - 1][length];
            int take = INT_MIN;
            if(length >= lengthOfWood[index])
            {
                take = price[index] + dp[index][length - lengthOfWood[index]];
            }
            dp[index][length] = max(notTake, take);
        }
    }
    return dp[n-1][n];
}
