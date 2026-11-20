1class Solution {
2public:
3    int maximumLength(vector<int>& nums) {
4        map<int,int> mp;
5        for(auto i : nums) mp[i]++;
6        int ans = 1;
7        for(auto i : mp){
8            long long curr = i.first, next = curr*curr, cnt = 1;
9            if(curr == 1) continue;
10            while(next <= 1e9 && mp[curr] >= 2 && mp[next] >= 1){
11                cnt += 2;
12                curr = next;
13                next = curr*curr;
14            }
15            ans = max(ans, (int)cnt);
16        }
17        ans = max(ans, (mp[1]%2 == 1 ? mp[1] : mp[1]-1)); // pure 1's
18        return ans;
19    }
20};