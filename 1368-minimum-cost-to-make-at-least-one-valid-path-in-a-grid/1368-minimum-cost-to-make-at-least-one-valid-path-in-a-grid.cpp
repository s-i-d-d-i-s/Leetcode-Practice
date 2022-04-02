class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        int distance[n][m];
        
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++) distance[i][j] = INT_MAX;
        
        multiset<pair<int,pair<int,int>>> ms;
        
        ms.insert({0,{0,0}});
        
        distance[0][0] = 0;
        
        while(ms.size()>0){
            auto [cost,cord] = *ms.begin();
            ms.erase(ms.begin());
            auto [r,c] = cord;
            if(r==n-1 and c==m-1) return cost;
            if(r-1>=0 and distance[r-1][c] > (distance[r][c] + (int)(grid[r][c]!=4))){
                distance[r-1][c] = (distance[r][c] + (int)(grid[r][c]!=4));
                ms.insert({distance[r-1][c],{r-1,c} } );
            }
            if(r+1<n and distance[r+1][c] > (distance[r][c] + (int)(grid[r][c]!=3))){
                distance[r+1][c] = (distance[r][c] + (int)(grid[r][c]!=3));
                ms.insert({distance[r+1][c],{r+1,c} });
            }
            if(c-1>=0 and distance[r][c-1] > (distance[r][c] + (int)(grid[r][c]!=2))){
                distance[r][c-1] = (distance[r][c] + (int)(grid[r][c]!=2));
                ms.insert({distance[r][c-1],{r,c-1} } );
            }
            if(c+1<m and distance[r][c+1] > (distance[r][c] + (int)(grid[r][c]!=1))){
                distance[r][c+1] = (distance[r][c] + (int)(grid[r][c]!=1));
                ms.insert({distance[r][c+1],{r,c+1} } );
            }
        }
        return -1;
    }
};