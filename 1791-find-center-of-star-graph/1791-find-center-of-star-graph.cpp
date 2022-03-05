class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        map<int,vector<int>> adjList;
        for(auto x:edges){
            adjList[x[0]].push_back(x[1]);
            adjList[x[1]].push_back(x[0]);
        }
        int maxEdges = 0;
        int node = -1;
        for(auto x:adjList){
            if(x.second.size()>=maxEdges){
                node=x.first;
                maxEdges = x.second.size();
            }
        }
        return node;
    }
};