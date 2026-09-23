1class Solution {
2public:
3    int maxArea(vector<int>& height) {
4        int i = 0, j = height.size()-1;
5        int ans = 0;
6        while(i < j){
7            ans = max(ans,(j-i)*min(height[j],height[i]));
8            if(height[i] < height[j]) i++;
9            else j--;
10        }
11        return ans;
12    }
13};
14
15// maximise the area of rectangle 
16// area: (j-i) * min(height[j],height[i]) such that j > i
17// for maximising (j-i) start from extreme end and then keep the max height 