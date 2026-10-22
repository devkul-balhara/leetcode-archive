1class Solution {
2public:
3    int minOperations(string s) {
4        int n = s.size();
5        char mn = s[0], mx = s[0];
6        int ok = 1;
7        for(int i = 1; i < n; i++){
8            if (s[i] < s[i - 1]) ok = 0;
9            if (s[i] < mn) mn = s[i];
10            if (s[i] > mx) mx = s[i];
11        }
12        if(ok) return 0;
13        if(n == 2) return -1;
14        if(s[0] == mn || s[n-1] == mx) return 1;
15        for(int i = 1; i < n-1; i++){
16            if(s[i] == mn || s[i] == mx) return 2;
17        }
18        return 3;
19    }
20};