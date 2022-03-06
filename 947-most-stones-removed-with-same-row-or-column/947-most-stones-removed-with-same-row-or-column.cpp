class DSU{
    public:
    map<pair<int,int>,pair<int,int>> parent;
    DSU(){
        
    }
    
    pair<int,int> root(pair<int,int> n){
        if(parent.find(n) == parent.end() or n == parent[n]) return n;
        parent[n] = root(parent[n]);
        return parent[n];
    }
    void uni(vector<int> &_n1,vector<int> &_n2){
        pair<int,int> n1 = {_n1[0],_n1[1]};
        pair<int,int> n2 = {_n2[0],_n2[1]};
        auto r1 = root(n1);
        auto r2 = root(n2);
        if(r1 == r2) return;
        parent[r2] = r1;
        return;
    }    
    bool find(pair<int,int> n1,pair<int,int> n2){
        return root(n1) == root(n2);
    }
};
class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        DSU dsu;
        vector<int> rows[10001],cols[10001];
        
        for(auto x:stones){
            if(rows[x[0]].size()>0)
                dsu.uni(x,rows[x[0]]);   
            
            if(cols[x[1]].size()>0)
                dsu.uni(x,cols[x[1]]);
            
            rows[x[0]]=x;
            cols[x[1]]=x;
        }
        map<pair<int,int>,int> freq;
        for(auto x:stones){
            freq[dsu.root({x[0],x[1]})]++;
        }
        int result=0;
        for(auto x:freq){
            result+=(x.second-1);
        }
        return result;
    }
};