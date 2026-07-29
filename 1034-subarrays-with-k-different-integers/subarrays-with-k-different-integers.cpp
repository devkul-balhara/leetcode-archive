class Solution {
public:
    int atMost(vector<int>& nums, int target){
        unordered_map<int,int> mp;
        int start = 0, ans = 0;
        for(int i = 0; i < nums.size(); i++){
            mp[nums[i]]++;
            if(mp.size() > target){
                while(mp.size() > target){
                    mp[nums[start]]--;
                    if(mp[nums[start]] == 0) mp.erase(nums[start]);
                    start++;
                }
            }
            ans += i-start+1;
        }
        return ans;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atMost(nums,k)-atMost(nums,k-1);
    }
};