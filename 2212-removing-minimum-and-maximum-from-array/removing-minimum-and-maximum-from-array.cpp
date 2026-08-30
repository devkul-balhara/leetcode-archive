class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int mini = 1e6, maxi = -1e6, mini_idx = -1, maxi_idx = -1;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] > maxi){
                maxi = nums[i];
                maxi_idx = i;
            }
            if(nums[i] < mini){
                mini = nums[i];
                mini_idx = i;
            }
        }
        int n = (int)nums.size();
        cout << mini_idx << " " << maxi_idx;
        return min({min(mini_idx+1, n-mini_idx) + min(maxi_idx+1, n-maxi_idx), max(mini_idx+1, maxi_idx+1), max(n-mini_idx, n-maxi_idx)});
    }
};