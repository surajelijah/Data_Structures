//URL - https://leetcode.com/problems/single-element-in-a-sorted-array/description/

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n=nums.size();

        if(n==1)
            return nums[0];
        int ans=nums[0];
        for(int i=1;i<n;i++)
            ans^=nums[i];
        return ans;
    }
};


// Following is the O(log(n)) approach
// Watch the video - Very Nice observation

