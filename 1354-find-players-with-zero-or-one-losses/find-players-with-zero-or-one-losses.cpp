class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        map<int,int> mp;
        set<int> s;
        for(auto i : matches){
            mp[i[1]]++;
            s.insert(i[1]);
        }
        set<int> one_lose;
        for(auto i : mp){
            if(i.second == 1) one_lose.insert(i.first);
        }
        set<int> zero_lose;
        for(auto i : matches){
            if(s.find(i[0]) == s.end()) zero_lose.insert(i[0]);
        }
        vector<vector<int>> ans;
        vector<int> v1,v2;
        for(auto i : zero_lose) v1.push_back(i);
        for(auto i : one_lose) v2.push_back(i);
        ans.push_back(v1); ans.push_back(v2);
        return ans;
    }
};

// 1,2,3,5,4,10
// 1,2,10