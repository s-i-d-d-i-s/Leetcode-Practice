class Solution {
public:
    const long MOD = 1000000007;
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>> adjList(n+1);
        
        for(auto edge:roads){
            adjList[edge[0]].push_back({edge[1],edge[2]});
            adjList[edge[1]].push_back({edge[0],edge[2]});
        }
        
        multiset<pair<long long,long long>> q;
        
        vector<long long> dist(n,LLONG_MAX),ways(n,0);        
        dist[0]=0;
        ways[0]=1;
        q.insert({dist[0],0});
        while(q.size()>0 ){
            auto node = *q.begin();
            q.erase(q.begin());            
            long long currentCost = node.first;
            long long nodeValue = node.second;
            for(auto x:adjList[nodeValue]){
                if(dist[x.first]>currentCost+x.second){
                    dist[x.first]=currentCost+x.second;
                    q.insert({dist[x.first],x.first});
                    ways[x.first]=ways[nodeValue]%MOD;
                }else if(dist[x.first]==currentCost+x.second){
                    ways[x.first]+=ways[nodeValue];
                    ways[x.first] %= MOD;
                }
            }
        }
        return ways[n-1];
    }
};