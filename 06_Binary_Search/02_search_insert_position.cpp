#include <bits/stdc++.h>

int searchInsert(vector<int>& arr, int m)
{
	return lower_bound(arr.begin(),arr.end(),m) - arr.begin();
}

int main()
{

}