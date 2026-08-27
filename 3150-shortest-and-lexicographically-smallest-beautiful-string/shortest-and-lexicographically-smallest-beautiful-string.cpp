class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        if(k == 1){
            for(auto i : s){
                if(i == '1') return "1";
            }
            return "";
        }
        int l = 0, st = -1, len = 1e3, cnt = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '1') cnt++;
            if(cnt == k){
                while(l < i && cnt == k){
                    if(s[l] == '1') cnt--;
                    l++;
                }
                if(i-(l-1)+1 < len){
                    len = i-(l-1)+1;
                    st = l-1;
                }
                else if(i-(l-1)+1 == len){
                    string t1 = s.substr(st,len);
                    string t2 = s.substr(l-1,len);
                    if(t2 < t1) st = l-1;
                }
            }
        }
        if(st == -1) return "";
        string ans = s.substr(st,len);
        return ans;
    }
};