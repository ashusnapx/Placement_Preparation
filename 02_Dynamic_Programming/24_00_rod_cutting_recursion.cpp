int helper(int index,int length, vector<int> lengthOfWood, vector<int> &price)
{
    /* base case */
    if(index == 0)
    {
        return length * price[0];
    }

    int notTake = 0 + helper(index - 1, length, lengthOfWood, price);
    int take = INT_MIN;
    if(length >= lengthOfWood[index])
    {
        take = price[index] + helper(index,length-lengthOfWood[index],lengthOfWood, price);
    }

    return max(take, notTake);
}
int cutRod(vector<int> &price, int n)
{
	vector<int> lengthOfWood;
    for(int i = 0; i < n; i++)
    {
        lengthOfWood.push_back(i + 1);
    }
    return helper(n-1, n, lengthOfWood, price);
}
