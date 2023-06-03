// smallest index such that arr[index] >= given_number_x
#include <bits/stdc++.h>
using namespace std;

int lower_bound_without_stl(int *arr, int arr_size, int target)
{
    int low = 0 , high = arr_size - 1, ans = arr_size;

    while( low <= high )
    {
        int mid = (high + low) / 2;

        if( arr[mid] >= target )
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return ans;
}

int main()
{
    // int arr[] = { 3, 5 , 8 , 15 , 19 };
    // int arr[] = { 1 , 2 , 3 , 3 , 5 , 8 , 8 , 10 , 10 , 11 };
    int arr[] = { 1,2,1,3,5,6,4 };
    int n = 7;
    cout << "Lower bound = " << lower_bound_without_stl(arr, n, 6) << endl;
    cout << "Lower bound (using STL) = "<< lower_bound(arr , arr + 7 , 6) - arr << endl;
}

/* Time complexity - O(log base 2 n) */