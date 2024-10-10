/*
This is similar question to the Nearest Element to the Right, but with some changes

Since we need to the left, we start from the left and do the same process as in the Nearest Greater to the Right


*/

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find the next greater element for each element of the array.
    vector<long long> nextLargerElement(vector<long long> arr, int n){
        // Your code here
        
        vector<long long> v;
        stack<long long> st;        
        n=arr.size();
        
        if(n==1){
            v.push_back(-1);
        }
        
        int i=1;
        v.push_back(-1); // Pushed answer for first element
        st.push(arr[0]); // Pushed the first element into the stack 
        
        while(i<n){
            
            if(st.top()>arr[i]){
                v.push_back(st.top());
                st.push(arr[i]);
            }
            else{
                while(!st.empty() && st.top()<=arr[i]){
                    st.pop();
                }
                if(st.empty()){
                    v.push_back(-1);
                }
                else{
                    v.push_back(st.top());
                }
                st.push(arr[i]);            
            }
            i++;
        }

        return v; // Need not reverse
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        
        int n;
        cin>>n;
        vector<long long> arr(n);
        for(int i=0;i<n;i++)
            cin>>arr[i];
        
        Solution obj;
        vector <long long> res = obj.nextLargerElement(arr, n);
        for (long long i : res) cout << i << " ";
        cout<<endl;
    }
	return 0;
}