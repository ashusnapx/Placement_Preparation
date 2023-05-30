/* 
https://www.codingninjas.com/codestudio/problems/frog-jump_3621012?leftPanelTab=0
 */

// Memoization Method
#include <bits/stdc++.h> 

int f(int n, vector<int> &h,vector<int> &dp)
{
    if(n == 0) return n;
    if(dp[n]!=-1) return dp[n];

    int left = f(n-1, h,dp) + abs(h[n] - h[n-1]);
    int right = INT_MAX;
    if(n > 1)
    {
        right = f(n-2, h,dp) + abs(h[n] - h[n-2]);
    }
    return dp[n] = min(left,right);
}

int frogJump(int n, vector<int> &heights)
{
    vector<int> dp(n+1,-1);
    return f(n-1,heights,dp);
}

// Tabulation method
int frogJump(int n, vector<int> &h) { 
    vector<int> dp(n, 0); 
    for(int i=1; i < n; i++)
    {
        int left = dp[i-1] + abs(h[i] - h[i-1]);
        int right = INT_MAX;

        if(i > 1)
        {
            right = dp[i-2] + abs(h[i] - h[i-2]);
        }

        dp[i] = min(left,right);
    }
    return dp[n-1];
}

// More optimised without using vector/array
int frogJump(int n, vector<int> &h)
{
    int prev2 = 0, prev = 0,curr;
    for (int i = 1; i < n; i++) 
    {
        int left = prev + abs(h[i] - h[i-1]);
        int right = INT_MAX;

        if(i > 1)
        {
            right = prev2 + abs(h[i] - h[i-2]);
        }
        curr = min(left,right);
        prev2 = prev;
        prev = curr;
    }
    return curr;
}