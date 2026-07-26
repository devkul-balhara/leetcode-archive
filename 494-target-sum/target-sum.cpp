class Solution {
public:
    // no of ways from i till end
    int rec(int i, int k, int offset, vector<int>& nums, vector<vector<int>>& dp){
        int n = nums.size();
        if(i == n){
            if(k == 0) return 1;
            else return 0;
        }
        if(dp[i][k+offset] != -1) return dp[i][k+offset];
        return dp[i][k+offset] = rec(i+1,k+nums[i],offset,nums,dp)+rec(i+1,k-nums[i],offset,nums,dp);
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int sum = accumulate(nums.begin(),nums.end(),0);
        int max_value = max(sum,target+sum);
        int min_value = min(-sum,target-sum);
        int offset = -min_value;
        vector<vector<int>> dp(n,vector<int>(max_value + offset + 1,-1));
        return rec(0,target,offset,nums,dp);
    }
};