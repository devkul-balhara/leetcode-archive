class Solution {
public:
   vector<long long> resultArray(vector<int>& nums, int k) {
       int n = nums.size();
       vector<vector<long long>> dp(n, vector<long long>(k, 0));
       dp[0][nums[0] % k] = 1;

       for(int i = 1; i < n; i++) {
           dp[i][nums[i] % k] = 1;
           for(long j = 0; j < k; j++)
               dp[i][(nums[i] * j) % k] += dp[i - 1][j];
       }


       vector<long long> out(k, 0);
       for(int x = 0; x < k; x++) {
           for(int i = 0; i < n; i++) {
               out[x] += dp[i][x];
           }
       }
       return out;
   }
};