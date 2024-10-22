//URL - https://leetcode.com/problems/minimum-path-sum/description/

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        
        // Writing the DP Solution directly, seems like I got the hang of it

        int m=grid.size();
        int n=grid[0].size();

        vector<vector<int>> dp(m,vector<int>(n,0));
        //Base cases

        int sum=0;
        for(int i=0;i<m;i++){
            sum+=grid[i][0];
            dp[i][0]=sum;
        }//Row sum, beacuse we need not compare it with the left,it is only down

        sum=0;
        for(int i=0;i<n;i++){
            sum+=grid[0][i];
            dp[0][i]=sum;
        }// Column sum, because we need not compare it with the top, it is only right

        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                dp[i][j]=min((grid[i][j]+dp[i-1][j]),(grid[i][j]+dp[i][j-1]));
            }
        }
    return dp[m-1][n-1];
    }
};

