class Solution {
public:
    // length of largest subset ending at i
    int rec(int i, vector<int>& nums, vector<int>& dp){
        int n = nums.size();
        if(i == 0) return 1;
        if(dp[i] != -1) return dp[i];
        int ans = 1;
        for(int j = 0; j < i; j++){
            if(nums[i]%nums[j] == 0 || nums[j]%nums[i] == 0) ans = max(ans, 1+rec(j,nums,dp));
        }
        return dp[i] = ans;
    }

    // reconstruction
    void build(int i, vector<int>& nums, vector<int>& dp, vector<int>& v){
        if(rec(i,nums,dp) == 1){
            v.push_back(nums[i]);
            return;
        }
        for(int j = 0; j < i; j++){
            if((nums[i]%nums[j] == 0 || nums[j]%nums[i] == 0) && rec(i,nums,dp) == 1+rec(j,nums,dp)){
                v.push_back(nums[i]);
                build(j,nums,dp,v);
                return;
            }
        }
    }

    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        vector<int> parent(n), dp(n,-1);
        int len = 1, end = 0;
        for(int i = 0; i < n; i++){
            if(rec(i,nums,dp) > len){
                len = rec(i,nums,dp);
                end = i;
            };
        }
        vector<int> v;
        build(end,nums,dp,v);
        reverse(v.begin(),v.end());
        return v;
    }
};