1class Solution {
2public:
3    vector<vector<int>> generateMatrix(int n) {
4        int x = 0, y = 0, dx = 1, dy = 0;
5        vector<vector<int>> res(n, vector<int>(n, 0));
6        for(int i = 0; i < n * n; i++){
7            res[y][x] = i+1;
8            if(!(0 <= x + dx && x + dx < n && 0 <= y + dy && y + dy < n && res[y+dy][x+dx] == 0)){
9                int temp = dx;
10                dx = -dy;
11                dy = temp;
12            }
13            x += dx;
14            y += dy;
15        }
16        return res;        
17    }
18};