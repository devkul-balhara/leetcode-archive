1class Solution {
2    struct Server {
3        long long at;  // the second it frees up; 0 while free, so free servers sort by weight, then index
4        int weight, index;
5        auto operator<=>(const Server&) const = default;
6    };
7    using MinHeap = priority_queue<Server, vector<Server>, greater<>>;
8
9public:
10    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
11        vector<Server> all;
12        for (int i = 0; i < ssize(servers); ++i) all.push_back({0, servers[i], i});
13        MinHeap free(greater<>{}, std::move(all));
14
15        MinHeap busy;
16        vector<int> ans;
17        for (int s = 0; s < ssize(tasks); ++s) {
18            while (!busy.empty() && busy.top().at <= s) {  // done by second s
19                auto [at, weight, index] = busy.top();
20                busy.pop();
21                free.push({0, weight, index});
22            }
23            MinHeap& from = free.empty() ? busy : free;  // none free: the first to finish takes it
24            auto [at, weight, index] = from.top();
25            from.pop();
26            busy.push({max<long long>(at, s) + tasks[s], weight, index});
27            ans.push_back(index);
28        }
29
30        return ans;
31    }
32};