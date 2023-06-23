#include <bits/stdc++.h> 
int longestPalindromeSubsequence(string s)
{
    string b = s;
    int n = s.size();
    int h = b.size();
    reverse(b.begin(), b.end());
    vector<vector<int>> dp(n+1, vector<int> (n+1, 0));

    /* base case */
    for(int i = 0; i < n; i++) dp[i][0] = 0;
    for(int j = 0; j < h; j++) dp[0][j] = 0;

    for(int index1 = 1; index1 <= n; index1++)
    {
        for(int index2 = 1; index2 <= h; index2++)
        {
            if(s[index1 - 1] == b[index2 - 1])
            {
                dp[index1][index2] = 1 + dp[index1-1][index2-1];
            }
            else
            {
                dp[index1][index2] = 0 + max(dp[index1-1][index2], dp[index1][index2-1]);
            }
        }
    }
    return dp[n][h];
}