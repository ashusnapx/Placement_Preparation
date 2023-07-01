#include <bits/stdc++.h>
int findKRotation(vector<int> &arr){
   int low = 0, high = arr.size() - 1, ans = INT_MAX, ans_index = -1, mid;

   while(low <= high)
   {
       mid = (low + high) / 2;
        if(arr[low] <= arr[high])
        {
            if(arr[low] < ans)
            {
                ans_index = low;
                ans = arr[low];
            }
            // ans = min(ans, arr[low]);
            break;
        }

       //sorted
       if(arr[low] <= arr[mid])
       {
           if(arr[low] <= ans)
           {
               ans = arr[low];
               ans_index = low;
           }
        //    ans = min(ans, arr[low]);
           low = mid + 1;
       }
       else
       {
           if(arr[mid] < ans)
           {
               ans = arr[mid];
               ans_index = mid;
           }
        //    ans = min(ans, arr[mid]);
           high = mid - 1;
       }
   }

   return ans_index;
}