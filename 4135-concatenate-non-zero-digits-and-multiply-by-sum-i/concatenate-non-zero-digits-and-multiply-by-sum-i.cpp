class Solution {
public:
    long long sumAndMultiply(int n) {
        long long mul = 1, x = 0, sum = 0;
        while(n > 0){
            long long dig = n%10;
            if(dig != 0){
                x += dig*mul;
                mul *= 10;
                sum += dig;
            }
            n /= 10;
        }
        cout << x << " " << sum;
        return sum*x;
    }
};