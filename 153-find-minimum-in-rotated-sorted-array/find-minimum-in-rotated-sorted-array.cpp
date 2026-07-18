class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0, h = nums.size()-1;
        int ans = nums.back();
        while(l <= h){
            int mid = l+(h-l)/2;
            if(nums[mid] <= nums[h]){
                ans = min(ans,nums[mid]);
                h = mid-1;
            }
            else l = mid+1;
        }
        return ans;
    }
};