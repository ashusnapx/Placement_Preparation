#include <bits/stdc++.h> 
int uniquePaths(int m, int n) {
	// Write your code here.
	if (m == 0 || n == 0) {
        return 0;  // Reached out of bounds, no valid path exists
    }

    if (m == 1 || n == 1) {
        return 1;  // Reached the boundary, only one path exists
    }


	int up = uniquePaths(m-1, n);
	int left = uniquePaths(m, n-1);

	return up + left;
}