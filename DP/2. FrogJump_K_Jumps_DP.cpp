//URL - https://www.geeksforgeeks.org/problems/minimal-cost/1



//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  
  
    int minEnergyMemoiz(vector<int>& height, int ind,vector<int>& dp,int k){
        
        if(ind<=0){
            return 0;
        }
        //Base cases are same
        
        if(dp[ind]!=-1)
            return dp[ind];
            
        //Memoization check
        int mini =INT_MAX;
        for(int i=1;i<=k;i++){
            if(ind-i>=0)
                mini=min(mini,abs(height[ind]-height[ind-i]) +  minEnergyMemoiz(height,ind-i,dp,k));
        }
        //Recrusion calls are same
        return dp[ind]=mini; // Store the result of new subproblem and return
    }
    
    
    int minimumEnergyDP(vector<int>& height, int n,vector<int>& dp,int k){
        
        dp[0]=0;
        // These are the base cases from recursion
        
        for(int ind=1;ind<n;ind++){
            
                //if you observer properly whatever is written in the recursive memoization we get here and modify it
            
                int mini =INT_MAX;
                
                for(int i=1;i<=k;i++){
                    if(ind-i>=0)
                        mini=min(mini,abs(height[ind]-height[ind-i]) +  minEnergyMemoiz(height,ind-i,dp,k));
                }
                
                dp[ind]=mini;
                // Till here is the recursive modification
                
        } // This the DP Tabulation method, wherever there is recursive function call there we put the dp call
        return dp[n-1];
    }
    
    
    
    int minimizeCost(int k, vector<int>& arr) {
        // Code here
        int n=arr.size();
        vector<int> dp(n+1,-1);
        
        return minimumEnergyDP(arr,n,dp,k);
        //return minEnergyMemoiz(arr,n-1,dp,k);
    }
};

//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        int res = obj.minimizeCost(k, arr);
        cout << res << endl;
        // string tl;
        // getline(cin, tl);
    }
    return 0;
}

// } Driver Code Ends



