class Solution {
public:
    // max profit from i till end
    int rec(int i, int buy, vector<int>& price, vector<vector<int>>& dp){
        int n = price.size();
        if(i == n) return 0;
        if(dp[i][buy] != -1) return dp[i][buy];
        // skip 
        int ans = rec(i+1,buy,price,dp);
        if(buy){
            // sell
            ans = max(ans, price[i]+rec(i+1,0,price,dp));
        }
        else{
            // buy
            ans = max(ans, -price[i]+rec(i+1,1,price,dp));
        }
        return dp[i][buy] = ans;
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n,vector<int>(2,-1));
        return rec(0,0,prices,dp);
    }
};