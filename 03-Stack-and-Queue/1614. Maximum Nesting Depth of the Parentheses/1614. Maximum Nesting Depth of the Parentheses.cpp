1class Solution {
2public:
3    int maxDepth(string s) {
4        int cnt = 0, ans = 0;
5        for(int i = 0; i < s.size(); i++){
6            if(s[i] == '(') cnt++;
7            else if(s[i] == ')') cnt--;
8            ans = max(ans, cnt);
9        }
10        return ans;
11    }
12};