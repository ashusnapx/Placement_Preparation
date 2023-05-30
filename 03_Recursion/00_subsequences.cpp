#include <bits/stdc++.h>
using namespace std;

// Recursive function to print all subsets of the array
void printF(int index, vector<int> &newArray, int oldArray[], int n)
{
    // Base case: All elements have been processed
    if (index == n)
    {
        // Print the elements in the current subset
        for (auto it : newArray)
        {
            cout << it << " ";
        }

        // Check if the subset is empty
        if (newArray.size() == 0)
        {
            cout << "yeh null h bhai" << endl;
        }

        cout << endl;
        return;
    }

    // Accept or pick the element at the current index
    newArray.push_back(oldArray[index]);

    // Recursive call to process the next index
    printF(index + 1, newArray, oldArray, n);

    // Remove the last element to backtrack
    newArray.pop_back();

    // Reject or not pick the element at the current index
    printF(index + 1, newArray, oldArray, n);
}

int main()
{
    // Read the value of n
    int n;
    cin >> n;

    // The original array
    int arr[] = {3, 1, 2};

    // Create an empty vector to store the subsets
    vector<int> v;

    // Call the printF function with initial parameters
    printF(0, v, arr, n);

    return 0;
}

         +------------------+
         |                  |
         |     main()       |
         |                  |
         +---------+--------+
                   |
                   V
       +-----------+-----------------------------+
       |                                         |
       |   printF(index, newArray, oldArray, n)  |
       |                                         |
       +-----------+-----------------------------+
                   |
         +---------+--------+
         |                  |
         V                  V
+--------+--------+  +------+------+
|                 |  |             |
| if (index == n) |  |  else       |
|                 |  |             |
+--------+--------+  +------+------+
         |                  |
         V                  V
+--------+--------+   +------+------+
|                  |  |             |
|   Print subset   |  |             |
|   elements       |  |  Accept     |
|                  |  |  element    |
+--------+--------+   |  at current |
         |            |  index      |
         V            |             |
+--------+--------+   +------+------+
|                  |  |             |
| Recursive call   |  |  Remove     |
| to process next  |  |  last       |
| index            |  |  element    |
|                  |  |             |
+--------+--------+   +------+------+
         |                   |
         V                   V
+--------+---------+  +------+------+
|                  |  |             |
| Recursive call   |  |             |
| to process next  |  |  Reject     |
| index            |  |  element    |
|                  |  |  at current |
|                  |  |  index      |
+------------------+  +-------------+
