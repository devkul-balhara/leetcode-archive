class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int ans = -1;
        vector<int> vmax(nums.size()), vmin(nums.size());
        vmax[0] = nums[0];
        vmin.back() = nums.back();
        for(int i = 1; i < nums.size(); i++) vmax[i] = max(vmax[i-1], nums[i]);
        for(int i = nums.size()-2; i >= 0; i--) vmin[i] = min(vmin[i+1], nums[i]);
        for(int i = 0; i < nums.size(); i++){
            int maxi = vmax[i], mini = vmin[i];
            if(maxi-mini <= k){
                ans = i;
                break;
            }
        }
        return ans;
    }
};