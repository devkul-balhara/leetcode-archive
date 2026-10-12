1class Solution {
2public:
3    int maxSum(vector<int>& nums, int k) {
4        const long long MOD = 1e9 + 7;
5        int bits[31] = {};
6
7        for(int x : nums)
8            for(int b = 0; b < 31; b++){
9                if(x & (1 << b)) bits[b]++;
10            }
11
12        long long ans = 0;
13
14        while(k--){
15            long long x = 0;
16            for(int b = 0; b < 31; b++){
17                if(bits[b] > 0) x |= (1LL << b), bits[b]--;
18            }
19            ans = (ans + x * x) % MOD;
20        }
21        return ans;
22    }
23};