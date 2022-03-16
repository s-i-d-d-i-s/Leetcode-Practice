class Solution {
public:
    map<int,vector<pair<int,int>>> adjList;
    
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        for(auto x:times)
            adjList[x[0]].push_back({x[1],x[2]});
        
        vector<int> distance(n+1,INT_MAX);
        distance[k]=0;
        
        set<pair<int,int>> Q;
        Q.insert({0,k});
        
        while(Q.size()>0){
            auto [cost,node] = *Q.begin();
            Q.erase(Q.begin());
            
            for(auto x:adjList[node]){
                if(distance[x.first] > x.second+cost){
                    distance[x.first] = x.second+cost;
                    Q.insert({distance[x.first],x.first});
                }
            }
        }
        int result=INT_MIN;
        for(int i=1;i<=n;i++) {
            if(distance[i] == INT_MAX) return -1;
            result = max(result,distance[i]);
        }
        
        return result;
    }
};