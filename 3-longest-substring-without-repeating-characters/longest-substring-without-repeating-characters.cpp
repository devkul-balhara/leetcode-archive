class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size() == 0) return 0;
        int ans = 1, start = 0;
        vector<int> v(256,0);
        for(int i = 0; i < s.size(); i++){
            v[s[i]]++;
            if(v[s[i]] > 1){
                ans = max(ans,i-start);
                while(v[s[i]] > 1){
                    v[s[start]]--;
                    start++;
                }
            }
        }
        ans = max(ans,(int)s.size()-start);
        return ans;
    }
};