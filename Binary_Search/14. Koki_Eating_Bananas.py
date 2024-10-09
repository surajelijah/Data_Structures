# URL - https://leetcode.com/problems/koko-eating-bananas/



'''

    How did I realize that here Binary Search can be applied

    - Now when I saw this problem, it said we have to complete all bananas and we are given the hours

    - And since we are asked the minimum rate, I thought let me start with the minimum value in the array

    - Now 
        - With k= minimum value in array
        - Check how many hours will it take to eat all bananas
        - if that sum is < h , then we have our minimum k
        - else increase the k i.e k++ and repeat

    - Now if you the above is linear time

    - And also we are searching in the search space of [minarray value, k] which is sorted

    - So here since our search space is sorted we use binary search, [1,maxarrayvalue] and check the sum
      of hours in the array and reduce it to Binary Search

    - Here the main clue is that the search space is sorted and we are removing the higher terms and iteratring
      on the other half


'''

class Solution:
    def minEatingSpeed(self, piles: List[int], h: int) -> int:

        low=1
        high=max(piles)
        ans=0


        while(low<=high):

            mid = low + (high-low)//2

            check_val = sum([math.ceil(i/mid) for i in piles])

            if(check_val<=h):
                ans=mid
                high=mid-1
            else:
                low=mid+1
        return ans
