// URL - https://www.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1


//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    
  private:
  
  bool detectCycle(int node,int parent,int V,vector<int> adj[],int vis[]){
        
        vis[node]=1;
        
        for(auto i:adj[node]){
            if(vis[i]==0){
                if(detectCycle(i,node,V,adj,vis))
                    return 1;
            }
            else if(i!=parent)
                return 1;
        }
        return 0;
  }
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        int vis[V]={0};
        
        // This is to test the cycle present if there are multiple components in the graph
        for(int i=0;i<V;i++){
            if(vis[i]==0){
                if(detectCycle(i,-1,V,adj,vis))
                   return 1;
            }
        }
        return 0;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends