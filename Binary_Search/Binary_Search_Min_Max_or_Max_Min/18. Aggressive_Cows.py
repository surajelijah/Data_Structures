# URL - https://www.spoj.com/problems/AGGRCOW/


# Video is a must watch 

def aggressiveCows(stalls, k):
    # Write your code here.


    def possible(sheds,k,mid):

        #mid here the min distance maitained among the cows

        cows=1
        last_placed=sheds[0]

        n=len(sheds)

        for i in range(n):
            if((sheds[i]-last_placed)>=mid):
                cows+=1
                last_placed=sheds[i]

        return cows>=k

    stalls.sort()
    n=len(stalls)

    low=1
    high=stalls[n-1]- stalls[0] #This is the answer search space, the max distance that can be between two cows 

    ans=0

    while(low<=high):

        mid = low+(high-low)//2

        checked_value=possible(stalls,k,mid)

        if(checked_value):
            ans=mid
            low=mid+1 # Beacuas you want the max among the values that satiesfies the condition so going to the right half
        else:
            high=mid-1

    return ans
