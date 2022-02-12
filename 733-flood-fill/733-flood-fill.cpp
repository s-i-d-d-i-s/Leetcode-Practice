class Solution {
public:
    void solve(int x,int y,vector<vector<int>>& grid,vector<vector<bool>>& visit,int oldC,int newC){
        int n = grid.size();
        int m = grid[0].size();
        if(x<0 or x>=n or y<0 or y>=m) return;
        if(grid[x][y] != oldC or visit[x][y])return;
        visit[x][y]=1;
        grid[x][y]=newC;
        solve(x+1,y,grid,visit,oldC,newC);
        solve(x-1,y,grid,visit,oldC,newC);
        solve(x,y+1,grid,visit,oldC,newC);
        solve(x,y-1,grid,visit,oldC,newC);
        return;
    }
    vector<vector<int>> floodFill(vector<vector<int>>& grid, int sr, int sc, int newColor) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> visit(n,vector<bool>(m,0));
        solve(sr,sc,grid,visit,grid[sr][sc],newColor);
        return grid;   
    }
};