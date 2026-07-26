class Solution {
public:
    // no of ways to make k from i till end
    int rec(int i, int k, vector<int>& coins, vector<vector<int>>& dp){
        int n = coins.size();
        if(i == n){
            if(k == 0) return 1;
            else return 0;
        }
        if(dp[i][k] != -1) return dp[i][k];
        int ans = rec(i+1,k,coins,dp);
        if(k-coins[i] >= 0) ans += rec(i,k-coins[i],coins,dp);
        return dp[i][k] = ans;
    }

    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        return rec(0,amount,coins,dp);
    }
};