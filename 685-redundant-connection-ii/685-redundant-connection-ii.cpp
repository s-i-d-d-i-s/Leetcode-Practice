class DSU{
    vector<int> parent;
    public:
    DSU(int n){
        parent.resize(n+5);
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
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        
        auto cycleSol = getCycleSolution(edges);
        auto parentSol = getParentSolution(edges);
        
        if(parentSol[0] == -1) return cycleSol;
        if(cycleSol[0] == -1) return parentSol;

        edges = eraseEdge(edges,parentSol);
        cycleSol = getCycleSolution(edges);
        if(cycleSol[0] == -1) return parentSol;        
        
        edges.push_back(parentSol);
        reverse(edges.begin(),edges.end());
        parentSol = getParentSolution(edges);

        return parentSol;        
    }
    
    vector<vector<int>> eraseEdge(vector<vector<int>>& edges,vector<int> edge){
        vector<vector<int>> result;
        for(auto x:edges){
            if(x==edge) continue;
            result.push_back(x);
        }
        return result;
    }
        
    vector<int> getCycleSolution(vector<vector<int>>& edges){
        int n = edges.size();        
        DSU dsu(n);        
        for(auto x:edges){
            if(dsu.find(x[0],x[1])){
                return x;
            }
            dsu.uni(x[0],x[1]);
        }
        return {-1,-1};
    }
    
    vector<int> getParentSolution(vector<vector<int>>& edges){
        int n = edges.size();
        vector<int> parent(n+1,-1);
        for(auto x:edges){
            if(parent[x[1]] != -1){
                return x;
            }
            parent[x[1]]=x[0];
        }
        return {-1,-1};
    }
};