class Solution {
public:
    int characterReplacement(string s, int k) {
        int ans = 0, maxi = 0, start = 0;
        vector<int> v(26,0);
        for(int i = 0; i < s.size(); i++){
            v[s[i]-'A']++;
            maxi = max(maxi,v[s[i]-'A']);
            if(i-start+1-maxi > k){
                ans = max(ans,i-start);
                while(i-start+1-maxi > k){
                    v[s[start]-'A']--;
                    start++;
                }
            }
        }
        ans = max(ans,(int)s.size()-start);
        return ans;
    }
};