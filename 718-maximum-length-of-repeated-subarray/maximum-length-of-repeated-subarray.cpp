class Solution {
public:
    // max length of longest common substring from [i..end] and [j..end] starting at i,j
    int rec(int i, int j, vector<int>& nums1, vector<int>& nums2, vector<vector<int>>& dp){
        if(i == nums1.size() || j == nums2.size()) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int len = 0;
        if(nums1[i] == nums2[j]) len = 1+rec(i+1,j+1,nums1,nums2,dp);
        return dp[i][j] = len;
    }

    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        int ans = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++) ans = max(ans,rec(i,j,nums1,nums2,dp));
        }
        return ans;
    }
};