class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(edges.size()==0)return vector<int>(1);
        map<int,set<int>> adjList;
        for(auto x:edges){
            adjList[x[0]].insert(x[1]);
            adjList[x[1]].insert(x[0]);
        }
        queue<int> Q;
        map<int,int> inQ;
        for(auto x:adjList){
            if(x.second.size()==1){
                Q.push(x.first);
                inQ[x.first]=1;
            }
        }
        int totalNodes=n;
        while(totalNodes>2){
            int count = Q.size();
            for(int i=0;i<count;i++){
                int node = Q.front();
                Q.pop();
                totalNodes--;
                int parent = *adjList[node].begin();
                adjList.erase(node);
                adjList[parent].erase(node);
                if(adjList[parent].size()==1 and !inQ[parent]){
                    Q.push(parent);
                    inQ[parent]=1;
                }
            }
        }
        vector<int> result;
        while(Q.size()>0){
            result.push_back(Q.front());
            Q.pop();
        }
        return result;
    }
};