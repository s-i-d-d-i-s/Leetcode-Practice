class Solution {
public:
    int result=0;
    set<pair<int,int>> storedEdges;
    
    
    void depthFirstSearch(int source,vector<vector<int>> &adjList,int parent=-1){
        for(int child:adjList[source]){
            if(child!=parent){
                if(storedEdges.find({child,source}) == storedEdges.end()) {
                    result+=1;
                }
                depthFirstSearch(child,adjList,source);
            }
        }
    }
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adjList(n+1);
        for(auto edge:connections){
            storedEdges.insert({edge[0],edge[1]});
            adjList[edge[0]].push_back(edge[1]);
            adjList[edge[1]].push_back(edge[0]);
        }
        depthFirstSearch(0,adjList);
        return result;
    }
};