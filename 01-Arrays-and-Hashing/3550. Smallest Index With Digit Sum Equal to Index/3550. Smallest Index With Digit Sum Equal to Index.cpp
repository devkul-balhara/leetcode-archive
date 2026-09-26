1class Solution {
2public:
3    int smallestIndex(vector<int>& nums) {
4        for(int i = 0; i < nums.size(); i++){
5            int num = nums[i];
6            int sum = 0;
7            while(num > 0){
8                sum += num%10;
9                num = num/10;
10            }
11            if(sum == i) return i;
12        }
13        return -1;
14    }
15};