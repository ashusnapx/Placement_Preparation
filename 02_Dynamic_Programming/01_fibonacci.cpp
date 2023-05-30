/* 
fibonacci series - 0 1 1 2 3 5 8 13 21 34...
index of series  - 0 1 2 3 4 5 6 7  8  9
 */

#include <bits/stdc++.h>
using namespace std;

// Recursive Approach
int fibonacci(int n)
{
    if(n == 0 or n == 1)
    {
        return n;
    }

    int smallAns = fibonacci(n-1) + fibonacci(n-2);

    return smallAns;
}

// Dynamic Programming Approach
int fibonacci_dynamic(int n, vector<int> &dp)
{
    // Step - 1 is to declare a dp array dp[n+1]
    // Step - 2 is to make a call to function and then the base case is checked and then the subproblems are solved but before that it is also checked whether it was solved previousl or not.
    if(n == 0 or n == 1) return n;

    if(dp[n] != -1) return dp[n]; // this means if it already calculated then it might be present in the dp vector, please check

    return dp[n] = fibonacci_dynamic(n-1, dp) + fibonacci_dynamic(n-2, dp); // this means if not present then calculate and put its value in the dp vector
}

/* More optimised Method */
int fibonacci_optimised(int n)
{
    int prev2 = 0, prev = 1, current;
    for(int i = 2; i <= n ; i++)
    {
        current = prev + prev2;
        prev2 = prev;
        prev = current;
    }
    return prev;
}

int main()
{
    int n;
    cout << "Enter the number : " ;
    cin >> n;

    vector<int> dp(n+1,-1);

    cout <<"The fibonacci number is "  << fibonacci(n) << endl;

    cout <<"The fibonacci number is "  << fibonacci_dynamic(n, dp) << endl;

    cout <<"The fibonacci number (found using most optimised way) is "  << fibonacci_optimised(n) << endl;
}

/* 
Time complexity: 
5 called 4 and 3 --> 4 and 3 were already calculated
4 called 3 and 2 --> 3 and 2 were already calculated
3 called 2 and 1 --> 2 was already calculated and 1 is the base case
2 called 1 and 0 --> this was done

so for 5th fibonacci number i've to perform 2 calculations only

-> Time complexity comes out to be --> O(n)
-> Space complexity comes out to be --> O(n) + O(n) <-- one of the O(n) belongs to recursion stack space and other one for vector/array.

 */