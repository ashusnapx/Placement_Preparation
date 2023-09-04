/* problem link : https://practice.geeksforgeeks.org/problems/max-sum-subarray-of-size-k5313/1

Date - 6th August, 2023
 */

long maximumSumSubarray(int k, vector<int> &arr, int N) {
    long sum = 0, mx = 0;
    int i = 0, j = 0; // they'll denote window size
    while (j < N) {
        // ya toh window size hit hoga
        if (j - i + 1 == k) {
            sum += arr[j]; // Add the element at index 'j' to the sum
            mx = max(mx, sum); // Update the maximum sum
            sum -= arr[i]; // Remove the element at index 'i' from the sum
            i++;
            j++;
        } else {
            sum += arr[j]; // Add the element at index 'j' to the sum
            j++;
        }
    }

    return mx;
}
