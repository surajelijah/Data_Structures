// URL - https://www.geeksforgeeks.org/problems/row-with-max-1s0023/1


//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
    
    
  private:
    
    int lower_bound_index(vector<int> v,int cols,int target){
        
        
        int low=0;
        int high=cols-1;
        
        int ans=cols;
        
        int mid;
        while(low<=high){
            
            mid = low + (high-low)/2;
            
            if(v[mid]>=target){
                ans= mid;
                high=mid-1;
            }
            else
                low=mid+1;
        }
        
        return ans;
    }
  
  public:
    int rowWithMax1s(vector<vector<int> > &arr) {
        // code here
        
        int m=arr.size();
        int n=arr[0].size();
        
        int ans_row=-1;
        int max_count_ones=0;
        
        for(int i=0;i<m;i++){
            
            //Count the number of ones in each row,since it is sorted apply binary search
            
            int countones = n - lower_bound_index(arr[i],n,1);
            
            if(countones> max_count_ones){
                max_count_ones=countones;
                ans_row=i;
            }
        }
        return ans_row;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int> > arr(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> arr[i][j];
            }
        }
        Solution ob;
        auto ans = ob.rowWithMax1s(arr);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends