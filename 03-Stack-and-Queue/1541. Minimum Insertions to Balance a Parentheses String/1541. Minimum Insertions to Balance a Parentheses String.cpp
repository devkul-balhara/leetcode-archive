1class Solution {
2public:
3    int minInsertions(string& s) {
4        int p = 0, k = 0;
5        for(int i = 0; i < s.size(); i++){
6            char c = s[i];
7            if(c == '('){
8                p+=2;
9                if(p&1 == 1){
10                    k++;
11                    p--;
12                }
13            }
14            else{
15                p--;
16                if(p < 0){
17                    k++;
18                    p+=2;
19                }
20               
21            }
22        }
23        return p+k;
24    }
25};