class Solution {
public:
    string smallestSubsequence(string s) {
       vector<int> v(26,-1);
       vector<bool> vis(26,false);
       for(int i = 0; i < s.size(); i++){
           v[s[i]-'a'] = i;
       } 
       stack<char> st;
       for(int i = 0; i < s.size(); i++){
           if(vis[s[i]-'a']) continue; 
           while(!st.empty() && s[i] < st.top() && v[st.top()-'a'] > i){
               vis[st.top()-'a'] = false; 
               st.pop();
           }
           st.push(s[i]);
           vis[s[i]-'a'] = true;
       }
       
       string ans;
       while(!st.empty()){
           ans += st.top();
           st.pop();
       }
       reverse(ans.begin(), ans.end());
       return ans;
    }
};