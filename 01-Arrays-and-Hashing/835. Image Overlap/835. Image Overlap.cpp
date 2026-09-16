1class Solution {
2public:
3    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
4        int n = img1.size();
5        vector<pair<int,int>> ones1, ones2;
6        for(int i = 0; i < n; i++){
7            for(int j = 0; j < n; j++){
8                if (img1[i][j] == 1) ones1.push_back({i,j});
9                if (img2[i][j] == 1) ones2.push_back({i,j});
10            }
11        }
12        vector<vector<int>> scnt(2*n, vector<int>(2*n,0));
13        int maxi = 0;
14        for(auto& p1 : ones1){
15            for(auto& p2 : ones2){
16                int dx = p2.first - p1.first;
17                int dy = p2.second - p1.second;
18                scnt[dx+n][dy+n]++;
19                maxi = max(maxi, scnt[dx+n][dy+n]);
20            }
21        }
22        return maxi;
23    }
24};