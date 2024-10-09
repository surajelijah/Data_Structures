// URL - https://www.geeksforgeeks.org/problems/square-root/

// Watch the video, the idea here is Nice 

// Like if there is a solution where we are trying to switch from a particular sorted half then we usually
// use Binary Search


//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// Function to find square root
// x: element to find square root
class Solution {
  public:
    long long int floorSqrt(long long int n) {
        // Your code goes here
        
        
        long long low=1;
        long long high=n;
        
        long long mid,ans=1;
        
        while(low<=high){
            mid = low + (high - low)/2;
            
            if((mid*mid)<=n){
                ans=mid;
                low=mid+1;
            }
            else
                high=mid-1;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        Solution obj;
        cout << obj.floorSqrt(n) << endl;
    }
    return 0;
}

// } Driver Code Ends