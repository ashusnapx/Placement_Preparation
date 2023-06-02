/* Question basically yeh bol rha hai ki agar tumhare pas ek list hai.....maan lo [1,3,4,5] toh jaise 1 ke adjacent 3 hai, 3 ke 4, 4 ke 5, toh unko add nhi kr sakte
jaise ki maan lo chosen number hai:
1: 4 + 5 = 9
3: 5 = 5
4: 1 = 1
5: 1 + 3 = 4

so if asked maximum then 1 is the answer and if min then 4.
 */

#include <bits/stdc++.h>
using namespace std;

int helper(int index, vector<int> &nums)
{
    // if their is only a single element in the vector, so it can't be compared with others. so when function maximum_non_adjacent_sum passes size - 1 = 1 - 1 = 0
    if(index == 0) return nums[index];

    // this is an edge case as question mentioned that we cannot consider the subsequent element and to satisfy that condition we need to check index - 2 every time and if at any case then 0th index crosses so we put a check so that no error may come.
    if(index < 0) return 0;

    int pick = nums[index] + helper(index - 2, nums);

    int not_pick = 0 + helper(index - 1, nums);

    return max(pick, not_pick);
}

int maximum_non_adjacent_sum(vector<int> nums)
{
    int n = nums.size();
    return helper(n-1, nums);
}

int main()
{
    vector<int> nums;
    nums.push_back(2);
    nums.push_back(1);
    nums.push_back(4);
    nums.push_back(9);

    cout << maximum_non_adjacent_sum(nums);
}