1class Solution {
2public:
3    int maxPalindromes(string s, int k) {
4        int n = s.size();
5        vector<vector<bool>> isPalindrome(n, vector<bool>(n));
6        for(int len = 1; len <= n; len++){
7            for (int left = 0; left+len <= n; left++){
8                int right = left + len - 1;
9                isPalindrome[left][right] =
10                    s[left] == s[right] &&
11                    (len <= 2 || isPalindrome[left+1][right-1]);
12            }
13        }
14        vector<int> dp(n + 1);
15        for(int i = 1; i <= n; i++){
16            dp[i] = dp[i-1];
17            for(int j = 0; j + k <= i; j++){
18                if(isPalindrome[j][i-1]){
19                    dp[i] = max(dp[i], dp[j]+1);
20                }
21            }
22        }
23        return dp[n];
24    }
25};