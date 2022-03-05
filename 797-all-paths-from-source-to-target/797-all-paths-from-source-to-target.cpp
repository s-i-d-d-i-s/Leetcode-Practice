class Solution {
public:
    vector<vector<int>> result;
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int> path;
        depthFirstSearch(0,graph,path);
        return result;
    }
    
    void depthFirstSearch(int source,vector<vector<int>>& graph,vector<int> &path){
        
        path.push_back(source);
        for(int node:graph[source]){
            depthFirstSearch(node,graph,path);
        }
        if(source == (graph.size()-1)){
            result.push_back(path);
        }
        path.pop_back();
        return;
    }
};