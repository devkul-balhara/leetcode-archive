1class Solution {
2public:
3    int maxSelectedElements(vector<int>& nums) {
4        sort(nums.begin(), nums.end());
5        unordered_map<int, int> dp;
6        int ans = 0;
7        for (int num : nums) {
8            dp[num+1] = dp[num] + 1;
9            dp[num] = dp[num-1] + 1;
10            ans = max({ans, dp[num], dp[num+1]});
11        }
12        return ans;
13    }
14};