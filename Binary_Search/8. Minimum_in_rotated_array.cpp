// URL - https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/

class Solution {
public:
    int findMin(vector<int>& nums) {

     int low=0;
     int high=nums.size()-1;
     int ans=INT_MAX;

     while(low<=high){

        int mid = low + (high-low)/2;

        if(nums[low]<=nums[mid]){ // Left half is sorted
            ans=min(ans,nums[low]); // Pick the min element
            low=mid+1;
        }
        else{
            ans=min(ans,nums[mid]);
            high= mid-1;
        }
     }
     return ans;
    }
};