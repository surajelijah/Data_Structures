# URL - https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold/description/


class Solution:
    def smallestDivisor(self, nums: List[int], threshold: int) -> int:

        
        # Why Binary search beacause the answer search space is sorted and linear
        
        low=1
        high=max(nums)  
        ans=0
        while(low<=high):

            mid = low+ ( high- low)//2

            check_value = sum([math.ceil(i/mid) for i in nums])
            if(check_value<=threshold):
                ans=mid
                high=mid-1
            else:
                low=mid+1
        
        return ans




        