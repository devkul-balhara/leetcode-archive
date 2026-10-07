1class Solution {
2public:
3    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
4        queue<pair<int,int>> q; // {x,y}
5        int n = image.size(), m = image[0].size();
6        vector<vector<int>> vis(n,vector<int>(m,false));
7        q.push({sr,sc});
8        vis[sr][sc] = true;
9        int scolor = image[sr][sc];
10        image[sr][sc] = color;
11        vector<int> xmov = {1,-1,0,0};
12        vector<int> ymov = {0,0,1,-1};
13        while(!q.empty()){
14            int x = q.front().first;
15            int y = q.front().second;
16            q.pop();
17            for(int k = 0; k < 4; k++){
18                int nx = x+xmov[k];
19                int ny = y+ymov[k];
20                if(nx >= 0 && nx < n && ny >= 0 && ny < m 
21                && image[nx][ny] == scolor && !vis[nx][ny]){
22                    vis[nx][ny] = true;
23                    image[nx][ny] = color;
24                    q.push({nx,ny});
25                }
26            }
27        }
28        return image;
29    }
30};
31
32// Note: visited vector is needed here because scolor and color can be equal which means you will reject a cell without ever visiting it.