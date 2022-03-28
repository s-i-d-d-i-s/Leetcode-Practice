class DSU{
    public:
    map<pair<int,int>,pair<int,int>> parent;
    map<pair<int,int>,int> size;
    DSU(){
        parent[{-1,-1}]={-1,-1};
        size[{-1,-1}]=0;
    }
    
    pair<int,int> root(pair<int,int> n){
        if(parent.find(n) == parent.end()){
            parent[n]=n;
            size[n]=1;
        }
        if(parent[n]==n) return n;
        parent[n] = root(parent[n]);
        return parent[n];
    }
    bool uni(pair<int,int> n1,pair<int,int> n2){
        auto r1 = root(n1);
        auto r2 = root(n2);
        if(r1 == r2) return false;
        parent[r2] = r1;
        size[r1]+=size[r2];
        return true;
    }
    int getSize(pair<int,int> n){
        return size[root(n)];
    }
};



void unionAround(int i,int j,vector<vector<int>> &grid, DSU &dsu){
    int n = grid.size();
    int m = grid[0].size();
    
    for(auto dx:{-1,0,1}){
        for(auto dy:{-1,0,1}){
            if(dx!=0 and dy!=0)continue;                            
            if(dx==0 and dy==0)continue;                            
            if(i+dx >=0 and i+dx<n and j+dy>=0 and j+dy<m and grid[i+dx][j+dy]==1){
                dsu.uni({i,j},{i+dx,j+dy});
            }
        }
    }
    if(i==0){
        dsu.uni({i,j},{-1,-1});
    }
}


class Solution {
public:
    vector<int> hitBricks(vector<vector<int>>& grid, vector<vector<int>>& hits) {
        int n = grid.size();
        int m = grid[0].size();
        
        for(int i=0;i<hits.size();i++){
            if(grid[hits[i][0]][hits[i][1]]==1)
                grid[hits[i][0]][hits[i][1]]=2;
        }
        DSU dsu;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    unionAround(i,j,grid,dsu);
                }
            }
        }
        vector<int> result;
        int currentBricks = dsu.getSize({-1,-1});
        
        reverse(hits.begin(),hits.end());
        
        for(auto x:hits){
            int i = x[0];
            int j = x[1];
            if(grid[i][j]==2){
                grid[i][j]=1;
                
                unionAround(i,j,grid,dsu);
                
                int nowBricks = dsu.getSize({-1,-1});
                
                int bricksFallen = nowBricks-currentBricks-1;
                
                result.push_back(max(0,bricksFallen));
                
                currentBricks = nowBricks;
            }else{
                result.push_back(0);
            }
        }    
        reverse(result.begin(),result.end());
        return result;        
    }
};
