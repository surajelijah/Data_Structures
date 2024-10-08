class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {

        int n=nums.size();        
        int low=0;
        int high=n-1;
        int mid=0;

        vector<int> v;

        bool present=false;
        while(low<=high){
            
            mid= low + (high - low)/2;
            if(nums[mid]==target){
                present=true;
                break;
            }
            else if(nums[mid]>=target)
                high=mid-1;
            else
                low=mid+1;
        }

        if(n==0 || target<nums[0] || target>nums[n-1] || !present ) {
            v.push_back(-1);
            v.push_back(-1);
            return v;
        }

        

        low=0;
        high=n-1;
        mid=0;

        while(low<=high){
            mid = low + (high - low)/2;

            if(nums[mid]>=target)
                high=mid-1;
            else
                low=mid+1;
        }

        v.push_back(low);

        low=0;
        high=n-1;
        mid=0;
        while(low<=high){
            mid = low + (high - low)/2;

            if(nums[mid]>target)
                high=mid-1;
            else
                low=mid+1;
        }

        v.push_back(low-1);

        return v;

        /*

            The above code to find 
            the first occurence it is the lowerbound code
            the last occurence it is the upperbound code
            
        */
    }
};