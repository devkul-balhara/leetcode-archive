class Solution {
public:
    // p matches s from i,j till end
    bool rec(int i, int j, string &s, string &p, vector<vector<int>> &dp){
        int n = s.size(), m = p.size();
        if(i == n && j == m) return true;
        if(i == n){
            for(int k = j; k < m; k++){
                if(p[k] != '*') return false;
            }
            return true;
        }
        if(j == m) return false;
        if(dp[i][j] != -1) return dp[i][j];
        bool ok = false;
        if(s[i] == p[j] || p[j] == '?') ok = rec(i+1,j+1,s,p,dp);
        else if(p[j] == '*') ok = rec(i+1,j,s,p,dp) | rec(i,j+1,s,p,dp);
        return dp[i][j] = ok;
    }

    bool isMatch(string s, string p) {
        int n = s.size(), m = p.size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return rec(0,0,s,p,dp);
    }
};