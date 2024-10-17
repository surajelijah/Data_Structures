/*

https://www.youtube.com/watch?v=9kdHxplyl5I&list=PLgUwDviBIf0q7vrFA_HEWcqRqMpCXzYAL
https://www.youtube.com/watch?v=EHCGAZBbB88&list=PL_z_8CaSLPWeM8BDJmIYDaoQ5zuwyxnfj



*/


/* Now in Sliding Window Questions, we have two types


    - Fixed Sliding Window - Here the Size of the window is given and we have to return something based
                             the given condition

                            - Find the maximum sum subarray of size=3
                                - If you observe the window size is fixed which is 3
                                - And the condition here is that we have to return the maximum among all 
                                  the subarrays that are of size=3


    - Varibale Sliding Window - Here we have to find the size of the subarray such that a given condition
                                satisfied

                              - Find the maximum size subarray such that the sum <= K
                                - If you observe, here we need the size 
                                - And the condition given is sum<=k 


         - In this we either expand the window or shrink the window as per the case and return accordingly




 - Usually in such questions are asked on arrays or strings ,where we are asked to find a subarray or substring
   where we are asekd to give the longest or maximum or some condition to satisfy and window size = k

   This window size sometimes they give ( fixed window ) and sometimes we are asked to give the window size
   that satisfies the condition (variable window)



   Constant Window - Find maximum sum subarray of size = 3
   Varaible Window - Find the maximum size subarray of sum = k 

*/


// Maximum Sum Subarray of Size k 
// In this we have to fin the maximum sum subarray of size k

/* Brute Force  - From all the subarrays calculate the sum of each subarary and among them find the max


    for(int i=0;i<=n-k;i++){
        sum=0;
        for(j=i;j<k;j++){ // Here the (j-i+1) is the window size, so we calculate sum till the windows size <=k
            sum+=arr[i+j];
        }
        maxsum=max(max,sum);
    }
     - O(n^2) - You can write the condtions for the loops in different manner but main thing is we are
                calculating and moving the fixed size window

*/

// Optimal pattern for the Constant Window Problems

/*

    - We have a start index  - i
    - We have a end indexx - j

    - Here the (j-i+1) - is the Window size

    - So we keep on adding elements ( adding because according to this problem we have to add ) until
      (j-i+1) < k , meaning until we hit the window size we add the elements

    - Once we hit the window size (j-i+1)=k, we do some processing, and also calculate the answer

    - We stop this process when j<n - n is the size of the array

*/

// Window size =k ,now we process and move the window

class Solution{   
public:
    long maximumSumSubarray(int K, vector<int> &Arr , int N){
        // code here 
        
        long sum=0,maxsum=0;
        int i=0,j=0;
        
        
        
        while(j<N){
            
            sum+=Arr[j]; // We add the element into the window
        
            if( (j-i+1) < K) // Window size < k, increase the window size 
                j++;
            else if( (j-i+1) == K ){ // Window size =k ,now we process and move the window
                
                maxsum = max(maxsum,sum); // Answer is updated as we reached the window size, we process that window
                
                sum-=Arr[i]; // we remove the left index element from the window
                
                i++; //Move the start of the window
                j++; // Move the end of the window
            }
        }
        return maxsum;

    }
};





















