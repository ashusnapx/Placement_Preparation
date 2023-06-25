#include <bits/stdc++.h>

long getMaximumProfit(long *value, int n)
{
    vector<long> prev(n+1, 0), cur(2, 0);
    /* base case */
    cur[0] = cur[1] = 0;

    /* now the main code starts, where we'll calculate buy and sell */
    

    /* if the user will buy */
    for(long i = n-1; i >= 0; i--)
    {
        for(long buy = 0; buy <= 1; buy++)
        {
            long profit = 0;
            /* if the user will buy and if they not */
            if(buy)
            {
               profit = max(-value[i] + prev[0], 0 + prev[1]);
            }
            else
            {
                profit = max(value[i] + prev[1], 0 + prev[0]);
            }
            cur[buy] = profit;
        }
        prev = cur;
    }
    return cur[1];
}