1class Solution {
2public:
3
4    void rec(string s, int co, int cc, int n, vector<string>& res){
5        if(s.size() == 2*n){
6            res.push_back(s);
7            return;
8        }
9        if(cc+1 <= n && co >= cc) rec(s+')', co, cc+1, n, res);
10        if(co+1 <= n && co >= cc) rec(s+'(', co+1, cc, n, res);
11    }
12
13    vector<string> generateParenthesis(int n) {
14        vector<string> ans;
15        string s = ;
16        rec(s,0,0,n,ans);
17        return ans;
18    }
19};