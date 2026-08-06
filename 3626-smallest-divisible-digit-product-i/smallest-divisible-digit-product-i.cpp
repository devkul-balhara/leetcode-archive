class Solution {
public:
    int rec(int n){
        int ans = 1;
        while(n > 0){
            ans *= n%10;
            n /= 10; 
        }
        return ans;
    }

    int smallestNumber(int n, int t) {
        int ans;
        for(int i = n; i <= n+t; i++){
            int pro = rec(i);
            if(pro%t == 0){
                ans = i;
                break;
            }
        }
        return ans;
    }
};