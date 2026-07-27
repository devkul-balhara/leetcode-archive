class Solution {
public:
    // min op from i,j till end
    int rec(int i, int j, string &s1, string &s2,vector<vector<int>> &dp){
        int n = s1.size(), m = s2.size();
        if(i == n) return m-j;
        if(j == m) return n-i;
        if(dp[i][j] != -1) return dp[i][j];
        if(s1[i] == s2[j]) return dp[i][j] = rec(i+1,j+1,s1,s2,dp);
        // if inserted then s2[j] has been taken care of so j gets incd but i remains intact [j+1,i]
        // if deleted then s2[j] has not been taken care of so j remains intact but i gets incd [j,i+1]
        // if replaced then s2[j] has been taken care of so j gets incd and i too gets incd [j+1,i+1]
        return dp[i][j] = 1+min({rec(i+1,j,s1,s2,dp), rec(i+1,j+1,s1,s2,dp), rec(i,j+1,s1,s2,dp)});
    }

    int minDistance(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return rec(0,0,word1,word2,dp);
    }
};