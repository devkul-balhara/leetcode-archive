class Solution {
public:
    int minimumPushes(string word) {
        map<int,int> mp;
        for(int i = 0; i < word.size(); i++){
            mp[word[i]-'a']++;
        }
        int sz = mp.size();
        vector<int> times;
        for(auto i : mp) times.push_back(i.second);
        sort(times.rbegin(), times.rend());
        int chk = 1, ans = 0;
        for(int i = 0; i < times.size(); i++){
            if(i/8 == chk) chk++;
            ans += times[i]*chk;
        }
        return ans;
    }
};