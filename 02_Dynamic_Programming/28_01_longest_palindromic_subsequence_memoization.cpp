#include <bits/stdc++.h> 

int helper(int index1, int index2, string &a, string &b, vector<vector<int>> &dp)
{
    // base case
    if(index1 < 0 or index2 < 0)
    {
        return 0;
    }

    if(dp[index1][index2] != -1)
    {
        return dp[index1][index2];
    }

    //if at a single index, both strings value are same
    if(a[index1] == b[index2])
    {
        return 1 + helper(index1-1, index2-1, a, b, dp);
    }

    //if at a single index, both strings value are not same
    if(a[index1] != b[index2])
    {
        return max(helper(index1-1, index2, a,b, dp), helper(index1, index2-1, a, b, dp));
    }
}

int longestPalindromeSubsequence(string s)
{
    int n = s.size();
    string b = s;
    reverse(b.begin(), b.end());
    vector<vector<int>> dp(n+1, vector<int> (n+1, -1));
    return helper(n-1, n-1, s, b, dp);
}