#include <bits/stdc++.h>
int mod = 1e9+7;
int helper(int i, int j, string &t, string &s, vector<vector<int>> &dp)
{
    if (j < 0)
        return 1;
    if (i < 0)
        return 0;
    if(dp[i][j] != -1)
    {
        return dp[i][j];
    }
    if (t[i] == s[j])
    {
        return (helper(i - 1, j - 1, t, s, dp) + helper(i - 1, j, t, s, dp)) % mod;
    }
    return dp[i][j] = (helper(i - 1, j, t, s, dp)) % mod;
}

int subsequenceCounting(string &t, string &s, int lt, int ls)
{
    vector<vector<int>> dp(lt+1, vector<int>(ls+1, -1));
    return helper(lt - 1, ls - 1, t, s, dp);
}
