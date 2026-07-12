class Solution {
public:

    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<vector<bool>> vis(m,vector<bool>(n,false));
        vector<vector<int>> ans(m,vector<int>(n));
        vector<int> xmov = {1,-1,0,0};
        vector<int> ymov = {0,0,1,-1};
        queue<pair<int,int>> q; // {x,y}
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(mat[i][j] == 0){
                    q.push({i,j});
                    vis[i][j] = true;
                }
            }
        }
        int dis = 0;
        while(!q.empty()){
            int s = q.size();
            for(int i = 0; i < s; i++){
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                ans[x][y] = dis;
                for(int i = 0; i < 4; i++){
                    int nx = x+xmov[i], ny = y+ymov[i];
                    if(nx >= 0 && nx < m && ny >= 0 && ny < n && !vis[nx][ny]){
                        q.push({nx,ny});
                        vis[nx][ny] = true;
                    }
                }
            }
            dis++;
        }
        return ans;
    }
};