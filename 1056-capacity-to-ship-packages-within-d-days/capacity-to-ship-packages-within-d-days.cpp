class Solution {
public:

    bool check(vector<int>& v, int mid, int days){
        int w = 0, cnt = 0;
        for(int i = 0; i < v.size(); i++){
            w += v[i];
            if(w > mid){
                cnt++;
                w = v[i];
            }
        }
        cnt++;
        return cnt <= days;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int l = *max_element(weights.begin(), weights.end()), h = accumulate(weights.begin(), weights.end(), 0);
        int ans = -1;
        while(l <= h){
            int mid = l+(h-l)/2;
            if(check(weights, mid, days)){
                ans = mid;
                h = mid-1;
            }
            else l = mid+1;
        }
        return ans;
    }
};