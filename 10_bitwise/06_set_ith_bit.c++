/* 
1 1 1 1 --> this means 15 --> i've to set 3rd bit
0 1 0 0 --> this is the mask and i'm performing OR operation
-------
1 0 1 1 --> this means 11 (1 + 2 + 0 + 8)
*/

#include <bits/stdc++.h>
 
using namespace std;
 
// function to set the kth bit
int setKthBit(int n, int k)
{
    // kth bit of n is being set by this operation
    return ((1 << k) | n);
}
 
// Driver program to test above
int main()
{
    int n = 10, k = 2; // 10 --> 1010 and 14 --> 1110
    cout << "Kth bit set number = "
         << setKthBit(n, k);
    return 0;
}

/* 
10 --> 1010 and 14 --> 1110
1010
0100 (1 left shifted by 2 and became 100)
----
1110
*/