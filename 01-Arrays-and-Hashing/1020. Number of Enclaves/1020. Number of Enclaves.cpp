1class Solution {
2public:
3    int numEnclaves(vector<vector<int>>& grid) {
4        int m = grid.size(), n = grid[0].size();
5        vector<vector<bool>> vis(m,vector<bool>(n,false));
6        queue<pair<int,int>> q; // {x,y}
7        for(int i = 0; i < m; i++){
8            for(int j = 0; j < n; j++){
9                if((i == 0 || i == m-1 || j == 0 || j == n-1) && grid[i][j] == 1){
10                    q.push({i,j});
11                    vis[i][j] = true;
12                }
13            }
14        }
15        vector<int> xmov = {1,-1,0,0};
16        vector<int> ymov = {0,0,1,-1};
17        while(!q.empty()){
18            int x = q.front().first;
19            int y = q.front().second;
20            q.pop();
21            for(int i = 0; i < 4; i++){
22                int nx = x+xmov[i], ny = y+ymov[i];
23                if(nx >= 0 && nx < m-1 && ny >= 0 && ny < n-1 && grid[nx][ny] == 1 && !vis[nx][ny]){
24                    q.push({nx,ny});
25                    vis[nx][ny] = true;
26                }
27            }
28        }
29        int ans = 0;
30        for(int i = 0; i < m; i++){
31            for(int j = 0; j < n; j++){
32                if(grid[i][j] == 1 && !vis[i][j]) ans++;
33            }
34        }
35        return ans;
36    }
37};
38
39// can also be done by repeated bfs or repeated dfs for boundary cells 