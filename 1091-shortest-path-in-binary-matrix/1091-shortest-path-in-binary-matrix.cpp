class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int,int>> Q;
        vector<vector<int>> result(n,vector<int>(m,INT_MAX));
        if(grid[0][0]!=0 or grid[n-1][m-1]!=0)
            return -1;
        
        Q.push({0,0});
        result[0][0]=1;        
        while(Q.size()>0){
            auto [r,c] = Q.front();
            Q.pop();
            for(auto dx:{-1,0,1}){
                for(auto dy:{-1,0,1}){
                    if(dx!=0 or dy!=0){
                        int nr = r+dx;
                        int nc = c+dy;
                        if(nr>=0 and nr<n and nc>=0 and nc<m and grid[nr][nc]==0 and result[nr][nc]==INT_MAX){
                            result[nr][nc] = 1+result[r][c];
                            Q.push({nr,nc});
                        }
                    }
                }
            }
        }
        if(result[n-1][m-1] == INT_MAX)result[n-1][m-1]=-1;
        return result[n-1][m-1];
    }
};