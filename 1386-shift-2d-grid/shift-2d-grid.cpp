class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> temp(grid);
        k %= (m*n);
        for(int i = 0; i < k; i++){
            for(int x = 0; x < m; x++){
                for(int y = 0; y < n; y++){
                    if(x == m-1 && y == n-1) temp[0][0] = grid[x][y];
                    else if(y == n-1) temp[x+1][0] = grid[x][y];
                    else temp[x][y+1] = grid[x][y];
                }
            }
            grid = temp;
        }
        return temp;
    }
};