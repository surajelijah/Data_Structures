// URL - https://leetcode.com/problems/unique-paths-ii/


class Solution {
public:

    int uniquePathsDP(vector<vector<int>>& grid,vector<vector<int>>& dp,int m,int n){

        // Now in the first row or first column i I see an obstacle after that we cannot have any way in that row or column;

        int k=0;
        while(k<m && grid[k][0]!=1){
            dp[k][0]=1;
            k++;
        }//Found the obstacle
        while(k<m){
            dp[k][0]=0;
            k++;
        }

        k=0;
        while(k<n && grid[0][k]!=1){
            dp[0][k]=1;
            k++;
        }//Found the obstacle
        while(k<n){
            dp[0][k]=0;
            k++;
        }
        
        // Base cases are done now incorporate the recursion

        for(int i =1;i<m;i++){
            for(int j=1;j<n;j++){

                if(grid[i][j]==1){
                    dp[i][j]=0;
                    continue;
                } // This means when you are at obstacle all the ways till this are nullified so 0
                
                int l = dp[i-1][j];
                int r = dp[i][j-1];
                dp[i][j]=l+r;
            }
        }
        return dp[m-1][n-1];
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {

        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();

        vector<vector<int>> dp(m,vector<int>(n,0));

        return uniquePathsDP(obstacleGrid,dp,m,n);
    }
};