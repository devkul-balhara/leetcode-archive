1class Solution {
2public:
3    int mul(int p){
4        int n = 1;
5        for(int i = 0; i < p; i++) n *= 3;
6        return n;
7    }
8
9    int pow(int n){
10        int p = 0; 
11        while(n >= 3){
12            p++;
13            n /= 3;
14        }
15        return p;
16    }
17    
18    bool isPossible(int n, int start){
19        if(n == 0) return true; 
20        int p = pow(n); 
21        for(int i = start; i <= p; i++){
22            int num = mul(i);
23            if(isPossible(n-num, i+1)) return true;
24        }
25        return false;
26    }
27
28    bool checkPowersOfThree(int n){
29        return isPossible(n,0); 
30    }
31};