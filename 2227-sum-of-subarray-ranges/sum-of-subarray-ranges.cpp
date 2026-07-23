class Solution {
public:
    vector<int> nse(vector<int>& arr){
        vector<int> ans(arr.size(),-1); // stores next smaller element's index
        stack<int> st;
        for(int i = arr.size()-1; i >= 0; i--){
            while(!st.empty() && arr[st.top()] >= arr[i]) st.pop();
            if(!st.empty()) ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }

    vector<int> psee(vector<int>& arr){
        vector<int> ans(arr.size(),-1); // stores prev smaller or equal element's index (why equal ? to avoid duplicates like in 2 6 2: subarrays that have 1st 2 as min are 2, 2 6, 2 6 2 and subarrays the have 2nd 2 as min are 2, 6 2, 2 6 2 notice 2 6 2 repeating if equal was not there now with equal for 2nd 2 it becomes 2, 6 2 so no duplicates)
        stack<int> st;
        for(int i = 0; i < arr.size(); i++){
            while(!st.empty() && arr[st.top()] > arr[i]) st.pop();
            if(!st.empty()) ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }

    vector<int> nge(vector<int>& nums){
        vector<int> ans(nums.size(),-1); // stores next greater element's index
        stack<int> st;
        for(int i = nums.size()-1; i >= 0; i--){
            while(!st.empty() && nums[st.top()] <= nums[i]) st.pop();
            if(!st.empty()) ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }

    vector<int> pgee(vector<int>& nums){
        vector<int> ans(nums.size(),-1); // stores prev greater or equal element's index (why equal ? to avoid duplicates like in 6 2 6: subarrays that have 1st 6 as max are 6, 6 2, 6 2 6 and subarrays the have 2nd 6 as min are 6, 2 6, 6 2 6 notice 6 2 6 repeating if equal was not there now with equal for 2nd 6 it becomes 6, 2 6 so no duplicates)
        stack<int> st;
        for(int i = 0; i < nums.size(); i++){
            while(!st.empty() && nums[st.top()] < nums[i]) st.pop();
            if(!st.empty()) ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }

    long long subArrayRanges(vector<int>& nums) {
        // sum of larget - smallest = (sum of largest - sum of smallest)
        vector<int> vnse = nse(nums), vnge = nge(nums), vpsee = psee(nums), vpgee = pgee(nums);
        long long largest = 0, smallest = 0;

        // largest
        for(int i = 0; i < nums.size(); i++){
            int left_idx = vpgee[i], right_idx = vnge[i]; // index of pgee and nge elements, now these should not be included in finding no of left or right elements so use left_idx+1, right_idx-1
            int left_cnt = i-(left_idx+1), right_cnt = (right_idx == -1 ? nums.size()-1 : right_idx-1)-i;
            // now for total subarrays:
            // 1. the current must be present
            // 2. we can extend 0...left_cnt elements to left from current i
            // 3. we can extend 0...right_cnt elements to right from current i
            // hence total contri would be 1 * (left_cnt+1) * (right_cnt+1) * nums[i]
            largest += (1LL * nums[i] * (left_cnt+1) * (right_cnt+1));
        }

        // smallest
        for(int i = 0; i < nums.size(); i++){
            int left_idx = vpsee[i], right_idx = vnse[i]; // index of psee and nse elements, now these should not be included in finding no of left or right elements so use left_idx+1, right_idx-1
            int left_cnt = i-(left_idx+1), right_cnt = (right_idx == -1 ? nums.size()-1 : right_idx-1)-i;
            // now for total subarrays:
            // 1. the current must be present
            // 2. we can extend 0...left_cnt elements to left from current i
            // 3. we can extend 0...right_cnt elements to right from current i
            // hence total contri would be 1 * (left_cnt+1) * (right_cnt+1) * nums[i]
            smallest += (1LL * nums[i] * (left_cnt+1) * (right_cnt+1));
        }

        return largest - smallest;
    }
};