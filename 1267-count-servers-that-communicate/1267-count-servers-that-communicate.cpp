class DSU{
    public:
    map<pair<int,int>,pair<int,int>> parent;
    DSU(){
        
    }
    
    pair<int,int> root(pair<int,int> a){
        if(parent.find(a) == parent.end()){
            parent[a]=a;
        }        
        if(parent[a]==a)
            return a;
        parent[a] = root(parent[a]);
        return parent[a];
    }
    
    void uni(pair<int,int> a,pair<int,int> b){
        cout << a.first << " " << a.second << " " << b.first << " " << b.second << endl;
        pair<int,int> r1 = root(a);
        pair<int,int> r2 = root(b);
        if(r1 == r2) return;
        parent[r1]=r2;
    }
    
    bool find(pair<int,int> &a,pair<int,int> &b){
        return root(a) == root(b);
    }
};
class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        DSU dsu;
        for(int i=0;i<grid.size();i++){
            int last=-1;
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j]==1){
                    if(last != -1){
                        dsu.uni({i,last},{i,j});
                    }
                    last=j;
                }
                
            }
        }
        for(int i=0;i<grid[0].size();i++){
            int last=-1;
            for(int j=0;j<grid.size();j++){
                if(grid[j][i]==1){
                    if(last != -1){
                        dsu.uni({last,i},{j,i});
                    }
                    last=j;
                }
            }
        }
        map<pair<int,int>,int> counter;
        int result=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j]==1){
                    result++;
                    counter[dsu.root({i,j})]++;
                }
            }
        }
        for(auto x:counter){            
            if(x.second==1) result--;
        }
        return result;
    }
};