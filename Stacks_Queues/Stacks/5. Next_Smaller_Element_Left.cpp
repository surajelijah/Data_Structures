/*

This is similar to the other questions, as asked from left we, traverse from the left and make some changes
to the Nearest Smaller Element on the right.

*/


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
        st.push(arr[0]); // Pushed the last first into the stack 
        
        while(i<n){
            
            if(st.top() < arr[i]){ // Top is lesser than the current, this is the change that is made
                v.push_back(st.top());
                st.push(arr[i]);
            }
            else{
                while(!st.empty() && st.top()>=arr[i]){ // Change made here
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
        // Need not reverse
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