class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        // Use a vector of size 26 instead of a map for O(1) space and faster lookups
        vector<int> mp(26, 0);
        int maxi = 0, cmax = 0;
        
        // Count frequencies and find the maximum frequency simultaneously
        for(char c : tasks) {
            mp[c - 'A']++;
            maxi = max(maxi, mp[c - 'A']);
        }
        
        // Count how many tasks have that exact maximum frequency
        for(int count : mp) {
            if(count == maxi) {
                cmax++;
            }
        }
        
        // Calculate the intervals based on gaps
        int calculated_intervals = (n + 1) * (maxi - 1) + cmax;
        
        // Return the maximum of the calculated intervals or the raw number of tasks
        // Ex: ["A","A","B","B","C","D","E"], n = 2
        // Formula gives: (2+1) * (2-1) + 2 = 5. But there are 7 tasks! You cannot complete 7 tasks in 5 intervals.
        return max((int)tasks.size(), calculated_intervals);
    }
};