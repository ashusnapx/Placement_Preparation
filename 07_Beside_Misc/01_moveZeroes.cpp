#include <iostream>
#include <vector>

using namespace std;

void moveZeroes(vector<int>& nums) {
    int i = 0;  // index for non-zero elements

    // Iterate through the array
    for (int num : nums) {
        if (num != 0) {
            nums[i] = num;  // Move non-zero element to the current index
            i++;
        }
    }

    // Fill the remaining elements with zeroes
    while (i < nums.size()) {
        nums[i] = 0;
        i++;
    }
}

int main() {
    vector<int> nums = {0, 1, 0, 3, 12};

    cout << "Original array: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    moveZeroes(nums);

    cout << "Modified array: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
