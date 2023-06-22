#include <bits/stdc++.h>
using namespace std;
int findWays(vector<int> &num, int target)
{
    int n = num.size();
    vector<vector<int>> dp(n, vector<int>(target+1, 0));

    for(int i = 0; i < n; i++) dp[i][target] = 1;

    if(num[0] <= target)
    {
        dp[0][num[0]] = 1;
    }

    for(int index = 1; index < n; index++)
    {
        for(int sum = 0; sum <= target; sum++)
        {
            int notTake = dp[index - 1][sum];
            int take = 0;
            if(sum >= num[index])
            {
                take = dp[index - 1][sum - num[index]];
            }
            dp[index][sum] = take + notTake;
        }
    }
    return dp[n-1][target];
}

int main()
{
    int t; // Number of test cases
    cin >> t;

    while (t--)
    {
        int n; // Size of the input array
        cin >> n;

        vector<int> num(n); // Input array
        for (int i = 0; i < n; i++)
        {
            cin >> num[i];
        }

        int target; // Target sum
        cin >> target;

        int result = findWays(num, target);
        cout << result << endl;
    }

    return 0;
}