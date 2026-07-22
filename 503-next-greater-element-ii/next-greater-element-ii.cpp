class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        stack<int> st;
        vector<int> next_greater(n,-1);
        for(int i = 2*n-1; i >= 0; i--){
            if(st.empty()) st.push(nums[i%n]);
            while(!st.empty() && st.top() <= nums[i%n]) st.pop();
            if(!st.empty() && i < n) next_greater[i] = st.top(); 
            st.push(nums[i%n]);
        }
        return next_greater;
    }
};