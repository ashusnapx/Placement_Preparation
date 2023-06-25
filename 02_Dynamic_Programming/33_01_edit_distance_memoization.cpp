int helper(int n, int m, string &a, string &b, vector<vector<int>> &dp)
{
    /* if string 1 gets exhausted, then you've to insert all the remaining portion of string 2 */
    if(n < 0) return m + 1;
    if(m < 0) return n + 1;

    if(dp[n][m] != -1)
    {
        return dp[n][m];
    }

    /* if strings matched at some point, no work done */
    if(a[n] == b[m]) return dp[n][m] = 0 + helper(n-1, m-1, a, b, dp);

    return dp[n][m] = 1 + min(helper(n-1, m, a, b, dp), 
    min(helper(n, m-1, a, b, dp), helper(n-1, m-1, a, b, dp))
    );
}
int editDistance(string str1, string str2)
{
    int n = str1.size();
    int m = str2.size();
    vector<vector<int>> dp(n+1, vector<int> (m+1, -1));
    return helper(n-1, m-1, str1, str2, dp);
}