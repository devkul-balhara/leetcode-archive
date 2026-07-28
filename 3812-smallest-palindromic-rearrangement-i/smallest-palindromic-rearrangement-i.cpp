class Solution {
public:
    string smallestPalindrome(string s) {
        vector<int> v(26,0);
        for(auto i : s) v[i-'a']++;
        string even = "";
        int odd = -1;
        for(int i = 0; i < 26; i++){
            if(v[i]&1){
                for(int j = 0; j < (v[i]-1)/2; j++){
                    char c = 'a'+i;
                    even.push_back(c);
                }
                odd = i;
            }
            else{
                for(int j = 0; j < v[i]/2; j++){
                    char c = 'a'+i;
                    even.push_back(c);
                }
            }
        }
        string reven = even;
        reverse(reven.begin(), reven.end());
        if(odd == -1) return even + reven;
        else{
            char c = 'a'+odd;
            return even + string(1, c) + reven;
        }
    }
};