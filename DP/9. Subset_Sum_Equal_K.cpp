//URL - https://www.geeksforgeeks.org/problems/subset-sum-problem-1611555638/1


//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
  
    bool isSubsetSumRec(vector<int>& arr,int target, int sum,int ind,int n){
        
        if(ind<n && target>sum)
            return false;
            
        if(ind==n){
            if(sum==target){
                return true;
            }
            else
                return false;
        }
        
        if(isSubsetSumRec(arr,target+arr[ind],sum,ind+1,n))
            return true;
        
        if(isSubsetSumRec(arr,target,sum,ind+1,n))
            return true;
        
        return false;
    }
    
    
    bool isSubsetSumDP(vector<int> arr, int sum,int n){
        
        vector<vector<bool>> dp(n,vector<bool>(sum+1,false));
        
        //base cases
        
        for(int i=0;i<n;i++)
            dp[i][0] = true; // Because a sum of 0 is always possible from null set
        
        // Filling the first row
        
        for(int i=1;i<=sum;i++){
            if((arr[0]-i)==0)
                dp[0][i]=true;
            else
                dp[0][i]=false;
        }
        
        for(int i=1;i<n;i++){
            for(int j=1;j<=sum;j++){
                
                if(dp[i-1][j]){
                    dp[i][j]=true; // If there was a subset that was possible before
                    continue;
                }
                // Now include this add this to the subset
                int t= j-arr[i];
                
                if(t<0)
                    dp[i][j]=false;
                else{
                    
                    if(dp[i-1][t]) // Here I check if I am able to form t till using i-1 ind
                        dp[i][j]=true;
                    else
                        dp[i][j]=false;
                }
            }
        }
        
        /*for(int i=0;i<n;i++){
            for(int j=0;j<=sum;j++){
                cout<<dp[i][j]<<" ";
            }
            cout<<"\n";
        }*/
        
        
        return dp[n-1][sum];
        
    }
  
    bool isSubsetSum(vector<int> arr, int sum) {
        // code here
        int n=arr.size();
        
        return isSubsetSumDP(arr,sum,n);
        //return isSubsetSumRec(arr,0,sum,0,n);
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int sum;
        cin >> sum;
        cin.ignore();

        Solution ob;
        if (ob.isSubsetSum(arr, sum))
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }
    return 0;
}

// } Driver Code Ends