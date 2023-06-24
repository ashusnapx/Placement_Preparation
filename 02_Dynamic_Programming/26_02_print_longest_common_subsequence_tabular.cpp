#include <bits/stdc++.h>
using namespace std;

string print_lcs(string &a, string &b, int &lcs_size)
{
    /* size declaration */
    int n = a.size(), m = b.size();

    /* declaration of vector dp */
    // vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
    vector<int> prev(n+1, 0), cur(m+1, 0);

    /* so negative index is something that we cannot show in dp index form, so we opted to right shift the indexes */
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            /* now if value at both strings are same */
            if (a[i-1] == b[j-1])
            {
                cur[j] = 1 + prev[j-1];
            }
            else
            {
                cur[j] = max(prev[j], cur[j-1]);
            }
            prev = cur;
        }
    }

    lcs_size = cur[m]; // Store the size of the LCS

    string result(lcs_size, '$');

    int index = lcs_size - 1; // because we always start from back, following a bottom-up approach

    /* now we have to traverse the dp array and insert values in the string to return it */
    int i = n, j = m;
    while (i > 0 && j > 0)
    {
        /* if both characters are the same */
        if (a[i-1] == b[j-1])
        {
            result[index] = a[i-1]; // you can also write b[j-1] because both are the same
            i--, j--;
            index--;
        }
        /* if the maximum of (left, up) is from the left */
        else if (cur[j-1] > prev[j])
        {
            j--;
        }
        /* if the maximum of (left, up) is from the up */
        else
        {
            i--;
        }
    }
    return result;
}

int main()
{
    string a = "adebc";
    string b = "dcadb";
    int lcs_size;

    string lcs = print_lcs(a, b, lcs_size);

    cout << "Longest Common Subsequence: " << lcs << endl;
    cout << "Size of LCS: " << lcs_size << endl;

    return 0;
}
