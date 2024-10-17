// URL - https://leetcode.com/problems/max-consecutive-ones-iii/


/*

    Idea is to within the window count the number of 1's and 0's, when the condition is reached we know that we can convert those into the 1's so we take that window as max

*/

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        
        int n= nums.size();

        int i=0,j=0;

        int count_ones=0,count_zeroes=0,ans=0;

        if(nums[0]==1)
            count_ones++;
        else
            count_zeroes++;


        while(j<n){

            while(i<=j && count_zeroes > k){
                if(nums[i]==1)
                    count_ones--;
                else
                    count_zeroes--;

                i++;
            }

            if(count_zeroes<=k){
                ans=max(ans,(j-i+1));
            }

            j++;
            if(j<n){

                if(nums[j]==1)
                    count_ones++;
                else
                    count_zeroes++;
            }
        }
        return ans;
    }
};