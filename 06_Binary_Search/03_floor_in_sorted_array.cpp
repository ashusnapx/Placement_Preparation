// largest number in array <= given number
// iska mtlb jo tumhe number diya hua hai, usse equal element nikal do ya agar equal na ho toh given number se just smallest number nikal do

#include <bits/stdc++.h>
using namespace std;

int floor(int *arr, int arr_size, int value)
{
    int ans = -1;
    int low = 0, high = arr_size - 1;

    while(low <= high)
    {
        int mid = (low + high) / 2;

        if(arr[mid] <= value)
        {
            ans = arr[mid];
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return ans;
}

int main()
{
    int arr[] = {5, 10, 15, 20};
    int size = 4;
    int val = 17;

    cout << floor(arr, size, val) << endl;
}