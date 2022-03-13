class Solution {
public:
    map<int,vector<int>> adjList;
    bool canFinish(int numCourses, vector<vector<int>>& pre) {        
        for(auto x:pre){
            adjList[x[1]].push_back(x[0]);
        }
        vector<int> visit(numCourses+1,false);        
        for(int i=0;i<numCourses;i++)
            if(!visit[i])
                if(hasCycle(i,visit))return false;
        
        return true;
    }
    
    bool hasCycle(int src,vector<int> &visit){
        visit[src] =1;
        for(int x:adjList[src]){
            if(visit[x]==0){
                if(hasCycle(x,visit))return true;
            }else if(visit[x]==1){
                return true;
            }
        }
        visit[src]=2;
        return false;
    }
};