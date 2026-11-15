1class Solution {
2public:
3    int numOfSubarrays(vector<int>& arr) {
4        int n = arr.size();
5        long long mod = 1e9+7;
6        vector<int> pref(n);
7        pref[0] = arr[0];
8        for(int i = 1; i < n; i++) pref[i] = pref[i-1] + arr[i];
9        long long ans = 0, odd = 0, even = 0;
10        for(int i = 0; i < n; i++){
11            if(pref[i]%2 == 1){
12                ans = (ans%mod+even+1)%mod;
13                odd++;
14            }
15            else{
16                ans = (ans%mod+odd)%mod;
17                even++;
18            }
19        }
20        return ans%mod;
21    }
22};