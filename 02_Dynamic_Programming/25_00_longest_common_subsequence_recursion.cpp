#include <bits/stdc++.h>

int helper(int index1, int index2, string s1, string s2)
{
    /* base case */
    if(index1 < 0 or index2 < 0)
    {
        return 0;
    }

    /* when a index of both strings are same */
    if(s1[index1] == s2[index2])
    {
        return 1 + helper(index1-1, index2-1, s1, s2);
    }

    /* when a index of both strings are not same */
    if(s1[index1] != s2[index2])
    {
        return 0 + max(helper(index1-1, index2,s1,s2), helper(index1, index2-1, s1,s2));
    }
}
int lcs(string s, string t)
{
    int m = s.size();
    int n = t.size();
	return helper(m - 1, n - 1, s, t);
}