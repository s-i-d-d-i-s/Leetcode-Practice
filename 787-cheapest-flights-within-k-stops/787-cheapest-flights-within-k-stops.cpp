class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
        vector<int> distance(n+1,INT_MAX);
        distance[src]=0;
        for(int i=0;i<=k;i++){       
            vector<int> next_distance=distance;
            for(auto x:flights){
                if(distance[x[0]]!= INT_MAX and distance[x[0]]+x[2] < next_distance[x[1]]){
                    next_distance[x[1]] = distance[x[0]]+x[2];
                }
            }
            distance=next_distance;
        }
        
        if(distance[dst] == INT_MAX) return -1;
        return distance[dst];
    }
};