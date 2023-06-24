#include <bits/stdc++.h> 
#include <bits/stdc++.h>

int lcs(string s, string t)
{
    int m = s.size();
    int n = t.size();
    vector<vector<int>> dp(m+1, vector<int> (n+1, 0));
	
    /* base case */

    for(int i = 0; i <= m; i++) dp[i][0] = 0;
    for(int j = 0; j <= n; j++) dp[0][j] = 0;

    for(int index1 = 1; index1 <= m; index1++)
    {
        for(int index2 = 1; index2 <= n; index2++)
        {
            if(s[index1 - 1] == t[index2 - 1])
            {
                dp[index1][index2] = 1 + dp[index1-1][index2-1];
            }
            else
            {
                dp[index1][index2] = max(dp[index1-1][index2], dp[index1][index2-1]);
            }
        }
    }

    return dp[m][n];
}
int canYouMake(string &str, string &ptr)
{
    return str.length() + ptr.length() - (2 * lcs(str, ptr));
}