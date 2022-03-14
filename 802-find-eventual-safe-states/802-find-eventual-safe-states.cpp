class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> colour(n);
        /*
            0 -> unvisited
            1 -> visiting
            2 -> visited
        */
        for(int i=0;i<n;i++){
            if(colour[i]==0){
                depthFirstSearchHasCycle(i,graph,colour);
            }
        }
        vector<int> result;
        for(int i=0;i<n;i++){
            if(colour[i]==2){
                result.push_back(i);
            }
        }
        return result;
    }
    
    bool depthFirstSearchHasCycle(int source,vector<vector<int>> &graph,vector<int> &colour){
        if(colour[source] == 2) return false;
        if(colour[source] == 1) return true;
        
        colour[source] = 1;
        for(int x:graph[source]){
            if(depthFirstSearchHasCycle(x,graph,colour)){
                return true;
            }
        }
        colour[source]=2;
        return false;
    }
};