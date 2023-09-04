/* 
lower bound matlab hota hai ki, smallest index such that uss index pr jo bhi number h, woh kisi given number se bada ya barabar ho
 */

int lowerBound(vector<int> arr, int n, int x) {
	// Write your code here
	int low = 0, high = n - 1;
	int ans = n;

	while(low <= high)
	{
		int mid = (low + high) / 2;

		if(arr[mid] >= x)
		{
			ans = mid;
			high = mid - 1;
		}
		else
		{
			low = mid + 1;
		}
	}

	return ans;
}
