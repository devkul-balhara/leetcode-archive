class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {  
        vector<vector<pair<int,int>>> adj(n);
        for(auto &f : flights){
            adj[f[0]].push_back({f[1], f[2]});
        }
        // {cost, {node, stops}}
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        pq.push({0, {src, 0}});
        vector<vector<int>> dist(n, vector<int>(k+2, INT_MAX)); // best price for nodes considering stops
        dist[src][0] = 0;
        while(!pq.empty()){
            auto [cost, p] = pq.top();
            pq.pop();
            int node = p.first;
            int stops = p.second;
            if(node == dst) return cost;
            if(cost > dist[node][stops]) continue;
            // atmost k stops means atmost k+1 flights 
            if(stops > k) continue;
            for(auto &[next, price] : adj[node]){
                int newCost = cost + price;
                if(newCost < dist[next][stops+1]){
                    dist[next][stops+1] = newCost;
                    pq.push({newCost, {next, stops+1}});
                }
            }
        }
        return -1;
    }
};