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
    int makeConnected(int n, vector<vector<int>>& connections) {
        DSU dsu(n);
        int extra = 0, parts = 0;
        for(auto i : connections){
            int upu = dsu.get(i[0]), upv = dsu.get(i[1]);
            if(upu == upv) extra++;
            else dsu.unite(upu,upv);
        }
        for(int i = 0; i < n; i++){
            if(dsu.get(i) == i) parts++;
        }
        if(extra >= parts-1) return parts-1;
        else return -1;
    }
};