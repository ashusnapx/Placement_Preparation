#include <bits/stdc++.h>
int mod = 1e9+7;

int subsequenceCounting(string &t, string &s, int lt, int ls)
{
    vector<vector<int>> dp(lt+1, vector<int>(ls+1, 0));
    
    for(int i = 1; i <= lt; i++)
    {
        for(int j = 1; j <= ls; j++)
        {
            if(s[i - 1] == t[j - 1])
            {
                dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
            }
            else
            {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[lt-1][ls-1] % mod;
}
