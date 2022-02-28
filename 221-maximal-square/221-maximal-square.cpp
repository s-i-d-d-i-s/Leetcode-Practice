class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int dp[n][m];
        int result = 0;
        dp[0][0]=matrix[0][0]=='1';
        for(int i=0;i<n;i++)
            dp[i][0]=matrix[i][0]=='1';
        for(int i=0;i<m;i++)
            dp[0][i]=matrix[0][i]=='1';
        
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(matrix[i][j]=='1'){
                    int p1 = dp[i-1][j-1];
                    int p2 = dp[i-1][j];
                    int p3 = dp[i][j-1];
                    dp[i][j] = max(1,min({p2,p3,p1})+1);
                }else{
                    dp[i][j]=0;
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                result = max(result,dp[i][j]);
            }
        }
        return result*result;
    }
};