// URL - https://www.geeksforgeeks.org/problems/find-nth-root-of-m5843/1


//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	int NthRoot(int n, int m)
	{
	    // Code here.
	    
	    
	    int low=1;
	    int high=m;
	    
	    int mid;
	    
	    while(low<=high){
	        
	        mid= low + (high - low)/2;
	        
	        double val=pow(mid,n); // use double to store the overflow multplication
	        
	        if(val== m){
	            return mid;
	        }
	        else if(val<m)
	            low = mid+1;
	        else{
	            high = mid - 1;
	        }
	    }
	    return -1;
	}  
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		Solution ob;
		int ans = ob.NthRoot(n, m);
		cout << ans << "\n";
	}  
	return 0;
}
// } Driver Code Ends