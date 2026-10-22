1class Solution {
2public:
3    int minOperations(auto& A) {
4        int n = A.size();
5        int asc = 1, dsc = 1;
6        for(int i = 1; i < n; i++){
7            asc += A[i] == (A[i-1]+1) % n;
8            dsc += A[i-1] == (A[i]+1) % n;
9        }
10        if(asc == n) return A.front() ? min(n-A.front(), A.front()+2) : 0;
11        if(dsc == n) return min(n-A.back(), A.back())+1;
12        return -1;
13    }
14};