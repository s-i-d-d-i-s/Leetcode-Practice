class Solution {
public:
    map<int,bool> visit;
    int N = 1e5+5;
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<int> adjList[N];
        for(int i=0;i<n;i++){
            if(manager[i]!=-1){
                adjList[manager[i]].push_back(i);
            }
        }
        return timeToInform(headID,adjList,informTime);
    }
    int timeToInform(int empId, vector<int> adjList[], vector<int>& informTime){
        int result=0;
        for(int x:adjList[empId]){
            result = max(result,timeToInform(x,adjList,informTime));
        }
        result += informTime[empId];
        return result;
    }
};