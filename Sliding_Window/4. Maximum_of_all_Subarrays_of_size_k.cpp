// URL - https://www.interviewbit.com/problems/sliding-window-maximum/
// https://www.youtube.com/watch?v=xFJXtB5vSmM&list=PL_z_8CaSLPWeM8BDJmIYDaoQ5zuwyxnfj&index=6




/*

 Here the window size is fixed

 - And we need to give the maximum from the subarrays of size k

 - This is similar to the first negative element but here we need to track the maximum, which can be anywhere
   in the subarray,so here also we use the same queue data structure because we need to have the maximum of the subarray
   when we remove the previous maximum and slide the window.

 - Similar to the 2 Problem in this list
*/