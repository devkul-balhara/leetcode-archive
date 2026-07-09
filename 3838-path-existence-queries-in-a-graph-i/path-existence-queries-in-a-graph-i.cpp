class Solution {

public:

    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<pair<int,int>> intervals;
        vector<bool> ans;
        int s = 0, e = 0;
        while(s < nums.size() && s <= e){
            if(e < nums.size() && abs(nums[s]-nums[e]) <= maxDiff) e++;
            else{
                intervals.push_back({s,e-1});
                s++;
            }
        }
        // for(auto i : intervals) cout << i.first << " " << i.second << '\n';
        vector<pair<int,int>> merge;
        int prevs = intervals[0].first, preve = intervals[0].second;  
        for(int i = 1; i < intervals.size(); i++){
            if(intervals[i].first <= preve){
                preve = intervals[i].second;
            }
            else{
                merge.push_back({prevs,preve});
                prevs = intervals[i].first;
                preve = intervals[i].second;
            }
        }
        merge.push_back({prevs,preve});
       // for(auto i : merge) cout << i.first << " " << i.second << '\n';
        map<int,int> mp;
        vector<int> start;
        for(auto i : merge){
            mp[i.first] = i.second;
            start.push_back(i.first);
        }

        for(int i = 0; i < queries.size(); i++){
            int f = min(queries[i][0],queries[i][1]), s = max(queries[i][0],queries[i][1]);
            int idx = upper_bound(start.begin(), start.end(), f)-start.begin()-1;
            if(idx == -1){
                ans.push_back(false);
                continue;
            }
            if(s <= mp[start[idx]]) ans.push_back(true);
            else ans.push_back(false);
        }
        return ans;
    }
};