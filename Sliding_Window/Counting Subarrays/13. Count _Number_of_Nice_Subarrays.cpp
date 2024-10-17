//URL - https://leetcode.com/problems/count-number-of-nice-subarrays/

// In these == questions, you never know when to shrink the subarray, so we go to incorporate a solution
// where we can use the sliding window properly like shrinking and all


/*

This is similar to the Binary sum question , it is just that here

    Subarrys where oddcount <=k - Subarrays where oddcount <= k-1, that's all.


*/


class Solution {
public:

    int support_func(vector<int>& nums, int k){

        if(k<0)
            return 0;

        int n=nums.size();

        int i=0,j=0;

        int ans =0;

        int odd_count=0;


        if(nums[0]&1)
            odd_count++; // Added first element and updated

        while(j<n){

            while(i<=j && odd_count>k){
                if(nums[i]&1)
                    odd_count--;
                i++;
            }

            if(odd_count<=k)
                ans+=(j-i+1);

            j++;
            if(j<n){
                if(nums[j]&1)
                    odd_count++;
            }

        }

        return ans;
    }

    int numberOfSubarrays(vector<int>& nums, int k) {
        
        return support_func(nums,k) - support_func(nums,k-1);
    }
};