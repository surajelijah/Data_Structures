// URL - https://leetcode.com/problems/number-of-provinces/submissions/1411210208/


class Solution {

private:
    void dfs_(int node,vector<int> adj[],vector<int>& vis){
        if(vis[node]==1)
            return;
        vis[node]=1;

        for(auto i: adj[node]){
            if(!vis[i])
                dfs_(i,adj,vis);
        }
        return;
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        
        int V  =isConnected[0].size();

        vector<int> adj[V];

        for(int i=0;i<V;i++){
            for(int j=0;j<V;j++){
                if(isConnected[i][j]==1 && i!=j){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        int count=0;

        vector<int> vis(V,0);

        for(int i=0;i<V;i++){
            if(!vis[i]){
                count++;
                dfs_(i,adj,vis);
            }
        }

        return count;
    }
};