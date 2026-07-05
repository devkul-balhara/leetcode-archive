class Solution {
public:
    // return true -> if path exists from current node till end with required health >= 1
    // else return false
    bool dfs(vector<vector<int>>& grid, int health, int x, int y, vector<vector<int>>& best){
        int m = grid.size(), n = grid[0].size();
        if(grid[x][y] == 1){
            health--;
        }
        if(health == 0) return false;
        if(x == m-1 && y == n-1) return true;
        if(health <= best[x][y]) return false;
        best[x][y] = health;
        vector<int> delta_x = {0,0,1,-1};
        vector<int> delta_y = {1,-1,0,0};
        bool ans = false;
        for(int i = 0; i < 4; i++){
            int nx = x+delta_x[i];
            int ny = y+delta_y[i];
            if(nx >= 0 && ny >= 0 && nx < m && ny < n){
                if(dfs(grid,health,nx,ny,best)) return true;
            }
        }
        return false;
    }

    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> best(m, vector<int>(n, -1));
        if(dfs(grid,health,0,0,best)) return true;
        return false;
    }
};