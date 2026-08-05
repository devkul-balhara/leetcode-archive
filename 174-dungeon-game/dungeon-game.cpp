class Solution {
public:
    // min health from i,j till end
    int rec(int i, int j, vector<vector<int>>& dungeon, vector<vector<int>>& dp){
        int m = dungeon.size(), n = dungeon[0].size();
        if(i == m-1 && j == n-1){
            if(dungeon[i][j] < 0) return 1-dungeon[i][j];
            else return 1;
        }
        if(dp[i][j] != -1) return dp[i][j];
        int ans = INT_MAX;
        if(i+1 < m) ans = min(ans, rec(i+1,j,dungeon,dp));
        if(j+1 < n) ans = min(ans, rec(i,j+1,dungeon,dp));
        ans -= dungeon[i][j];
        ans = max(ans,1);
        return dp[i][j] = ans;
    }

    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size(), n = dungeon[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return rec(0,0,dungeon,dp);
    }
};