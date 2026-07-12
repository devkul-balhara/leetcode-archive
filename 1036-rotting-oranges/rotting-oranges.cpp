class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int ans = 0;
        queue<pair<int,int>> q; // {x,y}
        int n = grid.size(), m = grid[0].size(), fresh = 0, cnt = 0;
        vector<vector<int>> vis(n,vector<int>(m,false));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 1) fresh++;
                if(grid[i][j] == 2){
                    q.push({i,j});
                    vis[i][j] = true;
                }
            }
        }
        vector<int> xmov = {1,-1,0,0};
        vector<int> ymov = {0,0,1,-1};
        int t = -1;
        while(!q.empty()){
            int s = q.size();
            for(int i = 0; i < s; i++){
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                for(int k = 0; k < 4; k++){
                    int nx = x + xmov[k];
                    int ny = y + ymov[k];
                    if(nx >= 0 && nx < n && ny >= 0 && ny < m 
                    && grid[nx][ny] == 1 && !vis[nx][ny]){
                        cnt++;
                        vis[nx][ny] = true;
                        q.push({nx,ny});
                    }
                }
            }
            t++;
        }
        if(cnt != fresh) return -1;
        return t == -1 ? 0 : t;
    }
};