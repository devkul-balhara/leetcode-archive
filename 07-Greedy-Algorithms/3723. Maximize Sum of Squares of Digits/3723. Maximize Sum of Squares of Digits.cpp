1class Solution {
2public:
3    string maxSumOfSquares(int num, int sum) {
4        if(num*9 < sum) return ;
5        string ans = ;
6        while(num--){
7            if(sum > 9){
8                ans += '9';
9                sum -= 9;
10            }
11            else{
12                ans += to_string(sum);
13                sum = 0;
14            }
15        }
16        return ans;
17    }
18};