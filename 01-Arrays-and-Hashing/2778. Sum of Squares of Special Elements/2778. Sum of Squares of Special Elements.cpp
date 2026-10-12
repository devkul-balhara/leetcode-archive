1class Solution {
2public:
3    int sumOfSquares(vector<int>& nums) {
4        int n = nums.size(), ans = 0;
5        for(int i = 1; i <= n; i++){
6            if(n%i == 0){
7                ans += nums[i-1]*nums[i-1];
8            }
9        }
10        return ans;
11    }
12};