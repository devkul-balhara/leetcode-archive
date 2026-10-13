1class Solution {
2public:
3    long long maxAlternatingSum(vector<int>& nums) {
4        for(int i = 0; i < nums.size(); i++){
5            if(nums[i] < 0) nums[i] = -1*nums[i];
6        }
7        sort(nums.begin(), nums.end());
8        long long suma = 0, sumb = 0;
9        for(int i = 0; i < nums.size()/2; i++){
10            suma += nums[i]*nums[i];
11        }
12        for(int i = nums.size()/2; i < nums.size(); i++){
13            sumb += nums[i]*nums[i];
14        }
15        return sumb-suma;
16    }
17};