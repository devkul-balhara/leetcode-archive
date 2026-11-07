1class Solution {
2public:
3    long long countValidSubstrings(string s) {
4        long long ans = 0;
5        int lastA = -1, lastAB = -1, l = 0;
6        for(int r = 0; r < s.size(); r++){
7            if(s[r] == 'a') lastA = r;
8            else if(s[r] == 'b' && lastA != -1) lastAB = lastA;
9            else if(s[r] == 'c' && lastAB != -1) l = lastAB+1;
10            ans += r-l+1;
11        }
12        return ans;
13    }
14};