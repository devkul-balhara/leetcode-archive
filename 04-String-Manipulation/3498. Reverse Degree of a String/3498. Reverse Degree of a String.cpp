1class Solution {
2public:
3    int reverseDegree(string s) {
4        int ans = 0;
5        for(int i = 0; i < s.size(); i++){
6            char c = s[i];
7            int p = 26-(c-'a');
8            ans += p*(i+1);
9        }
10        return ans;
11    }
12};