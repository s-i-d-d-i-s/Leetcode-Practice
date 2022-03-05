class Solution {
public:
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        int noOfNodes = isConnected.size();
        vector<bool> isVisited(noOfNodes,false);
        int result = 0;
        for(int i=0;i<noOfNodes;i++){
            if(!isVisited[i]){
                result++;
                depthFirstSearch(i,isConnected,isVisited);
            }
        }
        return result;
    }
    
    void depthFirstSearch(int source,vector<vector<int>> &isConnected,vector<bool> &visited){
        visited[source] = true;
        int noOfNodes = isConnected.size();
        for(int i=0;i<noOfNodes;i++){
            if(i!=source and !visited[i] and isConnected[source][i]){
                depthFirstSearch(i,isConnected,visited);
            }
        }
        return;
    }
};