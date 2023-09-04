/* so i've a array and every number in array twice but one element comes once. find that element. (using bit manipulation)*/

/* thoda chutiya type feel ho rha bhai, yhi kaam 2 saal pehle kr leta, toh aaj kuch aur phod rha hota, but nvm, phodenge aaj nhi toh kl */

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int arr[5] = {1,2,3,2,1};
    int ans = 0;
    for(int i = 0; i < 5; i++)
    {
        ans ^= arr[i];
    }

    cout << ans << endl;
}