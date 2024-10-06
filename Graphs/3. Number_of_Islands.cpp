//Problem URL - https://www.geeksforgeeks.org/problems/find-the-number-of-islands/1


// Solution - Here we have the nice eight direction adjacent travel technique which is subtle

class Solution {

  private:
    void bfs(int row,int col,int m, int n, vector<vector<int>>& vis,vector<vector<char>> grid){

        queue<pair<int,int>> q; // creating a queue whcih takes a pair({row,col})
        
        q.push({row,col});
        vis[row][col]=1;
        
        while(!q.empty()){
         
         int r=q.front().first;
         int c=q.front().second;
         q.pop();
         
         //Travelling in all the eight directions
         
         for(int uprow=-1;uprow<=1;uprow++){
             for(int upcol=-1;upcol<=1;upcol++){
                 int urow=r+uprow;
                 int ucol=c+upcol;
                 
                 if(urow>=0 && urow<m && ucol>=0 && ucol<n && !vis[urow][ucol] && grid[urow][ucol]=='1'){
                  
                    q.push({urow,ucol});
                    vis[urow][ucol]=1;
                     
                 }
             }
         }
            
            
            
        }
    }

  public:
    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        
        int count = 0;
        int m=grid.size();
        int n=grid[0].size();
        
        vector<vector<int>> vis(m,vector<int>(n,0)); // creating a visiting array similar to grid
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                
                if(!vis[i][j] && grid[i][j]=='1'){
                    count++;
                    bfs(i,j,m,n,vis,grid);
                }
            }
        }
        return count;
    }
};
