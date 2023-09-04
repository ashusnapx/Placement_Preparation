#include <bits/stdc++.h>
using namespace std;

bool isOdd(int n)
{
    return (n & 1) == 1; // this means agar 1 hua toh odd nhi toh even
}

int main()
{
    cout << "This code is written by Ashutosh on 1st september, 2023" << endl;

    int n = 11;
    if(isOdd(n))
    {
        cout << n << " is Odd" << endl;
    }
    else
    {
        cout << n << " is Even" << endl;
    }
}