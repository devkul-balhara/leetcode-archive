class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int,vector<bool>> mp;
        vector<int> start = {2,4,6};
        for(auto i : reservedSeats){
            int seat = i[1];
            vector<bool> ok = mp[i[0]];
            if(ok.empty()) ok.resize(3,true);
            if(seat >= 2 && seat <= 3) ok[0] = false;
            else if(seat >= 4 && seat <= 5){
                ok[0] = false;
                ok[1] = false;
            }
            else if(seat >= 6 && seat <= 7){
                ok[1] = false;
                ok[2] = false;
            }
            else if(seat >= 8 && seat <= 9) ok[2] = false;
            mp[i[0]] = ok;
        }
        int ans = 0;
        for(auto& i : mp){
            vector<bool> ok = i.second;
            if(ok[0] && ok[1] && ok[2]) ans += 2;
            else if(!ok[0] && ok[1] && ok[2]) ans += 1;
            else if(ok[0] && ok[1] && !ok[2]) ans += 1;
            else if(!ok[0] && !ok[1] && ok[2]) ans += 1;
            else if(ok[0] && !ok[1] && !ok[2]) ans += 1;
            else if(!ok[0] && ok[1] && !ok[2]) ans += 1;
        }
        int left = n-mp.size();
        ans += 2*left;
        return ans;
    }
};