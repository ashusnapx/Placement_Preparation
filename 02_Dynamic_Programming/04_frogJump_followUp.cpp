/* In this questtion basically the frog can jump upto "K" steps, ie. it can either go i+1,i+2,i+3,...,i+k (this k will be provided in the argument of function). Space optimisation isn't possible, coz we don't know what the K would be. */
/* Let me give a try */
int frogJump(int numberOfStairs, int stepsPossible, vector<int> &h)
{
    // base case
    if(numberOfStairs == 0 || stepsPossible == 0) return 0;

    vector<vector<int>> dp(n,0);

    for(int i = 1; i < numberOfStairs; i++)
    {
        for(int j = 1; j <= stepsPossible; j++)
        {
            int jump = dp[i-j] + abs(h[i] - h[j]);
        }
    }
}