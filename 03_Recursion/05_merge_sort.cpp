#include <bits/stdc++.h>

using namespace std;

void merge(vector<int>& arr, int low, int mid, int high)
{
    vector<int> updatedArr;
    int left = low, right = mid + 1;
    while (left <= mid && right <= high)
    {
        if (arr[left] <= arr[right])
        {
            updatedArr.push_back(arr[left]);
            left++;
        }
        else
        {
            updatedArr.push_back(arr[right]);
            right++;
        }
    }

    while (left <= mid)
    {
        updatedArr.push_back(arr[left]);
        left++;
    }

    while (right <= high)
    {
        updatedArr.push_back(arr[right]);
        right++;
    }

    left = 0;
    while(left<updatedArr.size()){
        arr[low++]=updatedArr[left++];
    }
}

void merge_algo(int low, int high, vector<int> &arr)
{
    /* base case */
    if (low >= high)
        return;

    int mid = (low + high) / 2;

    merge_algo(low, mid, arr);
    merge_algo(mid + 1, high, arr);
    merge(arr, low, mid, high);
}

void mergeSort(vector<int> &arr, int n)
{
    merge_algo(0, n - 1, arr);
}
