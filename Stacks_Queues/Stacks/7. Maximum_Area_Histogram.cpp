/*

URL - https://www.geeksforgeeks.org/problems/maximum-rectangular-area-in-a-histogram-1587115620/1

This is the Problem where we have to find the Maximum Area in a histogram


Brute Force Approach is to go through all possible histogram form the possible rectangle and choose
the max among them

        n=len(histogram)
        if(n==1):
            return histogram[0]
        i=0
        j=0
        ans=-1
        
        while(i<n):
            j=i+1
            while(j<n):
                ans = max(ans, (j-i+1) * min(histogram[i:j+1]))
                j+=1
            i+=1
        
        return ans

    If you observer we have j  dependant on i


So now think about how to use stacks to optimize

If you observe we are finding the min every time, so use this and try to see if we can use anything


Standing at every building we try to expand on both ends, to increse the width,

So we find the NSL and NSR indexes and max( (NSL- NSR - 1) * height)

https://www.youtube.com/watch?v=J2X70jj_I1o&list=PL_z_8CaSLPWdeOezg68SKkeLN4-T_jNHd&index=7


    - right [] = NSR 
    - lefft [] = NSL
    - width = (right[i]-left[i]-1)
    - area = hist[i] * width[i]
 
    return the max area

*/


