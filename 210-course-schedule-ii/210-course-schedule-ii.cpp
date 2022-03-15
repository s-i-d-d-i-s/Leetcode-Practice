class Solution {
public:
    vector<vector<int>> adjList;
    bool hasCycle=false;
    
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        adjList.resize(numCourses+1);
        for(auto x:prerequisites){
            adjList[x[1]].push_back(x[0]);
        }
        vector<int> topoSort,visit(numCourses);
        for(int i=0;i<numCourses;i++){
            if(visit[i]==0){
                depthFirstSearch(i,topoSort,visit);
            }
        }
        if(hasCycle)
            topoSort.clear();
        reverse(topoSort.begin(),topoSort.end());
        return topoSort;
    }
    
    void depthFirstSearch(int source,vector<int> &topoSort,vector<int> &visit){
        if(visit[source] == 1){
            hasCycle=true;
            return;
        }
        if(visit[source] == 2)return;
        visit[source]=1;
        
        for(int x:adjList[source]){
            depthFirstSearch(x,topoSort,visit);
        }
        visit[source]=2;
        topoSort.push_back(source);
        return;
    }
};