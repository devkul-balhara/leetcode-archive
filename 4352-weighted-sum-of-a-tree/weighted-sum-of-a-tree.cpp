class Solution {
public:
    void bfs(vector<vector<int>>& adj, vector<int>& depth){
        int n = adj.size();
        vector<bool> vis(n,false);
        queue<int> q;
        q.push(0);
        vis[0] = true;
        int d = 1;
        while(!q.empty()){
            int sz = q.size();
            for(int i = 0; i < sz; i++){
                int curr = q.front();
                q.pop();
                depth[curr] = d;
                for(auto n : adj[curr]){
                    if(!vis[n]){
                        q.push(n);
                        vis[n] = true;
                    }
                }
            }
            d++;
        }
    }

    long long weightedSum(vector<int>& parent, vector<int>& nums) {
        int n = parent.size();
        vector<vector<int>> adj(n);
        for(int i = 0; i < n; i++){
            if(parent[i] == -1) continue;
            else{
                adj[i].push_back(parent[i]);
                adj[parent[i]].push_back(i);
            }
        }
        vector<int> depth(n);
        bfs(adj,depth);
        int height = *max_element(depth.begin(), depth.end());
        long long ans = 0;
        for(int i = 0; i < n; i++){
            ans += nums[i]*1LL*(height-depth[i]+1);
        }
        return ans;
    }
};