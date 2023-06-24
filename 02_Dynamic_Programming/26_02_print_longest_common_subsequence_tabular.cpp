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

👨‍💻 Overview: This code finds the Longest Common Subsequence(LCS) of two given strings 'a' and 'b' using Dynamic Programming. It also returns the size of the LCS.

📝 Variables:
- a: First string
- b: Second string
- lcs_size: Stores the size of the LCS
- prev: Vector to store the previous row of the dynamic programming table
- cur: Vector to store the current row of the dynamic programming table
- result: String to store the LCS
- index: Index to keep track of the index in the result string
- i, j: Indexes to traverse the dynamic programming table

💻 Code Walkthrough:
- We first calculate the sizes of string 'a' and 'b'
- We declare two vectors 'prev' and 'cur' to store the previous and current rows of the dynamic programming table. Here, we right shift the vector indexes so that the negative index is not there.
- We use two nested for-loops to traverse the dynamic programming table starting from the bottom.
- If the characters at 'i-1' and 'j-1' of 'a' and 'b' are equal, we add 1 to the LCS size and move to the diagonal element of the table.
- If the characters are not equal, we move to the maximum element of its top or left.
- We use a while-loop to traverse the dynamic programming table from the end to start to get the LCS.
- We check if the characters at 'i-1' and 'j-1' of 'a' and 'b' are equal. If yes, we store the character in the result string and move diagonally.
- If the element to the left is greater, we move left, else we move up.
- We return the result string and the size of LCS.

🤔 Optimization:
- We can optimize the space complexity of this code by using only two rows of the dynamic programming table instead of two vectors.