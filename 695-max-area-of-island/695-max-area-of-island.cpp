class Solution {
public:
    int solve(int x,int y,vector<vector<int>>& grid,vector<vector<bool>>& visit){
        int n = grid.size();
        int m = grid[0].size();
        if(x<0 or x>=n or y<0 or y>=m)
            return 0;
        if(grid[x][y] == 0 or visit[x][y])return 0;
        visit[x][y]=1;
        return 1+solve(x+1,y,grid,visit) + solve(x-1,y,grid,visit)  
             + solve(x,y+1,grid,visit) + solve(x,y-1,grid,visit);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> visit(n,vector<bool>(m,0));
        int res=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0 or visit[i][j]==1)continue;
                int cur = solve(i,j,grid,visit);
                res = max(res,cur);
            }
        }
        return res;
    }
};