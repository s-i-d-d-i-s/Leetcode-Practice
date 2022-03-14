class Solution {
public:
    int dp[200][200];
    Solution(){
        memset(dp,-1,sizeof dp);
    }
    int minimumTotal(vector<vector<int>>& triangle,int r=0,int c=0) {
        if(r>=triangle.size() or c>=triangle[r].size())return 0;
        if(dp[r][c] != -1)
            return dp[r][c];
        
        return dp[r][c] = triangle[r][c] + min(minimumTotal(triangle,r+1,c),minimumTotal(triangle,r+1,c+1));
    }
};