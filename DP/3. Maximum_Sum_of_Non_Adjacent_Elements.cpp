// URL - https://www.naukri.com/code360/problems/maximum-sum-of-non-adjacent-elements_843261


// This is basically the maximum sum of subsequence where elements are not adjacent

#include <bits/stdc++.h> 
int maximumNonAdjacentSum(vector<int> &nums){
    // Write your code here.

    int n=nums.size();

    if(n==0)
        return nums[0];

    vector<int> dp(n,-1);
    dp[0]=nums[0];
    dp[1]=max(nums[0],nums[1]);

    for(int i=2;i<n;i++){
        dp[i]=max((nums[i]+dp[i-2]),dp[i-1]); // Directly wrote this after writing the recursion on Paper
    }
    return dp[n-1];
}