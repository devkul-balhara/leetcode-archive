class Solution {
public:
    static bool cmp(vector<int>& v1, vector<int>& v2){
        if(v1[0] != v2[0]) return v1[0] < v2[0];
        else return v1[1] > v2[1];
    }

    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int ans = 1;
        sort(intervals.begin(), intervals.end(), cmp);
        int s = intervals[0][0], e = intervals[0][1];
        for(int i = 1; i < intervals.size(); i++){
            if(intervals[i][0] <= e && intervals[i][1] <= e) continue;
            else{
                s = intervals[i][0];
                e = intervals[i][1];
                ans++;
            }
        }
        return ans;
    }
};