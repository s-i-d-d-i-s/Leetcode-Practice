class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int n = heightMap.size();
        int m = heightMap[0].size();
        
        // (height, (x,y))
        multiset<pair<int,pair<int,int>>> pq;
        
        vector<vector<int>> visited(n,vector<int>(m,false));
            
        // All Boundary Rows
        for(int i=0;i<n;i++){
            int r=i;
            int c=0;
            pq.insert({heightMap[r][c],{r,c}});
            visited[r][c]=1;
            c=m-1;
            pq.insert({heightMap[r][c],{r,c}});
            visited[r][c]=1;
        }
        
        // All Boundary Cols
        for(int i=0;i<m;i++){
            int r=0;
            int c=i;
            pq.insert({heightMap[r][c],{r,c}});
            visited[r][c]=1;
            r=n-1;
            pq.insert({heightMap[r][c],{r,c}});
            visited[r][c]=1;
        }
        
        int result=0;
        while(pq.size()>0){
            auto [height,cord] = *pq.begin();
            auto [row,col] = cord;
            pq.erase(pq.begin());
            for(int dx:{-1,0,1}){
                for(int dy:{-1,0,1}){
                    if(dx==0 or dy==0){
                        int nextRow = row + dx;
                        int nextCol = col + dy;
                        if(nextRow >= 0 and nextRow <n and nextCol>=0 and nextCol<m 
                           and !visited[nextRow][nextCol]){
                            int water = max(0,height - heightMap[nextRow][nextCol]);
                            result += water;                            
                            int nextHeight = max(height,heightMap[nextRow][nextCol]);
                            pq.insert({nextHeight,{nextRow,nextCol}});
                            visited[nextRow][nextCol]=1;
                        }
                    }
                }
            }
        }
        return result;
    }
};