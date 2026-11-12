class Solution {
    private int longestIncreasingSubarray(int[] nums) {
        int ans = 1;
        int curr = 1;
        int n = nums.length;
        for (int i = 1; i < n; i++) {
            if (nums[i] < nums[i-1]) {
                curr++;
                ans = Math.max(curr, ans);
            }
            else {
                curr = 1;
            }
        }
        return ans;
    }
    private int longestDecreasingSubarray(int[] nums) {
        int ans = 1;
        int curr = 1;
        int n = nums.length;
        for (int i = 1; i < n; i++) {
            if (nums[i] > nums[i-1]) {
                curr++;
                ans = Math.max(curr, ans);
            }
            else {
                curr = 1;
            }
        }
        return ans;        
    }

    public int longestMonotonicSubarray(int[] nums) {
        return Math.max(longestIncreasingSubarray(nums), longestDecreasingSubarray(nums));
    }
}