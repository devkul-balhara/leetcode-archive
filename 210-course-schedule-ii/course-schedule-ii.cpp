class Solution {
public:

    bool cycle_dfs(vector<vector<int>>& adj, vector<bool>& vis, vector<bool>& path, int node){
        vis[node] = 1;
        path[node] = 1;
        for(auto i : adj[node]){
            if(!vis[i]){
                if(cycle_dfs(adj,vis,path,i)) return true;
            }
            else if(path[i]) return true;
        }
        path[node] = 0;
        return false;
    }

    void topo_dfs(vector<vector<int>>& adj, vector<bool>& vis, vector<int>& topo, int node){
        vis[node] = 1;
        for(auto i : adj[node]){
            if(!vis[i]) topo_dfs(adj,vis,topo,i);
        }
        topo.push_back(node);
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        vector<bool> vis(n,false);
        vector<bool> path(n,false);
        vector<vector<int>> adj(n);
        for(auto i : prerequisites) adj[i[0]].push_back(i[1]);
        bool ok = false;
        for(int i = 0; i < n; i++){
            if(!vis[i]){
                if(cycle_dfs(adj,vis,path,i)) ok = true;
            }
        }
        vector<int> ans;
        if(ok) return ans;
        for(int i = 0; i < n; i++) vis[i] = false;
        for(int i = 0; i < n; i++){
            if(!vis[i]) topo_dfs(adj,vis,ans,i);
        }
        return ans;
    }
};