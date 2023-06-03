#include <iostream>
#include <vector>
using namespace std;

pair<int, int> first_and_last_brute(vector<int>& arr, int arr_size, int value)
{
    // initialize first and last as -1
    int first = -1, last = -1;

    // traverse through loop and update values as they're found
    for (int i = 0; i < arr_size; i++)
    {
        if (arr[i] == value)
        {
            if (first == -1)
            {
                first = i;
            }
            last = i;
        }
    }

    return make_pair(first, last);
}

pair<int, int> first_and_last_using_STL(vector<int>& arr, int arr_size, int value)
{
    int first = lower_bound(arr.begin(),arr.end(),value) - arr.begin();

    if(first == arr_size || arr[first] != value)
    {
        return {-1,-1};
    }

    return make_pair(first, upper_bound(arr.begin(),arr.end(),value) - arr.begin() - 1);
}

int first_using_plain_binary(vector<int>& arr, int arr_size, int value)
{
    int first = -1;
    int low = 0, high = arr_size - 1;

    while(low <= high)
    {
        int mid = (low + high) / 2;

        if(arr[mid] == value)
        {
            first = mid;
            high = mid - 1;
        }
        else if(arr[mid] < value)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return first;
}
int last_using_plain_binary(vector<int>& arr, int arr_size, int value)
{
    int last = -1;
    int low = 0, high = arr_size - 1;

    while(low <= high)
    {
        int mid = (low + high) / 2;

        if(arr[mid] == value)
        {
            last = mid;
            low = mid + 1;
        }
        else if(arr[mid] < value)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return last;
}

int main()
{
    vector<int> arr = {1, 2, 3, 3, 4, 5, 5, 6, 6, 6};
    int value = 6;
    int arr_size = arr.size();

    pair<int, int> result = first_and_last_brute(arr, arr_size, value);
    pair<int, int> result2 = first_and_last_using_STL(arr, arr_size, value);

    cout << "First occurrence: " << result.first << endl;
    cout << "Last occurrence: " << result.second << endl;

    cout << endl;

    cout << "First occurrence(using STL): " << result2.first << endl;
    cout << "Last occurrence(using STL): " << result2.second << endl;

    return 0;
}
