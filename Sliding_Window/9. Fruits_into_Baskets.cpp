// URL - https://www.geeksforgeeks.org/problems/fruit-into-baskets-1663137462/1



//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int totalFruits(vector<int> &s) {
    
    /*
    
        Now how did you identify, two baskets and unlimited, meaning the longest 
        
        
        This is similar to the Longest Subarray with K unique characters
        
        Here K=2, maximum number of fruits is the size of the longest window
    
    */
    int n=s.size(),k=2;
    int i=0,j=0;
    
    
    map<int,int> mp;
    
    int ans=1;
    mp[s[0]]=1; //Added the first element in the map
    
    while(j<n){
        
        while(i<=j && mp.size()>k){
            mp[s[i]]--;
            if(mp[s[i]]==0)
                mp.erase(s[i]);
            i++;
        }
        
        if(mp.size()==k)
            ans=max(ans, (j-i+1));
            
        j++;
        if(j<n){
            if(mp.find(s[j])!=mp.end()){
                mp[s[j]]++;
            }
            else{
                mp[s[j]]=1;
            }
        }
    }
    
    return ans;
    
    }
    
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // To ignore any newline character left in the buffer
    while (t--) {
        string line;
        getline(cin, line); // Read the entire line of input
        stringstream ss(line);
        vector<int> arr;
        int num;

        // Parse the input line into integers and add to the vector
        while (ss >> num) {
            arr.push_back(num);
        }
        Solution ob;
        int ans = ob.totalFruits(arr);

        cout << ans << endl;
    }
    return 0;
}

// } Driver Code Ends