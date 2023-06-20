#include <bits/stdc++.h> 
bool helper(int index, int target, vector<int> &arr)
{
    /* base case */
    if(target == 0) return true; 
    /* so basically in this approach we reduce target everytime we move forward */

    if(index == 0)
    {
        if(arr[0] == target)
        {
            return true;
        }
        return false;
    }

    /* condition of not including array value */
    bool notTake = helper(index - 1, target, arr);

    /* condition for including new value */
    bool take = false;

    if( target >= arr[index])
    {
        take = helper(index - 1, target - arr[index], arr);
    }

    return (take) or (notTake);
}
bool subsetSumToK(int array_size, int target, vector<int> &arr) {
    /* if the target is 0, then  */
    return helper(array_size, target, arr);
}

/* Time complexity : O(2 to the power n) */
/* Space complexity : O(n) */