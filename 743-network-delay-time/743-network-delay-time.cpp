class Solution {
public:
    map<int,vector<pair<int,int>>> adjList;
    
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {        
        vector<bool> visited(n+1,false);
        
        for(auto x:times)
            adjList[x[0]].push_back({x[1],x[2]});
        
        vector<int> distance(n+1,INT_MAX);
        
        multiset<pair<int,int>> Q;
        
        Q.insert({0,k});
        visited[k]=1;
        distance[k]=0;
        
        while(Q.size()>0){
            auto node = *Q.begin();            
            Q.erase(Q.begin());
            
            for(auto x:adjList[node.second]){                
                if(distance[x.first] > distance[node.second]+x.second){
                    distance[x.first] = distance[node.second]+x.second;
                    Q.insert({distance[x.first],x.first});
                    visited[x.first]=1;                    
                }
            }
        }
        int result=0;
        for(int i=1;i<=n;i++){
            if(distance[i]==INT_MAX) return -1;
            result = max(result,distance[i]);
        }
        return result;
    }
    
};