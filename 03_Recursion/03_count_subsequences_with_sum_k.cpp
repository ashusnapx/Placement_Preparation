#include <bits/stdc++.h>
using namespace std;

int count_subsequences(int index, int initial_sum, int final_sum, int *arr, int size_of_array)
{
    // if all the elements in array are +ve then strict case
    if(initial_sum > final_sum) return 0;

    // base case
    if(index == size_of_array)
    {
        if(initial_sum == final_sum)
        {
            return 1;
        }
        return 0;
    }

    // the pointer will now move towards left tree and right and move upto leaf node and will check and add to ds vector those subsequences whose initial_sum == final_sum
    initial_sum += arr[index];

    int l = count_subsequences(index + 1, initial_sum, final_sum, arr, size_of_array);

    initial_sum -= arr[index];

    // not pick situation
    int r = count_subsequences(index + 1, initial_sum, final_sum, arr, size_of_array);

    return l + r;
}

int main()
{
    int final_sum = 2;
    int size_of_array = 3;
    int arr[] = {1,2,1};
    cout << count_subsequences(0, 0, final_sum, arr, size_of_array);
}