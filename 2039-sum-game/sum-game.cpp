class Solution {
public:
    bool sumGame(string num) {
        int sum1 = 0, cnt1 = 0, cnt2 = 0, sum2 = 0;
        int n = num.size();
        
        for(int i = 0; i < n / 2; i++){
            if(num[i] == '?') cnt1++;
            else sum1 += num[i] - '0';
        }
        for(int i = n / 2; i < n; i++){
            if(num[i] == '?') cnt2++;
            else sum2 += num[i] - '0';
        }
        
        // 1. If total '?' is odd, Alice always gets the last move and wins.
        if((cnt1 + cnt2) % 2 != 0) return true; 
        
        // 2. If even, Bob wins ONLY if the difference perfectly offsets the '?' imbalance
        if(2 * (sum1 - sum2) == 9 * (cnt2 - cnt1)) return false;
        return true;
    }
};