class Solution {
public:
    vector<int> dp;
    unordered_set<string> st;

    bool solve(int i, string &s) {
        if (i == s.size()) return true;
        if (dp[i] != -1) return dp[i];
        for (int j = i; j < s.size(); j++) {
           string word = s.substr(i, j - i + 1);
           if (st.count(word) && solve(j + 1, s)) return dp[i] = true;
        }
        return dp[i] = false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        st.insert(wordDict.begin(), wordDict.end());
        dp.assign(s.size(), -1);
        return solve(0, s);
    }
};