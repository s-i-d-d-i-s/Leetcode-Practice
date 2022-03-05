class DSU{
    public:
    vector<int> parent;
    DSU(int n){
        parent.resize(n);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
    }
    
    int root(int n){
        if(n == parent[n])return n;
        parent[n] = root(parent[n]);
        return parent[n];
    }
    void uni(int a,int b){
        int r1 = root(a);
        int r2 = root(b);
        if(r1 == r2)return;
        parent[r2]=r1;
    }
    bool find(int a,int b){
        int r1 = root(a);
        int r2 = root(b);
        return r1==r2;
    }
    
};
class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(n-1>connections.size())return -1;
        DSU dsu(n+1);
        for(auto edge:connections){
            dsu.uni(edge[0],edge[1]);
        }
        int result=0;
        vector<bool> components(n,false);
        for(int i=0;i<n;i++){
            if(components[dsu.root(i)]) continue;
            components[dsu.root(i)] = true;
            result++;
        }
        return result-1;
    }
};