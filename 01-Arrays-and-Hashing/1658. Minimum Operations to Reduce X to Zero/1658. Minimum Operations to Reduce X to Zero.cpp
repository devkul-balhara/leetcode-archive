1class Solution {
2public:
3    int minOperations(vector<int>& A, int x) {
4        int k = reduce(A.begin(),A.end())-x, n = A.size();
5        if(k < 0) return -1;
6        if(k == 0) return n;
7        int best = -1, i = 0, sum = 0;
8        for(int j = 0; j < n; j++){
9            sum += A[j];
10            while(sum > k) sum -= A[i++];
11            if(sum == k) best = max(best, j-i+1);
12        }
13        return best+1 ? n-best:-1;
14    }
15};