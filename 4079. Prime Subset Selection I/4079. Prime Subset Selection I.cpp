1class Solution {
2public:    
3    vector<int> maxPrimes(int n, int s) {
4        vector<int> ans;
5        vector<bool> prime(n+1,true);
6        prime[0] = false;
7        prime[1] = false;
8        for(int i = 2; i <= n; i++){
9            if(prime[i]){
10                for(int j = 2*i; j <= n; j += i) prime[j] = false;
11            }
12        }
13        int sum = 0;
14        for(int i = 2; i <= n; i++){
15            if(prime[i] && sum+i <= s){
16                sum += i;
17                ans.push_back(i);
18            }
19        }
20        return ans;
21    }
22};