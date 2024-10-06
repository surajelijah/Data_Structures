// URL - https://leetcode.com/problems/flood-fill/

class Solution {

private:

    void dfs(int row,int col,vector<vector<int>>& ans,vector<vector<int>> &image, int deltarow[],int deltacol[],int inicolor,int color,int m,int n){

        ans[row][col]=color;

        for(int i=0;i<4;i++){

            int r= row + deltarow[i];
            int c= col + deltacol[i];

            if(r>=0 && r<m && c>=0 && c<n && image[r][c]==inicolor && ans[r][c]!=color){
                dfs(r,c,ans,image,deltarow,deltacol,inicolor,color,m,n);
            }
        }
        return ;
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {

        int m= image.size();
        int n= image[0].size();
        int inicolor=image[sr][sc];

        vector<vector<int>> ans=image;

        int deltarow[]={-1,0,1,0}; // These are used to traverse in four directions
        int deltacol[]={0,1,0,-1};

        dfs(sr,sc,ans,image,deltarow,deltacol,inicolor,color,m,n);

        return ans;
    }
};