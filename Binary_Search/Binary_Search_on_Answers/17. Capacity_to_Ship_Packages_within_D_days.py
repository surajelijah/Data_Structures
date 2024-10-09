# URL - https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/


class Solution:
    def shipWithinDays(self, weights: List[int], days: int) -> int:
        
        def possible(luggage,mid):

            d=1 # these are the days that will take by using the mid capacity
            n=len(luggage)
            i=0
            s=0
            while(i<n): # Like this while ( Why because see the if condition, there we see that before adding the element and checking, we check and then add it to the sum and then if the condition breaks we update and add the current element, Nice loop )
                if((s + luggage[i]) > mid):
                    d+=1
                    s=luggage[i]    
                else:
                    s+=luggage[i]
                i+=1
            
            return d
                
        low=max(weights)
        high=sum(weights)
        ans=0

        while(low<=high):

            mid= low + (high-low)//2
            
            checked_value=possible(weights,mid)

            if(checked_value<=days):
                ans=mid
                high=mid-1
            else:
                low=mid+1

        return ans

        