// URL - https://leetcode.com/problems/binary-subarrays-with-sum/


/*

https://www.youtube.com/watch?v=XnMdNUkX6VM&list=PLgUwDviBIf0q7vrFA_HEWcqRqMpCXzYAL&index=9

This question can be solved using the Subarray with sum=k , where we used Hashing to be the optimal solution
for both +ve and -ve elements


Here we can use the same but, let's try something else


    Find the number of subarrays where sum<=k = (A) 
                         and 
    Find the number of subarrays where sum<=(k-1) = (B)

    A-B = gives the answer to Subarrays that are equal to k


*/

class Solution {
public:

    int support_func(vector<int>& v, int k){

        if(k<0)
            return 0;

        int n=v.size();

        int i=0,j=0;

        int ans=0;

        int sum=v[0];// Added first element

        while(j<n){

            while(i<=j && sum>k){
                sum-=v[i];
                i++;
            }

            if(sum<=k){
                ans+=(j-i+1); //The length = All the subarrays that can be formed with j as the end index and behind
            }

            j++;
            if(j<n){
                sum+=v[j];
            }
        }
        
        return ans;
    }

    int numSubarraysWithSum(vector<int>& nums, int goal) {
        
        return support_func(nums,goal) - support_func(nums,goal-1); 
        
    }
};

