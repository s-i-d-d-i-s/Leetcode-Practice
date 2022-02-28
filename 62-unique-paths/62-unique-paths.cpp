class Solution {
public:
    int dp[101][101];
    Solution(){
        memset(dp,-1,sizeof dp);
    }
    int uniquePaths(int m, int n) {
        if(m==1 and n==1) return 1;
        if(dp[n][m]!=-1)
            return dp[n][m];
        if(m==1) return dp[n][m]=uniquePaths(m,n-1);
        if(n==1) return dp[n][m]=uniquePaths(m-1,n);
        return dp[n][m]=uniquePaths(m-1,n) + uniquePaths(m,n-1);
    }
};