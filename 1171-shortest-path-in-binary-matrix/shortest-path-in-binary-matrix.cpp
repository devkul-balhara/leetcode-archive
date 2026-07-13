class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if(grid[0][0] || grid[n-1][n-1]) return -1;
        vector<vector<bool>> vis(n,vector<bool>(n,false));
        queue<pair<int,int>> q; // {x,y}
        q.push({0,0});
        vis[0][0] = true;
        vector<int> xmov = {0,0,1,-1,1,1,-1,-1};
        vector<int> ymov = {1,-1,0,0,1,-1,1,-1};
        int len = 1;
        while(!q.empty()){
            int s = q.size();
            for(int i = 0; i < s; i++){
                int x = q.front().first;
                int y = q.front().second;
                if(x == n-1 && y == n-1) return len;
                q.pop();
                for(int i = 0; i < 8; i++){
                    int nx = x+xmov[i];
                    int ny = y+ymov[i];
                    if(nx >= 0 && nx < n && ny >= 0 && ny < n && !vis[nx][ny] && grid[nx][ny] == 0){
                        q.push({nx,ny});
                        vis[nx][ny] = true;
                    }
                }
            }
            if(!q.empty()) len++;
        }
        return -1;
    }
};