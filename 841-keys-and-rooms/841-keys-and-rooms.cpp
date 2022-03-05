class Solution {
public:
    
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool> visited(n,false);
        depthFirstSearch(rooms,visited,0);
        for(int i=0;i<n;i++){
            if(!visited[i]) return false;
        }
        return true;
    }
    
    
    void depthFirstSearch(vector<vector<int>> &graph,vector<bool> &visited,int source){
        visited[source]=true;
        for(int node:graph[source]){
            if(!visited[node]){
                depthFirstSearch(graph,visited,node);
            }
        }
        return;
    }
};