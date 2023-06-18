#include <bits/stdc++.h>
using namespace std;

int search_rotated_array(vector<int> &arr, int target)
{
    int low = 0, high = arr.size() - 1;

    while(low <= high)
    {
        int mid = ( low + high ) / 2;

        if(arr[mid] == target)
        {
            return mid;
        }
        /* check if left or right half is sorted */

        /* imagining left half is sorted */
        else if(arr[low] < arr[mid])
        {
            if(target >= arr[low] and target <= arr[mid])
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }

        /* imagining right half is sorted */
        else
        {
            if(target >= arr[mid] and target <= arr[high])
            {
                high = mid + 1;
            }
            else
            {
                low = mid - 1;
            }
        }
    }

    return -1;
}

int main()
{
    vector<int> arr;
    arr.push_back(5);
    arr.push_back(6);
    arr.push_back(7);
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(3);
    arr.push_back(4);

    int target = 1;

    cout << "Index is: " << search_rotated_array(arr, target) << endl;
}