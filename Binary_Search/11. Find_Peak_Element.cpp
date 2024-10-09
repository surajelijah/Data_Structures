// URL - https://leetcode.com/problems/find-peak-element/


class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        
        // You can wrtie a O(n) code for this basically by
        // comparing the if arr[i-1]< arr[i] > arr[i+1], in a linear way and return i 

        // But we thought of Binary Search because there is a tendency of two halves being sorted and we can make the search O(logn)

        int n=nums.size();

        if(n==1)
            return 0;

        // Writing the case for the first element

            if(nums[0]>nums[1])
                return 0;
        // Writing the case for the last element

            if(nums[n-1]>nums[n-2])
                return n-1;

        // Now that we have written code for the edge cases we can start the code

        int low =1;
        int high=n-2;
        int mid;

        while(low<=high){

            mid=low + (high - low )/2;

            if(nums[mid-1]<=nums[mid] && nums[mid]>=nums[mid+1]){ // Check if mid is peak element
                return mid;
            } 
            if(nums[mid-1]<nums[mid]) // Because mid is on the increasing sorted order the peak would be on the right
                low=mid+1;
            else if(nums[mid]>nums[mid+1])// Because mid is on the decreasing sorted order the peak would be on the left
                high=mid-1;
            else // This is at the case where the mid is on the down point of the 'V', in this case you can either go to your righ or left
                low=mid+1; // you can write high = mid-1 too here
        }
        return -1;
    }
};