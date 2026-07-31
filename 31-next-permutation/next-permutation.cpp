class Solution {
public:
    void nextPermutation(vector<int>& nums) {

        // Step 1: Find the first index from the right where
        // nums[i] > nums[i - 1].
        // This is the pivot that needs to be increased.
        int idx = -1;
        for (int i = nums.size() - 1; i > 0; i--) {
            if (nums[i] > nums[i - 1]) {
                idx = i - 1;
                break;
            }
        }

        // If no pivot exists, the array is in descending order
        // (largest permutation). Reverse to get the smallest permutation.
        if (idx == -1) {
            reverse(nums.begin(), nums.end());
        } 
        else {

            // Step 2: Find the smallest element greater than nums[idx].
            // Since the suffix is in descending order, the first greater
            // element from the right is the correct one.
            for (int i = nums.size() - 1; i >= 0; i--) {
                if (nums[i] > nums[idx]) {
                    swap(nums[i], nums[idx]);
                    break;
                }
            }

            // Step 3: Reverse the suffix to make it the smallest possible
            // arrangement (ascending order).
            reverse(nums.begin() + idx + 1, nums.end());
        }
    }
};