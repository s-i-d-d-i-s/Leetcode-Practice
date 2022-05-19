class Solution {
public:
    int dp[202][202];
    
    int solve(int x,int y,vector<vector<int>>& matrix){
        int res=1;
        if(dp[x][y]!=-1){
            return dp[x][y];
        }
        if(x-1>=0 and matrix[x][y]<matrix[x-1][y]){
            res = max(res,1+solve(x-1,y,matrix));
        }
        if(x+1<matrix.size() and matrix[x][y]<matrix[x+1][y]){
            res = max(res,1+solve(x+1,y,matrix));
        }
        if(y-1>=0 and matrix[x][y]<matrix[x][y-1]){
            res = max(res,1+solve(x,y-1,matrix));
        }
        if(y+1<matrix[0].size() and matrix[x][y]<matrix[x][y+1]){
            res = max(res,1+solve(x,y+1,matrix));
        }
        return dp[x][y]=res;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        memset(dp,-1,sizeof dp);
        int res=0;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                res = max(res,solve(i,j,matrix));
            }
        }
        return res;
    }
};