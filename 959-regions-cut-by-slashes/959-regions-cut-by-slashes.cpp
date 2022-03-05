class Solution {
public:
    
    void fill(vector<string>& grid,int r,int c,char cell){
        r = r*3;
        c = c*3;
        if(cell=='/'){
            
            grid[r][c+2]='#';
            grid[r+1][c+1]='#';
            grid[r+2][c]='#';
            
        }else if(cell=='\\'){
            for(int i=0;i<3;i++){
                grid[r+i][c+i]='#';
            }
        }
        return;
    }
    vector<string> upScale(vector<string>& grid){
        int n = grid.size();
        int m = grid[0].size();
        vector<string> newGrid(3*n,string(3*m,' '));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                char cell = grid[i][j];
                fill(newGrid,i,j,cell);
            }
        }
        return newGrid;
    }
    int regionsBySlashes(vector<string>& grid) {
        grid = upScale(grid);
        return noOfRegions(grid);
    }
    int noOfRegions(vector<string> &grid){
        int n = grid.size();
        int m = grid[0].size();
        int result = 0;
        vector<vector<bool>> visited(n,vector<bool>(m,false));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == '#') continue;
                if(visited[i][j]) continue;
                result++;
                depthFirstSearch(grid,visited,i,j,n,m);
            }
        }
        return result;
    }
    void depthFirstSearch(vector<string> &grid,vector<vector<bool>> &visited,
                          int i,int j,int n,int m){
        if(i<0 or j<0 or i>=n or j>=m or visited[i][j] or grid[i][j]=='#') return;
        visited[i][j]=true;
        depthFirstSearch(grid,visited,i+1,j,n,m);
        depthFirstSearch(grid,visited,i-1,j,n,m);
        depthFirstSearch(grid,visited,i,j-1,n,m);
        depthFirstSearch(grid,visited,i,j+1,n,m);
    }
    
};