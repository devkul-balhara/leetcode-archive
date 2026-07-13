class Solution {
public:

    // bfs approach
    bool bfs(vector<vector<int>>& graph, vector<int>& color, int node){
        queue<int> q; 
        q.push(node);
        while(!q.empty()){
            int curr_node = q.front();
            int curr_color = color[curr_node];
            q.pop();
            for(auto i : graph[curr_node]){
                if(color[i] == -1){
                    q.push(i);
                    color[i] = !curr_color;
                }
                else if(curr_color == color[i]) return false;
            }
        }
        return true;
    }

    // dfs approach
    bool dfs(vector<vector<int>>& graph, vector<int>& color, int node){
        for(auto i : graph[node]){
            if(color[i] == -1){
                color[i] = !color[node];
                if(!dfs(graph,color,i)) return false;
            }
            else if(color[i] == color[node]) return false;
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n,-1);
        for(int i = 0; i < n; i++){
            if(color[i] == -1){
                color[i] = 0;
                // if(!dfs(graph,color,i)) return false;
                if(!bfs(graph,color,i)) return false;
            }
        }
        return true;
    }
};