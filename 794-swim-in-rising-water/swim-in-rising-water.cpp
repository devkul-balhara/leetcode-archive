class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        // {max elevation so far, x, y}
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> minHeap;
        
        // Use standard 'dist' array initialized to INT_MAX
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));

        minHeap.push({grid[0][0], 0, 0});
        dist[0][0] = grid[0][0];

        vector<pair<int, int>> dirs = {{0,1}, {1,0}, {0,-1}, {-1,0}};

        while (!minHeap.empty()) {
            auto curr = minHeap.top(); minHeap.pop();
            int elevation = curr[0], r = curr[1], c = curr[2];

            if (r == n - 1 && c == n - 1) return elevation;

            // Optimization: Ignore stale entries in the priority queue
            if (elevation > dist[r][c]) continue;

            for (auto& dir : dirs) {
                int nr = r + dir.first;
                int nc = c + dir.second;

                if (nr >= 0 && nc >= 0 && nr < n && nc < n) {
                    int nextElevation = max(elevation, grid[nr][nc]);
                    
                    // Only process and push if we found a strictly better path
                    if (nextElevation < dist[nr][nc]) {
                        dist[nr][nc] = nextElevation;
                        minHeap.push({nextElevation, nr, nc});
                    }
                }
            }
        }
        return -1;
    }
};