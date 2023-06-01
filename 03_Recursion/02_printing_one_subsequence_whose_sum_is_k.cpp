#include <bits/stdc++.h>
using namespace std;

bool printF(int index, vector<int> &result, int initial_sum, int final_sum, int *arr, int arr_size)
{
    if(index == arr_size)
    {
        // condition satisfied
        if(initial_sum == final_sum)
        {
            for(auto it: result)
            {
                cout << it << " ";
            }
            cout << endl;
            return true;
        }

        // condition not satisfied
        return false;
    }
    

    //TODO: pick
    result.push_back(arr[index]);

    // if picked then you've to add it to initial sum
    initial_sum += arr[index];

    // call the recursive functions
    if(printF(index + 1, result, initial_sum, final_sum, arr, arr_size)){
        return true;
    }

    // till now the pointer has traversed the whole recursive tree and it had also reached leaf node, so now its traversing back and making initial sum 0 again in order to check other part of tree ie. right tree.
    initial_sum -= arr[index];
    result.pop_back();

    // TODO: not pick
    if(printF(index + 1, result, initial_sum, final_sum, arr, arr_size)){
        return true;
    }

    // if none of the recursive calls gave false, then
    return false;
}

int main()
{
    int sum = 4;
    // cout << "What sum you want : " ;
    // cin >> sum;

    int arr_size = 5;
    // cout << "What should be array size : ";
    // cin >>  arr_size;

    int arr[] = {1, 3, 2, 2, 4};

    // for(int i = 0; i < arr_size; i++)
    // {
    //     cin >> arr[i];
    // }

    vector<int> ds;

    printF(0, ds, 0, sum, arr, arr_size);
}