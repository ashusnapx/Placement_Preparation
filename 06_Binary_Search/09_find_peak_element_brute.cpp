/* https://bit.ly/3BEDvZC */
int findPeakElement(vector<int> &arr) {
    int n = arr.size();

    for(int i = 0; i < n; i++)
    {
        if((i == 0 or arr[i - 1] < arr[i]) and (i == n - 1 or arr[i] > arr[i+1]))
        {
            return i;
        }
    }

    return -1;
}
