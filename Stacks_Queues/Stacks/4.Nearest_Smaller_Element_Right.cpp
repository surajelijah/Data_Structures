/*

Here also the idea is similar, but with some changes in the condition as we need the smaller element rather
than the larger one


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
        
        int i=n-2;
        v.push_back(-1); // Pushed answer for last element
        st.push(arr[n-1]); // Pushed the last element into the stack 
        
        while(i>=0){
            
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