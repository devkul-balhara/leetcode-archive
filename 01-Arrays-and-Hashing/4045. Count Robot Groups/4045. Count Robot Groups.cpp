1#define ll long long
2class Solution {
3public:
4    int countGroups(vector<int>& position, vector<int>& speed, int distance){
5        int n = position.size();
6        ll groups = n;
7        ll maxSpeed = speed[n-1];
8        for(int i = n-1; i > 0; --i){
9            if(position[i] - position[i-1] <= distance) groups--;
10            else if(speed[i-1] > maxSpeed) groups--;
11            else maxSpeed = speed[i-1];
12        }
13        return groups;
14    }
15};