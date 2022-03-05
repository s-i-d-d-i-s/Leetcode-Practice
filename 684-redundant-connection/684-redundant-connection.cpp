class DSU{
    vector<int> parent,rank;
    public:
    DSU(int n){
        parent.resize(n+1);
        rank.resize(n+1);
        for(int i=1;i<=n;i++){
            parent[i]=i;
        }
    }
    
    int root(int node){
        if(node == parent[node]) return node;
        parent[node] = root(parent[node]);
        return parent[node];
    }
    void uni(int node1,int node2){
        int parent1 = root(node1);
        int parent2 = root(node2);
        if(parent1 == parent2) return;
        
        // parent1 is the new parent
        parent[parent2] = parent1;
        return;
    }
    
    bool find(int node1,int node2){
        int parent1 = root(node1);
        int parent2 = root(node2);
        return parent1 == parent2;
    }
};
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        DSU dsu(n+1);
        for(auto edge:edges){
            if(dsu.find(edge[0],edge[1])){
                return edge;
            }
            dsu.uni(edge[0],edge[1]);
        }
        return {};
    }
};