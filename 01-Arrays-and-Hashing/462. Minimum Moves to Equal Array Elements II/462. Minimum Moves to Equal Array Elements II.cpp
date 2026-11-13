1class Solution {
2public:
3    int minMoves2(vector<int>& nums) {
4        sort(nums.begin(), nums.end());
5        int median = nums[nums.size()/2];
6        long long moves = 0;
7        for(int num : nums) moves += abs(num-median);
8        return moves;
9    }
10};