// URL - https://www.geeksforgeeks.org/problems/geeks-training/1


//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {

  public:
    
    // Here the recursion has two variables for each day, so we have day index as varibale and also what activity has been performed last also needs to be sent in the recursion
    // we have two varibles and hence we have a 2D DP array
    
    /*
    
    Compared to 1D DP - There at every index we had nothing to chose from rather than chosing that index and using it's value
    and moving to the next index as required, even though we have muliple options to chose here, all of them affected the index only, so we needed only
    on varible.
    
    But her in this - We have at every index multiple options to choose from, meaning we have a seperate varibale that is needed in the recursion,
    hence we needed 2D array.
    
    
    
    */
    
   int mPointsRec(vector<vector<int>>& arr, int n,int ind,int lastact){
       
       if(ind<0)
            return 0;
       if(ind==0){
           int maxi=INT_MIN;
           
           // When we reach day 0,we return the max among performing between the three tasks
       
           for(int i=0;i<=2;i++){
               if(i!=lastact)
                maxi=max(maxi,arr[0][i]);
           }
           return maxi;
       }
        
       int maxi=INT_MIN;
       
       for(int i=0;i<=2;i++){ // Pick any activity on a particular day and notify the next day it has performed it and make sure the days are not consecutive
            
            if(i!=lastact){
                
                int l = arr[ind][i] + mPointsRec(arr,n,ind-1,i);
                maxi=max(maxi,l);
            }
       }
       return maxi;
   }
   
   
   int mPointsMemoize(vector<vector<int>>& arr, int n,int ind,int lastact,vector<vector<int>>& dp){
       
       if(ind<0)
            return 0;
       if(ind==0){
           int maxi=INT_MIN;
           
           // When we reach day 0,we return the max among performing between the three tasks
       
           for(int i=0;i<=2;i++){
               if(i!=lastact)
                maxi=max(maxi,arr[0][i]);
           }
           return dp[ind][lastact]=maxi;
       }
       
       if(dp[ind][lastact]!=-1)
        return dp[ind][lastact];
        
       int maxi=INT_MIN;
       
       for(int i=0;i<=2;i++){ // Pick any activity on a particular day and notify the next day it has performed it and make sure the days are not consecutive
            
            if(i!=lastact){
                
                int points = arr[ind][i] + mPointsMemoize(arr,n,ind-1,i,dp);
                maxi=max(maxi,points);
            }
       }
       return dp[ind][lastact]=maxi;
   } 
   
   int mPointsDP(vector<vector<int>>& arr, int n,int ind,int lastact,vector<vector<int>>& dp){
       
       
       dp[0][0] = max(arr[0][1],arr[0][2]);
       dp[0][1] = max(arr[0][2],arr[0][3]);
       dp[0][2] = max(arr[0][1],arr[0][3]);
       dp[0][3] = max(max(arr[0][1],arr[0][2]),arr[0][1]);
       
       //We have two variable so we are iterating in 2D array and then place the recursion part in that
       for(int ind=1;ind<n;ind++){
           for(int lastact=0;lastact<=3;lastact++){
               
               int maxi=INT_MIN;
       
                for(int i=0;i<=2;i++){ // Pick any activity on a particular day and notify the next day it has performed it and make sure the days are not consecutive
            
                    if(i!=lastact){
                        int points = arr[ind][i] + dp[ind-1][i];
                        maxi=max(maxi,points);
                    }
                }
                dp[ind][lastact]=maxi;
           }
       }
       return dp[n-1][3];
   }
   
  
    int maximumPoints(vector<vector<int>>& arr, int n) {
        // Code here
        
        vector<vector<int>> dp(n,vector<int>(4,0));
        
        return mPointsDP(arr,n,n-1,3,dp);
        //return mPointsMemoize(arr,n,n-1,3,dp);
        
        //return mPointsRec(arr,n,n-1,3); // We start with 3 measn none of the act has been yet chosen and we can chose anything
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> arr;
        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            arr.push_back(temp);
        }

        Solution obj;
        cout << obj.maximumPoints(arr, n) << endl;
    }
    return 0;
}
// } Driver Code Ends