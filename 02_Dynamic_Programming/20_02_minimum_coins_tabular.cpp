#include <bits/stdc++.h> 
using namespace std;
int minimumCoins(int target)
{
    vector<int> denominations = {1, 2, 5, 10, 20, 50, 100, 500, 1000};
    vector<vector<int>> dp(denominations.size(), vector<int> (p+1, 0));

    /* base case */
    for(int i = 0; i <= target; i++)
    {
        if(target % denominations[0] == 0)
        {
            dp[0][target] = target / denominations[0];
        }
        else
        {
            dp[0][target] = 1e9;
        }
    }

    for(int i = 1; i < denominations.size(); i++)
    {
        for(int j = 1; j <= target; j++)
        {
            int notTake = dp[i - 1][j];
            int take = INT_MAX;
            if(target >= denominations[i])
            {
                take = dp[i][j-denominations[i]];
            }
        }
    }
}

int main()
{
    int p;
    cout << "Enter the target amount: ";
    cin >> p;

    int result = minimumCoins(p);

    cout << "Minimum number of coins required: " << result << endl;

    return 0;
}
