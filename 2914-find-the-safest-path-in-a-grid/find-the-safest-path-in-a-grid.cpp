class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();
        if(grid[0][0] == 1 || grid[n - 1][n - 1] == 1) return 0;
        // bfs to find min manhattan distance of each cell so that we can use max heap later on them
        vector<vector<int>> dist(n, vector<int>(n, -1));
        queue<pair<int, int>> q;
        for(int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                if(grid[i][j] == 1){
                    q.push({i, j});
                    dist[i][j] = 0;
                }
            }
        }
        int dx[] = {1, -1, 0, 0};
        int dy[] = {0, 0, 1, -1};
        while(!q.empty()){
            auto [r, c] = q.front();
            q.pop();
            for(int i = 0; i < 4; i++){
                int nr = r + dx[i];
                int nc = c + dy[i];
                if (nr >= 0 && nr < n && nc >= 0 && nc < n && dist[nr][nc] == -1) {
                    dist[nr][nc] = dist[r][c] + 1;
                    q.push({nr, nc});
                }
            }
        }
        // using max heap to get maximum safeness factor
        priority_queue<pair<int, pair<int, int>>> pq;
        vector<vector<int>> maxSafe(n, vector<int>(n, INT_MIN)); // store maximum safeness factor from (0,0) till current 
        maxSafe[0][0] = dist[0][0];
        pq.push({maxSafe[0][0], {0,0}}); // {safeness factor,{x,y}}
        while(!pq.empty()){
            auto [sf, cell] = pq.top();
            int r = cell.first;
            int c = cell.second;
            pq.pop();
            if(r == n-1 && c == n-1) return sf;
            if(maxSafe[r][c] > sf) continue;
            for(int i = 0; i < 4; i++){
                int nr = r + dx[i];
                int nc = c + dy[i];
                if(nr >= 0 && nr < n && nc >= 0 && nc < n){
                    int nsf = min(dist[nr][nc], sf);
                    if(nsf > maxSafe[nr][nc]){
                        maxSafe[nr][nc] = nsf;
                        pq.push({nsf,{nr,nc}});
                    }
                }
            }
        }
        return maxSafe[n-1][n-1];
    }
};