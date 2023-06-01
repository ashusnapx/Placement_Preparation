#include <bits/stdc++.h>
using namespace std;

void printF(int index, vector<int> &result, int initial_sum, int final_sum, int *arr, int arr_size)
{
    if(index == arr_size)
    {
        if(initial_sum == final_sum)
        {
            for(auto it: result)
            {
                cout << it << " ";
            }
            cout << endl;
        }
        return;
    }
    

    //TODO: pick
    result.push_back(arr[index]);

    // if picked then you've to add it to initial sum
    initial_sum += arr[index];

    // call the recursive functions
    printF(index + 1, result, initial_sum, final_sum, arr, arr_size);

    // till now the pointer has traversed the whole recursive tree and it had also reached leaf node, so now its traversing back and making initial sum 0 again in order to check other part of tree ie. right tree.
    initial_sum -= arr[index];
    result.pop_back();

    // TODO: not pick
    printF(index + 1, result, initial_sum, final_sum, arr, arr_size);
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

/* 
Certainly! Let's go through the code step by step and explain what each part does.

```cpp
#include <bits/stdc++.h>
using namespace std;
```
This code includes the necessary header files for the program.

```cpp
void printF(int index, vector<int> &result, int initial_sum, int final_sum, int *arr, int arr_size)
```
This function, `printF`, is a recursive function that finds all possible subsets of the given array `arr` whose elements sum up to `final_sum`. The function takes several parameters:
- `index` is the current index of the array being considered.
- `result` is a reference to a vector that stores the current subset being built.
- `initial_sum` is the sum of the elements in the current subset.
- `final_sum` is the target sum.
- `arr` is a pointer to the array of integers.
- `arr_size` is the size of the array.

```cpp
if(index == arr_size)
{
    if(initial_sum == final_sum)
    {
        for(auto it: result)
        {
            cout << it << " ";
        }
        cout << endl;
    }
    return;
}
```
This is the base case of the recursive function. When `index` reaches the size of the array, it means we have considered all elements. At this point, we check if the `initial_sum` is equal to the `final_sum`. If it is, we print the current subset stored in `result` by iterating over it and outputting each element. Then, we return from the function.

```cpp
result.push_back(arr[index]);
initial_sum += arr[index];
```
Here, we add the current element at `arr[index]` to the `result` vector, simulating picking the element for the subset. We also update the `initial_sum` by adding the value of the current element.

```cpp
printF(index + 1, result, initial_sum, final_sum, arr, arr_size);
```
This line recursively calls `printF` with the updated `index` (moving to the next element), `result`, `initial_sum`, `final_sum`, `arr`, and `arr_size`. This call represents picking the current element for the subset.

```cpp
initial_sum -= arr[index];
result.pop_back();
```
After the recursive call, we backtrack by subtracting the value of the current element from `initial_sum` and removing it from the `result` vector. This step simulates not picking the current element for the subset.

```cpp
printF(index + 1, result, initial_sum, final_sum, arr, arr_size);
```
Next, we make another recursive call to `printF` with the same parameters as before, except that the index is incremented by 1. This call represents not picking the current element for the subset.

```cpp
int main()
{
    int sum = 4;
    int arr_size = 5;
    int arr[] = {1, 3, 2, 2, 4};
    vector<int> ds;

    printF(0, ds, 0, sum, arr, arr_size);
}
```
In the `main` function, we define the target sum (`sum`), the size of the array (`arr_size`), and the array itself (`arr`). We also create an empty vector `ds` to store the subsets. Finally, we call the `printF` function with initial values for `index`, `result`, `initial_sum`, `final_sum`, `arr`, and `arr_size`.

The `printF` function then recursively explores all possible subsets of the array and prints those subsets whose

 elements sum up to the target `sum`.
 */