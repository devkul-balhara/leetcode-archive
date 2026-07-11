class Solution {
public:

    bool dfs(vector<vector<int>>& adj, vector<bool>& vis, vector<bool>& path, int node){
        vis[node] = 1;
        path[node] = 1;
        for(auto i : adj[node]){
            if(!vis[i]){
                if(dfs(adj,vis,path,i)) return true;
            }
            else if(path[i]) return true;
        }
        path[node] = 0;
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        vector<bool> vis(n,false);
        vector<bool> path(n,false);
        vector<vector<int>> adj(n);
        for(auto i : prerequisites) adj[i[0]].push_back(i[1]);
        for(int i = 0; i < n; i++){
            if(!vis[i]){
                if(dfs(adj,vis,path,i)) return false;
            }
        }
        return true;
    }
};