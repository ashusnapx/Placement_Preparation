#include <bits/stdc++.h> 
string shortestSupersequence(string a, string b)
{
	// Write your code here.
	int n = a.size(), m = b.size();

	vector<int> prev(n+1, 0), curr(m+1, 0);

	for(int i = 0; i < n; i++) curr[0] = 0;
	for(int j = 0; j < m; j++) prev[j] = 0;

	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= m; j++)
		{
			if(a[i-1] == b[j-1])
			{
				curr[j] = 1 + prev[j-1];
			}
			else
			{
				curr[j] = 0 + max(prev[j], curr[j-1]);
			}
		}
	}

	string ans = "";
	int i = n, j = m;
	while(i > 0 and j > 0)
	{
		if(a[i-1] == b[j-1])
		{
			ans += a[i-1];
			i--, j--;
		}
		else if(prev[j] > curr[j-1])
		{
			ans += a[i-1];
			i--;
		}
		else
		{
			ans += b[j-1];
			j--;
		}
	}

	while(i > 0)
	{
		ans += a[i-1];
		i--;
	}

	while(j > 0)
	{
		ans += b[j-1];
		j--;
	}

	reverse(ans.begin(), ans.end());

	return ans;
}