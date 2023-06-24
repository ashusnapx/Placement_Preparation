#include <bits/stdc++.h> 
#include <bits/stdc++.h>

int lcs(string s, string t)
{
    int m = s.size();
    int n = t.size();
    vector<int> prev(m+1, 0), cur(n+1, 0);
	
    /* base case */

    for(int i = 0; i <= m; i++) dp[i][0] = 0;
    for(int j = 0; j <= n; j++) dp[0][j] = 0;

    for(int index1 = 1; index1 <= m; index1++)
    {
        for(int index2 = 1; index2 <= n; index2++)
        {
            if(s[index1 - 1] == t[index2 - 1])
            {
                cur[index2] = 1 + prev[index2-1];
            }
            else
            {
                cur[index2] = max(prev[index2], cur[index2-1]);
            }
        }
    }

    return cur[n];
}
int canYouMake(string &str, string &ptr)
{
    return str.length() + ptr.length() - (2 * lcs(str, ptr));
}