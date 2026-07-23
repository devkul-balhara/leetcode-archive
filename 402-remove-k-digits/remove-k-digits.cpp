class Solution {
public:
    string removeKdigits(string num, int k) {
        // try to remove previous greater for current index starting from left
        stack<int> st;
        for(int i = 0; i < num.size(); i++){
            int val = num[i]-'0';
            while(!st.empty() && val < st.top() && k > 0){
                st.pop();
                k--;
            }
            st.push(val);
        }
        while(k > 0 && !st.empty()){
            st.pop();
            k--;
        }
        string ans = "";
        while(!st.empty()){
            ans += to_string(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        int cnt = 0;
        for(int i = 0; i < ans.size(); i++){
            if(ans[i] == '0') cnt++;
            else break;
        }
        ans = ans.substr(cnt,ans.size()-cnt);
        return (ans == "" ? "0" : ans);
    }
};