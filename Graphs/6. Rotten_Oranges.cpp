// URL - https://leetcode.com/problems/rotting-oranges/description/


class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        
    int m=grid.size();
    int n=grid[0].size();

    int ans=0;

    queue<pair<pair<int,int>,int>> q;
    vector<vector<int>> vis(m,vector<int>(n,0));

    int deltarow[]= {-1, 0, +1, 0};;
    int deltacol[]= {0, 1, 0, -1};

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){

            if(grid[i][j]==2){
                q.push({{i,j},0});
                vis[i][j]=1;
        }
       }
    }

    //BFS CODE
    while(!q.empty()){

                int r=q.front().first.first;
                int c=q.front().first.second;
                int t=q.front().second;
                    
                ans=max(ans,t);
                q.pop();

                for(int k=0;k<4;k++){
                        
                    int urow = r + deltarow[k];
                    int ucol = c + deltacol[k];

                    if(urow >=0 && urow<m && ucol>=0 && ucol<n && 
                                grid[urow][ucol]==1 && vis[urow][ucol]==0){
                                    q.push({{urow,ucol},t+1});
                                    vis[urow][ucol]=1;
                                }
                }
        }
    
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j]==1 && vis[i][j]==0){
                return -1;
            }
        }
    }
    
    return ans;



    
    /*int n = grid.size();
      int m = grid[0].size();

      // store {{row, column}, time}
      queue < pair < pair < int, int > , int >> q;
      int vis[n][m];
      int cntFresh = 0;
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
          // if cell contains rotten orange
          if (grid[i][j] == 2) {
            q.push({{i, j}, 0}); 
            // mark as visited (rotten) in visited array
            vis[i][j] = 2;
          }
          // if not rotten
          else {
            vis[i][j] = 0;
          }
          // count fresh oranges
          if (grid[i][j] == 1) cntFresh++;
        }
      }

      int tm = 0;
      // delta row and delta column
      int drow[] = {-1, 0, +1, 0};
      int dcol[] = {0, 1, 0, -1}; 
      int cnt = 0;

      // bfs traversal (until the queue becomes empty)
      while (!q.empty()) {
        int r = q.front().first.first;
        int c = q.front().first.second;
        int t = q.front().second;
        tm = max(tm, t);
        q.pop();
        // exactly 4 neighbours 
        for (int i = 0; i < 4; i++) {
          // neighbouring row and column
          int nrow = r + drow[i];
          int ncol = c + dcol[i];
          // check for valid cell and 
          // then for unvisited fresh orange
          if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
            vis[nrow][ncol] == 0 && grid[nrow][ncol] == 1) {
            // push in queue with timer increased
             q.push({{nrow, ncol}, t + 1}); 
            // mark as rotten
            vis[nrow][ncol] = 2;
            cnt++;
          }
        }
      }

      // if all oranges are not rotten
      if (cnt != cntFresh) return -1;

      return tm;*/

    }
};