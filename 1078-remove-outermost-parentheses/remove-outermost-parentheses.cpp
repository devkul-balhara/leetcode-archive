class Solution {
public:
    string removeOuterParentheses(string s) {
        int cnt = 0;
        string ans;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '(') cnt++;
            else cnt--;
            if(cnt == 1 && s[i] == '(' || cnt == 0 && s[i] == ')') continue;
            ans.push_back(s[i]);
        }
        return ans;
    }
};