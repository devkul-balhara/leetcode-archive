class Solution {
public:
    void dfs(int i, int j, vector<vector<pair<int,int>>>& adj, vector<int>& dis){
        if(i == j) return;
        for(auto x : adj[i]){
            int c = x.second;
            if(min(dis[i],c) < dis[x.first]){
                dis[x.first] = min(dis[i],c);
                dfs(x.first,j,adj,dis);
            }
        }
        return;
    }

    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto i : roads){
            int a = i[0], b = i[1], distance = i[2];
            a--;
            b--;
            adj[a].push_back({b,distance});
            adj[b].push_back({a,distance});
        }
        vector<int> dis(n,INT_MAX);
        for(int i = 0; i < n; i++){
            dfs(i,n-1,adj,dis);
        }
        return dis.back();
    }
};