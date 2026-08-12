class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>> adj(n);
        for(auto i : invocations) adj[i[0]].push_back(i[1]); 
        unordered_set<int> s;
        queue<int> q;
        q.push(k);
        while(!q.empty()){ 
            int sz = q.size();
            for(int i = 0; i < sz; i++){
                int curr = q.front();
                q.pop();
                if(s.find(curr) != s.end()) continue;
                s.insert(curr);
                for(auto nbr : adj[curr]){
                    if(s.find(nbr) == s.end()) q.push(nbr);
                }
            }
        }
        vector<int> ans;
        int idx = -1;
        for(int i = 0; i < n; i++){ 
            if(s.find(i) != s.end()) continue;
            else{
                for(auto nbr : adj[i]){
                    if(s.find(nbr) != s.end()){
                        idx = i;
                        break;
                    }
                }
                if(idx != -1) break;
                else ans.push_back(i);
            }
        }
        if(idx == -1) return ans;
        for(auto i : s) if(i < idx) ans.push_back(i);
        for(int j = idx; j < n; j++) ans.push_back(j);
        return ans;
    }
};