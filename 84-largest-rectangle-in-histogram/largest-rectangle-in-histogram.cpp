class Solution {
public:
    vector<int> nse(vector<int>& heights){
        vector<int> ans(heights.size(),-1);
        stack<int> st;
        for(int i = heights.size()-1; i >= 0; i--){
            while(!st.empty() && heights[st.top()] >= heights[i]) st.pop();
            if(!st.empty()) ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }

    vector<int> pse(vector<int>& heights){
        vector<int> ans(heights.size(),-1);
        stack<int> st;
        for(int i = 0; i < heights.size(); i++){
            while(!st.empty() && heights[st.top()] >= heights[i]) st.pop();
            if(!st.empty()) ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }

    int largestRectangleArea(vector<int>& heights) {
        vector<int> vpse = pse(heights), vnse = nse(heights);
        int ans = 0;
        for(int i = 0; i < heights.size(); i++){
            int right_idx = (vnse[i] == -1 ? heights.size()-1 : vnse[i]-1), left_idx = vpse[i]+1; // now prev smaller and next smaller can't be included so did vpse[i]+1, vnse[i]-1
            ans = max(ans, heights[i]*(right_idx-left_idx+1));
        }
        return ans;
    }
};