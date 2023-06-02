#include <bits/stdc++.h>
using namespace std;

long long int helper(vector<int> &money)
{
    int prev2 = 0, prev = money[0], current_i;
    for(int i = 1; i < money.size(); i++)
    {
        int rob = money[i];
        if(i >= 2)
        {
            rob += prev2;
        }

        int notRob = 0 + prev;

        // the value that needs to be stored
        current_i = max(rob, notRob);

        // update values for next iteration
        prev2 = prev;
        prev = current_i;
    }

    return prev;
}

long long int houseRobber(vector<int>& money)
{
    if(money.size() == 1) return money[0];

    vector<int> firstElementExcluded, lastElementExcluded;
    for(int i = 0; i < money.size() ; i++)
    {
        if(i!=0)
        {
            firstElementExcluded.push_back(money[i]);
        }
        if(i != money.size()-1)
        {
            lastElementExcluded.push_back(money[i]);
        }
    }
    

    return max(helper(firstElementExcluded), helper(lastElementExcluded));
}

int main()
{
    vector<int> money;
    // money.push_back(2);
    // money.push_back(3);
    // money.push_back(2);
    // money.push_back(1);

    money.push_back(1);
    money.push_back(2);
    money.push_back(3);
    money.push_back(1);

    cout << houseRobber(money) << endl;
}