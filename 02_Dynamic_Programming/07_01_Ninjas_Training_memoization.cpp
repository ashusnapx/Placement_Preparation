#include <bits/stdc++.h>
int helper(int current_day, int last_task_done, vector<vector<int>> &points, vector<vector<int>> &dp)
{
    if(current_day == 0)
    {
        int maximum = 0;
        for(int task = 0; task < 3; task++)
        {
            if(task != last_task_done)
            {
                maximum = max(maximum, points[0][task]);
            }
        }
        return maximum;
    }

    if(dp[current_day][last_task_done] != -1)
    {
        return dp[current_day][last_task_done];
    }

    // if number of days more than 1, then ->
    int maximum = 0;
    for(int task = 0; task < 3; task++)
    {
        // check if task was not done on last day
        if(task != last_task_done)
        {
            int point = points[current_day][task] + helper(current_day - 1, task, points, dp);
            maximum = max(maximum, point);
        }
    }
    return dp[current_day][last_task_done] = maximum;
}

int ninjaTraining(int n, vector<vector<int>> &points)
{
    // Write your code here.
    vector<vector<int>>dp(n,vector<int>(4,-1));
    return helper(n-1, 3, points, dp);
}

/* time complexity : O(n x 4) x 3 */
/* space complexity : O(n) + O(n x 4) */