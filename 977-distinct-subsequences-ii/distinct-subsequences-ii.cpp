class Solution {
public:
    int distinctSubseqII(string s) {
        const int MOD = 1e9 + 7;
        vector<int> dp(26, 0); // no of unique subsequences ending with char c
        int total = 0;
        for(char ch : s){
            int c = ch - 'a';
            // contribution of currect char in generating new subseq:
            // 1. can be added to all previous subseq (total in number) giving total new ones  
            // 2. character itself giving 1 new subseq
            int cur = (total + 1) % MOD;
            // duplicates would be no of all previous subsequences ending with char c and that are dp[c]
            cur = (cur - dp[c] + MOD) % MOD;
            // add contribution of current char to total and dp
            dp[c] = (dp[c] + cur) % MOD;
            total = (total + cur) % MOD;
        }
        return total;
    }
};