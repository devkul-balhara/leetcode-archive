class DSU{
    vector<int> rank,parent;
    public:
    DSU(int n){
        rank.resize(n);
        parent.resize(n);
        for(int i = 0; i < n; i++){
            parent[i] = i;
            rank[i] = 1;
        }
    }
    int get(int u){
        if(parent[u] == u) return u;
        else return parent[u] = get(parent[u]);
    }
    void unite(int u, int v){
        int upu = get(u), upv = get(v);
        if(upu != upv){
            if(rank[upu] == rank[upv]){
                parent[upv] = upu;
                rank[upu]++;
            }
            else if(rank[upu] > rank[upv]) parent[upv] = upu;
            else parent[upu] = upv;
        }
    }
};

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int maxr = 0, maxc = 0;
        for(auto i : stones){
            maxr = max(maxr,i[0]);
            maxc = max(maxc,i[1]);
        }
        DSU dsu(maxr+maxc+2);
        unordered_set<int> nodes; // track used nodes
        for(auto &s : stones){
            int row = s[0];
            int col = s[1]+maxr+1; // offset to avoid collisions when row == col
            dsu.unite(row,col);
            nodes.insert(row);
            nodes.insert(col);
        }
        int components = 0;
        for(auto node : nodes){
            if(dsu.get(node) == node) components++;
        }
        return stones.size() - components;
    }
};