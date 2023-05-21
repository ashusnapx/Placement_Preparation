/* so basically in selection sort, the algorithm chooses the minimum or lowest
element from list, then replaces it with the first element. and this goes on.

Step 1 - Compare the first two elements
Step 2 - Swap it if arr[i] > arr[i+1]
Step 3 - if not, then move forward
Step 4 - In first round the maximum element will come  at last position
Step 5 - In second round we don't need to compare the arr[n-1] with arr[n-2], because the element at arr[n-1] is already sorted and so the element at arr[n-2]
Step 6 - Thus in every single round the size of array for inspection decreases, like 
in 1st round - arr[n-1] became sorted
in 2nd round - arr[n-2] became sorted
in 3rd round - arr[n-3] became sorted
.
.
.
in nth round - arr[n-n] became sorted

TODO: Pushes the maximum to the last by adjacent swaps.
*/

#include <bits/stdc++.h>
using namespace std;


void bubble_sort(int *arr, int n)
{
  for(int i = n-1; i >= 1; i--)
  {
    int didSwap = 0;
    for(int j = 0; j <= i-1; j++)
    {
        if(arr[j] > arr[j+1])
        {
            int temp = arr[j+1];
            arr[j+1] = arr[j];
            arr[j] = temp;
            didSwap = 1;
        }
    }
    if(didSwap == 0)
    {
        break;
    }
    // cout << "Le vai tera array sorted nhi hai" <<endl;
  }
}

int main() {
  int n;
  cout << "Enter size of array" << endl;
  cin >> n;

  int arr[n];

  for (int i = 0; i < n; i++) {
    cout << "Enter element at index " << i << endl;
    cin >> arr[i];
  }

  bubble_sort(arr, n);

  for (int i = 0; i < n; i++)
  {
    cout << arr[i] << " " <<endl;
  }

  return 0;
}

/* Time complexity --> 
0(n square) <-- worst case and average case
0(n) <--  best case
*/