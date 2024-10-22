// URL - https://leetcode.com/problems/unique-paths/description/

class Solution {
public:

    int uniquePathsRec(int rowind,int colind){

        if(rowind<0 || colind<0)
            return 0;

        if(rowind==0 || colind==0)
            return 1;

        int l = uniquePathsRec(rowind-1,colind);
        int r=  uniquePathsRec(rowind,colind-1);

        return l+r;
    }


    int uniquePathsMemoize(int rowind,int colind,vector<vector<int>>& dp){

        if(rowind<0 || colind<0)
            return 0;

        if(rowind==0 || colind==0)
            return 1;
        
        if(dp[rowind][colind]!=-1)
            return dp[rowind][colind];

        int l = uniquePathsMemoize(rowind-1,colind,dp);
        int r=  uniquePathsMemoize(rowind,colind-1,dp);

        return dp[rowind][colind]=l+r;
    }

    int uniquePathsDP(int m,int n,vector<vector<int>>& dp){

        for(int i=0;i<m;i++)
            dp[i][0]=1; // This is the base case where row index is 0

        for(int i=0;i<n;i++)
            dp[0][i]=1; // This is the base case where col index is 0
        
        // Base cases are done now incorporate the recursion

        for(int i =1;i<m;i++){
            for(int j=1;j<n;j++){
                int l = dp[i-1][j];
                int r = dp[i][j-1];
                dp[i][j]=l+r;
            }
        }

        return dp[m-1][n-1];
    }


    int uniquePaths(int m, int n) {

        vector<vector<int>> dp(m,vector<int>(n,-1));

        return uniquePathsDP(m,n,dp);
        //return uniquePathsMemoize(m-1,n-1,dp);
        //return uniquePathsRec(m-1,n-1);        
    }
};

