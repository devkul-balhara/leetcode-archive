1#include <bits/stdc++.h>
2using namespace std;
3
4#define ll long long
5
6class Solution {
7public:
8    ll rec(int idx, int turn, vector<int>& nums, vector<vector<ll>>& dp){
9        int n = nums.size();
10        if(idx == n) return 0;
11        if(dp[idx][turn] != -1) return dp[idx][turn];    
12
13        ll pick1 = LLONG_MIN, pick2 = LLONG_MIN;
14
15        pick1 = nums[idx];
16        if(nums[idx]%3) pick1 += rec(idx+1,0,nums,dp);
17        else pick1 -= rec(idx+1,1,nums,dp); 
18        
19        if(idx+1 < n){
20            pick2 = nums[idx] + nums[idx+1];
21            if(pick2%3) pick2 += rec(idx+2,0,nums,dp); 
22            else pick2 -= rec(idx+2,1,nums,dp); 
23        }
24        return dp[idx][turn] = max(pick1, pick2);
25    }
26
27    long long maxDifference(vector<int>& nums) {
28        int n = nums.size();
29        vector<vector<ll>> dp(n, vector<ll>(2,-1));;
30        return rec(0,0,nums,dp);
31    }
32};