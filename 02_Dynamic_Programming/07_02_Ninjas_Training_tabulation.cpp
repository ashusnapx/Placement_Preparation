/* step 1 : declare the similar size DP array */
/* step 2 : think of base case in terms of 2D, jaise agar last day 0 hai, so you can take only task 1 and 2 in current day */

/* TASK PROIDED FOR 20 STUDENTS BATCH */
int ninjaTraining(int days, vector<vector<int>> &points)
{
    vector<vector<int>>dp(days, vector<int>(4,0));
    dp[0][0] = max(points[0][1], points[0][2]);
    dp[0][1] = max(points[0][0], points[0][2]);
    dp[0][2] = max(points[0][0], points[0][1]);
    dp[0][3] = max(points[0][1],max(points[0][1], points[0][2]));

    /* in total we can have 'n' days */
    for(int day = 1; day < days; day++)
    {
        /* each day can have atmax 4 ie. 0,1,2,3 [3rd one means ki koi bhi task opt nhi kiya hai] tasks to do */
        for(int last = 0; last <= 3; last++)
        {
            /* i'm trying to solve this */
            dp[day][last] = 0;

            /* i'll a carry a variable so that dp[day][task] = maximum, this maximum needs to be calculated */
            int maximum = 0;

            /* each day you can have atmax 3 ie. 0,1,2 options */
            for(int task = 0; task < 3; task++)
            {
                if(task != last)
                {
                    int point = points[day][task] + dp[day-1][task];
                    dp[day][last] = max(dp[day][last], point);
                }
            }
        }
    }
    return dp[days-1][3];
}