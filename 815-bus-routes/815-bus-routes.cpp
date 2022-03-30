class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        map<int,vector<int>> busstopsToBus,busTobusstops;
        for(int i=0;i<routes.size();i++){
            for(int j=0;j<routes[i].size();j++){
                busstopsToBus[routes[i][j]].push_back(i);
                busTobusstops[i].push_back(routes[i][j]);
            }
        }
        
        map<int,bool> visitedBusstop,visitedBus;
        
        queue<pair<int,int>> Q; //(busstop,currentBus)
        Q.push({source,0});
        
        visitedBusstop[source]=1;        
        while(Q.size()>0){
            auto [stop,busBoarded] = Q.front();
            if(stop == target) return busBoarded;
            Q.pop();            
            for(int bus : busstopsToBus[stop]){
                if(visitedBus[bus]) continue;
                visitedBus[bus]=1;
                for(int nextstop : busTobusstops[bus]){
                    if(visitedBusstop[nextstop]) continue;                    
                    visitedBusstop[nextstop] = 1;
                    Q.push({nextstop,busBoarded+1});
                }
            } 
        }
        return -1;
    }
};