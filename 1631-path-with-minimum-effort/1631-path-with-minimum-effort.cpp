class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<int>> distance(n,vector<int>(m,INT_MAX));
        set<pair<int,pair<int,int>>> pq;
        pq.insert({0,{0,0}});
        distance[0][0]=0;
        while(pq.size()>0){
            auto cost = pq.begin()->first;
            auto [r,c] = pq.begin()->second;
            pq.erase(pq.begin());
            for(int dx:{-1,0,1}){
                for(int dy:{-1,0,1}){
                    if((dx==0 or dy==0) and (dx!=0 or dy!=0)){
                        int nr = r+dx;
                        int nc = c+dy;
                        if(nr>=0 and nr<n and nc>=0 and nc<m){
                            int costToMove = abs(heights[r][c]-heights[nr][nc]);
                            if(max(costToMove,cost) < distance[nr][nc]){
                                distance[nr][nc] = max(costToMove,cost);
                                pq.insert({distance[nr][nc],{nr,nc}});
                            }
                        }
                    }
                }
            }
        }
        return distance[n-1][m-1];
    }
};