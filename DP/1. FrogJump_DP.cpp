//URL - https://www.geeksforgeeks.org/problems/geek-jump/1



//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
    
    int minEnergyRec(vector<int>& height, int ind){
        
        if(ind<=0){
            return 0;
        }
        
        if(ind==1)
            return abs(height[ind]-height[ind-1]);
        
        int l = abs(height[ind]-height[ind-1]) +  minEnergyRec(height,ind-1);
        int r = abs(height[ind]-height[ind-2]) +  minEnergyRec(height,ind-2);
        
        return min(l,r);
    }
    
    int minEnergyMemoiz(vector<int>& height, int ind,vector<int>& dp){
        
        if(ind<=0){
            return 0;
        }
        
        if(ind==1)
            return abs(height[ind]-height[ind-1]);
            
        //Base cases are same
        
        if(dp[ind]!=-1)
            return dp[ind];
            
        //Memoization check        
            
        int l = abs(height[ind]-height[ind-1]) +  minEnergyMemoiz(height,ind-1,dp);
        int r = abs(height[ind]-height[ind-2]) +  minEnergyMemoiz(height,ind-2,dp);
        
        //Recrusion calls are same
        
        
        return dp[ind]=min(l,r); // Store the result of new subproblem and return
        
    }
    
    
    int minimumEnergyDP(vector<int>& height, int n,vector<int>& dp){
        
        dp[0]=0;
        dp[1]=abs(height[1]-height[0]); // These are the base cases from recursion
        
        for(int ind=2;ind<n;ind++){
            
            dp[ind]=min(abs(height[ind]-height[ind-1]) + dp[ind-1],abs(height[ind]-height[ind-2]) + dp[ind-2]);
            
        } // This the DP Tabulation method, wherever there is recursive function call there we put the dp call
        return dp[n-1];
    }
    
  public:
    int minimumEnergy(vector<int>& height, int n) {
        // Code here
        
        vector<int> dp(n+1,-1);
        
        return minimumEnergyDP(height,n,dp);
        
        //return minEnergyMemoiz(height,n-1,dp);
        
        //return minEnergyRec(height,n-1); // Starting from index n;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minimumEnergy(arr, N) << "\n";
    }
    return 0;
}
// } Driver Code Ends



