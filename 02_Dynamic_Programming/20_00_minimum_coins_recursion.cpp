#include <bits/stdc++.h> 
using namespace std;
int helper(int index, int target, vector<int> &denominations)
{
    /* base case */
    if(index == 0)
    {
        if(target % denominations[index] == 0)
        {
            return target / denominations[index];
        }
        return 1e9;
    }

    int notTake = 0 + helper(index - 1, target, denominations);

    int take = INT_MAX;

    if(target >= denominations[index])
    {
        take = 1 + helper(index, target - denominations[index], denominations);
    }

    return min(notTake, take);
}
int minimumCoins(int p)
{
    vector<int> denominations = {1, 2, 5, 10, 20, 50, 100, 500, 1000};
    int ans = helper(denominations.size() - 1, p, denominations);
    if(ans >= 1e9)
    {
        return -1;
    }
    return ans;
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
