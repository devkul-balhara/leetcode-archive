class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int l = 0, h = nums.size()-1;
        while(l <= h){
            int mid = l+(h-l)/2;
            if(mid > 0 && nums[mid] == nums[mid-1]){
                if((nums.size()-1-mid)%2 == 0) h = mid-2;
                else l = mid+1;
            }
            else if(mid < nums.size()-1 && nums[mid] == nums[mid+1]){
                if((nums.size()-mid)%2 == 0) h = mid-1;
                else l = mid+2;
            }
            else return nums[mid];
        }
        return -1;
    }
};