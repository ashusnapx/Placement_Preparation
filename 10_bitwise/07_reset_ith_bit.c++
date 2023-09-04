#include <bits/stdc++.h>
 
using namespace std;
 
// function to reset the kth bit
int resetKthBit(int n, int k)
{
    // kth bit of n is being set by this operation
    int mask = ~(1 << k);
    return n & mask;
}
 
// Driver program to test above
int main()
{
    int n = 10, k = 1; // 10 --> 1010 and 8 --> 1000
    cout << "Kth bit set number = "
         << resetKthBit(n, k);
    return 0;
}

/* Reset in 3 steps
10 --> 1010
<< --> 0010
~  --> 1101
&  --> 1000 
*/