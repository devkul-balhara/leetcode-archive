class Solution {
public:
    // length of lis ending at index i
    int rec(int i, vector<int>& nums, vector<int>& dp){
        if(i == 0) return 1;
        if(dp[i] != -1) return dp[i];
        int ans = 1;
        for(int j = 0; j < i; j++){
            if(nums[i] > nums[j]){
                ans = max(ans, 1+rec(j,nums,dp));
            }
        }
        return dp[i] = ans;
    }

    // count no of way to make lis ending at index i
    int build(int i, vector<int>& nums, vector<int>& dp, vector<int>& cnt){
        if(rec(i,nums,dp) == 1) return 1;
        if(cnt[i] != -1) return cnt[i];
        int ways = 0;
        for(int j = 0; j < i; j++){
            if(nums[i] > nums[j] && rec(i,nums,dp) == 1+rec(j,nums,dp)){
                ways += build(j,nums,dp,cnt);
            }
        }
        return cnt[i] = ways;
    }

    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,-1), cnt(n,-1);
        int maxi = 1;
        for(int i = 0; i < n; i++){
            maxi = max(maxi, rec(i,nums,dp));
        }
        int ans = 0;
        for(int i = 0; i < n; i++){
            if(rec(i,nums,dp) == maxi){
                ans += build(i,nums,dp,cnt);
            }
        }
        return ans;
    }
};