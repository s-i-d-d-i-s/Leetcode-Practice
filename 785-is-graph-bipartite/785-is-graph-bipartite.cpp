class Solution {
public:
    bool result=true;
    map<int,int> colour;
    bool isBipartite(vector<vector<int>>& graph) {
        for(int i=0;i<graph.size();i++)
            if(colour[i] == 0)
                dfs(i,graph,0);
        for(int i=0;i<graph.size();i++){
            int node = i;
            for(int x:graph[node]){
                if(colour[x] == colour[node]) return false;
            }
        }
        return true;
    }
    void dfs(int src,vector<vector<int>>& graph,bool bit=0){
        colour[src]=(int)bit+1;
        for(int x:graph[src])
            if(colour[x]==0)
                dfs(x,graph,bit^1);
    }
};