// URL - https://www.geeksforgeeks.org/problems/bfs-traversal-of-graph/1

class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        
        int vis[V]={0};
        
        vector<int> bfs;
        queue<int> q;
        
        q.push(0);
        
        while(!q.empty()){
            
            int node=q.front();
            q.pop();
            if(vis[node]==1)
                continue;
            
            vis[node]=1;
            bfs.push_back(node);
            
            for(auto i: adj[node]){
                q.push(i);
            }
        }
        return bfs;
    }
};