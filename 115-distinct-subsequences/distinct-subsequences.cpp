class Solution {
public:
    // ways from i,j till end
    int rec(int i, int j, string &s, string &t, vector<vector<int>> &dp){
        int n = s.size(), m = t.size();
        if(j == m) return 1;
        if(i == n) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        if(s[i] == t[j]) return dp[i][j] = rec(i+1,j+1,s,t,dp) + rec(i+1,j,s,t,dp);
        return dp[i][j] = rec(i+1,j,s,t,dp);
    }

    int numDistinct(string s, string t) {
        int n = s.size(), m = t.size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return rec(0,0,s,t,dp);
    }
};