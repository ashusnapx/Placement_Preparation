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

int maximum_non_adjacent_sum(vector<int> nums)
{
    int n = nums.size();
    int prev = nums[0];
    int prev2 = 0;
    for(int i = 1 ; i < n ; i++)
    {
        int take = nums[i];
        if(i >= 2)
        {
            take += prev2;
        }

        int not_take = 0 + prev;

        int current_i = max(take, not_take);
        prev2 = prev;
        prev = current_i;
    }

    return prev;
}

int main()
{
    vector<int> nums;
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(2);
    nums.push_back(9);

    cout << maximum_non_adjacent_sum(nums);
}