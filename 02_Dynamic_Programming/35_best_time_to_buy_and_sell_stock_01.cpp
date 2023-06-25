#include <bits/stdc++.h> 
int maximumProfit(vector<int> &prices){
    int minimum_price = prices[0];
    int maximumProfit = 0;
    int n = prices.size();

    for(int i = 0; i < n; i++)
    {
        int cost = prices[i] - minimum_price;
        maximumProfit = max(maximumProfit, cost);
        minimum_price = min(minimum_price, prices[i]);
    }
    return maximumProfit;
}