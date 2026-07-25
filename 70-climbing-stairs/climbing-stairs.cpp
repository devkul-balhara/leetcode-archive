class Solution {
public:
    // ways from idx to end
    int rec(int idx, int n, vector<int>& dp){
        if(idx == n) return 1;
        if(dp[idx] != -1) return dp[idx];
        int ans = 0;
        for(int i = 1; i <= 2; i++){
            if(idx+i <= n) ans += rec(idx+i,n,dp);
        }
        return dp[idx] = ans;
    }

    int climbStairs(int n) {
        vector<int> dp(n,-1);
        return rec(0,n,dp);
    }
};