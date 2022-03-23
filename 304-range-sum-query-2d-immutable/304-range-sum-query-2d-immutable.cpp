class NumMatrix {
public:
    vector<vector<int>> dp2;
    NumMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                dp[i+1][j+1]=dp[i+1][j]+dp[i][j+1]-dp[i][j]+matrix[i][j];
            }
        }
        dp2=dp;
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return dp2[row2+1][col2+1] - dp2[row1][col2+1] - dp2[row2+1][col1] + dp2[row1][col1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */