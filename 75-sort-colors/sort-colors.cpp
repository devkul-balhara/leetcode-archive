class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low = 0, mid = 0, high = nums.size()-1;
        while(mid <= high){
            if(nums[mid] == 0){
                swap(nums[low], nums[mid]);
                // because low...mid contains 1 so after swapping low and mid values we will have 0 at low and 1 at mid so we can increase both
                low++;
                mid++;
            }
            else if(nums[mid] == 1) mid++;
            else{
                swap(nums[mid], nums[high]);
                // high value could be anything (0,1,2) which gets swapped at mid so we can decrease high but mid requires further processing
                high--;
            }
        }
    }
};