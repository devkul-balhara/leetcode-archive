1class Solution {
2public:
3    int minCost(int i, int n, vector<int>& costs, vector<int>& dp){
4        if(i == n) return 0;
5        if(dp[i] != -1) return dp[i];
6        int c = INT_MAX;
7        for(int j = 1; j <= 3; j++){
8           if(i+j <= n) c = min(c, minCost(i+j,n,costs,dp)+costs[i+j-1]+(j*j));
9        }
10        return dp[i] = c;
11    }
12
13    int climbStairs(int n, vector<int>& costs) {
14        vector<int> dp(1e6,-1);
15        return minCost(0,n,costs,dp);
16    }
17};