// URL - https://leetcode.com/problems/minimum-falling-path-sum/



class Solution {
public:

    int minFallingPathSumRec(vector<vector<int>>& matrix,int rowind,int colind,int m,int n){

        if(colind < 0 || colind>=n)
            return 1e8;
        if(rowind==m-1)
            return matrix[rowind][colind];

        int left = matrix[rowind][colind] + minFallingPathSumRec(matrix,rowind+1,colind-1,m,n);
        int down= matrix[rowind][colind] + minFallingPathSumRec(matrix,rowind+1,colind,m,n);
        int right = matrix[rowind][colind] + minFallingPathSumRec(matrix,rowind+1,colind+1,m,n);

        return min(left,min(right,down)); 
    }

    int minFallingPathMemoize(vector<vector<int>>& matrix,int rowind,int colind,int m,int n,vector<vector<int>>& dp){

        if(colind < 0 || colind>=n)
            return 1e8;
        if(rowind==m-1)
            return dp[rowind][colind]=matrix[rowind][colind];

        if(dp[rowind][colind]!=-1)
            return dp[rowind][colind];

        int left = matrix[rowind][colind] + minFallingPathMemoize(matrix,rowind+1,colind-1,m,n,dp);
        int down= matrix[rowind][colind] + minFallingPathMemoize(matrix,rowind+1,colind,m,n,dp);
        int right = matrix[rowind][colind] + minFallingPathMemoize(matrix,rowind+1,colind+1,m,n,dp);

        return dp[rowind][colind]=min(left,min(right,down)); 
    }

    int minFallingPathDP(vector<vector<int>>& matrix,int rowind,int colind,int m,int n,vector<vector<int>>& dp){

        for(int i=0;i<n;i++){
            dp[m-1][i]=matrix[m-1][i];
        }// base case

        for(int rowind=m-2;rowind>=0;rowind--){
            int left,right,down;
            for(colind=n-1;colind>=0;colind--){

                if(colind-1>=0)
                    left = matrix[rowind][colind] + dp[rowind+1][colind-1];
                if(colind+1<n)
                    right = matrix[rowind][colind] + dp[rowind+1][colind+1];
                down = matrix[rowind][colind] + dp[rowind+1][colind+1];

                dp[rowind][colind]=min(left,min(right,down));
            }
        }
        return 0;
    }





    int minFallingPathSum(vector<vector<int>>& matrix) {

        int m=matrix.size();
        int n=matrix[0].size();

        vector<vector<int>> dp(m,vector<int>(n,-1));

        int mini =INT_MAX;
        for(int i=0;i<n;i++){
            //mini = min(mini,minFallingPathMemoize(matrix,0,i,m,n,dp));
            mini = min(mini,dp[0][i]);
        }
        return mini;
    }
};