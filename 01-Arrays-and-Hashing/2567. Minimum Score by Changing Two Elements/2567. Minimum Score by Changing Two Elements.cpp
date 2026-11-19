1class Solution {
2public:
3    int minimizeSum(vector<int>& nums) {
4        int n = nums.size();
5        sort(nums.begin(), nums.end());
6        return min({nums[n-2]-nums[1], nums.back()-nums[2], nums[n-3]-nums[0]});
7    }
8};
9
10// sort and 1st ,2nd can be last, last 2nd or
11// last, last 2nd can be 1st, 2nd
12// 1st and last can be 2nd, last 2nd