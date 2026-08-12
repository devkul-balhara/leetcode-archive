class Solution {
public:
    int lengthOfLastWord(string s) {
        int idx = -1;
        for(int i = s.size()-1; i >= 0; i--){
            if(s[i] != ' '){
                idx = i;
                break;
            }
        }
        int cnt = 0;
        for(int i = idx; i >= 0; i--){
            if(s[i] != ' ') cnt++;
            else break;
        }
        return cnt;
    }
};