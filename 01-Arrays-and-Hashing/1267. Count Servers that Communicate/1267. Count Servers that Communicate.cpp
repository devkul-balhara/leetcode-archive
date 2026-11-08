1class Solution {
2public:
3    int countServers(vector<vector<int>>& grid) {
4        int n = grid.size(), m = grid[0].size();
5        vector<vector<bool>> vis(n,vector<bool>(m,0));
6        int ans = 0;
7        // row wise
8        for(int i = 0; i < n; i++){
9            int cnt = 0;
10            for(int j = 0; j < m; j++){
11                if(grid[i][j]) cnt++;
12            }
13            if(cnt > 1){
14                ans += cnt;
15                for(int j = 0; j < m; j++){
16                    if(grid[i][j]) vis[i][j] = 1;
17                }
18            }
19        }
20        // col wise
21        for(int j = 0; j < m; j++){
22            int cnt = 0, tot = 0;
23            for(int i = 0; i < n; i++){
24                if(grid[i][j] && !vis[i][j]) cnt++;
25                if(grid[i][j]) tot++;
26            }
27            if(tot > 1) ans += cnt;
28        }
29        return ans;
30    }
31};