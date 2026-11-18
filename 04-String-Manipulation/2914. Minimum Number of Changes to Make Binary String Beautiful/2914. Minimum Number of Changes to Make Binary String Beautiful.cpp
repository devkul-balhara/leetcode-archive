1class Solution {
2public:
3    int minChanges(string s) {
4        int ans = 0;
5        for(int i = 0; i < s.size()-1; i += 2){
6            if(s[i] != s[i+1]) ans++;
7        }
8        return ans;
9    }
10};