/* mujhe i'th bit find karna hai,
ab samajhte hn approach, dekho koi bhi number ka 'AND' 1 ke saath whi number hota hai, toh  mai ek mask create krunga, jo sirf uss specific postion ke bit pr 1 hoga aur baaki jagah 0 hoga. Ab question yeh bnta hai, mask bnega kaise? toh mask ko bnane k liye mujhe 1 ke right me zeroes lgaane hain, right mei zeroes chahiye toh left shift krunga, kitna left shift krunga, jitne position pr poocha hai, usse ek kam n, kyunki uss position pr 1 rhega n, buddhu.
 */

#include <bits/stdc++.h>
using namespace std;

#include <iostream>

int main() {
    int n = 15; // 1111 (binary representation of 15)
    
    // Creating a mask to extract the 3rd bit (position 2 from the right)
    int mask = 1 << 2; // Shift 1 by 2 positions to the left

    cout << "Mask: " << mask << endl;

    // Extract the 3rd bit using bitwise AND
    int extractedBit = (n & mask) >> 2; // Shift back to the right to get the bit value

    std::cout << "Extracted Bit (3rd bit): " << extractedBit << std::endl;

    return 0;
}


/* binary representation of 15 --> 1111(2^3 x 1 + 2^2 x 1 + 2^1 x 1 + 2^0 x 1) 
                                    8 + 4 + 2 + 1 = 15
mask = 1 1 1 1
       0 1 0 0 --> as i wanted to find 3rd bit  */