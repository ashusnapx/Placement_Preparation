#include <bits/stdc++.h>

int lcs(string &s, string &t)
{
    int m = s.size();
    int n = t.size();
    // vector<vector<int>> dp(m+1, vector<int> (n+1, 0));
    vector<int> prev(n+1, 0), cur(n+1, 0);
    int ans = 0;
    for(int index1 = 1; index1 <= m; index1++)
    {
        for(int index2 = 1; index2 <= n; index2++)
        {
            if(s[index1 - 1] == t[index2 - 1])
            {
                cur[index2] = 1 + prev[index2-1];
                ans = max(ans, cur[index2]);
            }
            else
            {
                cur[index2] = 0;
            }
        }
        prev = cur;
    }

    return ans;
}