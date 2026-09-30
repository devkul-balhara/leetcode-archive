1class Solution {
2public:
3    vector<int> maxDepthAfterSplit(string seq) {
4        int d = 0;
5        vector<int> ans;
6        for(char& c : seq){
7            if(c == '('){
8                d++;
9                ans.push_back(d%2);
10            }
11            else{
12                ans.push_back(d%2);
13                d--;
14            }
15        }
16        return ans;
17    }
18};