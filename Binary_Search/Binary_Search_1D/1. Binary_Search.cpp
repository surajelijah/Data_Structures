//URL - https://leetcode.com/problems/binary-search/description/


class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        int a=0,mid;
        int b=nums.size()-1;

        while(a<=b){
            mid=a+(b-a)/2;

            if(nums[mid]<target){
                a=mid+1;
            }
            else if(nums[mid]>target)
                b=mid-1;
            else
                return mid;
        }
        return -1;
    }

    /*

    int bs_recursive(vector<int>& v,int target,int low,int high){

        if(low>high)
            return -1;

        mid= low + (high-low)/2;

        if(v[mid]==target)
            return 1;

        if(target> v[mid])
            return bs_recursive(v,target,mid+1,high);
        else
            return bs_recursive(v,target,low,mid-1);

        return -1;
    }

    // Call

        low=0;
        high=v.size()-1;

        bs_recursive(v,target,low,high);
        
    */



};