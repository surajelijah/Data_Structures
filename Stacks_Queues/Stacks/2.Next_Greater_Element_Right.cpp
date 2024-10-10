
// Next Greater Element or Nearest Greater Element to the right


/*

URL - https://www.geeksforgeeks.org/problems/next-larger-element-1587115620/1

For this what would be our approach initially

For every element, we look to it's right and pick the first element which is greater than the current
element and that would be our Nearest Greater to the right

vector<int> v;
for(int i=0;i<n;i++){
    for(int j=i+1;j<n;j++){
        if(arr[j]>arr[i]) // Found the next larger element on th right 
            v.push_back(arr[j]);
            break
    }
}
return v;

If you observe the time complexity is O(n^2)


How can we reduce it, if you NOTICE, the inner loop is dependant on the outer loop that is j is dependant
on i

So we can expect to use stack and reduce the Time Complexity

*/



/*


Now here we use the stack

Now since we need the next larger element to the right, we start from the right end and move towards the left

We compare the element with the top of the stack

if(top >= current ) - push the current element - because we want the nearest greater

if(top< current) - pop all the element until (top >= current) - then use the top and push the current

*/


//{ Driver Code Starts
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
        
        int i=n-2;
        v.push_back(-1); // Pushed answer for last element
        st.push(arr[n-1]); // Pushed the last element into the stack 
        
        while(i>=0){
            
            if(st.top()>arr[i]){ // Top is greater than the largest
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
            i--;
        }
        reverse(v.begin(),v.end());
        return v;
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












