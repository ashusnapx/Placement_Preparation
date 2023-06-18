/* 
Ninja is planing this ‘N’ days-long training schedule. Each day, he can perform any one of these three activities. (Running, Fighting Practice or Learning New Moves). Each activity has some merit points on each day. As Ninja has to improve all his skills, he can’t do the same activity in two consecutive days. Can you help Ninja find out the maximum merit points Ninja can earn?

You are given a 2D array of size N*3  ‘POINTS’ with the points corresponding to each day and activity. Your task is to calculate the maximum number of merit points that Ninja can earn.

For example - 
If the given ‘POINTS’ array is [[1,2,5], [3 ,1 ,1] ,[3,3,3] ],
the answer will be 11 as 5 + 3 + 3.

Constraints:
1 <= T <= 10
1 <= N <= 100000.
1 <= values of POINTS arrays <= 100 .

Time limit: 1 sec
 */

#include <bits/stdc++.h>
int helper(int current_day, int last_task_done, vector<vector<int>> &points)
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

    // if number of days more than 1, then ->
    int maximum = 0;
    for(int task = 0; task < 3; task++)
    {
        // check if task was not done on last day
        if(task != last_task_done)
        {
            int point = points[current_day][task] + helper(current_day - 1, task, points);
            maximum = max(maximum, point);
        }
    }
    return maximum;
}

int ninjaTraining(int n, vector<vector<int>> &points)
{
    // Write your code here.
    return helper(n-1, 3, points);
}