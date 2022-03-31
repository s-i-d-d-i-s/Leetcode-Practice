class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        
        queue<vector<int>> Q;
        

        int visited[n][m][k+1]; // (allowedElimination,x,y)
        
        memset(visited,false,sizeof visited);
        
        Q.push({k,0,0,0}); // (allowedElimination,distance,x,y)
        
        visited[0][0][k]=1;
        
        while(Q.size()>0){
            int allowedElimination=Q.front()[0],distance=Q.front()[1],r=Q.front()[2],c=Q.front()[3];            
            Q.pop();

            if(r==n-1 and c==m-1){
                return distance;
            }
            for(int dx:{-1,0,1}){
                for(int dy:{-1,0,1}){
                    if((dx==0 or dy==0) and (dx!=dy)){
                        int nr = r+dx;
                        int nc = c+dy;

                        if(nr>=0 and nr<n and nc>=0 and nc<m){
                            if(grid[nr][nc]==1 and allowedElimination>0){  
                                vector<int> newState = {allowedElimination-1,distance+1,nr,nc};                                
                                
                                if(!visited[nr][nc][allowedElimination-1]){
                                    Q.push(newState);
                                    visited[nr][nc][allowedElimination-1]=1;
                                }
                            }else if(grid[nr][nc]==0){
                                vector<int> newState = {allowedElimination,distance+1,nr,nc};                                     
                                if(!visited[nr][nc][allowedElimination]){
                                    Q.push(newState);
                                    visited[nr][nc][allowedElimination]=1;
                                }
                            }
                        }
                    }
                }
            }
        }
        return -1;
    }
};

/*
[0,0,0]
[1,1,0]
[0,0,0]
[0,1,1]
[0,0,0]
1
*/