# URL - https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/


class Solution:
    def minDays(self, bloomDay: List[int], m: int, k: int) -> int:

        # Why I am doing Binary search is because the answer search space is sorted and linear

        def possible(flowers,mid,m,k): # mid is current number of days

            count=0
            consecutive=[]
            for i in flowers:
                if(i<=mid):
                    count+=1
                else:
                    consecutive.append(count)
                    count=0
            if(count!=0):
                consecutive.append(count)

            n=len(consecutive)
            bouquets_made=0
            i=0
            while(i<n):
                if(consecutive[i]>=k):
                    consecutive[i]-=k
                    bouquets_made+=1
                else:
                    i+=1

            return bouquets_made>=m

        low=1
        high=max(bloomDay)

        ans=-1

        while(low<=high):

            mid = low + (high-low)//2

            checked_value=possible(bloomDay,mid,m,k)

            if(checked_value):
                ans=mid
                high=mid-1
            else:
                low=mid+1


        return ans
        




        