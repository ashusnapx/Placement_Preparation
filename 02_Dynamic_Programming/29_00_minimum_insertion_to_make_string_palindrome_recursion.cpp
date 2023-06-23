#include <bits/stdc++.h> 
int minInsertion(string &s)
{
   string b = s;
    int n = s.size();
    int h = b.size();
    reverse(b.begin(), b.end());
    vector<int> prev(n+1, 0), cur(n+1, 0);

    for(int index1 = 1; index1 <= n; index1++)
    {
        for(int index2 = 1; index2 <= h; index2++)
        {
            if(s[index1 - 1] == b[index2 - 1])
            {
                cur[index2] = 1 + prev[index2-1];
            }
            else
            {
                cur[index2] = 0 + max(prev[index2], cur[index2-1]);
            }
        }
        prev = cur;
    }
    return n - cur[h];
}

/* if this question was about maximum insertions then the length of string was the answer, beacuse koi string hai, aur mai usmein usi k reverse append krdu toh obviously woh palindrome bn jayega */