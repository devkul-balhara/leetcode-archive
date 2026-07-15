class Solution {
public:
    int dfs_len(vector<vector<int>>& adj, vector<bool>& vis, int node){
        vis[node] = true;
        int len = 1;
        for(auto i : adj[node]){
            if(!vis[i]) len += dfs_len(adj,vis,i);
        }
        return len;
    }

    bool dfs(vector<vector<int>>& adj, vector<bool>& vis, int node, int len){
        vis[node] = true;
        if(adj[node].size() != len-1) return false;
        for(auto i : adj[node]){
            if(!vis[i]){
                if(!dfs(adj,vis,i,len)) return false;
            }
        }
        return true;
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(auto i : edges){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        vector<bool> vis(n,false);
        int ans = 0;
        for(int i = 0; i < n; i++){
            if(!vis[i]){
                int len = dfs_len(adj,vis,i);
                vector<bool> vis2(n,false);
                if(dfs(adj,vis2,i,len)) ans++;
            }
        }
        return ans;
    }
};