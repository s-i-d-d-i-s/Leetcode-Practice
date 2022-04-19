class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int result=0;
        int n = grid.size();
        int m = grid[0].size();
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 1){
                    int total = 4;
                    for(int dx:{-1,0,1}){
                        for(int dy:{-1,0,1}){
                            if((dx==0 or dy==0) and (dx!=0 or dy!=0)){
                                int nr = i+dx;
                                int nc = j+dy;
                                if(nr>=0 and nr<n and nc>=0 and nc<m){
                                    if(grid[nr][nc] == 1){
                                        total--;
                                    }
                                }
                            }
                        }
                    }
                    result += total;
                }
            }
        }
        return result;
    }
};