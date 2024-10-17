/*


 In these Varaible sized questions , we are not given the window but we are given a condition based on
 which we have to either find the maximimum or minimum subarray ( Unlike Fixed Window questions where we
 have the window size and we have to find the maximum or minimum based on the requirement within the fixed
 window )

Let's see the question where - Find the Largest Size Subarray where sum==k





Here in this 


i=0 //start of window
j=0 //end of window

while(j<n){

    //Calculations

    sum+=arr[j];
    if(sum<k){
        j++; // Expand the window size
    }
    else if(sum==k){
        Update the size of subaarray

        ans=max(ans,(j-i+1)) // (j-i+1) is the Window size

        j++;
    }
    else if(sum>k){

        //Shrink the window size until sum<=k

        while(sum>k){

            sum-=arr[i] //Remove calculation for i
            i++;
        }
        j++;
    }

}

The above is the General Template

*/


// The following is sort of the generic pattern but in this code, it only works for +ve elements

int longestSubarrayWithSumK(vector<int> a, long long k) {
    // Write your code here

    int ans=0;

    int n=a.size();
    long long sum;
    int i=0,j=0;

    sum=a[0];

    while(j<n){
      
      while(i<=j && sum>k){ // i to j is the window, so it should not cross
        sum-=a[i];
        i++;
      }//Shrinking the window till the condition is true

      if(sum==k){
        ans= max(ans,(j-i+1));
      } // if the condition satisfied then process the window

      j++; // Why doing it before because we have initialized the sum to first element and also it is clear that we want to add the next element

      if(j<n) // Have to check the boundary condition, because we are incrementing and adding
        sum+=a[j];
    }
    return ans;
}


// Hashing and Prefix method works for +ve and -ve elements

// https://takeuforward.org/data-structure/longest-subarray-with-given-sum-k/
// https://takeuforward.org/arrays/longest-subarray-with-sum-k-postives-and-negatives/





#include <bits/stdc++.h>
using namespace std;

int getLongestSubarray(vector<int>& a, int k) {
    int n = a.size(); // size of the array.

    map<int, int> preSumMap;
    int sum = 0;
    int maxLen = 0;
    for (int i = 0; i < n; i++) {
        //calculate the prefix sum till index i:
        sum += a[i];

        // if the sum = k, update the maxLen:
        if (sum == k) {
            maxLen = max(maxLen, i + 1);
        }

        // calculate the sum of remaining part i.e. x-k:
        int rem = sum - k;

        //Calculate the length and update maxLen:
        if (preSumMap.find(rem) != preSumMap.end()) {
            int len = i - preSumMap[rem];
            maxLen = max(maxLen, len);
        }

        //Finally, update the map checking the conditions:
        if (preSumMap.find(sum) == preSumMap.end()) {
            preSumMap[sum] = i; // We want the first update, not the latest so if we have it in the map we do not update, why watch the video, this is and edge case when 0 are involved
        }
    }

    return maxLen;
}

int main()
{
    vector<int> a = { -1, 1, 1};
    int k = 1;
    int len = getLongestSubarray(a, k);
    cout << "The length of the longest subarray is: " << len << "\n";
    return 0;
}




