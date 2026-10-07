1class Solution {
2public:
3    void dfs(vector<bool>& vis, vector<vector<int>>& v, int node){
4        vis[node] = true;
5        for(auto i : v[node]){
6            if(!vis[i]){
7                dfs(vis,v,i);
8            }
9        }
10    }
11
12    int findCircleNum(vector<vector<int>>& isConnected) {
13        int ans = 0, n = isConnected.size();
14        vector<vector<int>> v(n);
15        for(int i = 0; i < n; i++){
16            for(int j = 0; j < n; j++){
17                if(isConnected[i][j]){
18                    v[i].push_back(j);
19                    v[j].push_back(i);
20                }
21            }
22        }
23        vector<bool> vis(n,false);
24        for(int i = 0; i < n; i++){
25            if(!vis[i]){
26                ans++;
27                dfs(vis,v,i);
28            }
29        }
30        return ans;
31    }
32};