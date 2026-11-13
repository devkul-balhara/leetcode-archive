1class Solution {
2public:
3    int minMoves(vector<int>& nums) {
4        // final sum = nx, curr sum = s
5        // s + k(n - 1) = nx
6        // Since the minimum element must be incremented in every move:
7        // x = mini + k
8        // s + k*n - k = n*(mini + k)  ==>  k = s - n * mini
9        long long s = accumulate(nums.begin(), nums.end(), 0LL);
10        long long n = nums.size();
11        long long mini = *min_element(nums.begin(), nums.end());
12        return s-n*mini;
13    }
14};