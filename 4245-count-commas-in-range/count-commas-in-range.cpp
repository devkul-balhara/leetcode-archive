class Solution {
public:
    long long pow(long long n){
        long long num = 1;
        for(int i = 0; i < n; i++) num *= 10;
        return num;
    }

    void cal(long long& ans, long long cnt){
        ans += (cnt)*999*pow(3*cnt); 
    }

    long long countCommas(long long n) {
        long long dig = 0, num = n;
        while(num > 0){
            dig++;
            num /= 10;
        }
        long long ans = 0;
        if(dig <= 3) return 0LL;
        else{
            long long cnt = (dig-1)/3; 
            for(int i = 1; i < cnt; i++) cal(ans,i);
            long long start = 1000, temp = cnt;
            while(temp > 1){
                start *= 1000; 
                temp--;
            }
            ans += (n-start+1)*cnt;
            return ans;
        }
    }
};