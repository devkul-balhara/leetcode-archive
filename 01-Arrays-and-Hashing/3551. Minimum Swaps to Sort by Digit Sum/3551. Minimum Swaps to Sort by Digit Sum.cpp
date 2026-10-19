1class Solution {
2public:
3    int sum(int x){
4        int s = 0;
5        while(x > 0){
6            s += x%10;
7            x /= 10;
8        }
9        return s;
10    }
11
12    static bool cmp(pair<int,int>& p1, pair<int,int>& p2){
13        if(p1.second != p2.second) return p1.second < p2.second;
14        else return p1.first < p2.first;
15    }
16
17    int minSwaps(vector<int>& nums) {
18        int ans = 0;
19        vector<pair<int,int>> vp,t;
20        for(auto i : nums){
21            int s = sum(i);
22            vp.push_back({i,s});
23        }
24        t = vp;
25        sort(t.begin(),t.end(),cmp);
26        map<pair<int,int>,int> idx;
27        for(int i = 0; i < vp.size(); i++) idx[vp[i]] = i; 
28        for(int i = 0; i < t.size(); i++){
29            pair<int,int> p = t[i];
30            if(idx[p] != i){
31                ans++;
32                int pos = idx[p];
33                pair<int,int> pp = vp[i];
34                idx[p] = i;
35                idx[pp] = pos;
36                swap(vp[i],vp[pos]);
37            }
38        }
39        return ans;
40    }
41};