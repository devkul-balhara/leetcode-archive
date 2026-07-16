class Solution {
public:
    int gcd(int a, int b){
        if(b == 0) return a;
        return gcd(b,a%b);
    }

    long long gcdSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> maxi(n);
        maxi[0] = nums[0];
        for(int i = 1; i < n; i++) maxi[i] = max(maxi[i-1],nums[i]);
        vector<int> vg(n);
        for(int i = 0; i < n; i++) vg[i] = gcd(nums[i],maxi[i]);
        sort(vg.begin(),vg.end());
        int i = 0, j = n-1;
        long long ans = 0;
        while(i < j){
            ans += gcd(vg[i],vg[j]);
            i++;
            j--;
        }
        return ans;
    }
};