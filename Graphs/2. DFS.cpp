// URL - https://www.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1

class Solution {
  public:
    // Function to return a list containing the DFS traversal of the graph.
    
    void dfs_(int node,vector<int> adj[],vector<int> &dfs,int vis[]){
        
        if(vis[node]==1)
            return;
        
        vis[node]=1;
        dfs.push_back(node);
        
        for(auto i: adj[node]){
            if(!vis[i]){
                dfs_(i,adj,dfs,vis);
            }
        }
        return;
    }
    
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        
        vector<int> dfs;
        int vis[V]={0};
        
        dfs_(0,adj,dfs,vis);
        
        return dfs;
    }
};