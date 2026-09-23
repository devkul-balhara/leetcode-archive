1class Solution {
2public:
3    string convert(string s, int numRows) {
4        if(numRows == 1 || numRows >= s.size()) return s;
5        vector<string> rows(numRows);
6        int currRow = 0;
7        bool goingDown = true;
8        for(char c : s){
9            rows[currRow] += c;
10            if(currRow == 0) goingDown = true;
11            else if(currRow == numRows-1) goingDown = false;
12            currRow += goingDown ? 1 : -1;
13        }
14        string ans;
15        for(string &row : rows) ans += row;
16        return ans;
17    }
18};