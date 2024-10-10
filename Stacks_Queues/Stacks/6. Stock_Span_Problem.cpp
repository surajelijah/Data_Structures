// URL - https://www.geeksforgeeks.org/problems/stock-span-problem-1587115621/1


/*

https://www.youtube.com/watch?v=p9T-fE1g1pU&list=PL_z_8CaSLPWdeOezg68SKkeLN4-T_jNHd&index=6


Now brute force is to go from behind and for every element traverse back and count how many are
less than the current

Here j is dependant on i , so we have think of the possibility of Stacks


Now as per the requirement, we need to return for every element, how many consecutive prices are there
BEFORE IT AND LESS THAN THE CURRENT VALUE

Now what is it that we have to do get this count,

So we can use the Next Greater element to the left, because once we find that, it means whatever elements

that are there in between the Next greater element and the current element are technically less than the

current element.

So we use the same concept of Next Greater Element and calculate the count of the elements which are less
than the current element.



Now say the i/p

a =  0   1  2  3  4  5  6  - indices
    100 80 60 70 60 75 85  - values

    -1  100 80 80 70 80 100 - Next greater element on the left
b = -1   0   1  1  3  1  0  - Indices of the next greater element on the left

Now we perform the (a-b) - This gives us the count of the elements that are less than or equal to the current value 

a-b = 1 1 1 2 1 4 6 

This is the answer ( Nice question where we use the above concept of Next Greater Element)

Hints - Number of Consecutive Smaller elements on the left FOR EACH element 

*/



//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution
{
    public:
    //Function to calculate the span of stockâ€™s price for all n days.
    vector <int> calculateSpan(int arr[], int n)
    {
       // Your code here
       
        vector<int> v;
        stack<pair<int,int>> st;        
        
        if(n==1){
            v.push_back(1); //Here I include the first element
        }
        
        int i=1;
        v.push_back(-1); // Pushed answer for first element
        st.push({arr[0],0}); // Pushed the first element and its index as a pair into the stack 
        
        while(i<n){
            
            if(st.top().first>arr[i]){
                v.push_back(st.top().second); // Adding the index so that it is easy calculate the difference
                st.push({arr[i],i});
            }
            else{
                while(!st.empty() && st.top().first<=arr[i]){
                    st.pop();
                }
                if(st.empty()){
                    v.push_back(-1);
                }
                else{
                    v.push_back(st.top().second);
                }
                st.push({arr[i],i});            
            }
            i++;
        }
        
        for(int i=0;i<n;i++){
            v[i]=i-v[i];
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
		int i,a[n];
		for(i=0;i<n;i++)
		{
			cin>>a[i];
		}
		Solution obj;
		vector <int> s = obj.calculateSpan(a, n);
		
		for(i=0;i<n;i++)
		{
			cout<<s[i]<<" ";
		}
		cout<<endl;
	}
	return 0;
}

// } Driver Code Ends

