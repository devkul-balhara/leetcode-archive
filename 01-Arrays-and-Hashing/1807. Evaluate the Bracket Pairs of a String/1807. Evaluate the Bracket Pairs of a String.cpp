1class Solution {
2public:
3    string evaluate(string s, vector<vector<string>>& knowledge) {
4        unordered_map<string, string> d;
5        for(auto& k : knowledge) d[k[0]] = k[1];
6        string res;
7        for(int i = 0; i < s.size(); i++){
8            if(s[i] == '('){
9                int j = s.find(), i+1);
10                auto t = s.substr(i+1, j-i-1);
11                res += d.count(t) ? d[t] : ?;
12                i = j;
13            } 
14            else res += s[i];
15        }
16        return res;
17    }
18};