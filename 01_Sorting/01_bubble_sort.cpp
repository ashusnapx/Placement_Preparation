/* so basically in selection sort, the algorithm chooses the minimum or lowest
element from list, then replaces it with the first element. and this goes on.

Step 1 - Compare the first two elements
Step 2 - Swap it if arr[i] > arr[i+1]
Step 3 - if not, then move forward
Step 4 - In first round the maximum element will come  at last position
Step 5 - Swap it with element at 1st index
Repeat

TODO: Pushes the maximum to the last by adjacent swaps.
*/

#include <bits/stdc++.h>
#include <iostream>
using namespace std;


void selection_sort(int *arr, int n)
{
  int min_index = 0, min_element = INT_MIN;
  for (int i = 0; i < n - 2; i++) // n-2 because, if the size of array is n, then we index it from 0 to n-1 and the last index ie. n-1 will get sorted automatically because a single element is always sorted.
  {
    min_index = i;
    for(int j = i; j < n-1; j++)
    {
      if(arr[j] < arr[min_index])
      {
        min_index = j;
      }
    }
    swap(arr[min_index], arr[i]);
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

  selection_sort(arr, n);

  for (int i = 0; i < n; i++)
  {
    cout << arr[i] << " " <<endl;
  }

  return 0;
}
