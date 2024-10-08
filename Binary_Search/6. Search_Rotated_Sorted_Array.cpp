// URL - https://leetcode.com/problems/search-in-rotated-sorted-array/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        

        int n=nums.size();

        if(n==1 && target!=nums[0])
            return -1;
        
        if(n==1 && target==nums[0])
            return 0;

        int low=0;
        int high=n-1;
        int mid;

        while(low<=high){

            //Find which side is sorted
            mid = low + (high-low)/2;
            
            if(nums[mid]==target)
                return mid;
            
            if(nums[low]<=nums[mid]){ // This means the left half is sorted
                if(nums[low]<=target && target<=nums[mid]) // Here we check if the target is in the sorted part or not
                    high=mid-1;
                else
                    low=mid+1;
            }
            else{ // The right half is sorted
                if(nums[mid]<=target && target<=nums[high]) // Here we check if the target is in the sorted part or not
                    low=mid+1;
                else
                    high=mid-1;
            }       
    }
    return -1;
    }
};